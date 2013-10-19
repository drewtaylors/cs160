%option yylineno
%pointer

%{
#include <stdlib.h>
#include <string.h>
#include "parser.hpp"

void yyerror(const char *);
%}

/*
  The example below is very simple, but it shows almost everything you will need
  to do for this first part.

  The syntax is as follows:

  regular_expression      {  c code  }

  The lexer will try to match each regular expression.  When it does it will execute
  the c code.
*/

%%

bool                         { return BOOL;    }
else                         { return ELSE;    }
if                           { return IF;      }
int                          { return INT;     }
for                          { return FOR;     }
var                          { return VAR;     }
function                     { return FUNCTION;}
intarray                     { return INTARRAY;}
return                       { return RETURN;  }

"=="                         { return EQEQ;    }
">"                          { return GT;      }
">="                         { return GTE;     }
"<"                          { return LT;      }
"<="                         { return LTE;     }
"!="                         { return NE;      }
"&&"                         { return ANDAND;  }
"||"                         { return OROR;    }
"!"                          { return NOT;     }
"+"                          { return PLUS;    }
"-"                          { return MINUS;   }
"*"                          { return TIMES;   }
"/"                          { return DIVIDE;  }

true                         { return TRUE; }
false                        { return FALSE; }

[a-zA-Z][a-zA-Z]*            { return IDENTIFIER;}

[0]                          { return INTEGER; }
[1-9][0-9]*                  { return INTEGER; }
[0x|0X][0-9A-F]              { return INTEGER; }
[0][0-7]+                    { return INTEGER; }
[0-1]+[b]                    { return INTEGER; }

";"                          { return SEMICOLON;}
":"                          { return COLON; }
","                          { return COMMA; }
"|"                          { return ABSOLUTEVALUE;}
"{"                          { return LEFTBRACE;}
"}"                          { return RIGHTBRACE; }
"("                          { return LEFTPAREN; }
")"                          { return RIGHTPAREN; }
"["                          { return LEFTBRACKET; }
"]"                          { return RIGHTBRACKET; }
"="                          { return ASSIGNMENT; }

[ \t\n]                      ; /* skip whitespace */

.                            yyerror((char *) "invalid character");

%%


/* You shouldn't need to edit any part of this*/

int yywrap(void) {
	return 1;
}
