//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: recursive
#include <stdio.h>

void extract_metadata(char* file_path, int level);

int main() {
    char* file_path = "C:\\Users\\User\\Documents\\my_file.c";

    extract_metadata(file_path, 0);

    return 0;
}

void extract_metadata(char* file_path, int level) {
    // Print file name at current level of recursion
    for (int i = 0; i < level; i++) {
        printf("-");
    }
    printf("File: %s\n", file_path);

    // Open file
    FILE* file = fopen(file_path, "r");

    if (file == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    // Read file line by line
    char line[1000];
    while (fgets(line, 1000, file) != NULL) {
        // Check for metadata tags
        if (strstr(line, "@author")) {
            // Print author name
            printf("%*c Author: %s", level * 2, '-', strstr(line, "@author"));
        }

        if (strstr(line, "@date")) {
            // Print date
            printf("%*c Date: %s", level * 2, '-', strstr(line, "@date"));
        }

        if (strstr(line, "@description")) {
            // Print description
            printf("%*c Description: %s", level * 2, '-', strstr(line, "@description"));
        }

        if (strstr(line, "@param")) {
            // Print parameter information
            printf("%*c Param: %s", level * 2, '-', strstr(line, "@param"));
        }

        // Check for includes
        if (strstr(line, "#include")) {
            // Extract file name
            char* file_name = strtok(line, "<");
            file_name = strtok(NULL, ">");

            // Construct path
            char path[1000] = "C:\\Program Files (x86)\\CodeBlocks\\MinGW\\include\\";
            strcat(path, file_name);

            // Recursively extract metadata from included file
            extract_metadata(path, level + 1);
        }
    }

    // Close file
    fclose(file);
}