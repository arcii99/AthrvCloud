//FormAI DATASET v1.0 Category: File Backup System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILENAME_SIZE 100

void backup_file(char original_filename[MAX_FILENAME_SIZE], char backup_filename[MAX_FILENAME_SIZE]){
    FILE *original_file, *backup_file;
    char c;
    
    original_file = fopen(original_filename, "r");
    backup_file = fopen(backup_filename, "w");

    while ((c = fgetc(original_file)) != EOF)
        fputc(c, backup_file);

    fclose(original_file);
    fclose(backup_file);
}

int main(){
    char original_filename[MAX_FILENAME_SIZE], backup_filename[MAX_FILENAME_SIZE];

    printf("Enter the filename of the file you want to backup: ");
    scanf("%s", original_filename);

    printf("Enter the filename to save the backup as: ");
    scanf("%s", backup_filename);

    backup_file(original_filename, backup_filename);

    printf("File backup successful!\n");

    return 0;
}