#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stack>
#include <iostream>
#include <vector>
#include <math.h>   

using namespace std;


/*** Enums and Print Functions for Terminals and Non-Terminals  **********************/

#define MAX_SYMBOL_NAME_SIZE 25

//all of the terminals in the language
typedef enum {
	T_eof = 0,		// 0: end of file
	T_num,			// 1: numbers
	T_plus,			// 2: +
	T_minus,		// 3: -
	T_times,		// 4: *
        T_div,      	// 5: /
	T_comma,	    // 6: ,
	T_openparen,	// 7: (
	T_closeparen 	// 8: )
} token_type;

// This function returns a string for the token. It is used in the parsetree_t
// class to actually dump the parsetree to a dot file (which can then be turned
// into a picture).  Note that the return char* is a reference to a local copy
// and it needs to be duplicated if you are a going require multiple instances
// simultaneously.
//
// No need to do anything here
char* token_to_string(token_type c) {
	static char buffer[MAX_SYMBOL_NAME_SIZE];
	switch( c ) {
		case T_eof: strncpy(buffer,"eof",MAX_SYMBOL_NAME_SIZE); break;
		case T_num: strncpy(buffer,"num",MAX_SYMBOL_NAME_SIZE); break;
		case T_plus: strncpy(buffer,"+",MAX_SYMBOL_NAME_SIZE); break;
		case T_minus: strncpy(buffer,"-",MAX_SYMBOL_NAME_SIZE); break;
		case T_times: strncpy(buffer,"*",MAX_SYMBOL_NAME_SIZE); break;
		case T_div: strncpy(buffer,"/",MAX_SYMBOL_NAME_SIZE); break;
		case T_comma: strncpy(buffer,",",MAX_SYMBOL_NAME_SIZE); break;
		case T_openparen: strncpy(buffer,"(",MAX_SYMBOL_NAME_SIZE); break;
		case T_closeparen: strncpy(buffer,")",MAX_SYMBOL_NAME_SIZE); break;
		default: strncpy(buffer,"unknown_token",MAX_SYMBOL_NAME_SIZE); break;
	}
	return buffer;
}

// All of the non-terminals in the grammar. You need to add these in
// according to your grammar. These are used for printing the thing out, so
// please follow the convention we set up so that we can tell what the hack
// you are doing when I grade.
typedef enum {
	epsilon = 100,
	NT_List,
        NT_F,
        NT_R,
        NT_Z
	// WRITEME: add symbolic names for your non-terminals here
} nonterm_type;

// This function returns a string for the non-terminals. It is used in the
// parsetree_t class to actually dump the parsetree to a dot file (which can
// then be turned into a picture). Note that the return char* is a reference
// to a local copy and it needs to be duplicated if you are a going require
// multiple instances simultaneously.
//
// Add entries for all the non-terminals of your grammar following the same
// convention.
char* nonterm_to_string(nonterm_type nt)
{
	static char buffer[MAX_SYMBOL_NAME_SIZE];
	switch( nt ) {
		  case epsilon: strncpy(buffer,"e",MAX_SYMBOL_NAME_SIZE); break;
		  case NT_List: strncpy(buffer,"List",MAX_SYMBOL_NAME_SIZE); break;

                  case NT_F: strncpy(buffer,"F",MAX_SYMBOL_NAME_SIZE); break;
                  case NT_R: strncpy(buffer,"R",MAX_SYMBOL_NAME_SIZE); break;
                  case NT_Z: strncpy(buffer,"Z",MAX_SYMBOL_NAME_SIZE); break;
                default: strncpy(buffer,"unknown_nonterm",MAX_SYMBOL_NAME_SIZE); break;
		}
	return buffer;
}

/*** Scanner Class ***********************************************/

class scanner_t {
  public:

	// eats the next token and prints an error if it is not of type c
	void eat_token(token_type c);

	// peeks at the lookahead token
	token_type next_token();

	// return line number for errors
	int get_line();

	// constructor - inits g_next_token
	scanner_t();

  private:

	// WRITEME: Figure out what you will need to write the scanner
	// and to implement the above interface. It does not have to
	// be a state machine or anything fancy, it's pretty straightforward.
	// Just read in the characters one at a time from input (getchar would
	// be a good way) and group them into tokens. All of the tokens in
	// this calculator are trivial except for the numbers,
	// so it should not be that bad

