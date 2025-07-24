//FormAI DATASET v1.0 Category: Math exercise ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int num1, num2, num3, num4, sum, diff, prod; 
    float avg, root1, root2;

    printf("Enter four integers: ");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

    sum = num1 + num2 + num3 + num4;
    printf("The sum of the four integers is: %d\n", sum);

    diff = num1 - num2 - num3 - num4;
    printf("The difference of the four integers is: %d\n", diff);

    prod = num1 * num2 * num3 * num4;
    printf("The product of the four integers is: %d\n", prod);

    avg = (float)(num1 + num2 + num3 + num4) / 4;
    printf("The average of the four integers is: %.2f\n", avg);

    if (num1 < 0 || num2 < 0 || num3 < 0 || num4 < 0) {
        printf("One or more integers are negative. Cannot calculate square roots.\n");
    }
    else {
        root1 = sqrt(num1);
        root2 = sqrt(num2);
        printf("The square roots of the first two integers are: %.2f and %.2f\n", root1, root2);

        root1 = sqrt(num3);
        root2 = sqrt(num4);
        printf("The square roots of the last two integers are: %.2f and %.2f\n", root1, root2);
    }

    return 0;
}