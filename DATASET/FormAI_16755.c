//FormAI DATASET v1.0 Category: File handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    FILE *fp;
    char filename[] = "example.txt";
    char buffer[MAX_SIZE];
    int count = 0;

    // Writing to a file
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fputs("Hello, world!", fp);

    fclose(fp);

    // Reading from a file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, MAX_SIZE, fp)) {
        count++;
        printf("%d: %s", count, buffer);
    }

    fclose(fp);

    return 0;
}