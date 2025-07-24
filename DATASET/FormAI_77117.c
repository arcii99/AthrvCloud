//FormAI DATASET v1.0 Category: Data validation ; Style: shocked
#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("Welcome to the data validation program!\n");
    printf("Please enter your age: ");
    int age;
    bool is_valid = false;
    while (!is_valid) {
        if (scanf("%d", &age) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); //clear buffer
            printf("Please enter your age: ");
        } else if (age < 0 || age > 120) {
            printf("Invalid age! Please enter a number between 0 and 120 inclusive.\n");
            printf("Please enter your age: ");
        } else {
            is_valid = true;
        }
    }
    printf("Thank you for entering a valid age of %d.\n", age);
    printf("Please enter your height in inches: ");
    int height_in;
    is_valid = false;
    while (!is_valid) {
        if (scanf("%d", &height_in) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); //clear buffer
            printf("Please enter your height in inches: ");
        } else if (height_in < 12 || height_in > 120) {
            printf("Invalid height! Please enter a number between 12 and 120 inclusive.\n");
            printf("Please enter your height in inches: ");
        } else {
            is_valid = true;
        }
    }
    printf("Thank you for entering a valid height of %d inches.\n", height_in);
    return 0;
}