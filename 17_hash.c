#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void init() {
    for(int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;  // -1 means empty
    }
}

void insert(int key) {
    int index = key % SIZE;
    int i = 0;
    
    while(i < SIZE) {
        int newIndex = (index + i) % SIZE;
        if(hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            printf("Inserted %d at index %d\n", key, newIndex);
            return;
        }
        i++;
    }
    printf("Hash table full! Cannot insert %d\n", key);
}

void search(int key) {
    int index = key % SIZE;
    int i = 0;
    
    while(i < SIZE) {
        int newIndex = (index + i) % SIZE;
        if(hashTable[newIndex] == key) {
            printf("Found %d at index %d\n", key, newIndex);
            return;
        }
        if(hashTable[newIndex] == -1) {
            printf("%d not found\n", key);
            return;
        }
        i++;
    }
    printf("%d not found\n", key);
}

void display() {
    printf("\nHash Table:\n");
    for(int i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        if(hashTable[i] == -1) 
            printf("Empty\n");
        else 
            printf("%d\n", hashTable[i]);
    }
}

int main() {
    init();
    int choice, key;
    
    while(1) {
        printf("\n1.Insert 2.Search 3.Show 4.Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                search(key);
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


// 1.Insert 2.Search 3.Show 4.Exit
// Choice: 1
// Enter key: 25
// Inserted 25 at index 5

// 1.Insert 2.Search 3.Show 4.Exit
// Choice: 1
// Enter key: 35
// Inserted 35 at index 5

// 1.Insert 2.Search 3.Show 4.Exit
// Choice: 1
// Enter key: 45
// Inserted 45 at index 5

// 1.Insert 2.Search 3.Show 4.Exit
// Choice: 3

// Hash Table:
// Index 0: Empty
// Index 1: Empty
// Index 2: Empty
// Index 3: Empty
// Index 4: Empty
// Index 5: 25
// Index 6: 35
// Index 7: 45
// Index 8: Empty
// Index 9: Empty

// 1.Insert 2.Search 3.Show 4.Exit
// Choice: 2
// Enter key: 35
// Found 35 at index 6

// 1.Insert 2.Search 3.Show 4.Exit
// Choice: 2
// Enter key: 50
// 50 not found

// 1.Insert 2.Search 3.Show 4.Exit
// Choice: 4