Ramon Rovirosa
ramon.rovirosa@gmail.com
CS160
Project 1
10/11/13


Scanner
In the constructor, what I do is get the charecters, charecter by charecter using getchar(). I have a variable called token that gets the charecters and concatenates them to the string variable token. This is used to distinguish between numbers and the other operators.


Then I place the string variable inside of a vector<string> array. So by the end of the file, the vector = [2.0,+,5, ,] etc…


Then after I have all the characters for the numbers and operations figured out, I create a vector<token_type> that looks something like this: [T_num,T_plus,T_num,T_comma, T_EOF].


In eatToken, I increment the vector token position, as well as the string position, and say that if I encounter a new line in the string vector, then increment the linenumber variable that keeps track of what line I am on. In eat_token, I also make sure I have no mismatch errors.


Next token, simply gets the token at the current position in the token_type vector.


Parser
My Grammar is as follows: 


S    :    F R 
       | 'EOF'
       ;


R    :    '+' F R
        | '-' F R
        | Z
        ;


Z    :    '*' F R
        | '/' F R
        | ',' S
        ;


F    :  'number'
        | '(' F A ')'
        ;


A   :   '+' F A
        | '-' F A
        | B
        ;
B   :   '*' F A
        | '/' F A
        |
        ;
It is left recursive and unambiguous.
Using this grammar, my algorithm involves checking each character left to right. If the charecters are not the one they are supposed to be, than I throw a syntax error.
This is accomplished with a switch statmen that for example checks the first token:
switch( scanner.next_token() )
        {
        case T_eof:
            eat_token(T_eof);
            break;
        case T_num:
            F();
            R();
            break;
        case T_openparen:
            F();
            R();
            break;
        default:
           syntax_error(NT_F);
            break;
        }
The first token is either: EOF,a number, or open parenthesis. If we do not read in one of these three than we hit the default case and know we have a syntax error.