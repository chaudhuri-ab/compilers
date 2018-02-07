#ifndef scanner
#define scanner

struct token{
    char* str;
    int val;
};


struct state {
    int next_state;
    void *transition_fcn;
    int token_val; /*token constant found in scanner.h*/
};

#define SCANNER_INPUT_BUFFER 1024


//
extern FILE* curr_fp; /* current file pointer scanner is using */

extern struct val token_value; /* Used By Parser To Get Token Value */
extern int scanner_current_state; 
#define NUM_STATES 13
#define NUM_ALPHABET 94
extern struct state scanner_state_machine[NUM_STATES][NUM_ALPHABET];

//


#define KEYWORD_COUNT 33
extern struct token keywords[KEYWORD_COUNT];


/* Token Constants - KEYWORDS */
#define END_OF_FILE 299
#define AUTO 300
#define DOUBLE 301
#define INT 302
#define STRUCT 303
#define CONST  304
#define FLOAT  305
#define SHORT  306
#define UNSIGNED 307
#define BREAK 308
#define ELSE 309
#define LONG 310
#define SWITCH 311
#define CONTINUE 312
#define FOR 313
#define SIGNED 314
#define VOID 315
#define CASE 316
#define ENUM 317
#define REGISTER 318
#define TYPEDEF 319
#define DEFAULT  320
#define GOTO  321
#define SIZEOF  322
#define VOLATILE 323
#define CHAR 324
#define EXTERN 325
#define RETURN 326
#define UNION 327
#define DO 328
#define IF 329
#define STATIC 330
#define WHILE 331
#define INCLUDE 1332

//


//Double and Triple Op Tokens
#define ELLIPSIS 332 /* ... */
#define RIGHT_ASSIGN 333 /* >>= */
#define LEFT_ASSIGN 334 /* <<= */
#define ADD_ASSIGN 335 /* += */ /*Done*/
#define SUB_ASSIGN 336 /* -= */ /*Done*/
#define MUL_ASSIGN 337 /* *= */
#define DIV_ASSIGN 338 /* /= */
#define MOD_ASSIGN 339 /* %= */
#define AND_ASSIGN 340 /* &= */
#define XOR_ASSIGN 341 /* ^= */
#define OR_ASSIGN 342 /* |= */
#define RIGHT_OP 343 /* >> */
#define LEFT_OP 344 /* << */
#define INC_OP 345 /* ++ */  /*Done*/
#define DEC_OP 346 /* -- */ /*Done*/
#define PTR_OP 347 /* -> */
#define AND_OP 348 /* && */
#define OR_OP 349 /* || */
#define LE_OP 350 /* <= */
#define GE_OP 351 /* >= */
#define EQ_OP 352 /* == */
#define NEQ_OP 353 /* != */


#define STRING_LITERAL 354
#define ID 355
#define CONSTANT 356


#define BAD_TOKEN 9999
#define PREPROCESSOR_FLAG 10000 /*Flag To Indicate Preprocessor*/

//Direct Return Tokens
/* 
";"			{ count(); return(';'); }
("{"|"<%")		{ count(); return('{'); }
("}"|"%>")		{ count(); return('}'); }
","			{ count(); return(','); }
":"			{ count(); return(':'); }
"="			{ count(); return('='); }
"("			{ count(); return('('); }
")"			{ count(); return(')'); }
("["|"<:")		{ count(); return('['); }
("]"|":>")		{ count(); return(']'); }
"."			{ count(); return('.'); }
"&"			{ count(); return('&'); }
"!"			{ count(); return('!'); }
"~"			{ count(); return('~'); }
"-"			{ count(); return('-'); }
"+"			{ count(); return('+'); }
"*"			{ count(); return('*'); }
"/"			{ count(); return('/'); }
"%"			{ count(); return('%'); }
"<"			{ count(); return('<'); }
">"			{ count(); return('>'); }
"^"			{ count(); return('^'); }
"|"			{ count(); return('|'); }
"?"			{ count(); return('?'); }

[ \t\v\n\f]		{ count(); } //Ignore spaces
 
 */
#endif
