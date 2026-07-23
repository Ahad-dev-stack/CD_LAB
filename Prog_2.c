#include <stdio.h>
#include <string.h>
#include <ctype.h>

char Keywords[][10] = {
    "if", "else", "while", "for", "int",
    "float", "char", "double", "return",
    "void", "main"
};

int isKeyword(char str[])
{
    int n = sizeof(Keywords) / sizeof(Keywords[0]);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(str, Keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main()
{
    char input[200], token[50];
    int i = 0, j;

    printf("Enter the input line:\n");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    while (input[i] != '\0')
    {
        if (isspace(input[i]))
        {
            i++;
            continue;
        }

        if (isalpha(input[i]) || input[i] == '_')
        {
            j = 0;

            while (isalnum(input[i]) || input[i] == '_')
            {
                token[j++] = input[i++];
            }

            token[j] = '\0';

            if (isKeyword(token))
                printf("%s ----> Keyword\n", token);
            else
                printf("%s ----> Identifier\n", token);
        }

        else if (isdigit(input[i]))
        {
            j = 0;

            while (isdigit(input[i]))
            {
                token[j++] = input[i++];
            }

            token[j] = '\0';

            printf("%s ----> Digit\n", token);
        }

        else if (strchr("+-*/%=<>", input[i]))
        {
            printf("%c ----> Operator\n", input[i]);
            i++;
        }

        else if (strchr(";,:", input[i]))
        {
            printf("%c ----> Separator\n", input[i]);
            i++;
        }

        else if (strchr("(){}[]", input[i]))
        {
            printf("%c ----> Special Symbol\n", input[i]);
            i++;
        }

        else
        {
            printf("%c ----> Unknown Symbol\n", input[i]);
            i++;
        }
    }

    return 0;
}
