//FormAI DATASET v1.0 Category: File system simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DISK_SIZE 1000      // total disk space in bytes
#define BLOCK_SIZE 32       // block size in bytes
#define NUM_BLOCKS DISK_SIZE/BLOCK_SIZE   // total number of blocks on disk

struct inode {
    char name[20];
    int size;
    int blockNum[10];
};

struct superblock {
    int freeBlocks[NUM_BLOCKS];
    int numFreeBlocks;
};

void initializeDisk(char disk[DISK_SIZE]) {
    memset(disk, '\0', DISK_SIZE);  // fill disk with null characters
}

void initializeSuperblock(struct superblock* sb) {
    sb->numFreeBlocks = NUM_BLOCKS;
    for(int i = 0; i < NUM_BLOCKS; i++) {
        sb->freeBlocks[i] = 1;   // initialize all blocks as free
    }
}

void createFile(struct inode* inodeTable, int* numInodes, struct superblock* sb, char* disk) {
    if(*numInodes >= 10) {
        printf("Maximum number of files reached.\n");
        return;
    }

    struct inode newFile;
    printf("Enter file name: ");
    scanf("%s", newFile.name);
    printf("Enter file size (in bytes): ");
    scanf("%d", &(newFile.size));

    int numBlocks = (newFile.size + BLOCK_SIZE - 1) / BLOCK_SIZE;  // calculate number of blocks needed for file
    if(numBlocks > sb->numFreeBlocks) {
        printf("Not enough space on disk.\n");
        return;
    }

    // allocate blocks to file
    int k = 0;  // index of freeBlocks array
    for(int i = 0; i < numBlocks; i++) {
        while(sb->freeBlocks[k] != 1) {
            k++;
        }
        sb->freeBlocks[k] = 0;
        newFile.blockNum[i] = k;
        k++;
    }
    sb->numFreeBlocks -= numBlocks;

    inodeTable[*numInodes] = newFile;
    (*numInodes)++;
    printf("File created successfully.\n");
}

void deleteFile(struct inode* inodeTable, int* numInodes, struct superblock* sb, char* disk) {
    char fileName[20];
    printf("Enter file name: ");
    scanf("%s", fileName);

    for(int i = 0; i < *numInodes; i++) {
        if(strcmp(inodeTable[i].name, fileName) == 0) {
            for(int j = 0; j < 10 && inodeTable[i].blockNum[j] != -1; j++) {
                sb->freeBlocks[inodeTable[i].blockNum[j]] = 1;
            }
            sb->numFreeBlocks += (inodeTable[i].size + BLOCK_SIZE - 1) / BLOCK_SIZE;
            inodeTable[i] = inodeTable[(*numInodes) - 1];
            memset(&(inodeTable[(*numInodes) - 1]), '\0', sizeof(struct inode));
            (*numInodes)--;
            printf("File deleted successfully.\n");
            return;
        }
    }
    printf("File not found.\n");
}

void displayFile(struct inode* inodeTable, int* numInodes, char* disk) {
    char fileName[20];
    printf("Enter file name: ");
    scanf("%s", fileName);

    for(int i = 0; i < *numInodes; i++) {
        if(strcmp(inodeTable[i].name, fileName) == 0) {
            printf("File Name: %s\n", inodeTable[i].name);
            printf("File Size: %d bytes\n", inodeTable[i].size);
            printf("File Contents:\n");
            for(int j = 0; j < 10 && inodeTable[i].blockNum[j] != -1; j++) {
                printf("%.*s", BLOCK_SIZE, &disk[(inodeTable[i].blockNum[j]) * BLOCK_SIZE]);
            }
            return;
        }
    }
    printf("File not found.\n");
}

void displayDisk(struct inode* inodeTable, int* numInodes, struct superblock* sb, char* disk) {
    printf("Superblock:\n");
    printf("Number of free blocks: %d\n", sb->numFreeBlocks);
    printf("Bit vector of free blocks:\n");
    for(int i = 0; i < NUM_BLOCKS; i++) {
        printf("%d ", sb->freeBlocks[i]);
    }
    printf("\n\nInode Table:\n");
    printf("| %-20s | %-10s | %s |\n", "File Name", "File Size", "Block Numbers");
    printf("| %-20s | %-10s | %s |\n", "--------------------", "----------", "-------------");
    for(int i = 0; i < *numInodes; i++) {
        printf("| %-20s | %-10d | ", inodeTable[i].name, inodeTable[i].size);
        for(int j = 0; j < 10 && inodeTable[i].blockNum[j] != -1; j++) {
            printf("%d ", inodeTable[i].blockNum[j]);
        }
        printf("|\n");
    }
    printf("\n\nDisk Contents:\n");
    for(int i = 0; i < NUM_BLOCKS; i++) {
        printf("Block %d: %.*s\n", i, BLOCK_SIZE, &disk[i * BLOCK_SIZE]);
    }
}

int main() {
    char disk[DISK_SIZE];
    initializeDisk(disk);

    struct superblock sb;
    initializeSuperblock(&sb);

    struct inode inodeTable[10];
    memset(inodeTable, '\0', sizeof(inodeTable));
    int numInodes = 0;

    int choice;
    do {
        printf("1. Create file\n");
        printf("2. Delete file\n");
        printf("3. Display file\n");
        printf("4. Display disk\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createFile(inodeTable, &numInodes, &sb, disk);
                break;
            case 2:
                deleteFile(inodeTable, &numInodes, &sb, disk);
                break;
            case 3:
                displayFile(inodeTable, &numInodes, disk);
                break;
            case 4:
                displayDisk(inodeTable, &numInodes, &sb, disk);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 5);

    return 0;
}