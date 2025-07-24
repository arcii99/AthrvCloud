//FormAI DATASET v1.0 Category: Math exercise ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int num1 = (rand() % 100) + 1;
    int num2 = (rand() % 100) + 1;
    int num3 = (rand() % 100) + 1;
    int num4 = (rand() % 100) + 1;
    int num5 = (rand() % 100) + 1;
    int sum = num1 + num2 + num3 + num4 + num5;
    int avg = sum / 5;

    printf("Find the minimum and maximum out of these five numbers:\n");
    printf("%d, %d, %d, %d, %d\n", num1, num2, num3, num4, num5);

    int min = num1;
    int max = num1;

    if(num2 < min)
        min = num2;
    if(num3 < min)
        min = num3;
    if(num4 < min)
        min = num4;
    if(num5 < min)
        min = num5;

    if(num2 > max)
        max = num2;
    if(num3 > max)
        max = num3;
    if(num4 > max)
        max = num4;
    if(num5 > max)
        max = num5;

    printf("Minimum number is: %d\n", min);
    printf("Maximum number is: %d\n", max);

    printf("Calculate the average of these five numbers:\n");
    printf("%d, %d, %d, %d, %d\n", num1, num2, num3, num4, num5);
    printf("Average is: %d", avg);

    return 0;
}