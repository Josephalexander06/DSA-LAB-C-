#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int steps = 0;
    
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            steps++;
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Bubble Sort Steps: %d\n", steps);
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
    
    bubbleSort(arr, n);
    
    printf("Sorted: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}

// Enter array size: 5
// Enter 5 numbers: 64 34 25 12 22
// Original: 64 34 25 12 22 
// Bubble Sort Steps: 10
// Sorted: 12 22 25 34 64