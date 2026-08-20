%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token NUMBER

%%

program:
        expr '\n'    { printf("Valid arithmetic expression\n"); }
        ;

expr:
        expr '+' term
      | expr '-' term
      | term
      ;

term:
        term '*' factor
      | term '/' factor
      | factor
      ;

factor:
        NUMBER
      | '(' expr ')'
      ;

%%

void yyerror(const char *s)
{
    printf("Invalid arithmetic expression\n");
}

int main(void)
{
    printf("Enter an arithmetic expression: ");
    yyparse();
    return 0;
}


/*
bison -d arith.y
flex arith.l
gcc arith.tab.c lex.yy.c -o arith
./arith

output:
Enter an arithmetic expression: 10 + 20 * 5
Valid arithmetic expression
*/
