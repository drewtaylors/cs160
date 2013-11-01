/* A Bison parser, made by GNU Bison 2.6.1.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_PARSER_HPP
# define YY_PARSER_HPP
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BOOL = 258,
     ELSE = 259,
     IF = 260,
     INT = 261,
     FOR = 262,
     VAR = 263,
     FUNCTION = 264,
     INTARRAY = 265,
     RETURN = 266,
     EQEQ = 267,
     GT = 268,
     GTE = 269,
     LT = 270,
     LTE = 271,
     NE = 272,
     ANDAND = 273,
     OROR = 274,
     NOT = 275,
     PLUS = 276,
     MINUS = 277,
     TIMES = 278,
     DIVIDE = 279,
     TRUE = 280,
     FALSE = 281,
     IDENTIFIER = 282,
     INTEGER = 283,
     SEMICOLON = 284,
     COLON = 285,
     COMMA = 286,
     ABSOLUTEVALUE = 287,
     LEFTBRACE = 288,
     RIGHTBRACE = 289,
     LEFTPAREN = 290,
     RIGHTPAREN = 291,
     LEFTBRACKET = 292,
     RIGHTBRACKET = 293,
     ASSIGNMENT = 294
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_PARSER_HPP  */
