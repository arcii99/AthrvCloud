//FormAI DATASET v1.0 Category: File Backup System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100

int main() {
    char sourceFile[MAX_FILENAME_LENGTH];
    char backupFile[MAX_FILENAME_LENGTH];
    char command[MAX_FILENAME_LENGTH * 3];

    printf("Enter source file name: ");
    scanf("%s", sourceFile);
    printf("Enter backup file name: ");
    scanf("%s", backupFile);

    // Create backup command
    sprintf(command, "cp %s %s", sourceFile, backupFile);

    // Execute backup command
    int status = system(command);
    if(status == -1) {
        printf("Failed to create backup!\n");
        return 1;
    } else {
        printf("Backup created successfully!\n");
        return 0;
    }
}