//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INPUT_SIZE 100

int main() {
    char input[MAX_INPUT_SIZE];
    double x, y;
    printf("Welcome to the Scientific Calculator!\n");

    while(1) {
        // Read user input
        printf("\nEnter an expression (q to quit): ");
        fgets(input, MAX_INPUT_SIZE, stdin);

        // Exit if user enters q
        if(input[0] == 'q') {
            printf("Goodbye!\n");
            break;
        }

        // Evaluate expression
        if(sscanf(input, "%lf + %lf", &x, &y) == 2) {
            printf("%.2lf\n", x + y);
        } else if(sscanf(input, "%lf - %lf", &x, &y) == 2) {
            printf("%.2lf\n", x - y);
        } else if(sscanf(input, "%lf * %lf", &x, &y) == 2) {
            printf("%.2lf\n", x * y);
        } else if(sscanf(input, "%lf / %lf", &x, &y) == 2) {
            printf("%.2lf\n", x / y);
        } else if(sscanf(input, "sin %lf", &x) == 1) {
            printf("%.2lf\n", sin(x));
        } else if(sscanf(input, "cos %lf", &x) == 1) {
            printf("%.2lf\n", cos(x));
        } else if(sscanf(input, "tan %lf", &x) == 1) {
            printf("%.2lf\n", tan(x));
        } else {
            printf("Invalid input!\n");
        }
    }

    return 0;
}