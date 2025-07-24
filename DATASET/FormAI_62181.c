//FormAI DATASET v1.0 Category: Error handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>

//Function prototypes
int divide(int a, int b);

int main()
{
    int x, y;

    printf("Enter the first number: ");
    scanf("%d", &x);

    printf("Enter the second number: ");
    scanf("%d", &y);

    //Error handling for dividing by zero
    if(y == 0)
    {
        printf("Error: Cannot divide by zero.");
        exit(0); //Exit program
    }

    printf("%d divided by %d = %d", x, y, divide(x, y));

    return 0;
}

//Function definition
int divide(int a, int b)
{
    return a / b;
}