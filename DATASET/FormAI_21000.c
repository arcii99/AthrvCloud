//FormAI DATASET v1.0 Category: Scientific ; Style: bold
/* ************ MY UNIQUE C SCIENTIFIC EXAMPLE PROGRAM ************ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926

int main()
{
    printf("Welcome to my scientific program!\n\n");

    double x;
    printf("Enter a value for x: ");
    scanf("%lf", &x);

    double result = sin(PI/4 * x) * log(x) + sqrt(pow(x, 3));
    printf("The result of the scientific calculation is %.2lf\n\n", result);

    printf("Do you want to do some more scientific calculations? (y/n): ");
    char answer;
    scanf(" %c", &answer);

    while (answer != 'n')
    {
        printf("\n");

        printf("Enter a new value for x: ");
        scanf("%lf", &x);

        result = sin(PI/4 * x) * log(x) + sqrt(pow(x, 3));
        printf("The result of the scientific calculation is %.2lf\n\n", result);

        printf("Do you want to do some more scientific calculations? (y/n): ");
        scanf(" %c", &answer);
    }

    printf("\nGoodbye! Thanks for using my program.\n");

    return 0;
}