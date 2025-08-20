#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 20

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '-' || c == '+')
        return 1;
    else
        return -1;
}

void infixToPostfix(char *exp)
{
    int len = strlen(exp);
    char stack[len];
    char result[len + 1];
    int top = -1;
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        char c = exp[i];

        if (isalnum(c))
            result[j++] = c;
        else if (c == '(')
            stack[++top] = c;
        else if (c == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                result[j++] = stack[top--];
            }
            top--;
        }
        else
        {
            while (top != -1 && prec(c) <= prec(stack[top]) && stack[top] != '(')
            {
                result[j++] = stack[top--];
            }
            stack[++top] = c;
        }
    }
    while (top != -1)
    {
        result[j++] = stack[top--];
    }
    result[j] = '\0';
    printf("%s\n", result);
}

int main()
{
    char ch[MAX];
    printf("Enter the infix expression: ");
    scanf("%s", ch);
    infixToPostfix(ch);
    return 0;
}