#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

int isFull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void push(int value)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        int value = stack[top];
        top--;
        return value;
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    printf("Stack: ");
    display();

    printf("\nPopped: %d\n", pop());

    printf("After pop: ");
    display();

    return 0;
}
