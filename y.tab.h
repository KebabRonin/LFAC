/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    ID = 258,
    TIP = 259,
    ASSIGN = 260,
    NR = 261,
    CMP_OP = 262,
    CLASS = 263,
    STRING = 264,
    FLOAT = 265,
    CHAR = 266,
    BOOL = 267,
    BGIN = 268,
    END = 269,
    CONST = 270,
    IF = 271,
    WHILE = 272,
    DO = 273,
    ELSE = 274,
    FOR = 275,
    BOOLAND = 276,
    BOOLOR = 277,
    TYPEOF = 278,
    EVAL = 279,
    GLOBDEF = 280,
    FNCDEF = 281,
    STRUCTDEF = 282
  };
#endif
/* Tokens.  */
#define ID 258
#define TIP 259
#define ASSIGN 260
#define NR 261
#define CMP_OP 262
#define CLASS 263
#define STRING 264
#define FLOAT 265
#define CHAR 266
#define BOOL 267
#define BGIN 268
#define END 269
#define CONST 270
#define IF 271
#define WHILE 272
#define DO 273
#define ELSE 274
#define FOR 275
#define BOOLAND 276
#define BOOLOR 277
#define TYPEOF 278
#define EVAL 279
#define GLOBDEF 280
#define FNCDEF 281
#define STRUCTDEF 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "limbaj.y"

int intval;
char* strval;
char charval;
float floatval;
struct Tip_Date* tipD;
struct list* ls;
struct simbol* symbol;
struct AstNode* ast;

#line 122 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
