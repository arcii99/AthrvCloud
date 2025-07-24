//FormAI DATASET v1.0 Category: Error handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

void handle_error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    FILE *file;
    int num1, num2, result;

    file = fopen("data.txt", "r"); // Opening the file in read mode

    if (file == NULL) {
        handle_error("Unable to open file");
    }

    if (fscanf(file, "%d %d", &num1, &num2) != 2) { // Reading two integers from the file
        handle_error("Cannot read data from file");
    }

    if (num2 == 0) {
        handle_error("Division by zero");
    }

    result = num1 / num2;

    printf("%d / %d = %d", num1, num2, result);

    if (fclose(file) != 0) { // Closing the file
        handle_error("Error in closing file");
    }

    return 0;
}