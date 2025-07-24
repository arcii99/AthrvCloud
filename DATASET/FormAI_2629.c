//FormAI DATASET v1.0 Category: File system simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_NAME_SIZE 20
#define BLOCK_SIZE 512
#define FILE_SIZE 1024

typedef struct {
    char name[MAX_FILE_NAME_SIZE];
    int length;
    int blocks[FILE_SIZE/BLOCK_SIZE];
} file;

void formatDisk(int *disk);
void createFile(int *disk, file *files, char *name, int length);
void deleteFile(int *disk, file *files, char *name);
void readFile(int *disk, file *files, char *name);
void writeFile(int *disk, file *files, char *name, char *data);

int main() {
    int disk[FILE_SIZE/BLOCK_SIZE] = {0};
    file files[MAX_FILES];

    formatDisk(disk);

    createFile(disk, files, "file1", 2);
    writeFile(disk, files, "file1", "Hello World!");
    readFile(disk, files, "file1");

    createFile(disk, files, "file2", 3);
    writeFile(disk, files, "file2", "How are you?");
    readFile(disk, files, "file2");

    deleteFile(disk, files, "file1");
    readFile(disk, files, "file1");
}

void formatDisk(int *disk) {
    for(int i = 0; i < FILE_SIZE/BLOCK_SIZE; i++) {
        *(disk + i) = 0;
    }
}

void createFile(int *disk, file *files, char *name, int length) {
    for(int i = 0; i < MAX_FILES; i++) {
        if(strlen(files[i].name) == 0) {
            strcpy(files[i].name, name);
            files[i].length = length;
            for(int j = 0; j < length; j++) {
                for(int k = 0; k < FILE_SIZE/BLOCK_SIZE; k++) {
                    if(*(disk + k) == 0) {
                        files[i].blocks[j] = k;
                        *(disk + k) = 1;
                        break;
                    }
                }
            }
            printf("Created file %s with length %d\n", name, length);
            return;
        }
    }
    printf("Error: Maximum files limit reached!\n");
}

void deleteFile(int *disk, file *files, char *name) {
    for(int i = 0; i < MAX_FILES; i++) {
        if(strcmp(files[i].name, name) == 0) {
            for(int j = 0; j < files[i].length; j++) {
                *(disk + files[i].blocks[j]) = 0;
            }
            strcpy(files[i].name, "");
            files[i].length = 0;
            printf("Deleted file %s\n", name);
            return;
        }
    }
    printf("Error: File %s not found!\n", name);
}

void readFile(int *disk, file *files, char *name) {
    for(int i = 0; i < MAX_FILES; i++) {
        if(strcmp(files[i].name, name) == 0) {
            printf("Content of file %s: ", name);
            for(int j = 0; j < files[i].length; j++) {
                for(int k = 0; k < BLOCK_SIZE; k++) {
                    printf("%c", *(disk + files[i].blocks[j]*BLOCK_SIZE + k));
                }
            }
            printf("\n");
            return;
        }
    }
    printf("Error: File %s not found!\n", name);
}

void writeFile(int *disk, file *files, char *name, char *data) {
    for(int i = 0; i < MAX_FILES; i++) {
        if(strcmp(files[i].name, name) == 0) {
            int dataIndex = 0;
            for(int j = 0; j < files[i].length; j++) {
                for(int k = 0; k < BLOCK_SIZE; k++) {
                    *(disk + files[i].blocks[j]*BLOCK_SIZE + k) = *(data + dataIndex++);
                }
            }
            printf("Wrote to file %s\n", name);
            return;
        }
    }
    printf("Error: File %s not found!\n", name);
}