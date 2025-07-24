//FormAI DATASET v1.0 Category: Scientific ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, num3, sum;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    sum = calculate_sum(num1, num2, num3);

    printf("The sum of the three numbers is: %d\n", sum);

    return 0;
}

int calculate_sum(int num1, int num2, int num3)
{
    int sum;

    sum = num1 + num2 + num3;

    return sum;
}