
%{
#include <stdio.h>
int yylex(void);
void yyerror(char *s);
%}

%%
S : '(' S ')' S
  | /* empty */
  ;
%%

int yylex()
{
    return getchar();
}

void yyerror(char *s)
{
    printf("Invalid string\n");
}

int main()
{
    printf("Enter parentheses: ");
    if (yyparse() == 0)
        printf("Valid string\n");
    return 0;
}
