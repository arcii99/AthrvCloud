//FormAI DATASET v1.0 Category: File system simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 20
#define MAX_FILE_COUNT 10
#define BLOCK_SIZE 512
#define MAX_BLOCK_COUNT 100

struct file {
    char name[MAX_FILE_NAME_SIZE];
    int start_block;
    int block_count;
};

struct block {
    char data[BLOCK_SIZE];
};

struct file_system {
    struct file files[MAX_FILE_COUNT];
    struct block blocks[MAX_BLOCK_COUNT];
    int file_count;
    int block_count;
};

void initialize_file_system(struct file_system *fs) {
    fs->file_count = 0;
    fs->block_count = 0;
}

int create_file(struct file_system *fs, const char *name, int blocks) {
    if (fs->file_count == MAX_FILE_COUNT) {
        return -1;
    }
    if (fs->block_count + blocks > MAX_BLOCK_COUNT) {
        return -2;
    }
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            return -3;
        }
    }
    int start_block = fs->block_count;
    struct file new_file = {
        .start_block = start_block,
        .block_count = blocks
    };
    strncpy(new_file.name, name, MAX_FILE_NAME_SIZE);
    fs->files[fs->file_count] = new_file;
    fs->file_count++;
    fs->block_count += blocks;
    return 0;
}

int delete_file(struct file_system *fs, const char *name) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            int blocks = fs->files[i].block_count;
            int start_block = fs->files[i].start_block;
            for (int j = start_block; j < start_block + blocks; j++) {
                memset(fs->blocks[j].data, 0, BLOCK_SIZE);
            }
            for (int j = i + 1; j < fs->file_count; j++) {
                fs->files[j - 1] = fs->files[j];
            }
            fs->file_count--;
            fs->block_count -= blocks;
            return 0;
        }
    }
    return -1;
}

int write_file(struct file_system *fs, const char *name, const char *data, int size) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            int blocks = fs->files[i].block_count;
            int start_block = fs->files[i].start_block;
            int bytes_left = blocks * BLOCK_SIZE;
            for (int j = start_block; j < start_block + blocks && size > 0; j++) {
                int bytes_to_write = size < BLOCK_SIZE - bytes_left % BLOCK_SIZE ? size : BLOCK_SIZE - bytes_left % BLOCK_SIZE;
                strncpy(fs->blocks[j].data + bytes_left % BLOCK_SIZE, data, bytes_to_write);
                data += bytes_to_write;
                size -= bytes_to_write;
                bytes_left -= bytes_to_write;
            }
            return size == 0 ? 0 : -2;
        }
    }
    return -1;
}

int read_file(struct file_system *fs, const char *name, char *buffer, int size) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            int blocks = fs->files[i].block_count;
            int start_block = fs->files[i].start_block;
            int bytes_left = blocks * BLOCK_SIZE;
            for (int j = start_block; j < start_block + blocks && size > 0; j++) {
                int bytes_to_read = size < BLOCK_SIZE - bytes_left % BLOCK_SIZE ? size : BLOCK_SIZE - bytes_left % BLOCK_SIZE;
                strncat(buffer, fs->blocks[j].data + bytes_left % BLOCK_SIZE, bytes_to_read);
                size -= bytes_to_read;
                bytes_left -= bytes_to_read;
            }
            return size == 0 ? 0 : -2;
        }
    }
    return -1;
}

int main() {
    struct file_system fs;
    initialize_file_system(&fs);
    create_file(&fs, "file1", 5);
    create_file(&fs, "file2", 3);
    char buffer[1000] = {0};
    write_file(&fs, "file1", "Hello World", 11);
    write_file(&fs, "file2", "Lorem ipsum", 11);
    read_file(&fs, "file1", buffer, 11);
    printf("%s\n", buffer);
    read_file(&fs, "file2", buffer, 11);
    printf("%s\n", buffer);
    delete_file(&fs, "file1");
    delete_file(&fs, "file2");
    return 0;
}