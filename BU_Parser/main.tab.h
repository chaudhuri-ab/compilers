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

#ifndef YY_YY_MAIN_TAB_H_INCLUDED
# define YY_YY_MAIN_TAB_H_INCLUDED
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
    LBRACKET = 258,
    ID = 260,
    STRING = 261,
    CHAR_CONST = 262,
    NUMBER = 263,
    ADD = 264,
    SUB = 265,
    MUL = 266,
    DIV = 267,
    ABS = 268,
    MOD = 269,
    LT = 270,
    GT = 271,
    LEQ = 272,
    GEQ = 273,
    EQUAL_TO = 274,
    ASSIGN = 275,
    NOT = 276,
    UNSIGNED = 277,
    SIGNED = 278,
    AND = 279,
    OR = 280,
    BITWISE_AND = 281,
    BITWISE_OR = 282,
    BITWISE_XOR = 283,
    OP = 284,
    CP = 285,
    LB = 286,
    RB = 287,
    RBRACKET = 288,
    INCREMENT = 289,
    DECREMENT = 290,
    EOL = 291,
    END_OF_FILE = 292,
    COLON = 293,
    PERIOD = 294,
    COMMA = 295,
    POINTER_TO_MEMBER = 296,
    SEMI_COLON = 297,
    INT = 298,
    FLOAT = 299,
    CHAR = 300,
    DOUBLE = 301,
    SHORT = 302,
    LONG = 303,
    IF = 304,
    ELSE = 305,
    WHILE = 306,
    FOR = 307,
    DO = 308,
    RETURN = 309,
    INCLUDE = 310
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 17 "main.y" /* yacc.c:1909  */

    int intValue;
    double floatValue;
    char *stringValue;

#line 115 "main.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MAIN_TAB_H_INCLUDED  */
