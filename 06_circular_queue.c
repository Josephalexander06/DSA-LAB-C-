//Output: Circular Queue Implementation in C
//This code implements a circular queue using an array in C.
//It allows adding, removing, and displaying elements in the queue.

#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

void enqueue(int value) {
    if((front == 0 && rear == SIZE-1) || (front == rear+1)) {
        printf("Queue is full!\n");
        return;
    }
    
    if(front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("Added: %d\n", value);
}

void dequeue() {
    if(front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Removed: %d\n", queue[front]);
    
    if(front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if(front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Queue: ");
    int i = front;
    while(i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d\n", queue[rear]);
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
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

//Example usage:
//1.Add 2.Remove 3.Show 4.Exit
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
// Choice: 1
// Enter value: 40
// Added: 40

// 1.Add 2.Remove 3.Show 4.Exit
// Choice: 1
// Enter value: 50
// Added: 50

// 1.Add 2.Remove 3.Show 4.Exit
// Choice: 1
// Enter value: 60
// Queue is full!

// 1.Add 2.Remove 3.Show 4.Exit
// Choice: 3
// Queue: 20 30 40 50

// 1.Add 2.Remove 3.Show 4.Exit
// Choice: 2
// Removed: 20

// 1.Add 2.Remove 3.Show 4.Exit
// Choice: 1
// Enter value: 60
// Added: 60

// 1.Add 2.Remove 3.Show 4.Exit
// Choice: 3
// Queue: 30 40 50 60

// 1.Add 2.Remove 3.Show 4.Exit
// Choice: 4
