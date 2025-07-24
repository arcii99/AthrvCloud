//FormAI DATASET v1.0 Category: File Backup System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char sourcePath[BUFFER_SIZE];
    char destinationPath[BUFFER_SIZE];
    char fileName[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    char timestamp[BUFFER_SIZE];
    FILE *sourceFile, *destinationFile;
    time_t rawtime;
    struct tm * timeinfo;
    int i, j, k;
    
    printf("Enter path of the file to be backed up: ");
    fgets(sourcePath, BUFFER_SIZE, stdin);
    sourcePath[strcspn(sourcePath, "\n")] = 0;
    
    sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Error: Cannot open the file.\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Enter path to backup the file: ");
    fgets(destinationPath, BUFFER_SIZE, stdin);
    destinationPath[strcspn(destinationPath, "\n")] = 0;
    
    printf("Enter file name: ");
    fgets(fileName, BUFFER_SIZE, stdin);
    fileName[strcspn(fileName, "\n")] = 0;
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(timestamp, BUFFER_SIZE, "%Y%m%d%H%M%S", timeinfo);
    
    strcat(destinationPath, "/");
    strcat(destinationPath, fileName);
    strcat(destinationPath, "_backup_");
    strcat(destinationPath, timestamp);
    
    destinationFile = fopen(destinationPath, "w");
    if (destinationFile == NULL) {
        printf("Error: Cannot create backup file.\n");
        exit(EXIT_FAILURE);
    }
    
    while ((i = fgetc(sourceFile)) != EOF) {
        fputc(i, destinationFile);
    }
    
    fclose(sourceFile);
    fclose(destinationFile);
    
    printf("Backup successful!\n");
    
    printf("Do you want to compress the backup file? (y/n) ");
    fgets(command, BUFFER_SIZE, stdin);
    command[strcspn(command, "\n")] = 0;
    
    if (strcmp(command, "y") == 0) {
        strcat(destinationPath, ".gz");
        sprintf(command, "gzip %s", destinationPath);
        system(command);
        printf("Backup file compressed!\n");
    } else {
        exit(EXIT_SUCCESS);
    }
    
    return 0;
}