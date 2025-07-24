//FormAI DATASET v1.0 Category: File Backup System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: backup [source] [destination]");
        exit(EXIT_FAILURE);
    }

    char *source_path = argv[1];
    char *destination_path = argv[2];

    // Check if source file exists and is readable
    if (access(source_path, R_OK) == -1) {
        printf("Error: Cannot read source file");
        exit(EXIT_FAILURE);
    }

    // Create destination file if it doesn't exist
    FILE *destination_file = fopen(destination_path, "w");
    if (destination_file == NULL) {
        printf("Error: Cannot create destination file");
        exit(EXIT_FAILURE);
    }

    // Open source file for reading
    FILE *source_file = fopen(source_path, "r");
    if (source_file == NULL) {
        printf("Error: Cannot open source file");
        fclose(destination_file);
        exit(EXIT_FAILURE);
    }

    // Copy contents of source file to destination file
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, source_file) != NULL) {
        fputs(buffer, destination_file);
    }

    // Close files
    fclose(source_file);
    fclose(destination_file);

    printf("Backup successful!");
    return 0;
}