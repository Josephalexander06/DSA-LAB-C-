#include <stdio.h>
#define SIZE 5

int dq[SIZE], front = -1, rear = -1;

void addFront(int value) {
    if((front == 0 && rear == SIZE-1) || (front == rear+1)) {
        printf("Deque is full!\n");
        return;
    }
    
    if(front == -1) {
        front = rear = 0;
    }
    else if(front == 0) {
        front = SIZE-1;
    }
    else {
        front--;
    }
    dq[front] = value;
    printf("Added %d at front\n", value);
}

void addRear(int value) {
    if((front == 0 && rear == SIZE-1) || (front == rear+1)) {
        printf("Deque is full!\n");
        return;
    }
    
    if(front == -1) {
        front = rear = 0;
    }
    else if(rear == SIZE-1) {
        rear = 0;
    }
    else {
        rear++;
    }
    dq[rear] = value;
    printf("Added %d at rear\n", value);
}

void removeFront() {
    if(front == -1) {
        printf("Deque is empty!\n");
        return;
    }
    
    printf("Removed %d from front\n", dq[front]);
    
    if(front == rear) {
        front = rear = -1;
    }
    else if(front == SIZE-1) {
        front = 0;
    }
    else {
        front++;
    }
}

void removeRear() {
    if(front == -1) {
        printf("Deque is empty!\n");
        return;
    }
    
    printf("Removed %d from rear\n", dq[rear]);
    
    if(front == rear) {
        front = rear = -1;
    }
    else if(rear == 0) {
        rear = SIZE-1;
    }
    else {
        rear--;
    }
}

void display() {
    if(front == -1) {
        printf("Deque is empty!\n");
        return;
    }
    
    printf("Deque: ");
    int i = front;
    while(1) {
        printf("%d ", dq[i]);
        if(i == rear) break;
        i = (i == SIZE-1) ? 0 : i+1;
    }
    printf("\n");
}

int main() {
    int choice, value;
    
    while(1) {
        printf("\n1.Add Front 2.Add Rear 3.Remove Front 4.Remove Rear 5.Show 6.Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Value: ");
                scanf("%d", &value);
                addFront(value);
                break;
            case 2:
                printf("Value: ");
                scanf("%d", &value);
                addRear(value);
                break;
            case 3: removeFront(); break;
            case 4: removeRear(); break;
            case 5: display(); break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

// Output: Double Ended Queue Implementation in C
// This code implements a double-ended queue (deque) using an array in C.
// It allows adding and removing elements from both ends, as well as displaying the current state of
// the deque.

// Example usage:
// 1.Add Front 2.Add Rear 3.Remove Front 4.Remove Rear 5.Show 6.Exit
// Choice: 1
// Value: 10
// Added 10 at front

// 1.Add Front 2.Add Rear 3.Remove Front 4.Remove Rear 5.Show 6.Exit
// Choice: 2
// Value: 20
// Added 20 at rear

// 1.Add Front 2.Add Rear 3.Remove Front 4.Remove Rear 5.Show 6.Exit
// Choice: 2
// Value: 30
// Added 30 at rear

// 1.Add Front 2.Add Rear 3.Remove Front 4.Remove Rear 5.Show 6.Exit
// Choice: 5
// Deque: 10 20 30

// 1.Add Front 2.Add Rear 3.Remove Front 4.Remove Rear 5.Show 6.Exit
// Choice: 1
// Value: 5
// Added 5 at front

// 1.Add Front 2.Add Rear 3.Remove Front 4.Remove Rear 5.Show 6.Exit
// Choice: 5
// Deque: 5 10 20 30

// 1.Add Front 2.Add Rear 3.Remove Front 4.Remove Rear 5.Show 6.Exit
// Choice: 3
// Removed 5 from front

// 1.Add Front 2.Add Rear 3.Remove Front 4.Remove Rear 5.Show 6.Exit
// Choice: 4
// Removed 30 from rear

// 1.Add Front 2.Add Rear 3.Remove Front 4.Remove Rear 5.Show 6.Exit
// Choice: 5
// Deque: 10 20

// 1.Add Front 2.Add Rear 3.Remove Front 4.Remove Rear 5.Show 6.Exit
// Choice: 6