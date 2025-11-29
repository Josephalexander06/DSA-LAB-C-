#include <stdio.h>

struct Term {
    int coeff;
    int exp;
};

int main() {
    struct Term p1[10], p2[10], result[20];
    int n1, n2, i, j, k = 0;

    printf("Enter terms in first polynomial: ");
    scanf("%d", &n1);
    printf("Enter coeff and exp for each term:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d%d", &p1[i].coeff, &p1[i].exp);
    }

    printf("Enter terms in second polynomial: ");
    scanf("%d", &n2);
    printf("Enter coeff and exp for each term:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d%d", &p2[i].coeff, &p2[i].exp);
    }

    // Copy all p1 terms to result
    for (i = 0; i < n1; i++) {
        result[k++] = p1[i];
    }
    
    // Add p2 terms to result
    for (i = 0; i < n2; i++) {
        int found = 0;
        for (j = 0; j < k; j++) {
            if (result[j].exp == p2[i].exp) {
                result[j].coeff += p2[i].coeff;
                found = 1;
                break;
            }
        }
        if (!found) {
            result[k++] = p2[i];
        }
    }

    // Combine duplicates (if any)
    for (i = 0; i < k; i++) {
        for (j = i + 1; j < k; j++) {
            if (result[i].exp == result[j].exp) {
                result[i].coeff += result[j].coeff;

                // Remove duplicate j
                for (int m = j; m < k - 1; m++) {
                    result[m] = result[m + 1];
                }
                k--;
                j--;
            }
        }
    }

    // Display result
    printf("\nResult: ");
    for (i = 0; i < k; i++) {
        if (result[i].coeff == 0) continue;  // skip zero terms
        if (i != 0 && result[i].coeff > 0) printf("+");
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