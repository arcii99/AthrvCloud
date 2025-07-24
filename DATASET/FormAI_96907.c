//FormAI DATASET v1.0 Category: File Backup System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to copy the contents of one file to another
void file_copy(FILE *source, FILE *destination) {
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }
}

int main() {
    char file_name[100];
    char backup_file_name[100];
    FILE *file_pointer;
    FILE *backup_file_pointer;
    
    // get the file name from the user
    printf("Enter the name of the file to backup: ");
    scanf("%99s", file_name);
    
    // open the file in read mode
    file_pointer = fopen(file_name, "r");
    
    // check if the file exists
    if (file_pointer == NULL) {
        printf("File does not exist.\n");
        return 1; // return 1 to indicate an error
    }
    
    // create the backup file name by appending "_backup" to the original file name
    strcpy(backup_file_name, file_name);
    strcat(backup_file_name, "_backup");
    
    // open the backup file in write mode
    backup_file_pointer = fopen(backup_file_name, "w");
    
    // check if the backup file creation was successful
    if (backup_file_pointer == NULL) {
        printf("Error: Could not create backup file.\n");
        fclose(file_pointer);
        return 1; // return 1 to indicate an error
    }
    
    // copy the contents of the original file to the backup file
    file_copy(file_pointer, backup_file_pointer);
    
    // close the files
    fclose(file_pointer);
    fclose(backup_file_pointer);
    
    printf("Backup complete!\n");
    
    return 0; // return 0 to indicate a successful program execution
}