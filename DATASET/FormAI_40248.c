//FormAI DATASET v1.0 Category: File system simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_BLOCKS 1024
#define MAX_FILENAME_LENGTH 32
#define MAX_FILE_SIZE 102400

struct file {
    char filename[MAX_FILENAME_LENGTH];
    int size;
    int block_ptr[MAX_FILE_BLOCKS];
};

struct directory_entry {
    char filename[MAX_FILENAME_LENGTH];
    int inode_number;
};

struct inode {
    struct file file_info;
    int in_use;
};

struct superblock {
    int num_inodes;
    int num_blocks;
    int free_inodes;
    int free_blocks[MAX_FILE_BLOCKS];
};

int get_free_inode(struct inode *inodes, int num_inodes) {
    for(int i=0; i<num_inodes; i++) {
        if(!inodes[i].in_use) {
            return i;
        }
    }
    return -1;
}

int get_free_block(struct superblock *sb) {
    for(int i=0; i<sb->num_blocks; i++) {
        if(sb->free_blocks[i]) {
            sb->free_blocks[i] = 0;
            return i;
        }
    }
    return -1;
}

int create_file(struct inode *inodes, struct directory_entry *dir, struct superblock *sb, char *filename) {
    int inode_number = get_free_inode(inodes, sb->num_inodes);
    if(inode_number == -1) {
        return -1;
    }

    int block_number = get_free_block(sb);
    if(block_number == -1) {
        return -1;
    }

    struct inode *inode = &inodes[inode_number];
    inode->in_use = 1;
    inode->file_info.size = 0;
    strcpy(inode->file_info.filename, filename);
    inode->file_info.block_ptr[0] = block_number;

    sb->free_inodes--;
    dir[inode_number].inode_number = inode_number;
    strcpy(dir[inode_number].filename, filename);

    return 1;
}

int delete_file(struct inode *inodes, struct directory_entry *dir, struct superblock *sb, char *filename) {
    for(int i=0; i<sb->num_inodes; i++) {
        if(inodes[i].in_use && strcmp(inodes[i].file_info.filename, filename)==0) {
            inodes[i].in_use = 0;
            int block_number = inodes[i].file_info.block_ptr[0];
            inodes[i].file_info.size = 0;
            sb->free_inodes++;
            sb->free_blocks[block_number] = 1;
            dir[i].inode_number = -1;
            strcpy(dir[i].filename, "");
            return 1;
        }
    }
    return -1;
}

int main() {
    struct inode inodes[100];
    struct directory_entry dir[100];
    struct superblock sb;

    sb.num_inodes = 100;
    sb.num_blocks = MAX_FILE_BLOCKS;
    sb.free_inodes = 100;

    for(int i=0; i<sb.num_blocks; i++) {
        sb.free_blocks[i] = 1;
    }

    create_file(inodes, dir, &sb, "file1");
    create_file(inodes, dir, &sb, "file2");
    create_file(inodes, dir, &sb, "file3");

    printf("Files in the directory:\n");
    for(int i=0; i<sb.num_inodes; i++) {
        if(dir[i].inode_number != -1) {
            printf("%s\n", dir[i].filename);
        }
    }

    delete_file(inodes, dir, &sb, "file2");

    printf("Files in the directory after delete:\n");
    for(int i=0; i<sb.num_inodes; i++) {
        if(dir[i].inode_number != -1) {
            printf("%s\n", dir[i].filename);
        }
    }

    return 0;
}