%{
#include <stdio.h>

int words = 0;
int lines = 0;
%}

%%

\n              { lines++; }
[ \t]+           ;
[^ \t\n]+        { words++; }

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter the text (Press Ctrl+D to finish):\n");

    yylex();

    printf("\nNumber of lines = %d\n", lines);
    printf("Number of words = %d\n", words);

    return 0;
}
