//FormAI DATASET v1.0 Category: Error handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please enter an integer as input.\n");
        return 1; // Exit program with error code 1
    }

    char *endptr;
    long num = strtol(argv[1], &endptr, 10);

    if (errno == ERANGE) {
        printf("Input error: Value is out of range.\n");
        return 2; // Exit program with error code 2
    }

    if (*endptr != '\0') {
        printf("Input error: Invalid character %c found.\n", *endptr);
        return 3; // Exit program with error code 3
    }

    if (num < -100 || num > 100) {
        printf("Input error: Value must be between -100 and 100.\n");
        return 4; // Exit program with error code 4
    }

    // Run program logic
    int result = num * 2;
    
    printf("The result is %d.\n", result);
    
    return 0; // Exit program with success code 0
}