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
