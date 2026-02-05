#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100

// Stack to hold operators 
char stack[MAX];
int top = -1;

// Stack to hold operands
int intStack[MAX];
int intTop = -1;

// Push function 
void push(char item) {
    if (top >= MAX - 1) 
    {
        printf("Stack Overflow\n");
    } else
     {
        top++;
        stack[top] = item;
    }
}

// Pop function
char pop() {
    if (top == -1)
     {
        return -1;
    } else 
    {
        char val = stack[top];
        top--;
        return val;
    }
}

// Push function for integer stack
void pushInt(int item) {
    if (intTop >= MAX - 1) 
    {
        printf("Stack Overflow\n");
    } 
    else
     {
        intTop++;
        intStack[intTop] = item;
    }
}

// Pop function for integer stack
int popInt() {
    if (intTop == -1) 
    {
        return -1;
    } else 
    {
        int val = intStack[intTop];
        intTop--;
        return val;
    }
}

// Function to return precedence of operators
int priority(char x)
{ 
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/' || x == '%')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

// Function to perform operation
int calc(int a, int b, char op) 
{
    switch(op) 
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '%': return a % b;
        case '^': return (int)pow(a, b);
        default: return 0;
    }
}

int main() {
    char exp[MAX], postfix[MAX];
    char *e, x;
    int i = 0;
    
    printf("Enter infix expression: ");
    scanf("%s", exp);
    
    e = exp;
    
    // To convert Infix to Postfix
    while (*e != '\0') 
    {
        if (isalnum(*e))
        {
            postfix[i++] = *e;
        } else if (*e == '(') 
        {
            push(*e);
        } else if (*e == ')') 
        {
            while ((x = pop()) != '(')
                postfix[i++] = x;
        } else 
        {
            while (top != -1 && priority(stack[top]) >= priority(*e)) 
            {
                postfix[i++] = pop();
            }
            push(*e);
        }
        e++;
    }
    
    while (top != -1)
     {
        postfix[i++] = pop();
     }
    postfix[i] = '\0';
    
    printf("Postfix Expression: %s\n", postfix);
    
    // Evaluate Postfix
 
e = postfix;
while (*e != '\0') 
{
    if (isdigit(*e))
    {
        pushInt(*e - '0');
    } 
    else
    {
        int val2 = popInt();
        int val1 = popInt();

        // If operands were valid
        if (val1 != -1 && val2 != -1) 
        {
            int res = calc(val1, val2, *e);
            pushInt(res);
        }
    }
    e++;
}

    if (intTop != -1)
        printf("Result: %d\n", popInt());
    
    return 0;
}
