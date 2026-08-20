%{
#include "variable_4b.tab.h"
%}

%%

[A-Za-z]    { return LETTER; }
[0-9]       { return DIGIT; }
[ \t]       ;
\n          { return '\n'; }
.           { return yytext[0]; }

%%

int yywrap(void)
{
    return 1;
}

