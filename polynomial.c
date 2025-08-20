#include <stdio.h>

#define MAX_TERMS 10

typedef struct {
    int coeff;
    int exp;
} poly;

void printPolynomial(poly p[], int n) {
    for (int i = 0; i < n; i++) {
        if (p[i].coeff == 0) continue;
        if (p[i].coeff > 0 && i != 0) printf("+");

        if (p[i].exp == 0)
            printf("%d", p[i].coeff);
        else if (p[i].exp == 1)
            printf("%dx", p[i].coeff);
        else
            printf("%dx^%d", p[i].coeff, p[i].exp);
    }
    printf("\n");
}

void sortPoly(poly p[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (p[j].exp > p[i].exp) {
                poly temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int addPolynomials(poly p1[], int n1, poly p2[], int n2, poly p3[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (p1[i].exp > p2[j].exp) {
            p3[k++] = p1[i++];
        } else if (p1[i].exp < p2[j].exp) {
            p3[k++] = p2[j++];
        } else {
            int sumCoeff = p1[i].coeff + p2[j].coeff;
            if (sumCoeff != 0) {
                p3[k].coeff = sumCoeff;
                p3[k].exp = p1[i].exp;
                k++;
            }
            i++; j++;
        }
    }
    while (i < n1) p3[k++] = p1[i++];
    while (j < n2) p3[k++] = p2[j++];

    return k;
}

int main() {
    poly poly1[MAX_TERMS], poly2[MAX_TERMS], poly3[2 * MAX_TERMS];
    int n1, n2, n3;

    printf("Enter number of terms for first polynomial (max %d): ", MAX_TERMS);
    scanf("%d", &n1);
    printf("Enter coefficients and exponents for first polynomial:\n");
    for (int i = 0; i < n1; i++) {
        printf("Term %d - coeff and exponent: ", i + 1);
        scanf("%d%d", &poly1[i].coeff, &poly1[i].exp);
    }

    printf("Enter number of terms for second polynomial (max %d): ", MAX_TERMS);
    scanf("%d", &n2);
    printf("Enter coefficients and exponents for second polynomial:\n");
    for (int i = 0; i < n2; i++) {
        printf("Term %d - coeff and exponent: ", i + 1);
        scanf("%d%d", &poly2[i].coeff, &poly2[i].exp);
    }

    sortPoly(poly1, n1);
    sortPoly(poly2, n2);

    n3 = addPolynomials(poly1, n1, poly2, n2, poly3);

    printf("\nFirst polynomial: ");
    printPolynomial(poly1, n1);

    printf("Second polynomial: ");
    printPolynomial(poly2, n2);

    printf("Sum polynomial: ");
    printPolynomial(poly3, n3);

    return 0;
}