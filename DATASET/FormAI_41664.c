//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: high level of detail
#include <stdio.h>
#include <string.h>

int main() {
    printf("Welcome to the C Antivirus Scanner\n");

    // Get user input for file name
    char filename[100];
    printf("Enter the name of the file to scan: ");
    scanf("%s", filename);

    // Check file extension to see if it is executable
    char *file_extension = strrchr(filename, '.');
    if (file_extension != NULL && strcmp(file_extension, ".exe") == 0) {
        printf("WARNING: This file may be executable and could be harmful!\n");
    }

    // Scan the file for any malicious code
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("ERROR: Unable to open file.\n");
        return 1;
    }

    int virus_found = 0;
    char line[1000];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "virus")) {
            virus_found = 1;
            printf("MALWARE DETECTED: \"%s\"\n", line);
        }
    }

    fclose(file);

    // Print final result to user
    if (virus_found) {
        printf("The file contains malicious code.\n");
    } else {
        printf("The file appears to be safe!\n");
    }

    return 0;
}