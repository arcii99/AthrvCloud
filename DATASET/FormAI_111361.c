//FormAI DATASET v1.0 Category: File system simulation ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define BLOCKSIZE 512
#define NUMBLOCKS 4096
#define INODESIZE 64
#define NUMINODES 256

typedef struct inode {
    char *name;
    int size;
    int blocks[8];
} inode;

typedef struct file_system {
    int free_blocks[NUMBLOCKS];
    inode inodes[NUMINODES];
} file_system;

void create_file_system(int fd) {
    file_system fs;
    int i, j;

    // initialize all blocks to free
    for(i=0; i<NUMBLOCKS; ++i) {
        fs.free_blocks[i] = 1;
    }

    // initialize all inodes
    for(i=0; i<NUMINODES; ++i) {
        fs.inodes[i].name = NULL;
        fs.inodes[i].size = 0;
        for(j=0; j<8; ++j) {
            fs.inodes[i].blocks[j] = -1;
        }
    }

    // write file system to disk
    lseek(fd, 0, SEEK_SET);
    write(fd, &fs, sizeof(file_system));
}

int main(int argc, char *argv[]) {
    int fd = open("my_fs", O_RDWR | O_CREAT, 0666);
    create_file_system(fd);

    // simulate file creation
    inode new_file;
    new_file.name = "file.txt";
    new_file.size = 10;
    new_file.blocks[0] = 100;

    // write inode to disk
    lseek(fd, sizeof(int) * NUMBLOCKS, SEEK_SET);
    write(fd, &new_file, sizeof(inode));
    close(fd);

    return 0;
}