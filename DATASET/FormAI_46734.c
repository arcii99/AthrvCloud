//FormAI DATASET v1.0 Category: File handling ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

int main() {
    char filename[50], line[MAX_LINE_LENGTH];
    FILE *file;
    int num_lines = 0, num_chars = 0;

    printf("Enter the name of the file: ");
    scanf("%s", filename);
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file. Exiting program.\n");
        exit(1);
    }

    // Counting the number of lines and characters in the file
    while(fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        num_lines++;
        num_chars += strlen(line);
    }

    // Printing the statistics
    printf("Number of lines in the file: %d\n", num_lines);
    printf("Number of characters in the file: %d\n", num_chars);

    fclose(file);

    return 0;
}