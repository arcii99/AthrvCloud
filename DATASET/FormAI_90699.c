//FormAI DATASET v1.0 Category: File system simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BLOCKS 100

typedef struct DirectoryEntry {
    char name[20];
    int firstBlock;
} DirectoryEntry;

typedef struct FileSystem {
    int freeBlockCount;
    int allocatedBlockCount;
    int blocks[MAX_BLOCKS];
    DirectoryEntry dir[MAX_BLOCKS];
} FileSystem;

void initializeFileSystem(FileSystem *fs) {
    fs->freeBlockCount = MAX_BLOCKS;
    fs->allocatedBlockCount = 0;
    
    for (int i = 0; i < MAX_BLOCKS; i++) {
        fs->blocks[i] = 0;
        strcpy(fs->dir[i].name, "");
        fs->dir[i].firstBlock = -1;
    }
}

int allocateBlock(FileSystem *fs) {
    if (fs->freeBlockCount > 0) {
        int randBlock = rand() % MAX_BLOCKS;
        while (fs->blocks[randBlock] == 1) {
            randBlock = rand() % MAX_BLOCKS;
        }
        fs->blocks[randBlock] = 1;
        fs->freeBlockCount--;
        fs->allocatedBlockCount++;
        return randBlock;
    }
    else {
        return -1;
    }
}

void addDirectoryEntry(FileSystem *fs, char *name, int firstBlock) {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (strcmp(fs->dir[i].name, "") == 0) {
            strcpy(fs->dir[i].name, name);
            fs->dir[i].firstBlock = firstBlock;
            break;
        }
    }
}

void printDirectory(FileSystem *fs) {
    printf("DIRECTORY CONTENTS:\n");
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (strcmp(fs->dir[i].name, "") != 0) {
            printf("%s - firstBlock: %d\n", fs->dir[i].name, fs->dir[i].firstBlock);
        }
    }
}

int main() {
    srand(time(0));
    
    FileSystem fs;
    initializeFileSystem(&fs);
    
    printf("Creating file 'alice'...\n");
    int aliceBlock = allocateBlock(&fs);
    addDirectoryEntry(&fs, "alice", aliceBlock);
    printf("Created file 'alice' in block %d\n", aliceBlock);
    printf("Free blocks remaining: %d\n", fs.freeBlockCount);
    
    printf("\nCreating file 'bob'...\n");
    int bobBlock = allocateBlock(&fs);
    addDirectoryEntry(&fs, "bob", bobBlock);
    printf("Created file 'bob' in block %d\n", bobBlock);
    printf("Free blocks remaining: %d\n", fs.freeBlockCount);
    
    printf("\nCreating file 'charlie'...\n");
    int charlieBlock = allocateBlock(&fs);
    addDirectoryEntry(&fs, "charlie", charlieBlock);
    printf("Created file 'charlie' in block %d\n", charlieBlock);
    printf("Free blocks remaining: %d\n", fs.freeBlockCount);
    
    printf("\nCreating file 'david'...\n");
    int davidBlock = allocateBlock(&fs);
    addDirectoryEntry(&fs, "david", davidBlock);
    printf("Created file 'david' in block %d\n", davidBlock);
    printf("Free blocks remaining: %d\n", fs.freeBlockCount);
    
    printDirectory(&fs);
    
    return 0;
}