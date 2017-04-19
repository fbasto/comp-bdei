/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BOOL = 258,
    CLASS = 259,
    DO = 260,
    DOTLENGTH = 261,
    DOUBLE = 262,
    ELSE = 263,
    IF = 264,
    INT = 265,
    PARSEINT = 266,
    PRINT = 267,
    PUBLIC = 268,
    RETURN = 269,
    STATIC = 270,
    STRING = 271,
    VOID = 272,
    WHILE = 273,
    OCURV = 274,
    CCURV = 275,
    OBRACE = 276,
    CBRACE = 277,
    OSQUARE = 278,
    CSQUARE = 279,
    AND = 280,
    OR = 281,
    LT = 282,
    GT = 283,
    EQ = 284,
    NEQ = 285,
    LEQ = 286,
    GEQ = 287,
    PLUS = 288,
    MINUS = 289,
    STAR = 290,
    DIV = 291,
    MOD = 292,
    NOT = 293,
    ASSIGN = 294,
    SEMI = 295,
    COMMA = 296,
    RESERVED = 297,
    NEWLINE = 298,
    BOOLLIT = 299,
    STRLIT = 300,
    DECLIT = 301,
    REALLIT = 302,
    ID = 303
  };
#endif
/* Tokens.  */
#define BOOL 258
#define CLASS 259
#define DO 260
#define DOTLENGTH 261
#define DOUBLE 262
#define ELSE 263
#define IF 264
#define INT 265
#define PARSEINT 266
#define PRINT 267
#define PUBLIC 268
#define RETURN 269
#define STATIC 270
#define STRING 271
#define VOID 272
#define WHILE 273
#define OCURV 274
#define CCURV 275
#define OBRACE 276
#define CBRACE 277
#define OSQUARE 278
#define CSQUARE 279
#define AND 280
#define OR 281
#define LT 282
#define GT 283
#define EQ 284
#define NEQ 285
#define LEQ 286
#define GEQ 287
#define PLUS 288
#define MINUS 289
#define STAR 290
#define DIV 291
#define MOD 292
#define NOT 293
#define ASSIGN 294
#define SEMI 295
#define COMMA 296
#define RESERVED 297
#define NEWLINE 298
#define BOOLLIT 299
#define STRLIT 300
#define DECLIT 301
#define REALLIT 302
#define ID 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "jac.y" /* yacc.c:1909  */

	char * string;
	struct node *node;

#line 155 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
