#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void addTerm(struct Node** poly, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    
    if(*poly == NULL) {
        *poly = newNode;
        return;
    }
    
    struct Node* temp = *poly;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    
    while(poly1 != NULL && poly2 != NULL) {
        if(poly1->exp == poly2->exp) {
            addTerm(&result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if(poly1->exp > poly2->exp) {
            addTerm(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        }
        else {
            addTerm(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
    }
    
    while(poly1 != NULL) {
        addTerm(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    
    while(poly2 != NULL) {
        addTerm(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
    
    return result;
}

void display(struct Node* poly) {
    if(poly == NULL) {
        printf("0\n");
        return;
    }
    
    while(poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if(poly != NULL) printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;
    
    int n, coeff, exp;
    
    // Input first polynomial
    printf("Enter terms in first polynomial: ");
    scanf("%d", &n);
    printf("Enter coeff and exp for each term:\n");
    for(int i=0; i<n; i++) {
        scanf("%d%d", &coeff, &exp);
        addTerm(&poly1, coeff, exp);
    }
    
    // Input second polynomial
    printf("Enter terms in second polynomial: ");
    scanf("%d", &n);
    printf("Enter coeff and exp for each term:\n");
    for(int i=0; i<n; i++) {
        scanf("%d%d", &coeff, &exp);
        addTerm(&poly2, coeff, exp);
    }
    
    // Add polynomials
    result = addPolynomials(poly1, poly2);
    
    // Display results
    printf("\nFirst Polynomial: ");
    display(poly1);
    
    printf("Second Polynomial: ");
    display(poly2);
    
    printf("Sum: ");
    display(result);
    
    return 0;
}

// This code implements polynomial addition using linked lists in C.
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

// First Polynomial: 3x^2 + 2x^1 + 1x^0
// Second Polynomial: 4x^3 + 2x^1 + 3x^0
// Sum: 4x^3 + 3x^2 + 4x^1 + 4x^0