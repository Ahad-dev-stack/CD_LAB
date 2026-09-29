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
