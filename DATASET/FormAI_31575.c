//FormAI DATASET v1.0 Category: File Backup System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILENAME_LENGTH 50

void backup_file(char* filename){
    char backup_filename[MAX_FILENAME_LENGTH + 8]; // filename + ".backup"
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".backup");

    FILE* original_file = fopen(filename, "r");
    if(original_file == NULL){
        printf("Error: Could not open %s for reading.\n", filename);
        return;
    }

    FILE* backup_file = fopen(backup_filename, "w");
    if(backup_file == NULL){
        printf("Error: Could not open %s for writing.\n", backup_filename);
        fclose(original_file);
        return;
    }

    char character;
    while((character = fgetc(original_file)) != EOF){
        fputc(character, backup_file);
    }

    fclose(original_file);
    fclose(backup_file);
    printf("%s backed up successfully to %s.\n", filename, backup_filename);
}

int main(){
    printf("Welcome to the File Backup System.\n");
    char filename[MAX_FILENAME_LENGTH];
 
    while(1){
        printf("Please enter the name of the file you want to backup, or 'exit' to exit: \n");
        scanf("%s", filename);
        if(strcmp(filename, "exit") == 0){
            break;
        }
        backup_file(filename);
    }
 
    printf("Thank you for using the File Backup System.\n");
    return 0;
}