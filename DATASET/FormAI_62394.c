//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1 = 0, num2 = 1, num3, i, n;
    printf("Enter the number of terms you want to see in the Fibonacci sequence: ");
    scanf("%d", &n);

    printf("\n\nIn fair Verona, where we lay our scene,\n");
    printf("From ancient grudge break to new mutiny,\n");
    printf("Where civil blood makes civil hands unclean.\n");
    printf("From forth the fatal loins of these two foes\n");
    printf("A pair of star-cross'd lovers take their life;\n\n");

    printf("The Fibonacci sequence is as follows:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d. %d\n", i+1, num1);
        num3 = num1 + num2;
        num1 = num2;
        num2 = num3;
    }

    printf("\nOh, who is already dead?\nWhat villain, madam?");

    return 0;
}