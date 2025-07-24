//FormAI DATASET v1.0 Category: File Backup System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_CONTENT_LENGTH 10000

void backupFile(char* fileName){
    FILE* file = fopen(fileName, "r");
    if(file == NULL){
        printf("File not found: %s\n", fileName);
        return;
    }

    char backupFileName[MAX_FILE_NAME_LENGTH + 5]; // +5 for ".bak" string
    sprintf(backupFileName, "%s.bak", fileName);

    FILE* backupFile = fopen(backupFileName, "w");
    if(backupFile == NULL){
        printf("Could not open backup file: %s\n", backupFileName);
        fclose(file);
        return;
    }

    char fileContent[MAX_FILE_CONTENT_LENGTH];
    size_t bytesRead = fread(fileContent, 1, MAX_FILE_CONTENT_LENGTH, file);
    if(bytesRead > 0){

        if(fwrite(fileContent, 1, bytesRead, backupFile) != bytesRead){
            printf("Could not write to backup file: %s\n", backupFileName);
        }
    }

    fclose(file);
    fclose(backupFile);

    printf("File \"%s\" backed up successfully as \"%s\"\n", fileName, backupFileName);
}

int main(int argc, char** argv){
    if(argc < 2){
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    for(int i = 1; i < argc; i++){
        backupFile(argv[i]);
    }

    return 0;
}