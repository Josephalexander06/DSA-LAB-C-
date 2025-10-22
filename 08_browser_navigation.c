#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char url[100];
    struct Node* prev;
    struct Node* next;
};

struct Node* current = NULL;

void visit() {
    char url[100];
    printf("Enter URL: ");
    scanf("%s", url);
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url, url);
    newNode->prev = current;
    newNode->next = NULL;
    
    if(current != NULL) current->next = newNode;
    current = newNode;
    printf("Visited: %s\n", url);
}

void back() {
    if(current == NULL || current->prev == NULL) {
        printf("Cannot go back\n");
    } else {
        current = current->prev;
        printf("Back to: %s\n", current->url);
    }
}

void forward() {
    if(current == NULL || current->next == NULL) {
        printf("Cannot go forward\n");
    } else {
        current = current->next;
        printf("Forward to: %s\n", current->url);
    }
}

void show() {
    if(current == NULL) {
        printf("No page loaded\n");
    } else {
        printf("Current: %s\n", current->url);
    }
}

int main() {
    int choice;
    
    while(1) {
        printf("\n1.Visit 2.Back 3.Forward 4.Show 5.Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: visit(); break;
            case 2: back(); break;
            case 3: forward(); break;
            case 4: show(); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

// This code implements a simple browser navigation system using a doubly linked list in C.
// It allows visiting new URLs, going back to the previous page, going forward to the next page, and displaying the current page.

// Example usage:

// 1.Visit 2.Back 3.Forward 4.Show 5.Exit
// Choice: 1
// Enter URL: google.com
// Visited: google.com

// 1.Visit 2.Back 3.Forward 4.Show 5.Exit
// Choice: 1
// Enter URL: youtube.com
// Visited: youtube.com

// 1.Visit 2.Back 3.Forward 4.Show 5.Exit
// Choice: 4
// Current: youtube.com

// 1.Visit 2.Back 3.Forward 4.Show 5.Exit
// Choice: 2
// Back to: google.com

// 1.Visit 2.Back 3.Forward 4.Show 5.Exit
// Choice: 3
// Forward to: youtube.com

// 1.Visit 2.Back 3.Forward 4.Show 5.Exit
// Choice: 2
// Back to: google.com

// 1.Visit 2.Back 3.Forward 4.Show 5.Exit
// Choice: 2
// Cannot go back

// 1.Visit 2.Back 3.Forward 4.Show 5.Exit
// Choice: 5