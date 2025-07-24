//FormAI DATASET v1.0 Category: File system simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 8192
#define BLOCK_COUNT 1024

// represents a block in the file system
typedef struct block {
    char data[BLOCK_SIZE];
} block_t;

// represents a file in the file system
typedef struct file {
    char name[32];
    int size;
    int block_ids[1024];
    int block_count;
} file_t;

// represents the file system
typedef struct file_system {
    block_t blocks[BLOCK_COUNT];
    file_t files[1024];
    int file_count;
} file_system_t;

// initializes the file system
void init_file_system(file_system_t* fs) {
    fs->file_count = 0;
    for (int i = 0; i < BLOCK_COUNT; ++i) {
        memset(fs->blocks[i].data, 0, BLOCK_SIZE);
    }
}

// creates a new file in the file system
int create_file(file_system_t* fs, const char* name, int size) {
    if (fs->file_count >= 1024 || size > BLOCK_COUNT) {
        return -1;
    }
    file_t file;
    strcpy(file.name, name);
    file.size = size;
    file.block_count = 0;
    int used_blocks = 0;
    for (int i = 0; i < BLOCK_COUNT; ++i) {
        if (used_blocks >= size) {
            break;
        }
        if (fs->blocks[i].data[0] == '\0') {
            file.block_ids[file.block_count++] = i;
            used_blocks++;
        }
    }
    if (used_blocks < size) {
        return -1;
    }
    memcpy(fs->files + fs->file_count, &file, sizeof(file_t));
    fs->file_count++;
    return 0;
}

// writes data to a file in the file system
int write_file(file_system_t* fs, const char* name, const char* data) {
    for (int i = 0; i < fs->file_count; ++i) {
        if (strcmp(fs->files[i].name, name) == 0) {
            int index = 0;
            int written = 0;
            for (int j = 0; j < fs->files[i].block_count; ++j) {
                memcpy(fs->blocks[fs->files[i].block_ids[j]].data, data + index, BLOCK_SIZE);
                written += BLOCK_SIZE;
                index += BLOCK_SIZE;
                if (written >= fs->files[i].size) {
                    break;
                }
            }
            return 0;
        }
    }
    return -1;
}

// reads data from a file in the file system
int read_file(file_system_t* fs, const char* name, char* data) {
    for (int i = 0; i < fs->file_count; ++i) {
        if (strcmp(fs->files[i].name, name) == 0) {
            int index = 0;
            int read = 0;
            for (int j = 0; j < fs->files[i].block_count; ++j) {
                memcpy(data + index, fs->blocks[fs->files[i].block_ids[j]].data, BLOCK_SIZE);
                read += BLOCK_SIZE;
                index += BLOCK_SIZE;
                if (read >= fs->files[i].size) {
                    break;
                }
            }
            return 0;
        }
    }
    return -1;
}

int main() {
    file_system_t fs;
    init_file_system(&fs);
    int ret = create_file(&fs, "test.txt", 100000);
    if (ret == -1) {
        printf("Failed to create file.\n");
        return 1;
    }
    char data[100000] = "Hello, world!";
    write_file(&fs, "test.txt", data);
    char read_data[100000];
    read_file(&fs, "test.txt", read_data);
    if (strcmp(data, read_data) != 0) {
        printf("Data read from file does not match.\n");
        return 1;
    }
    printf("File system is working correctly.\n");
    return 0;
}