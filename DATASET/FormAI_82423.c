//FormAI DATASET v1.0 Category: File Backup System ; Style: retro
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// define constants for file and directory names and backup directory
#define FILENAME "data.txt"
#define DIRNAME "backup"
#define BKUPDIRNAME "backup/old"

// function to create backup directory
void createDir(char *dirName) {
    char command[100];
    sprintf(command, "mkdir %s", dirName);
    system(command);
}

// function to create backup file with timestamp in backup directory
void backup(char *dirName, char *fileName) {
    char command[100], timestamp[20];
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", tm);
    sprintf(command, "cp %s/%s %s/%s_%s", dirName, fileName, BKUPDIRNAME, fileName, timestamp);
    system(command);
}

int main() {
    int choice;
    char command[100];

    while(1) {
        // print menu
        printf("=======================\n");
        printf("C File Backup System\n");
        printf("=======================\n");
        printf("1. Create backup directory\n");
        printf("2. Backup file\n");
        printf("3. Exit\n");
        printf("=======================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // create backup directory if not present
                sprintf(command, "test -d %s || mkdir %s", DIRNAME, DIRNAME);
                system(command);
                printf("Backup directory created successfully!\n");
                break;

            case 2:
                // create backup directory if not present
                sprintf(command, "test -d %s || mkdir %s", DIRNAME, DIRNAME);
                system(command);

                // create old backup directory if not present
                sprintf(command, "test -d %s || mkdir %s", BKUPDIRNAME, BKUPDIRNAME);
                system(command);

                // perform backup
                backup(DIRNAME, FILENAME);
                printf("File backup created successfully!\n");
                break;

            case 3:
                // exit program
                printf("Exiting program...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}