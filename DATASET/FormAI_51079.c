//FormAI DATASET v1.0 Category: Educational ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num; //declare an integer variable
    printf("Enter a number: "); //ask user for input
    scanf("%d", &num); //store input in variable
    if(num > 0) //check if number is positive
    {
        printf("%d is a positive number.\n", num); //output message
    }
    else if(num < 0) //check if number is negative
    {
        printf("%d is a negative number.\n", num); //output message
    }
    else //if number is not positive or negative, it must be zero
    {
        printf("You entered zero.\n"); //output message
    }
    
    int i, j, rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    for(i=1; i<=rows; i++) //outer loop for rows
    {
        for(j=1; j<=i; j++) //inner loop for printing stars
        {
            printf("* ");
        }
        printf("\n"); //move to next line after each row is printed
    }
    
    char name[20]; //declare a character array
    printf("Enter your name: ");
    scanf("%s", name); //store input in array
    printf("Hello, %s! Welcome to the world of C programming.\n", name); //output message
    
    int x = 10; //declare and initialize integer variable
    int *ptr = &x; //declare and initialize pointer variable
    printf("The value of x is %d\n", x); //output original value
    *ptr = 20; //change value using pointer
    printf("The value of x is now %d\n", x); //output new value
    
    return 0;
}