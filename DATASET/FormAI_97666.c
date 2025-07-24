//FormAI DATASET v1.0 Category: Arithmetic ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int a, b, c;
    printf("Enter three integer values separated by spaces: ");
    scanf("%d %d %d", &a, &b, &c);

    int sum = a + b + c;
    printf("The sum of the three integers is: %d\n", sum);

    int product = a * b * c;
    printf("The product of the three integers is: %d\n", product);

    float average = sum / 3.0;
    printf("The average of the three integers is: %f\n", average);

    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    printf("The maximum value is: %d\n", max);

    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    printf("The minimum value is: %d\n", min);

    return 0;
}