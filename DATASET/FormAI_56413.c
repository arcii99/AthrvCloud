//FormAI DATASET v1.0 Category: Error handling ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Custom error handler function
void handle_error(char *msg, int exit_code) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(exit_code);
}

int main() {
    FILE *file = fopen("nonexistent.txt", "r");
    if (file == NULL) {
        handle_error("Could not open file!", 1);
    }

    char buffer[50];
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        handle_error("Could not read file!", 2);
    }

    int num = atoi(buffer);
    if (num == 0) {
        handle_error("Invalid input!", 3);
    }

    printf("Success! Read number: %d\n", num);

    return 0;
}