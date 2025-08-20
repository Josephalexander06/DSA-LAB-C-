#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insertFront(int value)
{
    if (front == 0 && rear == MAX - 1 || front == rear + 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
    {
        front = 0, rear = 0;
    }
    else if (front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front -= 1;
    }
    queue[front] = value;
    printf("inserted value %d at front \n", value);
}

void insertRear(int value)
{
    if (front == 0 && rear == MAX - 1 || front == rear + 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
    {
        front = 0, rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear += 1;
    }
    queue[rear] = value;
    printf("inserted value %d at rear\n", value);
}

int deleteFront()
{
    if (front == -1)
    {
        printf("Queue underflow");
        return -1;
    }
    printf("deleted value %d at front\n", queue[front]);
    if (front == rear)
    {
        front = -1, rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front += 1;
    }
}

int deleteRear()
{
    if (front == -1)
    {
        printf("Queue underflow");
        return -1;
    }

    printf("deleted value %d at rear\n", queue[rear]);
    if (front == rear)
    {
        front = -1, rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear -= 1;
    }
}

void display()
{
    if (front == -1)
    {
        printf("underflow\n");
    }
    printf("values \n");

    if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    else
    {
        for (int i = front; i < MAX; i++)
            printf("%d ", queue[i]);

        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}
int main()
{
    int choice, value;
    while (1)
    {
        printf("\n");
        printf("1.insert value at front\n");
        printf("2.insert value at rear\n");
        printf("3.delete value at front\n");
        printf("4.delete value at rear\n");
        printf("5.display\n");
        printf("6.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the Number at front: ");
            scanf("%d", &value);
            insertFront(value);
            break;
        case 2:
            printf("Enter the Number at rear: ");
            scanf("%d", &value);
            insertRear(value);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            display();
            break;
        case 6: 
            printf("Exiting...");
            return 0;
        default:
            "wrong choice";
        }
    }
}