//FormAI DATASET v1.0 Category: File system simulation ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BLOCK_SIZE 512 // The size of each block in bytes
#define MAX_BLOCKS 1024 // The maximum number of blocks in the file system
#define MAX_NAME_LENGTH 20 // The maximum length of a file or directory name

// Struct for a directory entry
typedef struct {
    char name[MAX_NAME_LENGTH];
    int isDirectory;
    int blockIndex;
} DirectoryEntry;

// Struct for the file system
typedef struct {
    int freeBlock;
    DirectoryEntry directory[MAX_BLOCKS];
    char data[MAX_BLOCKS][BLOCK_SIZE];
} FileSystem;

FileSystem fileSystem;

// Initializes the file system
void initializeFileSystem() {
    fileSystem.freeBlock = 0;
    int i;
    for (i = 0; i < MAX_BLOCKS; i++) {
        fileSystem.directory[i].name[0] = '\0';
        fileSystem.directory[i].isDirectory = 0;
        fileSystem.directory[i].blockIndex = -1;
    }
}

// Adds a file or directory to the file system
int addFileOrDirectory(char *name, int isDirectory) {
    int i;
    // Check if the file or directory already exists
    for (i = 0; i < MAX_BLOCKS; i++) {
        if (strcmp(fileSystem.directory[i].name, name) == 0) {
            return 0;
        }
    }
    // Find a free block to use
    int blockIndex = fileSystem.freeBlock;
    if (blockIndex == MAX_BLOCKS) {
        return 0;
    }
    fileSystem.freeBlock++;
    // Initialize the directory entry
    strcpy(fileSystem.directory[blockIndex].name, name);
    fileSystem.directory[blockIndex].isDirectory = isDirectory;
    fileSystem.directory[blockIndex].blockIndex = blockIndex;
    return 1;
}

// Deletes a file or directory from the file system
int deleteFileOrDirectory(char *name) {
    int i;
    // Find the directory entry for the file or directory
    DirectoryEntry *entry = NULL;
    for (i = 0; i < MAX_BLOCKS; i++) {
        if (strcmp(fileSystem.directory[i].name, name) == 0) {
            entry = &fileSystem.directory[i];
            break;
        }
    }
    if (entry == NULL) {
        return 0;
    }
    // Delete the file or directory
    entry->name[0] = '\0';
    entry->isDirectory = 0;
    entry->blockIndex = -1;
    return 1;
}

// Prints the file system's directory
void printDirectory() {
    int i;
    printf("Directory:\n");
    for (i = 0; i < MAX_BLOCKS; i++) {
        if (fileSystem.directory[i].name[0] != '\0') {
            printf("%s", fileSystem.directory[i].name);
            if (fileSystem.directory[i].isDirectory) {
                printf("/");
            }
            printf("\n");
        }
    }
}

// The main function
int main() {
    initializeFileSystem();
    
    // Add some files and directories
    addFileOrDirectory("file1", 0);
    addFileOrDirectory("file2", 0);
    addFileOrDirectory("dir1", 1);
    addFileOrDirectory("dir2", 1);
    addFileOrDirectory("file3", 0);
    
    // Print the directory
    printDirectory();
    
    // Delete a file and a directory
    deleteFileOrDirectory("file2");
    deleteFileOrDirectory("dir1");
    
    // Print the directory again
    printDirectory();
    
    return 0;
}