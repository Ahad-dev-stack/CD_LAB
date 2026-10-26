
%{
#include <stdio.h>
int yylex(void);
void yyerror(char *s);
%}

%token NUM
%left '+' '-'
%left '*' '/'

%%
E : E '+' E  { $$ = $1 + $3; }
  | E '-' E  { $$ = $1 - $3; }
  | E '*' E  { $$ = $1 * $3; }
  | E '/' E  { $$ = $1 / $3; }
  | '(' E ')' { $$ = $2; }
  | NUM       { $$ = $1; }
  ;
%%

int yylex()
{
    int n;
    if (scanf("%d", &n) == 1) {
        yylval = n;
        return NUM;
    }
    return 0;
}

void yyerror(char *s)
{
    printf("Invalid expression\n");
}

int main()
{
    printf("Enter expression: ");
    yyparse();
    return 0;
}
