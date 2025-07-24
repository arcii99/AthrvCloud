//FormAI DATASET v1.0 Category: File system simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 256
#define NUM_BLOCKS 4096

typedef struct file_t {
    char name[32];
    int size;
    int start_block;
} file_t;

int file_count = 0;
file_t files[NUM_BLOCKS];

char blocks[NUM_BLOCKS][BLOCK_SIZE];
int block_map[NUM_BLOCKS] = {0};

void create_file(char *name, int size) {
    if (file_count == NUM_BLOCKS) {
        printf("Error: File system is full\n");
        return;
    }
    int i;
    for (i = 0; i < NUM_BLOCKS; i++) {
        if (block_map[i] == 0) {
            int j;
            for (j = i; j < i + size / BLOCK_SIZE + 1; j++) {
                if (block_map[j] == 1 || j >= NUM_BLOCKS) {
                    printf("Error: Not enough contiguous blocks for file\n");
                    return;
                }
            }
            strcpy(files[file_count].name, name);
            files[file_count].size = size;
            files[file_count].start_block = i;
            for (j = i; j < i + size / BLOCK_SIZE + 1; j++) {
                block_map[j] = 1;
            }
            file_count++;
            printf("File created successfully\n");
            return;
        }
    }
}

void delete_file(char *name) {
    int i;
    for (i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, name) == 0) {
            int j;
            for (j = files[i].start_block; j < files[i].start_block + files[i].size / BLOCK_SIZE + 1; j++) {
                block_map[j] = 0;
            }
            int k;
            for (k = i; k < file_count; k++) {
                files[k] = files[k + 1];
            }
            file_count--;
            printf("File deleted successfully\n");
            return;
        }
    }
    printf("Error: File not found\n");
}

void read_file(char *name) {
    int i;
    for (i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("Contents of file '%s':\n", name);
            int j;
            for (j = files[i].start_block; j < files[i].start_block + files[i].size / BLOCK_SIZE + 1; j++) {
                printf("%s", blocks[j]);
            }
            return;
        }
    }
    printf("Error: File not found\n");
}

void write_file(char *name, char *data, int size) {
    int i;
    for (i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, name) == 0) {
            int j;
            int block_offset = 0;
            for (j = files[i].start_block; j < files[i].start_block + files[i].size / BLOCK_SIZE + 1; j++) {
                if (block_offset + BLOCK_SIZE < size) {
                    memcpy(blocks[j], data + block_offset, BLOCK_SIZE);
                } else {
                    memcpy(blocks[j], data + block_offset, size - block_offset);
                }
                block_offset += BLOCK_SIZE;
            }
            printf("File written successfully\n");
            return;
        }
    }
    printf("Error: File not found\n");
}

int main() {
    printf("Welcome to the file system simulator\n");
    while (1) {
        printf("> ");
        char input[256];
        fgets(input, 256, stdin);
        if (strncmp(input, "create", 6) == 0) {
            char filename[32];
            int size;
            sscanf(input, "create %s %d", filename, &size);
            create_file(filename, size);
        } else if (strncmp(input, "delete", 6) == 0) {
            char filename[32];
            sscanf(input, "delete %s", filename);
            delete_file(filename);
        } else if (strncmp(input, "read", 4) == 0) {
            char filename[32];
            sscanf(input, "read %s", filename);
            read_file(filename);
        } else if (strncmp(input, "write", 5) == 0) {
            char filename[32];
            char data[256];
            int size;
            sscanf(input, "write %s %s %d", filename, data, &size);
            write_file(filename, data, size);
        } else if (strncmp(input, "exit", 4) == 0) {
            printf("Exiting file system simulator\n");
            return 0;
        } else {
            printf("Invalid command\n");
        }
    }
}