#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char x;

    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(') {
            push(infix[i]);
        }
        else if (infix[i] == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        }
        else {
            while (top != -1 && priority(stack[top]) >= priority(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* nodeStack[100];
int t2 = -1;

void pushNode(struct Node* x) {
    nodeStack[++t2] = x;
}

struct Node* popNode() {
    return nodeStack[t2--];
}

struct Node* createNode(char val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Build tree from postfix expression
struct Node* buildExpressionTree(char postfix[]) {
    int i = 0;
    struct Node *newNode, *leftNode, *rightNode;

    while (postfix[i] != '\0') {
        if (isalnum(postfix[i])) {
            newNode = createNode(postfix[i]);
            pushNode(newNode);
        }
        else if (isOperator(postfix[i])) {
            rightNode = popNode();
            leftNode = popNode();

            newNode = createNode(postfix[i]);
            newNode->left = leftNode;
            newNode->right = rightNode;

            pushNode(newNode);
        }
        i++;
    }

    return popNode();  // Final root
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

int main() {
    char infix[100], postfix[100];

    printf("Enter INFIX expression: ");
    scanf("%s", infix);

    // Step 1: convert infix → postfix
    infixToPostfix(infix, postfix);

    printf("Postfix: %s\n", postfix);

    // Step 2: build tree from postfix
    struct Node* root = buildExpressionTree(postfix);

    // Step 3: print postorder traversal
    printf("Postorder: ");
    postorder(root);

    printf("\n");
    return 0;
}


// Output: Expression Tree from Postfix in C
// This code builds an expression tree from a postfix expression and prints its postorder and prefix traversal forms.

// Example usage:

// Enter postfix expression: ab+c*
// Postorder: ab+c*
// Prefix: *+abc