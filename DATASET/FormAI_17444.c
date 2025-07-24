//FormAI DATASET v1.0 Category: Error handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    char *input = NULL;
    size_t size = 0;
    int num;

    printf("Enter a number: ");
    if (getline(&input, &size, stdin) == -1) {
        error_exit("Failed to read input");
    }

    errno = 0;
    num = strtol(input, NULL, 10);
    if (errno == EINVAL || errno == ERANGE) {
        fprintf(stderr, "Invalid input: %s\n", input);
        exit(EXIT_FAILURE);
    }

    printf("The square of %d is %d\n", num, num * num);

    free(input);
    return 0;
}