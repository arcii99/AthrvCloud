//FormAI DATASET v1.0 Category: File Backup System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_FILES 100
#define MAX_BACKUP_SIZE 1000000 //maximum backup size in bytes

//Structure to store file information
struct File {
    char filename[MAX_FILENAME_LEN];
    char* data;
    int size;
};

//Structure to store backup information
struct Backup {
    struct File files[MAX_FILES];
    int numFiles;
    int size;
};

//Function prototypes
void backupFiles(struct Backup* backup, int numFiles, char** filenames);
void restoreBackup(struct Backup* backup);
void printBackupInfo(struct Backup* backup);

int main(int argc, char** argv) {
    struct Backup backup;
    backup.numFiles = 0;
    backup.size = 0;

    int choice = 0;
    do {
        printf("1. Backup Files\n");
        printf("2. Restore Backup\n");
        printf("3. Print Backup Info\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int numFiles = 0;
                char** filenames = (char**)malloc(sizeof(char*) * MAX_FILES);
                printf("Enter the number of files to backup: ");
                scanf("%d", &numFiles);
                getchar(); //flush newline character from input buffer

                printf("Enter the names of the files to backup:\n");
                for(int i = 0; i < numFiles; i++) {
                    filenames[i] = (char*)malloc(sizeof(char) * MAX_FILENAME_LEN);
                    fgets(filenames[i], MAX_FILENAME_LEN, stdin);
                    filenames[i][strlen(filenames[i]) - 1] = '\0'; //replace newline character with null terminator
                }

                backupFiles(&backup, numFiles, filenames);
                printf("Files backed up successfully!\n");

                for(int i = 0; i < numFiles; i++) {
                    free(filenames[i]);
                }
                free(filenames);

                break;
            }
            case 2: {
                restoreBackup(&backup);
                printf("Backup restored successfully!\n");
                break;
            }
            case 3: {
                printBackupInfo(&backup);
                break;
            }
            case 4: {
                printf("Exiting program...\n");
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    } while(choice != 4);

    //Free memory allocated for backup data
    for(int i = 0; i < backup.numFiles; i++) {
        free(backup.files[i].data);
    }

    return 0;
}

/* Function to backup the given files */
void backupFiles(struct Backup* backup, int numFiles, char** filenames) {
    //Calculate total size of backup
    int totalSize = 0;
    for(int i = 0; i < numFiles; i++) {
        FILE* file = fopen(filenames[i], "rb");
        if(file == NULL) {
            printf("Error: Could not open file %s\n", filenames[i]);
            return;
        }

        fseek(file, 0, SEEK_END);
        int size = ftell(file);
        totalSize += size;
        fclose(file);
    }

    //Check if backup size is within limit
    if((backup->size + totalSize) > MAX_BACKUP_SIZE) {
        printf("Error: Backup size exceeds maximum limit!\n");
        return;
    }

    //Allocate memory for backup data
    backup->numFiles += numFiles;
    for(int i = (backup->numFiles - numFiles); i < backup->numFiles; i++) {
        backup->files[i].data = (char*)malloc(sizeof(char) * totalSize);
    }

    //Copy data from files to backup
    int offset = 0;
    for(int i = 0; i < numFiles; i++) {
        FILE* file = fopen(filenames[i], "rb");
        if(file == NULL) {
            printf("Error: Could not open file %s\n", filenames[i]);
            return;
        }

        fseek(file, 0, SEEK_END);
        int size = ftell(file);
        backup->files[i + (backup->numFiles - numFiles)].size = size;
        fseek(file, 0, SEEK_SET);
        fread(backup->files[i + (backup->numFiles - numFiles)].data + offset, 1, size, file);
        fclose(file);
        strncpy(backup->files[i + (backup->numFiles - numFiles)].filename, filenames[i], MAX_FILENAME_LEN);

        offset += size;
    }

    //Update backup size
    backup->size += totalSize;
}

/* Function to restore files from backup */
void restoreBackup(struct Backup* backup) {
    //Create directory to store restored files
    char dirname[MAX_FILENAME_LEN] = "restored_backup";
    mkdir(dirname);

    //Restore files from backup
    for(int i = 0; i < backup->numFiles; i++) {
        char filepath[MAX_FILENAME_LEN];
        snprintf(filepath, MAX_FILENAME_LEN, "%s/%s", dirname, backup->files[i].filename);

        FILE* file = fopen(filepath, "wb");
        if(file == NULL) {
            printf("Error: Could not create file %s\n", backup->files[i].filename);
            return;
        }

        fwrite(backup->files[i].data, 1, backup->files[i].size, file);
        fclose(file);
    }
}

/* Function to print backup information */
void printBackupInfo(struct Backup* backup) {
    printf("Number of files in backup: %d\n", backup->numFiles);
    printf("Size of backup: %d bytes\n", backup->size);

    for(int i = 0; i < backup->numFiles; i++) {
        printf("File %d:\n", i + 1);
        printf("\tFilename: %s\n", backup->files[i].filename);
        printf("\tSize: %d bytes\n", backup->files[i].size);
    }
}