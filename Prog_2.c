
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char keywords[][10] = {
    "int", "float", "char", "if", "else",
    "while", "for", "return", "void", "main"
};

int main() {
    char s[200], token[50];
    int i = 0, j, found;

    printf("Enter input: ");
    fgets(s, sizeof(s), stdin);

    while (s[i] != '\0') {
        if (isspace(s[i])) {
            i++;
        }
        else if (isalpha(s[i]) || s[i] == '_') {
            j = 0;

            while (isalnum(s[i]) || s[i] == '_')
                token[j++] = s[i++];

            token[j] = '\0';
            found = 0;

            for (int k = 0; k < 10; k++) {
                if (strcmp(token, keywords[k]) == 0)
                    found = 1;
            }

            if (found)
                printf("%s -> Keyword\n", token);
            else
                printf("%s -> Identifier\n", token);
        }
        else if (isdigit(s[i])) {
            printf("%c -> Digit\n", s[i++]);
        }
        else if (strchr("+-*/%=<>", s[i])) {
            printf("%c -> Operator\n", s[i++]);
        }
        else if (strchr(";,:", s[i])) {
            printf("%c -> Separator\n", s[i++]);
        }
        else if (strchr("(){}[]", s[i])) {
            printf("%c -> Special Symbol\n", s[i++]);
        }
        else {
            i++;
        }
    }

    return 0;
}
