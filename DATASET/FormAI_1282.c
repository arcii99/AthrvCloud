//FormAI DATASET v1.0 Category: Error handling ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// Define a custom error struct for our program
struct CustomError {
    int code;
    char* message;
};

// Function to handle errors
void handle_error(struct CustomError* err) {
    fprintf(stderr, "Error: %s. Error code: %d\n", err->message, err->code);
    exit(err->code);
}

int main() {
    // Demonstrate a potential error scenario
    int num;
    char str[10];
    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        struct CustomError err = {errno, "Invalid input"};
        handle_error(&err);
    }
    printf("Enter a string: ");
    if (scanf("%s", str) != 1) {
        struct CustomError err = {errno, "Invalid input"};
        handle_error(&err);
    }

    // Perform some operation that may encounter an error
    FILE* fp;
    fp = fopen("nonexistentfile.txt", "r");
    if (fp == NULL) {
        struct CustomError err = {errno, "Failed to open file"};
        handle_error(&err);
    }
    fclose(fp);

    printf("Program executed successfully\n");
    return 0;
}