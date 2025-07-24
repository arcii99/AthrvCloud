//FormAI DATASET v1.0 Category: Educational ; Style: automated
#include <stdio.h>

int main() {

    int num1, num2, i, j, k;

    // read the first number
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // read the second number
    printf("\nEnter the second number: ");
    scanf("%d", &num2);

    // calculate the GCD
    for(i = 1; i <= num1 && i <= num2; i++) {
        if(num1 % i == 0 && num2 % i == 0) {
            k = i;
        }
    }

    // print the GCD
    printf("\nGCD of %d and %d is: %d", num1, num2, k);

    // calculate the LCM
    if(k == 0) {
        printf("\nLCM of %d and %d is: 0", num1, num2);
    } else {
        j = (num1 * num2) / k;

        // print the LCM
        printf("\nLCM of %d and %d is: %d", num1, num2, j);
    }

    return 0;
}