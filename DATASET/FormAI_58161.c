//FormAI DATASET v1.0 Category: Error handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>

void divide(int a, int b) {
    if (b == 0) {
        printf("Error: %d cannot be divided by zero\n", a);
        exit(1);
    }
    printf("%d / %d = %d\n", a, b, a / b);
}

float calculate_average(int *numbers, int count) {
    if (count < 1) {
        printf("Error: Invalid number of elements\n");
        return 0.0;
    }
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    return sum / count;
}

int main() {
    int num1 = 10, num2 = 0;
    divide(num1, num2); // Division by zero error

    int arr[] = {1, 2, 3};
    float average = calculate_average(arr, -1); // Invalid input error
    printf("Average: %f\n", average);

    return 0;
}