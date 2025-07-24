//FormAI DATASET v1.0 Category: File system simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_NAME 20

typedef struct file {
    char* fileName;
    int fileSize;
    bool isUsed;
} File;

int totalDiskSpace = 100;
int remainingDiskSpace = 100;
File fileSystem[MAX_FILES];

void initFileSystem() {
    for (int i = 0; i < MAX_FILES; i++) {
        fileSystem[i].fileName = malloc(MAX_FILE_NAME);
        fileSystem[i].fileSize = 0;
        fileSystem[i].isUsed = false;
    }
}

void displayMenu() {
    printf("Welcome to File System Simulation!\n");
    printf("1. List files\n");
    printf("2. Create new file\n");
    printf("3. Delete file\n");
    printf("4. Exit\n");
}

void listFiles() {
    printf("List of files:\n");
    for (int i = 0; i < MAX_FILES; i++) {
        if (fileSystem[i].isUsed) {
            printf("%d. %s - %d KB\n", i+1, fileSystem[i].fileName, fileSystem[i].fileSize);
        }
    }
}

void createFile() {
    char* fileName = malloc(MAX_FILE_NAME);
    int fileSize;

    printf("Enter file name (max 20 characters): ");
    scanf("%s", fileName);

    printf("Enter file size (in KB): ");
    scanf("%d", &fileSize);

    if (fileSize > remainingDiskSpace) {
        printf("Not enough disk space remaining\n");
        return;
    }

    for (int i = 0; i < MAX_FILES; i++) {
        if (!fileSystem[i].isUsed) {
            strcpy(fileSystem[i].fileName, fileName);
            fileSystem[i].fileSize = fileSize;
            fileSystem[i].isUsed = true;
            remainingDiskSpace -= fileSize;
            printf("%s created successfully!\n", fileName);
            break;
        }
    }
}

void deleteFile() {
    int fileIndex;

    printf("Enter file index to delete: ");
    scanf("%d", &fileIndex);
    fileIndex--;

    if (!fileSystem[fileIndex].isUsed) {
        printf("File does not exist\n");
        return;
    }

    printf("%s deleted successfully!\n", fileSystem[fileIndex].fileName);
    remainingDiskSpace += fileSystem[fileIndex].fileSize;
    fileSystem[fileIndex].fileName = "";
    fileSystem[fileIndex].fileSize = 0;
    fileSystem[fileIndex].isUsed = false;
}

int main() {
    initFileSystem();

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                listFiles();
                break;
            case 2:
                createFile();
                break;
            case 3:
                deleteFile();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while(choice != 4);

    return 0;
}