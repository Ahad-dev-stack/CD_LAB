%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token LETTER DIGIT

%%

program:
        variable '\n'    { printf("Valid variable\n"); }
        ;

variable:
        LETTER chars
        ;

chars:
        LETTER chars
      | DIGIT chars
      | /* empty */
      ;

%%

void yyerror(const char *s)
{
    printf("Invalid variable\n");
}

int main(void)
{
    printf("Enter a variable: ");
    yyparse();
    return 0;
}

/*
bison -d variable_4b.y
flex variable_4a.l
gcc variable_4a.tab.c lex.yy.c -o variable_4a
./variable_4a

output:
Enter a variable: abc
Valid variable
123abc
Invalid variable

*/

