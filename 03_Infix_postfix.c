#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if(top == -1) return -1;
    return stack[top--];
}

int priority(char x) {
    if(x == '(') return 0;
    if(x == '+' || x == '-') return 1;
    if(x == '*' || x == '/') return 2;
    return 0;
}

int main() {
    char infix[100], postfix[100];
    int i = 0, j = 0;
    char x;
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    while(infix[i] != '\0') {
        if(isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        else if(infix[i] == '(') {
            push(infix[i]);
        }
        else if(infix[i] == ')') {
            while((x = pop()) != '(') {
                postfix[j++] = x;
            }
        }
        else {
            while(top != -1 && priority(stack[top]) >= priority(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }
    
    while(top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    
    printf("Postfix: %s\n", postfix);
    return 0;
}

// Output: Infix to Postfix Conversion in C
// This code converts an infix expression to postfix notation using a stack.
// It handles operators, parentheses, and operands, and outputs the resulting postfix expression.

// Example usage: 

// Enter infix expression: a+b*c
// Postfix: abc*+

// Enter infix expression: (a+b)*c
// Postfix: ab+c*

// Enter infix expression: a+b*c-d/e
// Postfix: abc*+de/-

// Enter infix expression: (a+b)*(c-d)
// Postfix: ab+cd-*