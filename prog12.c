
#include <stdio.h>

char E[10], T[10], F[10];
int ne = 0, nt = 0, nf = 0;

void add(char s[], int *n, char c)
{
    for (int i = 0; i < *n; i++)
        if (s[i] == c) return;

    s[(*n)++] = c;
}

void FIRST_F()
{
    add(F, &nf, '(');
    add(F, &nf, 'i');
}

void FIRST_T()
{
    FIRST_F();
    for (int i = 0; i < nf; i++)
        add(T, &nt, F[i]);
}

void FIRST_E()
{
    FIRST_T();
    for (int i = 0; i < nt; i++)
        add(E, &ne, T[i]);
}

void display(char name[], char s[], int n)
{
    printf("FIRST(%s) = { ", name);

    for (int i = 0; i < n; i++)
        printf("%s%c", i ? ", " : "", s[i] == 'i' ? 'i' : s[i]);

    printf(" }\n");
}

int main()
{
    FIRST_E();

    display("E", E, ne);
    display("T", T, nt);
    display("F", F, nf);

    return 0;
}
