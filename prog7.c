#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

// Allocate memory
void allocate(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = value;
    printf("Allocated: %d\n", value);
}

// Deallocate memory
void deallocate()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("Deallocated: %d\n", stack[top--]);
}

// Display allocated memory
void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Allocated memory: ");

    for (i = 0; i <= top; i++)
        printf("%d ", stack[i]);

    printf("\n");
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
