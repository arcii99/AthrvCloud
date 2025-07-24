//FormAI DATASET v1.0 Category: File Backup System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_FILE_NAME_LENGTH 100

//Function to create backup file of given filename and return backup filename
char* create_backup_file(char* filename) {
    char* backup_filename = (char*) malloc(MAX_FILE_NAME_LENGTH*sizeof(char));
    time_t now = time(NULL);
    struct tm* time_info = localtime(&now);
    strftime(backup_filename, MAX_FILE_NAME_LENGTH, "backup_%Y-%m-%d_%H-%M-%S_", time_info);   //Defining filename format as backup_yyyy-mm-dd_hh-mm-ss_filename
    strcat(backup_filename, filename);
    FILE* original_file = fopen(filename, "r");
    if (original_file == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(0);
    }
    FILE* backup_file = fopen(backup_filename, "w");
    if (backup_file == NULL) {
        printf("Error: Could not create backup file.\n");
        exit(0);
    }
    char c;
    while ((c = fgetc(original_file)) != EOF) {
        fputc(c, backup_file);
    }
    printf("Backup file created with filename '%s'.\n", backup_filename);
    fclose(original_file);
    fclose(backup_file);
    return backup_filename;
}

int main() {
    char filename[MAX_FILE_NAME_LENGTH];
    printf("Enter the name of the file to backup: ");
    scanf("%s", filename);
    char* backup_filename = create_backup_file(filename);
    printf("Backup of file '%s' complete!\n", filename);
    printf("Backup filename: %s\n", backup_filename);
    free(backup_filename);
    return 0;
}