	// This is a bogus member for implementing a useful stub, it should
	// be cut out once you get the scanner up and going.
	token_type bogo_token;
	void scan_error(char x);
	// error message and exit for mismatch
	void mismatch_error(token_type c);
        
        void tokenizeString();
        void scanNumber(string num);
        
        vector<string> strTokens;
        vector<token_type>tokens;
        int tokenPosition=0;
        int lineNumber=1;

};

token_type scanner_t::next_token()
{
	// WRITEME: replace this bogus junk with code that will take a peek
	// at the next token and return it to the parser.  It should _not_
	// actually consume a token - you should be able to call next_token()
	// multiple times without actually reading any more tokens in
  
    if(strTokens.size() == 0){
        return T_eof;
    }
   
    return tokens.at(tokenPosition);
   
}

void scanner_t::eat_token(token_type c)
{
	// if we are supposed to eat token c, and it does not match
	// what we are supposed to be reading from file, then it is a
	// mismatch error ( call - mismatch_error(c) )
    if(tokens.at(tokenPosition) == T_comma)
        lineNumber++;
    
    if(c != tokens.at(tokenPosition))
        mismatch_error(c);
    else
        tokenPosition++;

}

scanner_t::scanner_t()
{
        // WRITEME
    
    char c;
    string token;

    while ( (c = getchar()) != EOF ){
        if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' ||
           c=='6' || c=='7' || c=='8' || c=='9'){
            token+=c;
            int endOfNumber=0;
            while ( endOfNumber != 1){
                c = getchar();
                if( !(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' ||
                     c=='6' || c=='7' || c=='8' || c=='9' || c=='.') ){
                    endOfNumber=1;
                }
                else
                    token+=c;
            }
            strTokens.push_back(token);
            token.clear();
        }
        if(c==','){
            token+=c;
            strTokens.push_back(token);
            token.clear();
        }
        else if(c!='\n' && c!=' ' && c!=EOF){
               if(c=='+'||c=='-'||c=='*'|| c=='/'||c==','||c=='('||c==')'){
                token+=c;
                strTokens.push_back(token);
                token.clear();
               }
               else scan_error(c);
        }
        //else not a valid char
    }
    strTokens.push_back("EOF");
//    for(int i=0;i<strTokens.size();i++)
//        printf("strTokens: %s \n", strTokens.at(i).c_str());
//    
    tokenizeString();
    
}
void scanner_t::tokenizeString(){
    for(int i=0;i<strTokens.size();i++){
           if(strTokens.at(i) ==  "+" ) tokens.push_back(T_plus);
           else if(strTokens.at(i) ==  "-" ) tokens.push_back(T_minus);
           else if(strTokens.at(i) ==  "*" ) tokens.push_back(T_times);
           else if(strTokens.at(i) ==  "/" ) tokens.push_back(T_div);
           else if(strTokens.at(i) ==  "," ) tokens.push_back(T_comma);
           else if(strTokens.at(i) ==  "(" ) tokens.push_back(T_openparen);
           else if(strTokens.at(i) ==  ")" ) tokens.push_back(T_closeparen);
           else if(strTokens.at(i) ==  "EOF")tokens.push_back(T_eof);
           //its a number or error
           else scanNumber(strTokens.at(i));       
    }
//    for(int i=0;i<tokens.size();i++)
//        printf("Tokens: %s \n", token_to_string(tokens.at(i)));
    
}
void scanner_t::scanNumber(string num){
    int numDecimals = 0;
    
    if(num[0] != '0' && num[0] != '1' && num[0] != '2' && num[0] != '3' &&
       num[0] != '4' && num[0] != '5' && num[0] != '6' && num[0] != '7' &&
       num[0] != '8' && num[0] != '9'){
        scan_error(num[0]);
    }
   
    for(int i=1;i<num.length();i++){
       if(num[i] != '0' && num[i] != '1' && num[i] != '2' && num[i] != '3' &&
          num[i] != '4' && num[i] != '5' && num[i] != '6' && num[i] != '7' &&
          num[i] != '8' && num[i] != '9' && num[i] != '.')
           scan_error(num[i]);
       if(num[i] == '.')
           numDecimals++;
       if(numDecimals > 1)
           scan_error(num[i]);
    }
    //check decimal is 0-2^31-1
   float f = atof(num.c_str());
   if(f < 0 || f > (pow(2,31) -1) )
        scan_error(num[0]);
   tokens.push_back(T_num);
}

int scanner_t::get_line()
{
	// WRITEME
    return lineNumber;
}

