//FormAI DATASET v1.0 Category: File Backup System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Define MAX_FILE_SIZE to 10KB
#define MAX_FILE_SIZE 10240

//Define the file extension for backup files
#define BACKUP_EXTENSION ".bak"

typedef struct {
    char filename[50];
    char data[MAX_FILE_SIZE];
    time_t backup_time;
} file_backup;

file_backup backup_files[10]; //Array to store backup files information
int num_backup_files = 0; //Number of backup files

void backup_file(char* filename, char* data) {
    //Create file_backup struct for new backup file
    file_backup new_backup;
    strcpy(new_backup.filename, filename);
    strcpy(new_backup.data, data);
    new_backup.backup_time = time(NULL);
    
    //Create backup filename
    char backup_filename[strlen(filename) + strlen(BACKUP_EXTENSION) + 1];
    strcpy(backup_filename, filename);
    strcat(backup_filename, BACKUP_EXTENSION);
    
    //Open file for writing
    FILE* fp = fopen(backup_filename, "w");
    if (fp == NULL) {
        printf("Error: Could not create backup file.\n");
        return;
    }
    
    //Write data to backup file
    fprintf(fp, "%s", data);
    fclose(fp);
    
    //Add backup file to array
    backup_files[num_backup_files] = new_backup;
    num_backup_files++;
}

void list_backup_files() {
    printf("Backup Files:\n");
    for (int i = 0; i < num_backup_files; i++) {
        printf("%s - %ld\n", backup_files[i].filename, backup_files[i].backup_time);
    }
}

int main() {
    char test_file[] = "test.txt";
    char test_data[] = "This is a test file.\n";
    
    backup_file(test_file, test_data);
    list_backup_files();
    
    return 0;
}