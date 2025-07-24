//FormAI DATASET v1.0 Category: File handling ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    char filename[20];
    char ch;
    int count = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    while ((ch = fgetc(fptr)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }

    fclose(fptr);

    printf("Number of lines in %s: %d\n", filename, count);

    return 0;
}