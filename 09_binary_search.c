#include <stdio.h>

// Binary Search Algorithm
int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Prevents overflow
        
        if (arr[mid] == target) {
            return mid;  // Element found
        }
        else if (arr[mid] < target) {
            left = mid + 1;  // Search in right half
        }
        else {
            right = mid - 1;  // Search in left half
        }
    }
    
    return -1;  // Element not found
}

int main() {
    int n, target;
    
    // Input sorted array
    printf("Enter size of sorted array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d sorted numbers: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input target to search
    printf("Enter number to search: ");
    scanf("%d", &target);
    
    // Perform binary search
    int result = binarySearch(arr, n, target);
    
    // Display result
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }
    
    return 0;
}

// Output: Binary Search Implementation in C
// This code implements binary search on a sorted array in C.
// It allows input of a sorted array and a target number, and outputs the index of the

//  Example usage:

// Enter array size: 5
// Enter 5 sorted numbers: 10 20 30 40 50
// Enter number to search: 30
// Found at index 2

// Enter array size: 5
// Enter 5 sorted numbers: 10 20 30 40 50
// Enter number to search: 25
// Not found