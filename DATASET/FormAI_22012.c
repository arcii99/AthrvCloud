//FormAI DATASET v1.0 Category: File Backup System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char sourceFilePath[100];
    char backupFilePath[100];
    
    printf("Enter the source file path: ");
    scanf("%s", sourceFilePath);

    printf("Enter the backup file path: ");
    scanf("%s", backupFilePath);
    
    char command[100];
    sprintf(command, "cp %s %s", sourceFilePath, backupFilePath);
    system(command);

    printf("Backup successful!\n");
    
    return 0;
}