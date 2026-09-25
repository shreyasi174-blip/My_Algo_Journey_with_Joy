#include <stdio.h>

#define SIZE 5

int items[SIZE];
int front = -1;
int rear = -1;

int isFull()
{
    if ((rear + 1) % SIZE == front)
        return 1;

    return 0;
}

int isEmpty()
{
    if (front == -1)
        return 1;

    return 0;
}

void enQueue(int element)
{
    if (isFull())
    {
        printf("Queue is Full\n");
    }
    else
    {
        if (front == -1)
            front = 0;

        rear = (rear + 1) % SIZE;
        items[rear] = element;

        printf("Inserted: %d\n", element);
    }
}

int deQueue()
{
    int element;

    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return -1;
    }
    else
    {
        element = items[front];

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }

        return element;
    }
}

void display()
{
    int i;

    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        for (i = front; i != rear; i = (i + 1) % SIZE)
        {
            printf("%d ", items[i]);
        }

        printf("%d ", items[rear]);
        printf("\n");
    }
}

int main()
{
    enQueue(10);
    enQueue(20);
    enQueue(30);
    enQueue(40);
    enQueue(50);

    display();

    printf("Deleted: %d\n", deQueue());
    printf("Deleted: %d\n", deQueue());

    display();

    enQueue(60);
    enQueue(70);

    display();

    return 0;
}
