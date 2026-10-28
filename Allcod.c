#include <stdio.h>
#include <string.h>

struct Symbol 
{
    char name[20];
    char type[20];
};

int main() {
    struct Symbol table[20];
    int n, i;
    char search[20];

    printf("Enter number of symbols: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) 
    {
        printf("\nEnter symbol name: ");
        scanf("%s", table[i].name);

        printf("Enter type: ");
        scanf("%s", table[i].type);
    }

    printf("\n--- Symbol Table ---\n");
    printf("Name\tType\n");

    for(i = 0; i < n; i++) 
    {
        printf("%s\t%s\n", table[i].name, table[i].type);
    }

    printf("\nEnter symbol to search: ");
    scanf("%s", search);

    for(i = 0; i < n; i++) 
    {
        if(strcmp(table[i].name, search) == 0) 
        {
            printf("Symbol found!\n");
            printf("Name: %s\n", table[i].name);
            printf("Type: %s\n", table[i].type);
            return 0;
        }
    }

    printf("Symbol not found!\n");

    return 0;
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

