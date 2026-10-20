
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
