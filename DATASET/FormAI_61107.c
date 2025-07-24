//FormAI DATASET v1.0 Category: File Backup System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_NAME 50

struct FileInfo {
    char name[MAX_FILE_NAME];
    time_t creationTime;
};

struct Backup {
    struct FileInfo files[MAX_FILES];
    int numFiles;
};

void addFile(struct Backup *backup, char *name) {
    int i;
    for (i = 0; i < backup->numFiles; i++) {
        if (strcmp(backup->files[i].name, name) == 0) {
            printf("Error: file %s already exists in backup!\n", name);
            return;
        }
    }

    if (backup->numFiles == MAX_FILES) {
        printf("Error: backup is full!\n");
        return;
    }

    struct FileInfo newFile;
    strcpy(newFile.name, name);
    newFile.creationTime = time(NULL);
    backup->files[backup->numFiles] = newFile;
    backup->numFiles++;

    printf("File %s added to backup.\n", name);
}

void removeFile(struct Backup *backup, char *name) {
    int i;
    for (i = 0; i < backup->numFiles; i++) {
        if (strcmp(backup->files[i].name, name) == 0) {
            backup->numFiles--;
            backup->files[i] = backup->files[backup->numFiles];
            printf("File %s removed from backup.\n", name);
            return;
        }
    }

    printf("Error: file %s not found in backup!\n", name);
}

void printFiles(struct Backup *backup) {
    printf("Files in backup:\n");
    int i;
    for (i = 0; i < backup->numFiles; i++) {
        printf("%s (created on %s)", backup->files[i].name, ctime(&backup->files[i].creationTime));
    }
}

int main() {
    struct Backup backup;
    backup.numFiles = 0;

    char input[MAX_FILE_NAME + 10];
    char *command, *fileName;

    printf("*** Medieval C File Backup System ***\n");
    printf("Commands:\n");
    printf("  add <file_name>\n");
    printf("  remove <file_name>\n");
    printf("  list\n");
    printf("  exit\n");
    printf("\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_FILE_NAME + 10, stdin);
        command = strtok(input, " \n");
        if (command == NULL) continue;

        fileName = strtok(NULL, " \n");
        if (fileName == NULL && strcmp(command, "list") != 0 && strcmp(command, "exit") != 0) {
            printf("Error: file name not specified!\n");
            continue;
        }

        if (strcmp(command, "add") == 0) {
            addFile(&backup, fileName);
        } else if (strcmp(command, "remove") == 0) {
            removeFile(&backup, fileName);
        } else if (strcmp(command, "list") == 0) {
            printFiles(&backup);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Error: invalid command %s!\n", command);
        }
    }

    return 0;
}