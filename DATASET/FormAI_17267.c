//FormAI DATASET v1.0 Category: File system simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h> 

#define MAX_FILENAME_SIZE 100 
#define MAX_FILE_SIZE 1000 

typedef struct file {
    char filename[MAX_FILENAME_SIZE];
    char data[MAX_FILE_SIZE];
    int size;
    int isFree;
} File;

typedef struct filesystem {
    int totalSize;
    int numFiles;
    File files[MAX_FILE_SIZE];
} FileSystem;

void initFileSystem(FileSystem *fs) {
    fs->totalSize = MAX_FILE_SIZE * MAX_FILENAME_SIZE;
    fs->numFiles = 0;

    for (int i = 0; i < MAX_FILE_SIZE; i++) {
        fs->files[i].isFree = 1;
    }
}

void createFile(FileSystem *fs) {
    printf("Enter filename: ");
    scanf("%s", fs->files[fs->numFiles].filename);

    printf("Enter file content:\n");
    scanf("%s", fs->files[fs->numFiles].data);
    fs->files[fs->numFiles].size = sizeof(fs->files[fs->numFiles].data);

    fs->numFiles++;
}

void displayFiles(FileSystem fs) {
    printf("Filesystem contains:\n");

    for (int i = 0; i < fs.numFiles; i++) {
        printf("%d: %s\n", i+1, fs.files[i].filename);
    }

    if (fs.numFiles == 0) {
        printf("No files found.\n");
    }
}

void deleteFile(FileSystem *fs) {
    int index;
    displayFiles(*fs);
    printf("Enter the index of the file you want to delete: ");
    scanf("%d", &index);

    if (index <= fs->numFiles && index > 0) {
        for (int i = index - 1; i < fs->numFiles - 1; i++) {
            strcpy(fs->files[i].filename, fs->files[i+1].filename);
            strcpy(fs->files[i].data, fs->files[i+1].data);
            fs->files[i].size = fs->files[i+1].size;
            fs->files[i].isFree = fs->files[i+1].isFree;
        }

        fs->numFiles--;
        printf("File deleted.\n");
    } else {
        printf("Invalid index.\n");
    }
}

int main() {
    FileSystem fs;
    int choice;

    initFileSystem(&fs);

    do {
        printf("\n\nFilesystem Simulator Menu:\n");
        printf("1. Create a new file\n");
        printf("2. Display all files\n");
        printf("3. Delete a file\n");
        printf("4. Exit\n\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (fs.numFiles == MAX_FILE_SIZE) {
                    printf("Filesystem is full.\n");
                } else {
                    createFile(&fs);
                }
                break;
            case 2:
                displayFiles(fs);
                break;
            case 3:
                if (fs.numFiles == 0) {
                    printf("No files found.\n");
                } else {
                    deleteFile(&fs);
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}