//FormAI DATASET v1.0 Category: Error handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void) {
    FILE *fp;
    int num;

    fp = fopen("non_existent_file.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    num = 10 / 0; // Divide by zero generates a floating point exception

    if (errno) {
        perror("Error in division");
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    return 0;
}