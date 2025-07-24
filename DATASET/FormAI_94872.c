//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

// Define virus signature
const char* virus_signature = "rm -rf /";

int scan_file(const char* file_path) {
    FILE* file;
    char buffer[MAX_BUF_SIZE] = {0};
    int found_virus = 0;

    // Open the file
    file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Unable to open file: %s\n", file_path);
        return 0;
    }

    // Read the file line by line
    while (fgets(buffer, MAX_BUF_SIZE, file) != NULL) {
        // Check if the virus signature is present in the line
        if (strstr(buffer, virus_signature) != NULL) {
            printf("Virus detected in file: %s\n", file_path);
            printf("Infected line: %s\n", buffer);
            found_virus = 1;
            break;
        }
    }

    // Close the file and return virus status
    fclose(file);
    return found_virus;
}

int main(int argc, char** argv) {
    int i;
    int infected_files = 0;

    // Check if file paths are provided as command line arguments
    if (argc == 1) {
        printf("Usage: %s [file1] [file2] ... [fileN]\n");
        return 0;
    }

    // Scan each file provided as command line argument
    for (i = 1; i < argc; i++) {
        if (scan_file(argv[i])) {
            infected_files++;
        }
    }

    // Print the scan report
    if (infected_files == 0) {
        printf("Scan complete: No virus detected in any file.\n");
    } else {
        printf("Scan complete: %d infected file(s) found.\n", infected_files);
    }

    return 0;
}