void scanner_t::scan_error (char x)
{
	printf("scan error: unrecognized character '%c' -line %d\n",x, get_line());
	exit(1);

}

void scanner_t::mismatch_error (token_type x)
{
	printf("syntax error: found %s ",token_to_string(next_token()) );
	printf("expecting %s - line %d\n", token_to_string(x), get_line());
	exit(1);
}


/*** ParseTree Class **********************************************/

// This class is used to dump the parsed tree as a dot file. As you parse,
// you should dump the results here and not worry about it. This class is
// complete and you should not have to touch anything (if everything goes
// according to plan).
//
// While you don't have to modify it, you will have to call it from your
// recursive decent parser so read about the interface below.
class parsetree_t {
  public:
	void push(token_type t);
	void push(nonterm_type nt);
	void pop();
	void drawepsilon();
	parsetree_t();
  private:
	enum stype_t{
		TERMINAL=1,
		NONTERMINAL=0,
		UNDEF=-1
	};

	struct stuple {
		nonterm_type nt;
		token_type t;
		stype_t stype;
		int uniq;
	};
	void printedge(stuple temp); //prints edge from TOS->temp
	stack<stuple> stuple_stack;
	char* stuple_to_string(const stuple& s);
	int counter;
};


// the constructer just starts by initializing a counter (used to uniquely
// name all the parse tree nodes) and by printing out the necessary dot commands
parsetree_t::parsetree_t()
{
	counter = 0;
	printf("digraph G { page=\"8.5,11\"; size=\"7.5, 10\"\n");
}

// This push function taken a non terminal and keeps it on the parsetree
// stack. The stack keeps trace of where we are in the parse tree as
// we walk it in a depth first way. You should call push when you start
// expanding a symbol, and call pop when you are done. The parsetree_t
// will keep track of everything, and draw the parse tree as you go.
//
// This particular function should be called if you are pushing a non-terminal
void parsetree_t::push(nonterm_type nt)
{
	counter ++;
	stuple temp;
	temp.nt = nt;
	temp.stype = NONTERMINAL;
	temp.uniq = counter;
	printedge( temp );
	stuple_stack.push( temp );
}

//same as above, but for terminals
void parsetree_t::push(token_type t)
{
	counter ++;
	stuple temp;
	temp.t = t;
	temp.stype = TERMINAL;
	temp.uniq = counter;
	printedge( temp );
	stuple_stack.push( temp );
}

// When you are finished parsing a symbol, pop it. That way the parsetree_t
// will know that you are now working on a higher part of the tree.
void parsetree_t::pop()
{
	if ( !stuple_stack.empty() ) {
		stuple_stack.pop();
	}

	if ( stuple_stack.empty() ) {
		printf( "};\n" );
	}
}

// Draw an epsilon on the parse tree hanging off of the top of stack
void parsetree_t::drawepsilon()
{
	push(epsilon);
	pop();
}

// This private print function is called from push. Basically it
// just prints out the command to draw an edge from the top of the stack (TOS)
// to the new symbol that was just pushed. If it happens to be a terminal
// then it makes it a snazzy blue color so you can see your program on the leaves
void parsetree_t::printedge(stuple temp)
{
	if ( temp.stype == TERMINAL ) {
		printf("\t\"%s_%d\" [label=\"%s\",style=filled,fillcolor=powderblue]\n",
		  stuple_to_string(temp),
		  temp.uniq,
		  stuple_to_string(temp));
	} else {
		printf("\t\"%s_%d\" [label=\"%s\"]\n",
		  stuple_to_string(temp),
		  temp.uniq,
		  stuple_to_string(temp));
	}

	//no edge to print if this is the first node
	if ( !stuple_stack.empty() ) {
		//print the edge
		printf( "\t\"%s_%d\" ", stuple_to_string(stuple_stack.top()), stuple_stack.top().uniq );
		printf( "-> \"%s_%d\"\n", stuple_to_string(temp), temp.uniq );
	}
}

// just a private utility for helping with the printing of the dot stuff
char* parsetree_t::stuple_to_string(const stuple& s)
{
	static char buffer[MAX_SYMBOL_NAME_SIZE];
	if ( s.stype == TERMINAL ) {
		snprintf( buffer, MAX_SYMBOL_NAME_SIZE, "%s", token_to_string(s.t) );
	} else if ( s.stype == NONTERMINAL ) {
		snprintf( buffer, MAX_SYMBOL_NAME_SIZE, "%s", nonterm_to_string(s.nt) );
	} else {
		assert(0);
	}

	return buffer;
}


