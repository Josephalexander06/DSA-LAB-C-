#include <stdio.h>

struct Term {
    int coeff;
    int exp;
};

int main() {
    struct Term p1[10], p2[10], result[20];
    int n1, n2, i, j, k;
    
    // Input first polynomial
    printf("Enter terms in first polynomial: ");
    scanf("%d", &n1);
    printf("Enter coeff and exp for each term:\n");
    for(i=0; i<n1; i++) {
        scanf("%d%d", &p1[i].coeff, &p1[i].exp);
    }
    
    // Input second polynomial
    printf("Enter terms in second polynomial: ");
    scanf("%d", &n2);
    printf("Enter coeff and exp for each term:\n");
    for(i=0; i<n2; i++) {
        scanf("%d%d", &p2[i].coeff, &p2[i].exp);
    }
    
    // Add polynomials
    i = j = k = 0;
    while(i < n1 && j < n2) {
        if(p1[i].exp == p2[j].exp) {
            result[k].coeff = p1[i].coeff + p2[j].coeff;
            result[k].exp = p1[i].exp;
            i++; j++; k++;
        }
        else if(p1[i].exp > p2[j].exp) {
            result[k++] = p1[i++];
        }
        else {
            result[k++] = p2[j++];
        }
    }
    
    // Add remaining terms
    while(i < n1) result[k++] = p1[i++];
    while(j < n2) result[k++] = p2[j++];
    
    // Display result
    printf("\nResult: ");
    for(i=0; i<k; i++) {
        if(result[i].coeff > 0 && i != 0) printf("+");
        printf("%dx^%d", result[i].coeff, result[i].exp);
    }
    printf("\n");
    
    return 0;
}

// This code implements polynomial addition in C.
// It allows input of two polynomials and outputs their sum in standard form.

// Example usage:
// Enter terms in first polynomial: 3
// Enter coeff and exp for each term:
// 3 2
// 2 1
// 1 0

// Enter terms in second polynomial: 3
// Enter coeff and exp for each term:
// 4 3
// 2 1
// 3 0

// Result: 4x^3+3x^2+4x^1+4x^0