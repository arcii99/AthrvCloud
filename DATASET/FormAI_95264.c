//FormAI DATASET v1.0 Category: File system simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 4096
#define MAX_FILE_SIZE 1048576
#define MAX_FILES 100

struct file {
    char name[20];
    int size;
    int block_count;
    int blocks[256];
};

char filesystem[MAX_FILE_SIZE];
int filesystem_size = 0;
struct file directory[MAX_FILES];
int num_files = 0;

void format() {
    memset(filesystem, 0, MAX_FILE_SIZE);
    filesystem_size = 0;
    num_files = 0;
}

int get_free_block() {
    for (int i = 0; i < MAX_FILE_SIZE; i += BLOCK_SIZE) {
        if (!memcmp(&filesystem[i], "\0", 1)) {
            return i;
        }
    }
    return -1;
}

void save_file(int index, char* data, int size) {
    memcpy(&filesystem[index], data, size);
}

int create_file(char* name, char* data, int size) {
    int total_blocks = (size / BLOCK_SIZE) + 1;
    if (filesystem_size + (total_blocks * BLOCK_SIZE) > MAX_FILE_SIZE) {
        printf("Error: Not enough space in filesystem\n");
        return -1;
    }
    int file_index = get_free_block();
    directory[num_files].size = size;
    directory[num_files].block_count = total_blocks;
    directory[num_files].blocks[0] = file_index;
    memcpy(directory[num_files].name, name, strlen(name));
    save_file(file_index, data, BLOCK_SIZE);
    for (int i = 1; i < total_blocks; i++) {
        int block_index = get_free_block();
        directory[num_files].blocks[i] = block_index;
        save_file(block_index, &data[i * BLOCK_SIZE], BLOCK_SIZE);
    }
    filesystem_size += total_blocks * BLOCK_SIZE;
    num_files++;
    return 0;
}

int read_file(char* name, char* buffer) {
    for (int i = 0; i < num_files; i++) {
        if (!strcmp(directory[i].name, name)) {
            int size = directory[i].size;
            memcpy(buffer, &filesystem[directory[i].blocks[0]], BLOCK_SIZE);
            for (int j = 1; j < directory[i].block_count; j++) {
                memcpy(buffer + (j * BLOCK_SIZE), &filesystem[directory[i].blocks[j]], BLOCK_SIZE);
            }
            return size;
        }
    }
    return -1;
}

int main() {
    format();
    char data[] = "Hello World!";
    char buffer[MAX_FILE_SIZE];
    create_file("test.txt", data, strlen(data));
    read_file("test.txt", buffer);
    printf("File contents: %s\n", buffer);
    return 0;
}