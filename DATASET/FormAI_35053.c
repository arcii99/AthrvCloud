//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Dennis Ritchie
#include <stdio.h>

/* A simple program to demonstrate syntax parsing in C */

int main() {
    char input;
    int sum = 0, count = 0;

    printf("Enter some numbers separated by spaces (or press q to quit):\n");

    while (scanf("%c", &input) == 1) {
        if (input == 'q') {
            break;
        }
        else if (isdigit(input)) {
            sum += input - '0';
            count++;
        }
        else if (input == ' ') {
            continue;
        }
        else {
            printf("Invalid input. Please enter only numbers separated by spaces.\n");
            while ((getchar()) != '\n'); //flush stdin
            continue;
        }
    }

    if (count == 0) {
        printf("No numbers entered.\n");
    }
    else {
        printf("Sum of entered numbers: %d\nAverage of entered numbers: %f\n",
               sum, (float) sum / count);
    }

    return 0;
}