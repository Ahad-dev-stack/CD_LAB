#include <stdio.h>
#include <string.h>

char input[100];
int i = 0;

void S();
void L();
void Lprime();

/* S -> (L) | a */
void S()
{
    if (input[i] == 'a')
    {
        i++;
    }
    else if (input[i] == '(')
    {
        i++;
        L();

        if (input[i] == ')')
            i++;
        else
        {
            printf("Invalid Expression\n");
            return;
        }
    }
    else
    {
        printf("Invalid Expression\n");
        return;
    }
}

/* L -> S L' */
void L()
{
    S();
    Lprime();
}

/* L' -> , S L' | epsilon */
void Lprime()
{
    if (input[i] == ',')
    {
        i++;
        S();
        Lprime();
    }
}

int main()
{
    printf("Enter the expression: ");
    scanf("%s", input);

    S();

    if (input[i] == '\0')
        printf("Valid Expression\n");
    else
        printf("Invalid Expression\n");

    return 0;
}
