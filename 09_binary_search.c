#include <stdio.h>
#include <time.h>

// Binary Search Algorithm
int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int n, target;

    printf("Enter size of sorted array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d sorted numbers: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter number to search: ");
    scanf("%d", &target);

    // -------------------------------
    // Measure Time
    // -------------------------------
    clock_t start = clock();

    int result = binarySearch(arr, n, target);

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // -------------------------------
    // Space Calculation
    // -------------------------------
    int space_array = sizeof(arr);      // array memory
    int space_int = sizeof(int) * 3;    // left, right, mid (approx only)
    int total_space = space_array + space_int;

    // Result
    if (result != -1)
        printf("Element %d found at index %d\n", target, result);
    else
        printf("Element %d not found in the array\n", target);

    printf("Execution Time: %f seconds\n", time_taken);
    printf("Space Used: %d bytes\n", total_space);

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