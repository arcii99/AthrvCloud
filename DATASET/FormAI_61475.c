//FormAI DATASET v1.0 Category: File Backup System ; Style: interoperable
#include<stdio.h>
#include<string.h>

#define MAX_FILE_NAME_LENGTH 20
#define BACKUP_FOLDER "backup/"

void create_backup(char* filename){
    char backup_filename[MAX_FILE_NAME_LENGTH + 15]; // adding space for "backup/" prefix and ".bak" suffix
    sprintf(backup_filename, "%s%s.bak", BACKUP_FOLDER, filename);
    FILE* original_file = fopen(filename, "r");
    FILE* backup_file = fopen(backup_filename, "w");
    if(original_file == NULL){
        printf("Error: Unable to open original file\n");
        return;
    }
    if(backup_file == NULL){
        printf("Error: Unable to create backup file\n");
        fclose(original_file);
        return;
    }
    char line[100];
    while(fgets(line, sizeof(line), original_file)){
        fputs(line, backup_file);
    }
    fclose(original_file);
    fclose(backup_file);
    printf("Backup created successfully: %s\n", backup_filename);
}

void display_backup_menu(){
    printf("\nBackup Menu\n");
    printf("-----------\n");
    printf("1. Create backup\n");
    printf("2. Exit\n");
}

int main(){
    char file_name[MAX_FILE_NAME_LENGTH];
    printf("Enter the file name to create backup: ");
    scanf("%s", file_name);
    create_backup(file_name);
    return 0;
}