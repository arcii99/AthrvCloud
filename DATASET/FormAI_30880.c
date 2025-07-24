//FormAI DATASET v1.0 Category: File handling ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    FILE *file;
    char *filename = "retro.txt";
    char *content = "This is a sample text file for our retro file handling program.\n";
    char line[MAX_LINE_LENGTH];

    // Open file for writing
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return 1;
    }

    // Write content to file
    fputs(content, file);

    // Close file
    fclose(file);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file for reading.\n");
        return 1;
    }

    // Read file contents line by line and print to console
    printf("File Contents:\n");
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        printf("%s", line);
    }

    // Close file
    fclose(file);

    // Append additional content to file
    file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error: Unable to open file for appending.\n");
        return 1;
    }

    char *additional_content = "This is some additional content added after the initial text.\n";
    fputs(additional_content, file);

    // Close file
    fclose(file);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file for reading.\n");
        return 1;
    }

    // Read file contents again and print to console
    printf("Updated File Contents:\n");
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        printf("%s", line);
    }

    // Close file
    fclose(file);

    // Delete file
    if (remove(filename) == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Error: Unable to delete file.\n");
    }

    return 0;
}