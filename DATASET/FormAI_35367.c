//FormAI DATASET v1.0 Category: Funny ; Style: minimalist
#include <stdio.h>

int main() {
    char letter = 'z';
    int number = 10;
    float decimal = 3.14;

    printf("%c is a letter\n", letter);
    printf("%d is an integer\n", number);
    printf("%f is a decimal\n", decimal);

    printf("\n");

    // Let's do some math
    int sum = number + 5;
    float product = decimal * 2;
    int quotient = number / 3;

    printf("%d + 5 = %d\n", number, sum);
    printf("%f * 2 = %f\n", decimal, product);
    printf("%d divided by 3 = %d\n", number, quotient);

    printf("\n");

    // Let's test some conditions
    if (number > 0) {
        printf("%d is a positive number\n", number);
    } else if (number < 0) {
        printf("%d is a negative number\n", number);
    } else {
        printf("%d is neither positive nor negative\n", number);
    }

    if (decimal > 3) {
        printf("%f is greater than 3\n", decimal);
    } else {
        printf("%f is less than or equal to 3\n", decimal);
    }

    printf("\n");

    // Let's loop through some numbers
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d\n", i);
    }

    printf("\n");

    // Let's create an array of letters
    char letters[5] = {'a', 'b', 'c', 'd', 'e'};

    printf("The third letter in the array is %c\n", letters[2]);

    printf("\n");

    // Let's use a while loop
    int j = 0;
    while (j < 5) {
        printf("%c\n", letters[j]);
        j++;
    }

    return 0;
}