//FormAI DATASET v1.0 Category: File system simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 20
#define MAX_FILENAME 20
#define BLOCK_SIZE 512
#define MAX_BLOCKS 10000

typedef struct _file {
    char name[MAX_FILENAME];
    int size;
    int block_number;
    int block_count;
} file;

file files[MAX_FILES];
char file_system[MAX_BLOCKS * BLOCK_SIZE];

void create_file(char* filename, int size) {
    int index = 0;
    int block_count = 0;
    int blocks_required = size / BLOCK_SIZE;
    if (size % BLOCK_SIZE != 0) {
        blocks_required++;
    }
    if (blocks_required > MAX_BLOCKS) {
        printf("File size is too large.\n");
        return;
    }
    while (index < MAX_BLOCKS) {
        if (file_system[index*BLOCK_SIZE] == '\0') {
            int i = index + 1;
            while (i < MAX_BLOCKS && file_system[i*BLOCK_SIZE] == '\0' && block_count < blocks_required) {
                i++;
            }
            if (block_count < blocks_required) {
                continue;
            }
            for (int j = index; j < index + blocks_required; j++) {
                file_system[j*BLOCK_SIZE] = '1';
            }
            strcpy(files[MAX_FILES - 1].name, filename);
            files[MAX_FILES - 1].size = size;
            files[MAX_FILES - 1].block_number = index;
            files[MAX_FILES - 1].block_count = blocks_required;
            return;
        }
        index++;
    }
    printf("The file system is full, cannot create file.\n");
}

void delete_file(char* filename) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(files[i].name, filename) == 0) {
            for (int j = files[i].block_number; j < files[i].block_number + files[i].block_count; j++) {
                file_system[j*BLOCK_SIZE] = '\0';
            }
            strcpy(files[i].name, "");
            files[i].size = 0;
            files[i].block_number = 0;
            files[i].block_count = 0;
            return;
        }
    }
    printf("File not found.\n");
}

void list_files() {
    printf("%-20s%-10s%-20s\n", "Name", "Size", "Location");
    for (int i = 0; i < MAX_FILES; i++) {
        if (strlen(files[i].name) > 0) {
            printf("%-20s%-10d%-15d,%d\n", files[i].name, files[i].size, files[i].block_number, files[i].block_count);
        }
    }
}

int main() {
    memset(file_system, '\0', sizeof(file_system));
    memset(files, '\0', sizeof(files));
    create_file("file1", 1024);
    create_file("file2", 2048);
    create_file("file3", 512);
    list_files();
    delete_file("file2");
    list_files();
    create_file("file4", 4096);
    list_files();
    create_file("file5", 32768);
    create_file("file6", 16384);
    return 0;
}