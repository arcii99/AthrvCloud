//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

void scanFile(char fileName[]);

int main() {
    char fileName[100];
    printf("Enter file name: ");
    scanf("%s", fileName);
    scanFile(fileName);
    return 0;
}

void scanFile(char fileName[]) {
    char buffer[BUFFER_SIZE];
    FILE *file = fopen(fileName, "r");

    // Check if file exists
    if (file == NULL) {
        printf("File '%s' not found.\n", fileName);
        return;
    }

    // Read file contents
    while (fgets(buffer, BUFFER_SIZE, file)) {
        // Scan for virus signature
        if (strstr(buffer, "virus") != NULL) {
            printf("Virus detected in file '%s'.\n", fileName);
            fclose(file);
            return;
        }
    }

    printf("File '%s' is clean.\n", fileName);
    fclose(file);
}