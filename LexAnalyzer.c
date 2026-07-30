%{
#include <stdio.h>
%}

%%
"int"|"float"|"char"|"if"|"else"|"while"|"return"
        { printf("Keyword: %s\n", yytext); }

[0-9]+
        { printf("Number: %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]*
        { printf("Identifier: %s\n", yytext); }

"+"|"-"|"*"|"/"|"="|"=="|"<"|">"
        { printf("Operator: %s\n", yytext); }

[(){};,]
        { printf("Special Symbol: %s\n", yytext); }

[ \t\n]
        ;

.
        { printf("Invalid Character: %s\n", yytext); }
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter the input:\n");
    yylex();
    return 0;
}
