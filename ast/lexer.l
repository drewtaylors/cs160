%option yylineno
%pointer

%{
#include <stdlib.h>
#include <string.h>
#include "ast.hpp"
#include "parser.hpp"

void yyerror(const char *);
%}

/***************************************************************************
	Replace with your code from this point on
***************************************************************************/

%%


%%

/***************************************************************************
	Stop replacing code here
***************************************************************************/

int yywrap(void) {
	return 1;
}
