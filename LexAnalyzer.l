%{
#include <stdio.h>
%}

%%

int         { printf("Keyword: %s\n", yytext); }
float       { printf("Keyword: %s\n", yytext); }
char        { printf("Keyword: %s\n", yytext); }
if          { printf("Keyword: %s\n", yytext); }
else        { printf("Keyword: %s\n", yytext); }
while       { printf("Keyword: %s\n", yytext); }
return      { printf("Keyword: %s\n", yytext); }

[0-9]+      { printf("Number: %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]*   { printf("Identifier: %s\n", yytext); }

"=="        { printf("Operator: %s\n", yytext); }
"="         { printf("Operator: %s\n", yytext); }
"+"         { printf("Operator: %s\n", yytext); }
"-"         { printf("Operator: %s\n", yytext); }
"*"         { printf("Operator: %s\n", yytext); }
"/"         { printf("Operator: %s\n", yytext); }
"<"         { printf("Operator: %s\n", yytext); }
">"         { printf("Operator: %s\n", yytext); }

[(){};,]    { printf("Special Symbol: %s\n", yytext); }

[ \t\n]+    ;

.           { printf("Invalid Character: %s\n", yytext); }

%%

int yywrap(void)
{
    return 1;
}

int main(void)
{
    printf("Enter the input:\n");
    yylex();
    return 0;
}

//install in terminal
        //sudo apt install flex yacc
//Gen C file
        //flex lexAnalyzer.l
//Compile Gen c program
        //gcc lex.yy.c -o lexAnalyzer -lfl
//Running program
        //./lexAnalyzer