/*** Parser Class ***********************************************/

// Now on to the big stuff!
//
// The parser_t class handles everything. It has an instance of scanner_t
// so it can peek at tokens and eat them up. It also has access to the
// parsetree_t class so it can print out the parse tree as it figures it out.
// To make the recursive decent parser work, you will have to add some
// methods to this class. The helper functions are described below

class parser_t {
  private:
	scanner_t scanner;
	parsetree_t parsetree;
	void eat_token(token_type t);
	void syntax_error(nonterm_type);

	void List();
        void F();
        void R();
        void Z();
	// WRITEME: fill this out with the rest of the
	// recursive decent stuff (more methods)

  public:
	void parse();
};


// This function not only eats the token (moving the scanner forward one
// token), it also makes sure that token is drawn in the parse tree
// properly by calling push and pop.
void parser_t::eat_token(token_type t)
{
	parsetree.push(t);
	scanner.eat_token(t);
	parsetree.pop();
}

// Call this syntax error when you are trying to parse the
// non-terminal nt, but you fail to find a token that you need
// to make progress.  You should call this as soon as you can know
// there is a syntax_error.
void parser_t::syntax_error(nonterm_type nt)
{
	printf("syntax error: found %s in parsing %s - line %d\n",
		token_to_string( scanner.next_token()),
		nonterm_to_string(nt),
		scanner.get_line() );
	exit(1);
}



// Once the recursive decent parser is set up, you simply call parse()
// to parse the entire input, all of which can be derived from the start
// symbol
void parser_t::parse()
{
	List();
}


// WRITEME: the List() function is not quite right. Right now
// it is made to parse the grammar: List -> '+' List | EOF
// which is not a very interesting language. It has been included
// so you can see the basics of how to structure your recursive
// decent code.

//Here is an example
void parser_t::List()
{
	//push this non-terminal onto the parse tree.
	//the parsetree class is just for drawing the finished
	//parse tree, and should in should have no effect the actual
	//parsing of the data
	parsetree.push(NT_List);
            printf("list\n");
            switch( scanner.next_token() )
            {
            case T_eof:
                eat_token(T_eof);
                break;
            default:
               F();
               R();
               break;
            }
            
    //now that we are done with List, we can pop it from the data
    //stucture that is tracking it for drawing the parse tree
    parsetree.pop();
}
void parser_t::F(){
   parsetree.push(NT_F);
    printf("F\n");
	switch( scanner.next_token() )
	{
        case T_num:
            eat_token(T_num);
            break;
        case T_openparen:
            eat_token(T_openparen);
            List();
            if(scanner.next_token() == T_closeparen)
                eat_token(T_closeparen);
            break;
        default:
            syntax_error(NT_F);
            break;
        }
    parsetree.pop();
}
void parser_t::R() {
    parsetree.push(NT_R);
    printf("R\n");
    switch (scanner.next_token()) {
        case T_comma:
            Z();
            break;
        case T_times:
            Z();
            break;
        case T_div:
            Z();
            break;
        case T_closeparen:
            Z();
            break;
        case T_plus:
            eat_token(T_plus);
            F();
            R();
        case T_minus:
            eat_token(T_minus);
            F();
            R();
        default:
            syntax_error(NT_R);
            break;
    }
    parsetree.pop();
}

void parser_t::Z() {
    parsetree.push(NT_Z);
    printf("Z\n");
    switch (scanner.next_token()) {
        case T_comma:
            eat_token(T_comma);
            List();
            break;
        case T_closeparen:
            parsetree.drawepsilon();
            break;
        default:
            syntax_error(NT_Z);
            break;
    }
    parsetree.pop();
}
// WRITEME: you will need to put the rest of the procedures here


/*** Main ***********************************************/

int main(int argc, char* argv[])
{
	// just scanner
	if (argc > 1) {
                //If strcmp returns zero than equal
		if (strcmp(argv[1], "-s") == 0) {
			scanner_t scanner;
			token_type tok = scanner.next_token();
			while(tok != T_eof){
				scanner.eat_token(tok);
				printf("%s", token_to_string(tok));
				tok = scanner.next_token();
			}
			printf("%s\n", token_to_string(tok));
		}
	}
	else {
		parser_t parser;
		parser.parse();
	}
	return 0;
}
