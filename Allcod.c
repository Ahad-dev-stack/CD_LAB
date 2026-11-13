#include <stdio.h>
#include <string.h>

struct Symbol {
    char name[20];
    char type[20];
    int address;
};

int main() {
    struct Symbol s[10];
    int n = 0, choice, i, found;
    char search[20];

    while (1) {
        printf("\n1. Insert\n2. Display\n3. Search\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                if (n == 10) {
                    printf("Symbol Table Full!\n");
                    break;
                }

                printf("Enter name, type and address: ");
                scanf("%19s %19s %d", s[n].name, s[n].type, &s[n].address);

                n++;
                printf("Inserted Successfully!\n");
                break;

            case 2:
                printf("\nName\tType\tAddress\n");

                for (i = 0; i < n; i++) {
                    printf("%s\t%s\t%d\n",
                           s[i].name, s[i].type, s[i].address);
                }
                break;

            case 3:
                printf("Enter name to search: ");
                scanf("%19s", search);

                found = 0;

                for (i = 0; i < n; i++) {
                    if (strcmp(search, s[i].name) == 0) {
                        printf("Symbol Found!\n");
                        printf("Name: %s\nType: %s\nAddress: %d\n",
                               s[i].name, s[i].type, s[i].address);
                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                    printf("Symbol Not Found!\n");

                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }
}



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



#include <stdio.h>
#include <string.h>

int main()
{
    char type1[20], type2[20], result[20];

    printf("Enter type of first operand: ");
    scanf("%s", type1);

    printf("Enter type of second operand: ");
    scanf("%s", type2);

    printf("Enter result type: ");
    scanf("%s", result);

    printf("\n--- Type Checking ---\n");

    /* Check operand compatibility */
    if (strcmp(type1, type2) == 0)
    {
        printf("Operands have compatible types.\n");
    }
    else if ((strcmp(type1, "int") == 0 && 
              strcmp(type2, "float") == 0) ||
             (strcmp(type1, "float") == 0 && 
              strcmp(type2, "int") == 0))
    {
        printf("Operands are compatible through type conversion.\n");
    }
    else
    {
        printf("Type Error: Incompatible operand types.\n");
        return 0;
    }

    /* Check result type */
    if (strcmp(type1, "float") == 0 ||
        strcmp(type2, "float") == 0)
    {
        if (strcmp(result, "float") == 0)
            printf("Result type is correct.\n");
        else
            printf("Type Error: Result should be float.\n");
    }
    else
    {
        if (strcmp(result, "int") == 0)
            printf("Result type is correct.\n");
        else
            printf("Type Error: Result should be int.\n");
    }

    return 0;
}



#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void allocate(int x)
{
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
    {
        stack[++top] = x;
        printf("Allocated: %d\n", x);
    }
}

void deallocate()
{
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("Deallocated: %d\n", stack[top--]);
}

void display()
{
    if (top == -1)
        printf("Stack is empty\n");
    else
    {
        printf("Allocated memory: ");
        for (int i = 0; i <= top; i++)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main()
{
    allocate(10);
    allocate(20);
    allocate(30);

    display();
    deallocate();
    display();

    return 0;
}



#include <stdio.h>
#include <string.h>

char input[100];
int i = 0;

void E();
void T();
void F();

void E() {
    T();
    while (input[i] == '+') {
        i++;
        T();
    }
}

void T() {
    F();
    while (input[i] == '*') {
        i++;
        F();
    }
}

void F() {
    if (strncmp(&input[i], "id", 2) == 0)
        i += 2;
    else if (input[i] == '(') {
        i++;
        E();
        if (input[i] == ')')
            i++;
    }
    else {
        printf("Invalid Expression\n");
        return;
    }
}

int main() {
    printf("Enter expression: ");
    scanf("%99s", input);

    E();

    if (input[i] == '\0')
        printf("Valid Expression\n");
    else
        printf("Invalid Expression\n");

    return 0;
}


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


#include <stdio.h>

char E[10], T[10], F[10];
int ne = 0, nt = 0, nf = 0;

void add(char s[], int *n, char c)
{
    for (int i = 0; i < *n; i++)
        if (s[i] == c)
            return;

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
        printf("%s%c", i ? ", " : "", s[i]);

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

