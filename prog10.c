#include <stdio.h>
#include <string.h>

char input[100];
int i = 0;

void E();
void T();
void F();

void E()
{
    T();

    while (input[i] == '+')
    {
        i++;
        T();
    }
}

void T()
{
    F();

    while (input[i] == '*')
    {
        i++;
        F();
    }
}

void F()
{
    if (strncmp(&input[i], "id", 2) == 0)
    {
        i += 2;
    }
    else if (input[i] == '(')
    {
        i++;
        E();

        if (input[i] == ')')
            i++;
    }
    else
    {
        printf("Invalid Expression\n");
        return;
    }
}

int main()
{
    printf("Enter expression: ");
    scanf("%99s", input);

    E();

    if (input[i] == '\0')
        printf("Valid Expression\n");
    else
        printf("Invalid Expression\n");

    return 0;
}
