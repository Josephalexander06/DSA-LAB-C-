#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* stack[100];
int top = -1;

void push(struct Node* node) {
    stack[++top] = node;
}

struct Node* pop() {
    return stack[top--];
}

struct Node* buildTree(char* postfix) {
    for(int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        struct Node* newNode = createNode(c);
        
        if(isalnum(c)) {
            push(newNode);
        } else {
            newNode->right = pop();
            newNode->left = pop();
            push(newNode);
        }
    }
    return pop();
}

void postorder(struct Node* root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

void preorder(struct Node* root) {
    if(root != NULL) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    char postfix[100];
    
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    
    struct Node* root = buildTree(postfix);
    
    printf("Postorder: ");
    postorder(root);
    printf("\n");
    
    printf("Prefix: ");
    preorder(root);
    printf("\n");
    
    return 0;
}

// Output: Expression Tree from Postfix in C
// This code builds an expression tree from a postfix expression and prints its postorder and prefix traversal forms.

// Example usage:

// Enter postfix expression: ab+c*
// Postorder: ab+c*
// Prefix: *+abc