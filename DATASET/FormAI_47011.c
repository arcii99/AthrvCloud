//FormAI DATASET v1.0 Category: File system simulation ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCK_SIZE 1024
#define TOTAL_BLOCKS 100

struct superblock {
    int total_blocks;
    int free_blocks;
    int next_free_block;
};

struct inode {
    char file_name[100];
    int file_size;
    int block_number;
};

struct directory {
    struct inode files[50];
};

struct block {
    char data[BLOCK_SIZE];
    int next_block;
};

struct file_system {
    struct superblock sb;
    struct directory root_directory;
    struct block blocks[TOTAL_BLOCKS];
};

int create_file(struct file_system *fs, char *file_name, int file_size) {
    if(fs->sb.free_blocks == 0) {
        printf("Error: No free blocks left\n");
        return -1;
    }

    if(file_size > BLOCK_SIZE * fs->sb.free_blocks) {
        printf("Error: Not enough space to create file\n");
        return -1;
    }

    int block_index = fs->sb.next_free_block;
    fs->sb.free_blocks--;
    fs->sb.next_free_block++;
    strcpy(fs->root_directory.files[block_index].file_name, file_name);
    fs->root_directory.files[block_index].file_size = file_size;
    fs->root_directory.files[block_index].block_number = block_index;
    return 0;
}

int read_file(struct file_system *fs, char *file_name) {
    for(int i=0; i<TOTAL_BLOCKS; i++) {
        if(strcmp(fs->root_directory.files[i].file_name, file_name) == 0) {
            int block_number = fs->root_directory.files[i].block_number;
            while(block_number != -1) {
                printf("%s", fs->blocks[block_number].data);
                block_number = fs->blocks[block_number].next_block;
            }
            return 0;
        }
    }
    printf("Error: File not found\n");
    return -1;
}

int write_file(struct file_system *fs, char *file_name, char *data) {
    for(int i=0; i<TOTAL_BLOCKS; i++) {
        if(strcmp(fs->root_directory.files[i].file_name, file_name) == 0) {
            int block_number = fs->root_directory.files[i].block_number;
            int data_index = 0;
            while(block_number != -1) {
                strncpy(fs->blocks[block_number].data, &data[data_index], BLOCK_SIZE);
                data_index += BLOCK_SIZE;
                block_number = fs->blocks[block_number].next_block;
            }
            fs->root_directory.files[i].file_size = strlen(data);
            return 0;
        }
    }
    printf("Error: File not found\n");
    return -1;
}

int delete_file(struct file_system *fs, char *file_name) {
    for(int i=0; i<TOTAL_BLOCKS; i++) {
        if(strcmp(fs->root_directory.files[i].file_name, file_name) == 0) {
            int block_number = fs->root_directory.files[i].block_number;
            while(block_number != -1) {
                fs->sb.free_blocks++;
                int temp = block_number;
                block_number = fs->blocks[block_number].next_block;
                fs->blocks[temp].next_block = -1;
            }
            strcpy(fs->root_directory.files[i].file_name, "");
            fs->root_directory.files[i].file_size = 0;
            fs->root_directory.files[i].block_number = -1;
            return 0;
        }
    }
    printf("Error: File not found\n");
    return -1;
}

int main() {
    struct file_system fs;
    fs.sb.total_blocks = TOTAL_BLOCKS;
    fs.sb.free_blocks = TOTAL_BLOCKS;
    fs.sb.next_free_block = 0;
    for(int i=0; i<TOTAL_BLOCKS; i++) {
        memset(fs.blocks[i].data, 0, BLOCK_SIZE);
        fs.blocks[i].next_block = -1;
    }
    for(int i=0; i<50; i++) {
        strcpy(fs.root_directory.files[i].file_name, "");
        fs.root_directory.files[i].file_size = 0;
        fs.root_directory.files[i].block_number = -1;
    }
    create_file(&fs, "file1", 1024);
    create_file(&fs, "file2", 2048);
    write_file(&fs, "file1", "This is file1");
    write_file(&fs, "file2", "This is file2");
    read_file(&fs, "file1");
    read_file(&fs, "file2");
    delete_file(&fs, "file1");
    create_file(&fs, "file3", 512);
    create_file(&fs, "file4", 512);
    write_file(&fs, "file3", "This is file3");
    write_file(&fs, "file4", "This is file4");
    read_file(&fs, "file3");
    read_file(&fs, "file4");
    return 0;
}