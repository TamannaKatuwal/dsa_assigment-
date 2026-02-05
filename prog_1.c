#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define bool int
#define MAX 100
char stack[MAX];
int top = -1; 
// Function is used to push character to the stack
void push(char item) {
    if (top >= MAX - 1) {

        printf("Error cause of stack overflow\n");
    } else
    {
        top++;
        stack[top] = item;
    }
}
// Function is used here to pop character from the stack
char pop() {
    if (top == -1) 
    {
        return '\0'; 
    }
    else 
    {
        char item = stack[top];
        top--;
        return item;
    }
}
}
int main() {
    char exp[MAX];
    int i = 0;
    int isBalanced = 1; 
    
    printf("Enter the expression: ");
    fgets(exp, MAX, stdin); 
    int len = strlen(exp);
    
    for(i = 0; i < len; i++) {
        char ch = exp[i];
        
        // If opening bracket is there,it is pushed to the stack.
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        // If closing bracket is there, check with top of the stack
        else if (ch == ')' || ch == '}' || ch == ']') {
            
            if (top == -1) 
            {
                isBalanced = 0; // Stack empty but closing bracket found
                break;
            }
            
            char popped = pop();
            
            // Checking for the matching pairs
            if (ch == ')' && popped != '(') 
            {
                isBalanced = 0;
                break;
            }
            if (ch == '}' && popped != '{') 
            {
                isBalanced = 0;
                break;
            }
            if (ch == ']' && popped != '[') 
            {
                isBalanced = 0;
                break;
            }
        }
    }
    
    // If stack is not empty after processing the strings, it's unbalanced
    if (top != -1) 
    {
        isBalanced = 0;
    }
    
    if (isBalanced == 1) 
    {
     printf("Expression is Balanced\n");
    } 
    else
    {
     printf("Expression is Not Balanced\n");
    }
    
    return 0;
}

