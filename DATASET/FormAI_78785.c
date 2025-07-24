//FormAI DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    char filename[100], ch;
    int num_lines = 1;

    printf("Enter the filename to open: ");
    scanf("%s", filename);

    // Open file
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Unable to open file. \n");
        exit(EXIT_FAILURE);
    }

    // Count number of lines in file
    while ((ch = fgetc(fptr)) != EOF) {
        if (ch == '\n') {
            num_lines++;
        }
    }

    // Print number of lines
    printf("Number of lines in file: %d\n", num_lines);

    // Close file
    fclose(fptr);
    return 0;
}