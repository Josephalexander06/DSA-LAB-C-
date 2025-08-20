#include <stdio.h>
#define MAXSIZE 20

int queue[MAXSIZE];
int front = -1;
int rear = -1;

void Enqueue(int value)
{
    if ((front == 0 && rear == MAXSIZE - 1) || (front == rear + 1))
    {
        printf("Queue Overflow");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }
    rear = (rear + 1) % MAXSIZE;
    queue[rear] = value;
    printf("Element %d inserted\n", value);
}
int Dequeue()
{
    if (front == -1)
    {
        printf("underflow");
        return -1;
    }
    printf("Element %d deleted \n", queue[front]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAXSIZE;
    }
}
void Display()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("values \n");
    for (int i = front; i != rear; i = (i + 1) % MAXSIZE)
    {
        printf("%d ", queue[i]);
    }
    printf("%d\n", queue[rear]);
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\nEnter any value\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the Number of Enqueue: ");
            scanf("%d", &value);
            Enqueue(value);
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Display();
            break;
        case 4:
            printf("Exit program");
            return 0;

        default:
            "Wrong choice";
        }
    }
    return 0;
}