#ifndef scanner
#define scanner

struct token{
    char* str;
    int val;
};





#define KEYWORD_COUNT 32
extern struct token keywords[KEYWORD_COUNT];



extern FILE* curr_fp; /* current file pointer scanner is using */

extern int token_value;


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


//Add As Needed

#endif
