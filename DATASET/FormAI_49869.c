//FormAI DATASET v1.0 Category: File system simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCKSIZE 512
#define MAX_FILENAME_LENGTH 255
#define MAX_BLOCKS 2000
#define MAX_FILES 500
#define BITMAP_BLOCKS 4
#define INODE_BLOCKS 16

char *diskfile;

typedef struct superBlock {
    int block_size;
    int num_blocks;
    int bitmap_blocks;
    int inode_blocks;
    int num_inodes;
    int first_block;
} superBlock;

typedef struct inode {
    int size;
    int blocks[10];
} inode;

typedef struct dirEntry {
    char filename[MAX_FILENAME_LENGTH];
    int inode_number;
} dirEntry;

typedef struct directory {
    dirEntry entries[MAX_FILES];
    int num_entries;
} directory;

void create_disk() {
    // Creates a 1 MB disk image file
    FILE *disk = fopen(diskfile, "wb");
    char empty_block[BLOCKSIZE] = {0};
    for (int i = 0; i < MAX_BLOCKS; i++) {
        fwrite(empty_block, sizeof(char), BLOCKSIZE, disk);
    }
    fclose(disk);
}

void write_superblock(superBlock *sb) {
    FILE *disk = fopen(diskfile, "rb+");
    fseek(disk, 0, SEEK_SET);
    fwrite(sb, sizeof(superBlock), 1, disk);
    fclose(disk);
}

superBlock *read_superblock() {
    superBlock *sb = malloc(sizeof(superBlock));
    FILE *disk = fopen(diskfile, "rb");
    fseek(disk, 0, SEEK_SET);
    fread(sb, sizeof(superBlock), 1, disk);
    fclose(disk);
    return sb;
}

void write_bitmap(int *bitmap) {
    FILE *disk = fopen(diskfile, "rb+");
    fseek(disk, sizeof(superBlock), SEEK_SET);
    fwrite(bitmap, sizeof(int), MAX_BLOCKS, disk);
    fclose(disk);
}

void read_bitmap(int *bitmap) {
    FILE *disk = fopen(diskfile, "rb");
    fseek(disk, sizeof(superBlock), SEEK_SET);
    fread(bitmap, sizeof(int), MAX_BLOCKS, disk);
    fclose(disk);
}

void write_inode(int inode_num, inode *node) {
    FILE *disk = fopen(diskfile, "rb+");
    fseek(disk, sizeof(superBlock) + BITMAP_BLOCKS*BLOCKSIZE + inode_num*sizeof(inode), SEEK_SET);
    fwrite(node, sizeof(inode), 1, disk);
    fclose(disk);
}

inode *read_inode(int inode_num) {
    inode *node = malloc(sizeof(inode));
    FILE *disk = fopen(diskfile, "rb");
    fseek(disk, sizeof(superBlock) + BITMAP_BLOCKS*BLOCKSIZE + inode_num*sizeof(inode), SEEK_SET);
    fread(node, sizeof(inode), 1, disk);
    fclose(disk);
    return node;
}

void write_directory(directory *dir) {
    FILE *disk = fopen(diskfile, "rb+");
    fseek(disk, sizeof(superBlock) + BITMAP_BLOCKS*BLOCKSIZE + INODE_BLOCKS*sizeof(inode), SEEK_SET);
    fwrite(dir, sizeof(directory), 1, disk);
    fclose(disk);
}

directory *read_directory() {
    directory *dir = malloc(sizeof(directory));
    FILE *disk = fopen(diskfile, "rb");
    fseek(disk, sizeof(superBlock) + BITMAP_BLOCKS*BLOCKSIZE + INODE_BLOCKS*sizeof(inode), SEEK_SET);
    fread(dir, sizeof(directory), 1, disk);
    fclose(disk);
    return dir;
}

void init_filesystem() {
    superBlock sb = {
        .block_size = BLOCKSIZE,
        .num_blocks = MAX_BLOCKS,
        .bitmap_blocks = BITMAP_BLOCKS,
        .inode_blocks = INODE_BLOCKS,
        .num_inodes = MAX_FILES,
        .first_block = BITMAP_BLOCKS + INODE_BLOCKS
    };
    
    int bitmap[MAX_BLOCKS] = {0};
    for (int i = 0; i < BITMAP_BLOCKS + INODE_BLOCKS; i++) {
        bitmap[i] = 1;
    }
    
    write_superblock(&sb);
    write_bitmap(bitmap);
    
    // Initialize root directory
    directory dir = {
        .num_entries = 0
    };
    write_directory(&dir);
}

