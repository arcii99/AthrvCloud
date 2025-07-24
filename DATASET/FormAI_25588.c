//FormAI DATASET v1.0 Category: Error handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    FILE *input;
    char file_name[] = "example.txt";
    int num1, num2;

    input = fopen(file_name, "r");
    if (input == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    if (fscanf(input, "%d %d", &num1, &num2) != 2) {
        fprintf(stderr, "Error reading file\n");
        exit(EXIT_FAILURE);
    }

    if (num1 < 0 || num2 < 0) {
        fprintf(stderr, "Numbers must be positive\n");
        exit(EXIT_FAILURE);
    }

    int result = num1 / num2;

    if (errno == EDOM) {
        fprintf(stderr, "Math error with errno = %d\n", errno);
        exit(EXIT_FAILURE);
    }

    printf("%d / %d = %d\n", num1, num2, result);

    if (fclose(input) == EOF) {
        fprintf(stderr, "Error closing file\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}