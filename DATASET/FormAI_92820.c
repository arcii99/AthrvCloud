//FormAI DATASET v1.0 Category: Error handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {

    FILE *fp;
    char *filename = "sample.txt";
    int num;

    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Error opening file %s: %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (fscanf(fp, "%d", &num) == EOF) {
        fprintf(stderr, "Error reading from file %s: %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    if (num < 0) {
        fprintf(stderr, "Error: number read from file %s is negative\n", filename);
        exit(EXIT_FAILURE);
    }

    int result = 10 / num;

    if (errno == EDOM) {
        fprintf(stderr, "Error: divide by zero\n");
        exit(EXIT_FAILURE);
    }

    printf("Result: %d\n", result);

    return 0;
}