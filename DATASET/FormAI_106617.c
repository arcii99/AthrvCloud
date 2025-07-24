//FormAI DATASET v1.0 Category: File system simulation ; Style: safe
#include<stdio.h>
#include<stdlib.h>

#define MAX_BLOCKS 100       // maximum number of blocks in file system
#define BLOCK_SIZE 4096      // block size of the file system
#define MAX_FILENAME 100     // maximum file name length

// structure of each file
struct file_node {
    char filename[MAX_FILENAME];    // name of the file
    int start_block;                // starting block of the file
    int size;                       // size of the file
};

// structure of file system
struct file_system {
    char blocks[MAX_BLOCKS][BLOCK_SIZE]; // data blocks in the file system
    int free_blocks[MAX_BLOCKS];         // free blocks in file system
    int n_free_blocks;                   // number of free blocks in file system
    struct file_node files[MAX_BLOCKS];  // files in the file system
    int n_files;                         // number of files in file system
};

// initialise file system
void init_file_system(struct file_system *fs) {
    int i;
    for(i = 0; i < MAX_BLOCKS; i++) {
        fs->free_blocks[i] = 1;
    }
    fs->n_free_blocks = MAX_BLOCKS;
    fs->n_files = 0;
}

// get next free block for data storage
int get_free_block(struct file_system *fs) {
    int i;
    for(i = 0; i < MAX_BLOCKS; i++) {
        if(fs->free_blocks[i] == 1) {
            fs->free_blocks[i] = 0;
            fs->n_free_blocks--;
            return i;
        }
    }
    return -1;
}

// read data block from file system
void read_block(struct file_system *fs, int block_num, char *buffer) {
    strncpy(buffer, fs->blocks[block_num], BLOCK_SIZE);
}

// write data block to file system
void write_block(struct file_system *fs, int block_num, const char *buffer) {
    strncpy(fs->blocks[block_num], buffer, BLOCK_SIZE);
}

// create file in file system
void create_file(struct file_system *fs, const char *filename, int size) {
    if(fs->n_free_blocks < size) {
        printf("Not enough free space in file system to create file\n");
        return;
    }
    int start_block = get_free_block(fs);
    int i;
    for(i = 1; i < size; i++) {
        get_free_block(fs);
    }
    struct file_node new_file;
    strncpy(new_file.filename, filename, MAX_FILENAME);
    new_file.start_block = start_block;
    new_file.size = size;
    fs->files[fs->n_files++] = new_file;
    printf("Created file %s with size %d starting at block %d\n", filename, size, start_block);
}

// delete file from file system
void delete_file(struct file_system *fs, const char *filename) {
    int i;
    for(i = 0; i < fs->n_files; i++) {
        if(strcmp(fs->files[i].filename, filename) == 0) {
            int j;
            for(j = 0; j < fs->files[i].size; j++) {
                fs->free_blocks[fs->files[i].start_block+j] = 1;
                fs->n_free_blocks++;
            }
            printf("Deleted file %s\n", filename);
            fs->n_files--;
            fs->files[i] = fs->files[fs->n_files];
            return;
        }
    }
    printf("File %s not found to delete\n", filename);
}

// read file from file system
void read_file(struct file_system *fs, const char *filename, char *buffer) {
    int i;
    for(i = 0; i < fs->n_files; i++) {
        if(strcmp(fs->files[i].filename, filename) == 0) {
            int j;
            for(j = 0; j < fs->files[i].size; j++) {
                char block_buffer[BLOCK_SIZE];
                read_block(fs, fs->files[i].start_block+j, block_buffer);
                strncpy(buffer+j*BLOCK_SIZE, block_buffer, BLOCK_SIZE);
            }
            printf("Read file %s into buffer\n", filename);
            return;
        }
    }
    printf("File %s not found to read\n", filename);
}

// write file to file system
void write_file(struct file_system *fs, const char *filename, const char *buffer) {
    int i;
    for(i = 0; i < fs->n_files; i++) {
        if(strcmp(fs->files[i].filename, filename) == 0) {
            if(fs->files[i].size*BLOCK_SIZE < strlen(buffer)) {
                printf("Not enough space in file %s to write\n", filename);
                return;
            }
            int j;
            for(j = 0; j < fs->files[i].size; j++) {
                char block_buffer[BLOCK_SIZE];
                strncpy(block_buffer, buffer+j*BLOCK_SIZE, BLOCK_SIZE);
                write_block(fs, fs->files[i].start_block+j, block_buffer);
            }
            printf("Wrote buffer to file %s\n", filename);
            return;
        }
    }
    printf("File %s not found to write\n", filename);
}

// display information about file system
void display_file_system(struct file_system *fs) {
    printf("File System Information:\n");
    printf(" Total blocks: %d\n Free blocks: %d\n", MAX_BLOCKS, fs->n_free_blocks);
    printf(" Files [%d]:\n", fs->n_files);
    int i;
    for(i = 0; i < fs->n_files; i++) {
        printf("  %s [%d blocks]\n", fs->files[i].filename, fs->files[i].size);
    }
}

int main() {
    struct file_system fs;
    init_file_system(&fs);
    create_file(&fs, "file1", 3);
    display_file_system(&fs);
    create_file(&fs, "file2", 2);
    display_file_system(&fs);
    delete_file(&fs, "file1");
    display_file_system(&fs);
    char buffer[BLOCK_SIZE*2];
    strncpy(buffer, "Hello, world!", BLOCK_SIZE*2);
    write_file(&fs, "file2", buffer);
    read_file(&fs, "file2", buffer);
    printf("Buffer contents: %s\n", buffer);
    return 0;
}