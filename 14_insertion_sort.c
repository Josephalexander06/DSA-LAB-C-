#include <stdio.h>

void insertionSort(int arr[], int n) {
    int steps = 0;
    
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        
        while(j >= 0 && arr[j] > key) {
            steps++;
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        steps++;
    }
    printf("Insertion Sort Steps: %d\n", steps);
}

int main() {
    int n;
    
    printf("Enter array size: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d numbers: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Original: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    insertionSort(arr, n);
    
    printf("Sorted: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}


// Enter array size: 5
// Enter 5 numbers: 64 34 25 12 22
// Original: 64 34 25 12 22 
// Insertion Sort Steps: 9
// Sorted: 12 22 25 34 64