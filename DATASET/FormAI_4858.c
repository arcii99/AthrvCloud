//FormAI DATASET v1.0 Category: File system simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define File System Constants
#define BLOCK_SIZE 512
#define NUM_BLOCKS 1000
#define MAX_FILENAME_LENGTH 20
#define MAX_NUM_FILES 100
#define BITMAP_SIZE NUM_BLOCKS/8
#define NUM_DIRECT_BLOCKS 10

// Define Data Structures
struct Superblock {
    int num_blocks;
    int num_free_blocks;
    char bitmap[BITMAP_SIZE];
};

struct Inode {
    char filename[MAX_FILENAME_LENGTH];
    int size;
    int direct_blocks[NUM_DIRECT_BLOCKS];
    int single_indirect_block;
};

// Define Global Variables
char disk[NUM_BLOCKS * BLOCK_SIZE];

struct Superblock superblock;
struct Inode inodes[MAX_NUM_FILES];
int num_files = 0;

// Declare Function Prototypes
void init_superblock();
void create_file(char* filename, int size);
int find_free_block();
void write_block(int block_num, char* data);
void read_block(int block_num, char* data);
int find_inode(char* filename);
void write_inode(int inode_num);
void read_inode(int inode_num);
void print_filesystem();

// Define Function Implementations
void init_superblock() {
    superblock.num_blocks = NUM_BLOCKS;
    superblock.num_free_blocks = NUM_BLOCKS;
    memset(superblock.bitmap, 1, BITMAP_SIZE);
}

void create_file(char* filename, int size) {
    if (num_files == MAX_NUM_FILES) {
        printf("Error: Maximum number of files reached\n");
        return;
    }
    if (strlen(filename) > MAX_FILENAME_LENGTH) {
        printf("Error: Filename too long\n");
        return;
    }
    if (find_inode(filename) != -1) {
        printf("Error: File already exists\n");
        return;
    }

    int inode_num = num_files++;
    strncpy(inodes[inode_num].filename, filename, MAX_FILENAME_LENGTH);
    inodes[inode_num].size = size;

    // Allocate Direct Blocks
    int num_direct_blocks = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    for (int i = 0; i < NUM_DIRECT_BLOCKS && i < num_direct_blocks; i++) {
        int block_num = find_free_block();
        inodes[inode_num].direct_blocks[i] = block_num;
        superblock.num_free_blocks--;
        superblock.bitmap[block_num / 8] &= ~(1 << (block_num % 8));
    }

    // Allocate Single Indirect Block
    if (num_direct_blocks > NUM_DIRECT_BLOCKS) {
        int block_num = find_free_block();
        inodes[inode_num].single_indirect_block = block_num;
        superblock.num_free_blocks--;
        superblock.bitmap[block_num / 8] &= ~(1 << (block_num % 8));

        int* indirect_block = (int*)(&disk[block_num * BLOCK_SIZE]);
        for (int i = NUM_DIRECT_BLOCKS; i < num_direct_blocks; i++) {
            int block_num = find_free_block();
            indirect_block[i - NUM_DIRECT_BLOCKS] = block_num;
            superblock.num_free_blocks--;
            superblock.bitmap[block_num / 8] &= ~(1 << (block_num % 8));
        }
    }

    write_inode(inode_num);
}

int find_free_block() {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if ((superblock.bitmap[i / 8] & (1 << (i % 8))) != 0) {
            return i;
        }
    }
    return -1;
}

void write_block(int block_num, char* data) {
    memcpy(&disk[block_num * BLOCK_SIZE], data, BLOCK_SIZE);
}

void read_block(int block_num, char* data) {
    memcpy(data, &disk[block_num * BLOCK_SIZE], BLOCK_SIZE);
}

int find_inode(char* filename) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(inodes[i].filename, filename) == 0) {
            return i;
        }
    }
    return -1;
}

void write_inode(int inode_num) {
    char* inode_data = (char*)(&inodes[inode_num]);
    write_block(inode_num, inode_data);
}

void read_inode(int inode_num) {
    char* inode_data = (char*)(&inodes[inode_num]);
    read_block(inode_num, inode_data);
}

void print_filesystem() {
    printf("File System:\n");
    printf("Num Blocks: %d\n", superblock.num_blocks);
    printf("Num Free Blocks: %d\n", superblock.num_free_blocks);
    printf("Bitmap: ");
    for (int i = 0; i < BITMAP_SIZE; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d", (superblock.bitmap[i] & (1 << j)) != 0);
        }
    }
    printf("\n");
    printf("Inodes:\n");
    for (int i = 0; i < num_files; i++) {
        printf("Inode %d:\n", i);
        printf("Filename: %s\n", inodes[i].filename);
        printf("Size: %d\n", inodes[i].size);
        printf("Direct Blocks:");
        for (int j = 0; j < NUM_DIRECT_BLOCKS && inodes[i].direct_blocks[j] != -1; j++) {
            printf(" %d", inodes[i].direct_blocks[j]);
        }
        if (inodes[i].single_indirect_block != -1) {
            int* indirect_block = (int*)(&disk[inodes[i].single_indirect_block * BLOCK_SIZE]);
            for (int j = 0; j < inodes[i].size - NUM_DIRECT_BLOCKS * BLOCK_SIZE; j += BLOCK_SIZE) {
                printf(" %d", indirect_block[j / BLOCK_SIZE]);
            }
        }
        printf("\n");
    }
}

int main() {
    init_superblock();
    char filename[MAX_FILENAME_LENGTH];
    int size;

    // Create Files
    strncpy(filename, "post.txt", MAX_FILENAME_LENGTH);
    size = 2048;
    create_file(filename, size);

    strncpy(filename, "apoc.txt", MAX_FILENAME_LENGTH);
    size = 1024;
    create_file(filename, size);

    // Print File System
    print_filesystem();

    return 0;
}