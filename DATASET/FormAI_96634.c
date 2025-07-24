//FormAI DATASET v1.0 Category: File Backup System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50   // maximum length for file names
#define MAX_FILES 100    // maximum number of files in the backup system
#define MAX_BACKUPS 10   // maximum number of backups per file

typedef struct backup {
    char filename[MAX_FILENAME_LENGTH];
    int backup_num;
    char backup_time[20];
} Backup;

typedef struct file {
    char filename[MAX_FILENAME_LENGTH];
    Backup backups[MAX_BACKUPS];
    int num_backups;
} File;

File files[MAX_FILES];   // declare array of files

int num_files = 0;  // keep track of number of files in system

void backup_file(char *filename) {
    int i, j;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].filename, filename) == 0) {   // file already exists in system
            if (files[i].num_backups == MAX_BACKUPS) {   // maximum number of backups reached
                printf("Maximum number of backups reached for file %s\n", filename);
                return;
            }
            else {   // add backup to existing file
                Backup backup;
                strcpy(backup.filename, filename);
                backup.backup_num = files[i].num_backups + 1;
                time_t t = time(NULL);
                struct tm *tm = localtime(&t);
                strftime(backup.backup_time, sizeof(backup.backup_time), "%Y-%m-%d %H:%M:%S", tm);
                files[i].backups[files[i].num_backups++] = backup;
                printf("Backup %d created for file %s at %s\n", backup.backup_num, filename, backup.backup_time);
                return;
            }
        }
    }
    // file does not exist in system, create new file and backup
    File new_file;
    strcpy(new_file.filename, filename);
    Backup backup;
    strcpy(backup.filename, filename);
    backup.backup_num = 1;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(backup.backup_time, sizeof(backup.backup_time), "%Y-%m-%d %H:%M:%S", tm);
    new_file.backups[0] = backup;
    new_file.num_backups = 1;
    files[num_files++] = new_file;
    printf("File %s created with backup 1 at %s\n", filename, backup.backup_time);
}

void list_files() {
    printf("Files in backup system:\n");
    int i, j;
    for (i = 0; i < num_files; i++) {
        printf("%s\n", files[i].filename);
        for (j = 0; j < files[i].num_backups; j++) {
            printf("\tBackup %d created at %s\n", files[i].backups[j].backup_num, files[i].backups[j].backup_time);
        }
    }
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    int choice;
    while (1) {   // loop until user chooses to exit
        printf("\nFile Backup System Menu\n");
        printf("1. Backup File\n");
        printf("2. List Files\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter file name to backup: ");
                scanf("%s", filename);
                backup_file(filename);
                break;
            case 2:
                list_files();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    }
    return 0;
}