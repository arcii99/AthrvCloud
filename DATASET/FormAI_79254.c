//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

// function to check if the given character is a valid operator
int is_operator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
        return 1;
    else
        return 0;
}

// function to check if the given character is a valid alphabet or digit
int is_valid(char c)
{
    if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
        return 1;
    else
        return 0;
}

// function to validate the syntax of the given expression
int validate_expression(char* expression)
{
    int i,count=0;
    char prev=' ';
    for(i=0;i<strlen(expression);i++)
    {
        char curr=expression[i];

        if(curr=='(')
            count++;
        else if(curr==')')
            count--;
        else if(is_operator(curr))
        {
            if(!is_valid(prev) && prev!=')')
            {
                printf("Error: Invalid Syntax\n");
                return 0;
            }
            if(!is_valid(expression[i+1]) && expression[i+1]!='(')
            {
                printf("Error: Invalid Syntax\n");
                return 0;
            }
        }
        else
        {
            if(!is_valid(curr) && curr!='(' && curr!=')')
            {
                printf("Error: Invalid Syntax\n");
                return 0;
            }
            if(is_valid(prev) || prev==')')
            {
                printf("Error: Invalid Syntax\n");
                return 0;
            }
        }
        prev=curr;
    }
    if(count!=0)
    {
        printf("Error: Invalid Syntax\n");
        return 0;
    }
    printf("Expression is Valid\n");
    return 1;
}

int main()
{
    char expression[MAX];
    printf("Enter the expression to validate: ");
    fgets(expression,MAX,stdin);
    expression[strcspn(expression,"\n")]=0; // remove the trailing newline character
    validate_expression(expression);
    return 0;
}