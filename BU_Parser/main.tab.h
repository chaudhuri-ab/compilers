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
    ID = 258,
    STRING = 259,
    CHAR_CONST = 260,
    NUMBER = 261,
    ADD = 262,
    SUB = 263,
    MUL = 264,
    DIV = 265,
    ABS = 266,
    MOD = 267,
    LT = 268,
    GT = 269,
    LEQ = 270,
    GEQ = 271,
    EQUAL_TO = 272,
    ASSIGN = 273,
    NOT = 274,
    UNSIGNED = 275,
    SIGNED = 276,
    AND = 277,
    OR = 278,
    BITWISE_AND = 279,
    BITWISE_OR = 280,
    BITWISE_XOR = 281,
    OP = 282,
    CP = 283,
    LB = 284,
    RB = 285,
    INCREMENT = 286,
    DECREMENT = 287,
    EOL = 288,
    END_OF_FILE = 289,
    COLON = 290,
    PERIOD = 291,
    COMMA = 292,
    POINTER_TO_MEMBER = 293,
    SEMI_COLON = 294,
    INT = 295,
    FLOAT = 296,
    CHAR = 297,
    DOUBLE = 298,
    SHORT = 299,
    LONG = 300,
    IF = 301,
    ELSE = 302,
    WHILE = 303,
    FOR = 304,
    DO = 305,
    RETURN = 306,
    INCLUDE = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "main.y" /* yacc.c:1909  */

    int intValue;
    double floatValue;
    char *stringValue;

#line 113 "main.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MAIN_TAB_H_INCLUDED  */