int allocate_block(int *bitmap) {
    for (int i = BITMAP_BLOCKS + INODE_BLOCKS; i < MAX_BLOCKS; i++) {
        if (bitmap[i] == 0) {
            bitmap[i] = 1;
            write_bitmap(bitmap);
            return i;
        }
    }
    printf("Error: Disk full\n");
    exit(1);
}

void free_block(int block_num) {
    int bitmap[MAX_BLOCKS];
    read_bitmap(bitmap);
    bitmap[block_num] = 0;
    write_bitmap(bitmap);
}

int add_file(char *filename) {
    directory *dir = read_directory();
    if (dir->num_entries == MAX_FILES) {
        printf("Error: Maximum number of files reached\n");
        exit(1);
    }
    for (int i = 0; i < dir->num_entries; i++) {
        if (strcmp(dir->entries[i].filename, filename) == 0) {
            printf("Error: File already exists\n");
            exit(1);
        }
    }
    int inode_num = dir->num_entries;
    inode *node = malloc(sizeof(inode));
    node->size = 0;
    for (int i = 0; i < 10; i++) {
        node->blocks[i] = -1;
    }
    write_inode(inode_num, node);
    dir->entries[inode_num].inode_number = inode_num;
    strcpy(dir->entries[inode_num].filename, filename);
    dir->num_entries++;
    write_directory(dir);
    return inode_num;
}

void remove_file(char *filename) {
    directory *dir = read_directory();
    int found = 0;
    for (int i = 0; i < dir->num_entries; i++) {
        if (strcmp(dir->entries[i].filename, filename) == 0) {
            inode *node = read_inode(dir->entries[i].inode_number);
            for (int j = 0; j < 10; j++) {
                if (node->blocks[j] != -1) {
                    free_block(node->blocks[j]);
                }
            }
            free(node);
            dir->num_entries--;
            for (int j = i; j < dir->num_entries; j++) {
                dir->entries[j] = dir->entries[j+1];
            }
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("Error: File not found\n");
        exit(1);
    }
    write_directory(dir);
}

void write_file(int inode_num, char *buffer, int size) {
    inode *node = read_inode(inode_num);
    int block_num = node->size / BLOCKSIZE;
    int offset = node->size % BLOCKSIZE;
    int remaining = size;
    int buffer_offset = 0;
    while (remaining > 0) {
        if (block_num >= 10) {
            printf("Error: File too large\n");
            exit(1);
        }
        if (node->blocks[block_num] == -1) {
            int new_block = allocate_block;
            node->blocks[block_num] = new_block;
            write_inode(inode_num, node);
        }
        char block[BLOCKSIZE];
        FILE *disk = fopen(diskfile, "rb+");
        fseek(disk, node->blocks[block_num]*BLOCKSIZE + offset, SEEK_SET);
        if (remaining > BLOCKSIZE - offset) {
            fwrite(buffer + buffer_offset, sizeof(char), BLOCKSIZE - offset, disk);
            offset = 0;
            block_num++;
            buffer_offset += BLOCKSIZE - offset;
            remaining -= BLOCKSIZE - offset;
        }
        else {
            fwrite(buffer + buffer_offset, sizeof(char), remaining, disk);
            offset += remaining;
            remaining = 0;
        }
        fclose(disk);
    }
    node->size += size;
    write_inode(inode_num, node);
}

void read_file(int inode_num, char *buffer, int size) {
    inode *node = read_inode(inode_num);
    int block_num = 0;
    int offset = 0;
    int remaining = size;
    int buffer_offset = 0;
    while (remaining > 0 && node->size > block_num*BLOCKSIZE + offset) {
        if (node->blocks[block_num] == -1) {
            printf("Error: File system corrupted\n");
            exit(1);
        }
        char block[BLOCKSIZE];
        FILE *disk = fopen(diskfile, "rb");
        fseek(disk, node->blocks[block_num]*BLOCKSIZE + offset, SEEK_SET);
        int bytes_to_read;
        if (remaining > BLOCKSIZE - offset) {
            bytes_to_read = BLOCKSIZE - offset;
            offset = 0;
            block_num++;
            remaining -= bytes_to_read;
        }
        else {
            bytes_to_read = remaining;
            offset += remaining;
            remaining = 0;
        }
        fread(buffer + buffer_offset, sizeof(char), bytes_to_read, disk);
        buffer_offset += bytes_to_read;
        fclose(disk);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: filesystem [diskfile]\n");
        exit(1);
    }
    diskfile = argv[1];
    
    create_disk();
    init_filesystem();
    
    char buffer[100] = "This is a test file.\n";
    int inode_num = add_file("test.txt");
    write_file(inode_num, buffer, strlen(buffer));
    
    char read_buffer[100];
    read_file(inode_num, read_buffer, strlen(buffer));
    printf("%s", read_buffer);
    
    remove_file("test.txt");
    
    return 0;
}