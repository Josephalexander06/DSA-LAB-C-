#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if(rear == SIZE-1) {
        printf("Queue is full!\n");
    } else {
        if(front == -1) front = 0;
        rear++;
        queue[rear] = value;
        printf("Added: %d\n", value);
    }
}

void dequeue() {
    if(front == -1 || front > rear) {
        printf("Queue is empty!\n");
        front = rear = -1;  // Reset queue
    } else {
        printf("Removed: %d\n", queue[front]);
        front++;
    }
}

void display() {
    if(front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        for(int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    
    while(1) {
        printf("\n1.Add 2.Remove 3.Show 4.Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

// This code implements a circular queue using an array in C.
// It allows adding, removing, and displaying elements in the queue.

// Example usage:
// 1.Add 2.Remove 3.Show 4.Exit
// Choice: 1
// Enter value: 10
// Added: 10

// 1.Add 2.Remove 3.Show 4.Exit
// Choice: 1
// Enter value: 20
// Added: 20

// 1.Add 2.Remove 3.Show 4.Exit
// Choice: 1
// Enter value: 30
// Added: 30

// 1.Add 2.Remove 3.Show 4.Exit
// Choice: 3
// Queue: 10 20 30

// 1.Add 2.Remove 3.Show 4.Exit
// Choice: 2
// Removed: 10

// 1.Add 2.Remove 3.Show 4.Exit
// Choice: 3
// Queue: 20 30

// 1.Add 2.Remove 3.Show 4.Exit
// Choice: 2
// Removed: 20

// 1.Add 2.Remove 3.Show 4.Exit
// Choice: 2
// Removed: 30

// 1.Add 2.Remove 3.Show 4.Exit
// Choice: 2
// Queue is empty!

// 1.Add 2.Remove 3.Show 4.Exit
// Choice: 4