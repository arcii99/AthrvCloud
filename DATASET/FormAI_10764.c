//FormAI DATASET v1.0 Category: File system simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024
#define MAX_BLOCKS 1024

struct block {
    char data[BLOCK_SIZE];
};

struct file {
    char name[20];
    int blocks[MAX_BLOCKS];
    int size;
    int allocated_blocks;
};

struct file_system {
    struct block blocks[MAX_BLOCKS];
    int free_blocks[MAX_BLOCKS];
    int num_free_blocks;
    struct file files[MAX_BLOCKS];
    int num_files;
};

void init_file_system(struct file_system *fs) {
    int i;
    for (i = 0; i < MAX_BLOCKS; i++) {
        fs->free_blocks[i] = i;
        fs->blocks[i] = (struct block) {0};
    }
    fs->num_free_blocks = MAX_BLOCKS;
    fs->num_files = 0;
}

int allocate_block(struct file_system *fs) {
    if (fs->num_free_blocks == 0) {
        return -1;
    }
    int block_num = fs->free_blocks[--fs->num_free_blocks];
    return block_num;
}

void free_block(struct file_system *fs, int block_num) {
    fs->free_blocks[fs->num_free_blocks++] = block_num;
}

int create_file(struct file_system *fs, char *name) {
    if (fs->num_files == MAX_BLOCKS) {
        return -1;
    }
    int file_id = fs->num_files++;
    struct file *f = &fs->files[file_id];
    strncpy(f->name, name, sizeof(f->name));
    f->size = 0;
    f->allocated_blocks = 0;
    return file_id;
}

int write_file(struct file_system *fs, int file_id, char *data, int size) {
    struct file *f = &fs->files[file_id];
    int num_blocks_needed = (size + (BLOCK_SIZE - 1)) / BLOCK_SIZE;
    int i;
    for (i = f->allocated_blocks; i < num_blocks_needed; i++) {
        int block_num = allocate_block(fs);
        if (block_num == -1) {
            return -1;
        }
        f->blocks[i] = block_num;
        f->allocated_blocks++;
    }
    f->size = size;
    int bytes_written = 0;
    for (i = 0; i < num_blocks_needed; i++) {
        struct block *b = &fs->blocks[f->blocks[i]];
        int bytes_to_write = size - bytes_written;
        if (bytes_to_write > BLOCK_SIZE) {
            bytes_to_write = BLOCK_SIZE;
        }
        strncpy(b->data, data + bytes_written, bytes_to_write);
        bytes_written += bytes_to_write;
    }
    return bytes_written;
}

int read_file(struct file_system *fs, int file_id, char *data, int size) {
    struct file *f = &fs->files[file_id];
    if (size < f->size) {
        return -1;
    }
    int bytes_read = 0;
    int i;
    for (i = 0; i < f->allocated_blocks; i++) {
        struct block *b = &fs->blocks[f->blocks[i]];
        int bytes_to_read = f->size - bytes_read;
        if (bytes_to_read > BLOCK_SIZE) {
            bytes_to_read = BLOCK_SIZE;
        }
        strncpy(data + bytes_read, b->data, bytes_to_read);
        bytes_read += bytes_to_read;
    }
    return bytes_read;
}

int main() {
    struct file_system fs;
    init_file_system(&fs);
    int file_id = create_file(&fs, "example.txt");
    if (file_id == -1) {
        printf("Error: file system is full\n");
        return EXIT_FAILURE;
    }
    char data[] = "Hello, World!\n";
    int size = strlen(data);
    int bytes_written = write_file(&fs, file_id, data, size);
    if (bytes_written == -1) {
        printf("Error: not enough space in file system\n");
        return EXIT_FAILURE;
    }
    char buffer[MAX_BLOCKS * BLOCK_SIZE];
    int bytes_read = read_file(&fs, file_id, buffer, bytes_written);
    if (bytes_read == -1) {
        printf("Error: buffer not large enough to hold file\n");
        return EXIT_FAILURE;
    }
    printf("File contents: %s\n", buffer);
    return EXIT_SUCCESS;
}