



You said:
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100

// Stack for holding the operators 
char stack[MAX];
int top = -1;

// Stack for holding the operands
int intStack[MAX];
int intTop = -1;

// Push function for given character stack 
void push(char item)
 {
    if (top >= MAX - 1) 
    {
        printf("Stack Overflow\n");
    } else
     {
        top++;
        stack[top] = item;
    }
}

// Pop function for given character stack
char pop()
 {
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



// Pop function for the given integer stack
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

// Push function for the given integer stack
void pushInt(int item) 
{
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
// Function to return the precedence of given operators
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

// Function to perform the given operation
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
    
    // To convert Infix into Poatfix
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
    
    //To evaluate the postfix 
 
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

        // If operands given were valid
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

AI Code Humanizer said:
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100  

// operator stack (chars only)
char opStack[MAX];
int opTop = -1;

// operand stack (ints only)
int numStack[MAX];
int numTop = -1;

// pushing operator

void pushOp(char ch)
{
    if (opTop >= MAX - 1) {
        printf("Operator stack overflow!\n");
        return;
    }
    opStack[++opTop] = ch;
}

// popping operator
char popOp()
{
    if (opTop < 0) {
        return -1;   
    }
    return opStack[opTop--];
}

// push integer value
void pushNum(int val)
{
    if (numTop >= MAX - 1) {
        printf("Number stack overflow!\n");
        return;
    }
    numStack[++numTop] = val;
}

// pop integer value
int popNum()
{
    if (numTop < 0) {
        return -1;
    }
    return numStack[numTop--];
}

// precedence rules for operators
int precedence(char op)
{
    if (op == '(') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '^') return 3;
    return 0; // default case
}

// performs calculation on two operands
int calculate(int left, int right, char op)
{
    switch (op) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;   // assuming no divide-by-zero input
        case '%': return left % right;
        case '^': return (int)pow(left, right);
        default:
            return 0;
    }
}

int main()
{
    char infix[MAX];
    char postfix[MAX];
    char *ptr;
    int idx = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);   // reads without spaces

    ptr = infix;

    // converting infix to postfix
    while (*ptr != '\0') {

        if (isalnum(*ptr)) {
            postfix[idx++] = *ptr;
        }
        else if (*ptr == '(') {
            pushOp(*ptr);
        }
        else if (*ptr == ')') {
            char temp;
            while ((temp = popOp()) != '(') {
                postfix[idx++] = temp;
            }
        }
        else {
            while (opTop != -1 &&
                   precedence(opStack[opTop]) >= precedence(*ptr)) {
                postfix[idx++] = popOp();
            }
            pushOp(*ptr);
        }

        ptr++;
    }

    // pop any remaining operators
    while (opTop != -1) {
        postfix[idx++] = popOp();
    }

    postfix[idx] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    // evaluating postfix expression
    ptr = postfix;

    while (*ptr != '\0') {

        if (isdigit(*ptr)) {
            // converting char digit to int
            pushNum(*ptr - '0');
        }
        else {
            int b = popNum();
            int a = popNum();

            // basic safety check
            if (a != -1 && b != -1) {
                int result = calculate(a, b, *ptr);
                pushNum(result);
            }
        }
        ptr++;
    }

    if (numTop != -1) {
        printf("Result: %d\n", popNum());
    }

    return 0;
}

