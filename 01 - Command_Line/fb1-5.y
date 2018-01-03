

%{
#  include <stdio.h>
#  include <string.h>
#  include <stdlib.h>


void process_tuple_opts(char* opts);
void reset ();


int R = 0; //recursive
int user_perm = 0; //user user_perm
int group_perm = 0; //group group perm
int other_perm = 0; //other other perm
int options = 0; //option val
char* file;
%}

/* declare tokens */
%token OPT_RECUR OPT_UPERM OPT_GPERM OPT_OPERM OPT_OPTIONS
%token OPT_TRIPLE OPT_FOUR_TUPLE
%token NUMBER WORD
%token EOL

%%

input: /* nothing */
 | input command EOL { printf("File = %s | R = %d | User_Perm = %d | Group_Perm = %d | Other_Perm = %d | Options = %d\n\n> ", file, R, user_perm, group_perm, other_perm, options); free(file); reset();}
 | input EOL { printf("> "); } /* blank line or a comment */
 ;

command: WORD opt {file = $1; printf("1) %s\n", $1); }
 ;

 opt: 
 | opt_val opt
 ;
 
 opt_val: OPT_RECUR NUMBER {$$ = $2; R = $2;}
 | OPT_UPERM NUMBER {$$ = $2; user_perm = $2;}
 | OPT_GPERM NUMBER {$$ = $2; group_perm = $2;}
 | OPT_OPERM NUMBER {$$ = $2; other_perm = $2;}
 | OPT_OPTIONS NUMBER {$$ = $2; options = $2;} 
 | OPT_RECUR NUMBER opt_tuple {printf("2) opt_tuple = %s\n", $3); free($3); /*pass up value to parent prod*/}
 | opt_tuple {printf("3) opt_tuple = %s\n", $1); free($1);}
 ;
 
 opt_tuple: 
 |OPT_TRIPLE {process_tuple_opts($1);}
 | OPT_FOUR_TUPLE {process_tuple_opts($1);}
 
%%
main()
{
  printf("> "); 
  yyparse();
}

yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
}



void reset(){
    R = 0;
    user_perm = 0;
    group_perm = 0;
    other_perm = 0;
    options = 0;
    file = NULL;
    
}


void process_tuple_opts(char* opts){
    if(strlen(opts) == 3){
        int temp = atoi(opts);
        user_perm = (temp / 100) % 10;
        group_perm = (temp / 10) % 10;
        other_perm = (temp / 1) % 10;
    }else{
        int temp = atoi(opts);
        options = (temp / 1000) % 10;
        user_perm = (temp / 100) % 10;
        group_perm = (temp / 10) % 10;
        other_perm = (temp / 1) % 10;
    }
    
}