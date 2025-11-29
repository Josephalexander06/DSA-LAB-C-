#include <stdio.h>

struct Sparse {
    int row, col, value;
};

int main() {
    struct Sparse a[20], b[20], result[40];
    int term1, term2, i=0, j=0, k=0;
    
    // Input first matrix
    printf("Enter non-zero terms in first matrix: ");
    scanf("%d", &term1);
    printf("Enter row, col, value for each term:\n");
    for(i=0; i<term1; i++) {
        scanf("%d%d%d", &a[i].row, &a[i].col, &a[i].value);
    }
    
    // Input second matrix
    printf("Enter non-zero terms in second matrix: ");
    scanf("%d", &term2);
    printf("Enter row, col, value for each term:\n");
    for(i=0; i<term2; i++) {
        scanf("%d%d%d", &b[i].row, &b[i].col, &b[i].value);
    }
    
    // Add matrices
    i = j = k = 0;
    while(i < term1 && j < term2) {
        if(a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            result[k++] = a[i++];
        }
        else if(a[i].row > b[j].row || (a[i].row == b[j].row && a[i].col > b[j].col)) {
            result[k++] = b[j++];
        }
        else {
            int sum = a[i].value + b[j].value;
            if(sum != 0) {
                result[k].row = a[i].row;
                result[k].col = a[i].col;
                result[k].value = sum;
                k++;
            }
            i++; j++;
        }
    }
    
    while(i < term1) result[k++] = a[i++];
    while(j < term2) result[k++] = b[j++];
    
    // Display sum
    printf("\nSum Matrix:\n");
    printf("Row\tCol\tValue\n");
    for(i=0; i<k; i++) {
        printf("%d\t%d\t%d\n", result[i].row, result[i].col, result[i].value);
    }
    
    // Transpose (swap row and col)
    printf("\nTranspose:\n");
    printf("Row\tCol\tValue\n");
    for(i=0; i<k; i++) {
        printf("%d\t%d\t%d\n", result[i].col, result[i].row, result[i].value);
    }
    
    return 0;
}

// This code implements sparse matrix addition and transposition in C.
// It allows input of two sparse matrices and outputs their sum and transpose in standard form.

// Example usage:
// Enter non-zero terms in first matrix: 2
// Enter row, col, value for each term:
// 0 1 5
// 2 0 6
// Enter non-zero terms in second matrix: 2
// Enter row, col, value for each term:
// 1 2 9
// 2 1 4

// Sum Matrix:
// Row     Col     Value
// 0       1       5
// 1       2       9
// 2       0       6
// 2       1       4

// Transpose:
// Row     Col     Value
// 1       0       5
// 2       1       9
// 0       2       6
// 1       2       4
