//FormAI DATASET v1.0 Category: Math exercise ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    //Setup the random seed
    srand(time(NULL));

    //Randomly generate three numbers between 1 and 50
    int a = rand() % 50 + 1;
    int b = rand() % 50 + 1;
    int c = rand() % 50 + 1;

    //Calculate the value of the expression using the three numbers
    double result = pow((double)a, 2) + pow((double)b, 3) + pow((double)c, 4);
    result = sqrt(result);

    //Print out the three randomly generated numbers and the resulting value of the expression
    printf("The numbers are: %d, %d, %d\n", a, b, c);
    printf("The result of the expression is: %f\n", result);

    //Wait for the user to input a value to continue
    printf("Press any key to continue...");
    getchar();

    return 0;
}