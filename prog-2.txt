#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords[][10] = {
    "int", "float", "char", "if", "else",
    "while", "for", "return", "void", "main"
};

int isKeyword(char str[])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main()
{
    char input[200], token[50];
    int i = 0, j;

    printf("Enter a C statement:\n");
    fgets(input, sizeof(input), stdin);

    /* Remove newline character */
    input[strcspn(input, "\n")] = '\0';

    while (input[i] != '\0')
    {
        /* Skip spaces */
        if (isspace(input[i]))
        {
            i++;
            continue;
        }

        /* Keyword or Identifier */
        if (isalpha(input[i]) || input[i] == '_')
        {
            j = 0;
            while (isalnum(input[i]) || input[i] == '_')
            {
                token[j++] = input[i++];
            }
            token[j] = '\0';

            if (isKeyword(token))
                printf("%s --> Keyword\n", token);
            else
                printf("%s --> Identifier\n", token);
        }

        /* Constant */
        else if (isdigit(input[i]))
        {
            j = 0;
            while (isdigit(input[i]))
            {
                token[j++] = input[i++];
            }
            token[j] = '\0';

            printf("%s --> Constant\n", token);
        }

        /* Operators */
        else if (strchr("+-*/=%<>", input[i]))
        {
            printf("%c --> Operator\n", input[i]);
            i++;
        }

        /* Special Symbols */
        else if (strchr("(){}[],;", input[i]))
        {
            printf("%c --> Special Symbol\n", input[i]);
            i++;
        }

        /* Unknown Character */
        else
        {
            printf("%c --> Unknown\n", input[i]);
            i++;
        }
    }

    return 0;
}