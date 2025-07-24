//FormAI DATASET v1.0 Category: File handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 100

int main() {
    FILE *file_pointer;
    char file_name[] = "example.txt";
    char line[MAX_LINE_SIZE];
    int lines = 0;

    // Open the file for reading
    file_pointer = fopen(file_name, "r");
    if (file_pointer == NULL) {
        printf("Failed to open the file for reading.\n");
        return 1;
    }

    // Count the number of lines in the file
    while (fgets(line, sizeof(line), file_pointer)) {
        lines++;
    }
    rewind(file_pointer);

    // Allocate memory to store all the lines
    char **file_contents = calloc(lines, sizeof(char*));
    if (file_contents == NULL) {
        printf("Failed to allocate memory for file contents.\n");
        return 1;
    }

    // Read in all the lines
    int i;
    for (i = 0; i < lines; i++) {
        if (fgets(line, sizeof(line), file_pointer)) {
            // Remove the trailing new line character
            line[strcspn(line, "\n")] = 0;

            // Allocate memory for the line
            file_contents[i] = malloc(strlen(line) + 1);
            if (file_contents[i] == NULL) {
                printf("Failed to allocate memory for a line.\n");
                return 1;
            }

            // Copy the line into the allocated memory
            strcpy(file_contents[i], line);
        }
    }

    // Manipulate the data (in this case, add line numbers)
    for (i = 0; i < lines; i++) {
        char line_number[MAX_LINE_SIZE];
        sprintf(line_number, "%d", i+1);

        char *new_line = malloc(strlen(line_number) + strlen(file_contents[i]) + 1);
        if (new_line == NULL) {
            printf("Failed to allocate memory for a new line.\n");
            return 1;
        }

        strcpy(new_line, line_number);
        strcat(new_line, " ");
        strcat(new_line, file_contents[i]);

        free(file_contents[i]);
        file_contents[i] = new_line;
    }

    // Open the file for writing (overwriting the old contents)
    file_pointer = fopen(file_name, "w");
    if (file_pointer == NULL) {
        printf("Failed to open the file for writing.\n");
        return 1;
    }

    // Write the new contents of the file
    for (i = 0; i < lines; i++) {
        fputs(file_contents[i], file_pointer);
        fputs("\n", file_pointer);

        free(file_contents[i]);
    }

    // Free memory and close the file
    free(file_contents);
    fclose(file_pointer);

    return 0;
}