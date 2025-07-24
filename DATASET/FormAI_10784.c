//FormAI DATASET v1.0 Category: Pattern printing ; Style: scientific
#include <stdio.h> //header file for input-output operations in C programming

int main() //main function
{
    int n=7; //variable n for number of rows
    
    printf("This program generates a unique C pattern output with %d rows.\n",n); //program introduction
    
    for(int i=1; i<=n; i++) //outer loop for rows
    {
        for(int j=1; j<=n; j++) //inner loop for columns
        {
            if(i==1 || j==1 || i==n) //if statement for first and last row and first column
            {
                printf("*"); //asterisk symbol printed for the above condition
            }
            else if(i==j) //if statement for diagonal elements
            {
                printf("*"); //asterisk symbol printed for diagonal elements
            }
            else //else statement for remaining elements
            {
                printf(" "); //blank space printed for remaining elements
            }
        }
        printf("\n"); //newline character after each row is printed
    }
    return 0; //return statement to end the program
}