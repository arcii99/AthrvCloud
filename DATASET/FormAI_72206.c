//FormAI DATASET v1.0 Category: File system simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILES 100
#define FILENAME_LEN 20
#define MAX_DISK_SPACE 10000
#define BLOCK_SIZE 100

typedef struct {
    char filename[FILENAME_LEN];
    int inode;
} file;

typedef struct {
    int block_number;
    int block_size;
} inode;

int disk_space[MAX_DISK_SPACE];
file file_table[MAX_FILES];
inode inode_db[MAX_FILES];
int num_files = 0;
int num_inodes = 0;

void create_file(char* filename) {
    if(num_files >= MAX_FILES) {
        printf("Cannot create file, maximum number of files reached.\n");
        return;
    }

    for(int i = 0; i < num_files; i++) {
        if(strcmp(file_table[i].filename, filename) == 0) {
            printf("File already exists.\n");
            return;
        }
    }

    file new_file;
    strcpy(new_file.filename, filename);
    new_file.inode = num_inodes;

    file_table[num_files] = new_file;

    inode new_inode;
    new_inode.block_number = num_inodes * BLOCK_SIZE;
    new_inode.block_size = BLOCK_SIZE;

    inode_db[num_inodes] = new_inode;

    num_files++;
    num_inodes++;
}

void write_to_file(char* filename, char* data, int data_len) {
    int index = -1;
    for(int i = 0; i < num_files; i++) {
        if(strcmp(file_table[i].filename, filename) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("File not found.\n");
        return;
    }

    int inode_num = file_table[index].inode;
    inode file_inode = inode_db[inode_num];

    if(data_len > file_inode.block_size) {
        printf("Data too large to write to file.\n");
        return;
    }

    for(int i = 0; i < file_inode.block_size; i++) {
        if(i < data_len) {
            disk_space[file_inode.block_number + i] = data[i];
        } else {
            disk_space[file_inode.block_number + i] = 0;
        }
    }

    printf("Data written to file.\n");
}

void read_file(char* filename) {
    int index = -1;
    for(int i = 0; i < num_files; i++) {
        if(strcmp(file_table[i].filename, filename) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("File not found.\n");
        return;
    }

    int inode_num = file_table[index].inode;
    inode file_inode = inode_db[inode_num];

    char data[file_inode.block_size];

    for(int i = 0; i < file_inode.block_size; i++) {
        data[i] = disk_space[file_inode.block_number + i];
    }

    printf("Data in file: %s\n", data);
}

int main() {
    create_file("hello.txt");
    write_to_file("hello.txt", "Hello World!", 12);
    read_file("hello.txt");

    return 0;
}