//FormAI DATASET v1.0 Category: Syntax parsing ; Style: secure
#include <stdio.h> 
#include <string.h> 
  
int main() 
{ 
    char expression[1000]; 
    printf("Enter a C expression: "); 
    fgets(expression, 1000, stdin);  
  
    int len = strlen(expression); 
    char stack[len]; 
    int top = -1; 
    for(int i = 0; i < len; i++) 
    { 
        if(expression[i] == '(' || expression[i] == '[' || expression[i] == '{') 
        { 
            stack[++top] = expression[i]; 
        } 
        else if(expression[i] == ')' || expression[i] == ']' || expression[i] == '}') 
        { 
            if(top == -1) 
            {
                printf("Error: Expression is Not Correct\n"); 
                return 0;
            } 
            else if((stack[top] == '(' && expression[i] == ')') || (stack[top] == '[' && expression[i] == ']') || (stack[top] == '{' && expression[i] == '}')) 
            { 
                top--; 
            } 
            else 
            {
                printf("Error: Expression is Not Correct\n"); 
                return 0;
            } 
        } 
    } 
  
    if(top == -1) 
    {
        printf("Expression is Correct\n"); 
    } 
    else 
    {
        printf("Error: Expression is Not Correct\n"); 
    }
    return 0; 
}