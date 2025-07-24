//FormAI DATASET v1.0 Category: File system simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define MAX_BLOCKS 4096

typedef struct {
    char *filename;
    int start_block;
    int num_blocks;
} File;

char *disk[MAX_BLOCKS];
File *files[MAX_BLOCKS];
int num_files = 0;

void initialize_disk() {
    int i;
    for (i = 0; i < MAX_BLOCKS; i++) {
        disk[i] = malloc(BLOCK_SIZE);
    }
}

void create_file(char *filename, int size) {
    int i, j, blocks_needed;
    blocks_needed = size / BLOCK_SIZE + 1;
    for (i = 0; i < MAX_BLOCKS - blocks_needed; i++) {
        for (j = i; j < i + blocks_needed; j++) {
            if (disk[j] != NULL) {
                break;
            }
        }
        if (j == i + blocks_needed) {
            File *new_file = malloc(sizeof(File));
            new_file->filename = filename;
            new_file->start_block = i;
            new_file->num_blocks = blocks_needed;
            for (j = i; j < i + blocks_needed; j++) {
                disk[j] = malloc(BLOCK_SIZE);
            }
            files[num_files++] = new_file;
            printf("File created successfully!\n");
            return;
        }
    }
    printf("Could not create file, not enough space!\n");
}

void delete_file(char *filename) {
    int i, j;
    File *file = NULL;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i]->filename, filename) == 0) {
            file = files[i];
            break;
        }
    }
    if (file == NULL) {
        printf("File not found!\n");
        return;
    }
    for (i = file->start_block; i < file->start_block + file->num_blocks; i++) {
        free(disk[i]);
        disk[i] = NULL;
    }
    for (i = 0; i < num_files; i++) {
        if (files[i] == file) {
            for (j = i; j < num_files - 1; j++) {
                files[j] = files[j + 1];
            }
            num_files--;
            free(file);
            break;
        }
    }
    printf("File deleted successfully!\n");
}

void read_file(char *filename) {
    int i;
    File *file = NULL;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i]->filename, filename) == 0) {
            file = files[i];
            break;
        }
    }
    if (file == NULL) {
        printf("File not found!\n");
        return;
    }
    for (i = file->start_block; i < file->start_block + file->num_blocks; i++) {
        printf("%s", disk[i]);
    }
}

void write_file(char *filename, char *data) {
    int i;
    File *file = NULL;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i]->filename, filename) == 0) {
            file = files[i];
            break;
        }
    }
    if (file == NULL) {
        printf("File not found!\n");
        return;
    }
    int data_len = strlen(data);
    int blocks_needed = data_len / BLOCK_SIZE + 1;
    if (blocks_needed > file->num_blocks) {
        printf("Not enough space to write file!\n");
        return;
    }
    int start_block = file->start_block;
    int j;
    for (i = 0; i < data_len; i += BLOCK_SIZE) {
        char *block_start = disk[start_block];
        for (j = 0; j < BLOCK_SIZE && i + j < data_len; j++) {
            block_start[j] = data[i + j];
        }
        start_block++;
    }
    printf("File written successfully!\n");
}

int main() {
    initialize_disk();
    create_file("file1.txt", 2048);
    write_file("file1.txt", "This is the contents of file1.txt. It is a test file.");
    read_file("file1.txt");
    delete_file("file1.txt");
    return 0;
}