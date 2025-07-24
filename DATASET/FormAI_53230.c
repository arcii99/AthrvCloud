//FormAI DATASET v1.0 Category: File handling ; Style: introspective
#include <stdio.h>

int main() {
    FILE *fp;
    char filename[] = "example.txt";
    char c;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.");
        return 0;
    }

    printf("Content of file:\n");

    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }

    if (feof(fp)) {
        printf("\n\nReached end of file.\n");
    } else {
        printf("Error reading file.");
        return 0;
    }

    fclose(fp);

    return 0;
}