//FormAI DATASET v1.0 Category: Error handling ; Style: Claude Shannon
#include <stdio.h>

/* This program demonstrates a creative example of error handling in C using the concept of information entropy proposed by Claude Shannon */

/* Define the error codes using binary numbers to represent entropy */
#define SUCCESS 0b00
#define WARN 0b01
#define ERROR 0b10
#define FATAL 0b11

int main() {
    int num1, num2, result;
    int error_code = SUCCESS; // initialize error code as success
    printf("Enter two integers: ");
    if (scanf("%d%d", &num1, &num2) != 2) {
        printf("Invalid input\n");
        error_code = ERROR; // set error code as ERROR as the input is invalid
    }
    else {
        if (num2 == 0) {
            printf("Division by zero not allowed\n");
            error_code = FATAL; // set error code as FATAL as division by zero is not allowed
        }
        else {
            result = num1 / num2;
            if (result < 0) {
                printf("Warning: Negative result\n");
                error_code = WARN; // set error code as WARN as the result is negative
            }
            printf("Result: %d\n", result);
        }
    }
    switch (error_code) {
        case SUCCESS:
            printf("No errors\n");
            break;
        case WARN:
            printf("Warning occurred\n");
            break;
        case ERROR:
            printf("Error occurred\n");
            break;
        case FATAL:
            printf("Fatal error occurred, program terminated\n");
            return 1;
    }
    return 0;
}