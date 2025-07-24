//FormAI DATASET v1.0 Category: Error handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int divide(int a, int b) {
    if (b == 0) {
        // define error message
        char error_msg[50];
        sprintf(error_msg, "Error: Cannot divide by zero");
        // log error message to file
        FILE *file;
        file = fopen("error_log.txt", "a");
        fprintf(file, "%s\n", error_msg);
        fclose(file);
        // raise error and terminate program
        exit(EXIT_FAILURE);
    } else {
        return a / b;
    }
}

int main() {
    int a = 10;
    int b = 0;
    int result;

    // call divide function and handle error
    printf("Dividing %d by %d\n", a, b);
    result = divide(a, b);
    printf("Result: %d\n", result);

    return 0;
}