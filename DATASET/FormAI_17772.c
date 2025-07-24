//FormAI DATASET v1.0 Category: File Backup System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_SIZE 10000

int main() {
    // Variables
    char filename[MAX_FILENAME_LENGTH];
    char fileContent[MAX_FILE_SIZE];
    FILE* file = NULL;

    printf("Enter the filename to backup: ");
    scanf("%s", filename);

    // Open file to read
    file = fopen(filename, "r");

    if (!file) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read file
    fgets(fileContent, MAX_FILE_SIZE, file);

    // Close file
    fclose(file);

    // Create backup file with timestamp
    char backupFilename[MAX_FILENAME_LENGTH + 20];
    time_t timestamp = time(NULL);
    strftime(backupFilename, sizeof(backupFilename), "%Y-%m-%d_%H-%M-%S_", localtime(&timestamp));
    strcat(backupFilename, filename);

    // Open backup file to write
    file = fopen(backupFilename, "w");

    if (!file) {
        printf("Error creating backup file!\n");
        return 1;
    }

    // Write file content to backup file
    fputs(fileContent, file);

    // Close backup file
    fclose(file);

    printf("Backup saved to %s\n", backupFilename);

    return 0;
}