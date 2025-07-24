//FormAI DATASET v1.0 Category: Error handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    FILE *fp;
    char filename[20];
    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        if (errno == EACCES) {
            printf("Error: Access denied to the file\n");
        } else if (errno == ENOENT) {
            printf("Error: File not found\n");
        } else {
            perror("Error");
        }
        exit(EXIT_FAILURE);
    }

    char line[100];
    while (fgets(line, 100, fp) != NULL) {
        printf("%s", line);
    }

    if (fclose(fp) != 0) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }

    return 0;
}