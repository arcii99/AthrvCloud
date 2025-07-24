//FormAI DATASET v1.0 Category: Error handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int num1, num2;
    char *filename = "file.txt";

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    if (fscanf(fp, "%d %d", &num1, &num2) != 2) {
        fputs("Error reading from file\n", stderr);
        exit(EXIT_FAILURE);
    }

    if (num2 == 0) {
        fprintf(stderr, "Divide by zero error\n");
        exit(EXIT_FAILURE);
    }

    printf("%d divided by %d is %f\n", num1, num2, (float)num1/num2);

    if (fclose(fp) != 0) {
        perror("Failed to close file");
        exit(EXIT_FAILURE);
    }

    return 0;
}