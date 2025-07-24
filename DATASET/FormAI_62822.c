//FormAI DATASET v1.0 Category: Math exercise ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    // surreal numbers
    double a = 2.5 + 1.5i;
    double b = 4.0 + 2.0i;

    printf("Welcome to the surreal math exercise program!\n\n");

    // generate random numbers
    srand(time(NULL));
    int num1 = rand() % 10 + 1;
    int num2 = rand() % 10 + 1;
    int num3 = rand() % 10 + 1;

    // perform surreal math operations
    double c = pow(a, num1) + pow(b, num2);
    double d = sqrt(fabs(c));
    double e = sin(num3 * M_PI);

    printf("Your surreal math exercise is:\n\n");
    printf("Evaluate the value of the following expression:\n\n");
    printf("sqrt(|(%g)^%d + (%g)^%d|) * sin(%d * PI)\n", creal(a), num1, creal(b), num2, num3);
    printf("==============================================\n");

    // prompt user for answer
    double answer;
    printf("Enter your answer here: ");
    scanf("%lf", &answer);

    // check if answer is correct
    if(fabs(answer - e*d) < 0.0001)
    {
        printf("\nCongratulations! Your answer is correct!\n");
    }
    else
    {
        printf("\nSorry, your answer is incorrect.\n");
        printf("The correct answer is: %g\n", e*d);
    }

    return 0;
}