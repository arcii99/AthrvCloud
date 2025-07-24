//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main() {
    char file_path[100], file_extension[10];
    printf("Enter the file path: ");
    scanf("%s", file_path);
    printf("\nEnter the file extension: ");
    scanf("%s", file_extension);

    // Checking if the entered file extension is valid
    if (strcmp(file_extension, "c") && strcmp(file_extension, "h")) {
        printf("\nInvalid file extension.\n");
        return 1;
    }

    FILE *file_pointer = fopen(file_path, "r");
    if (file_pointer == NULL) {
        printf("\nUnable to open file.\n");
        return 1;
    }

    char line[200];
    int line_number = 0;
    while (fgets(line, sizeof(line), file_pointer)) {
        line_number++;

        // Checking for metadata tags in the comment section
        if (line[0] == '/' && line[1] == '/' && strstr(line, "@author")) {
            printf("\n%s", line);
        }
        else if (line[0] == '/' && line[1] == '/' && strstr(line, "@created")) {
            printf("%s", line);
        }
        else if (line[0] == '/' && line[1] == '/' && strstr(line, "@modified")) {
            printf("%s", line);
        }
    }

    fclose(file_pointer);

    return 0;
}