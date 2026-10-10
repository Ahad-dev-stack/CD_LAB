
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char s[])
{
    char kw[][10] = {"int", "float", "char", "if", "else",
                     "for", "while", "do", "return", "void"};

    for (int i = 0; i < 10; i++)
        if (strcmp(s, kw[i]) == 0)
            return 1;

    return 0;
}

int main()
{
    char s[100], word[20];
    int i = 0, j;

    printf("Enter a statement: ");
    fgets(s, sizeof(s), stdin);

    while (s[i] != '\0')
    {
        if (isspace(s[i]))
            i++;

        else if (isalpha(s[i]) || s[i] == '_')
        {
            j = 0;
            while (isalnum(s[i]) || s[i] == '_')
                word[j++] = s[i++];
            word[j] = '\0';

            printf("%s : %s\n", word,
                   isKeyword(word) ? "Keyword" : "Identifier");
        }
        else if (isdigit(s[i]))
        {
            j = 0;
            while (isdigit(s[i]))
                word[j++] = s[i++];
            word[j] = '\0';
            printf("%s : Constant\n", word);
        }
        else if (strchr("+-*/=", s[i]))
            printf("%c : Operator\n", s[i++]);

        else if (strchr(";,(){}", s[i]))
            printf("%c : Special Symbol\n", s[i++]);

        else
            i++;
    }

    return 0;
}
