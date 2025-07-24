//FormAI DATASET v1.0 Category: Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {

    int num1, num2, sum, diff, prod;

    printf("Hello there! I am a calculator bot!");

    printf("\nPlease enter two numbers to perform calculations:\n");
    scanf("%d %d", &num1, &num2);

    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;

    printf("\nHurray!! Here is your result:\n");
    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    printf("The difference of %d and %d is %d\n", num1, num2, diff);
    printf("The product of %d and %d is %d\n", num1, num2, prod);

    printf("\nBut wait, there's more!\n");
    printf("Do you want to perform some more calculations? (y/n): ");
    
    char choice = getchar();
    if (choice == 'y' || choice == 'Y') {

        printf("\nAwesome! Let's do this!\n");

        float num3, num4, div;

        printf("Enter two decimal numbers for division: ");
        scanf("%f %f", &num3, &num4);

        if (num4 == 0) {
            printf("Oops! Division by zero is not possible.");
        } else {
            div = num3 / num4;
            printf("\nYour quotient is: %.2f\n", div);
        }
    } else {
        printf("\nOkay! Bye-bye!");
    }

    return 0;
}