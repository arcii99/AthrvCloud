//FormAI DATASET v1.0 Category: Error handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void) {
    FILE *file;
    char *filename = "example.txt";
    int num;
    int sum = 0;
    errno = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%d", &num) == 1) {
        sum += num;
    }

    if (fclose(file) != 0) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }

    if (errno == EINVAL) {
        fprintf(stderr, "Invalid argument while opening file\n");
        exit(EXIT_FAILURE);
    } else if (errno == EACCES) {
        fprintf(stderr, "File access permission denied\n");
        exit(EXIT_FAILURE);
    }

    printf("The sum of the numbers in %s is %d\n", filename, sum);

    return 0;
}