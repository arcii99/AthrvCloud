//FormAI DATASET v1.0 Category: File Backup System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void backupFile(char* filename){
    // Open input file in read mode
    FILE* inputFile = fopen(filename, "rb");

    // Create backup file with .bak extension
    char* backupFilename = (char*)malloc((strlen(filename)+4)*sizeof(char));
    strcpy(backupFilename, filename);
    strcat(backupFilename, ".bak");

    // Open backup file in write mode
    FILE* backupFile = fopen(backupFilename, "wb");

    // Create buffer to read from file
    char buffer[BUFFER_SIZE];

    // Read from input file and write to backup file
    size_t bytes;
    while ((bytes = fread(buffer, sizeof(char), BUFFER_SIZE, inputFile)) > 0){
        fwrite(buffer, sizeof(char), bytes, backupFile);
    }

    // Close both files
    fclose(inputFile);
    fclose(backupFile);

    printf("File %s backed up to %s\n", filename, backupFilename);
}

int main(){
    // Ask user for filename to backup
    char* filename = (char*)malloc(BUFFER_SIZE*sizeof(char));
    printf("Enter filename to backup: ");
    scanf("%s", filename);

    // Backup file
    backupFile(filename);

    return 0;
}