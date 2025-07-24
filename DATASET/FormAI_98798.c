//FormAI DATASET v1.0 Category: File system simulation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the maximum file system and block sizes
#define MAX_FS_SIZE 512
#define MAX_BLOCK_SIZE 32

// Define the structures for file and block
typedef struct file {
    char* filename;
    int size;
    int blocks[10];
} File;

typedef struct block {
    int index;
    int used;
    char data[MAX_BLOCK_SIZE];
} Block;

// Declare the global variables for file system simulation
Block blocks[16];
int freeBlocks[16];
int numFreeBlocks = 16;

File files[10];
int numFiles = 0;

// Declare the function prototypes
int createFile(char* filename, int size);
int writeFile(char* filename, char* data, int size);
int readFile(char* filename, char* data, int size);
void deleteFile(char* filename);
void printFileSystem();

// Main function to start the file system simulation
int main() {
    int option;
    char filename[20];
    char data[MAX_BLOCK_SIZE];
    int size;

    // Initialize all the blocks as free
    for (int i = 0; i < 16; i++) {
        blocks[i].index = i;
        blocks[i].used = 0;
        freeBlocks[i] = i;
    }

    while (1) {
        // Display the menu options
        printf("\nFile System Simulation\n");
        printf("-----------------------\n");
        printf("1. Create a file\n");
        printf("2. Write to a file\n");
        printf("3. Read from a file\n");
        printf("4. Delete a file\n");
        printf("5. Print the file system\n");
        printf("6. Quit\n");

        // Prompt the user for the option
        printf("Enter an option: ");
        scanf("%d", &option);

        // Call the appropriate function based on the user option
        switch (option) {
            case 1:
                printf("Enter the filename: ");
                scanf("%s", filename);
                printf("Enter the file size: ");
                scanf("%d", &size);
                createFile(filename, size);
                break;
            case 2:
                printf("Enter the filename: ");
                scanf("%s", filename);
                printf("Enter the data: ");
                scanf("%s", data);
                size = strlen(data);
                writeFile(filename, data, size);
                break;
            case 3:
                printf("Enter the filename: ");
                scanf("%s", filename);
                printf("Enter the buffer size: ");
                scanf("%d", &size);
                readFile(filename, data, size);
                printf("%s\n", data);
                break;
            case 4:
                printf("Enter the filename: ");
                scanf("%s", filename);
                deleteFile(filename);
                break;
            case 5:
                printFileSystem();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }
}

// Function to create a file
int createFile(char* filename, int size) {
    // Check for the maximum number of files
    if (numFiles == 10) {
        printf("Maximum number of files created\n");
        return -1;
    }

    // Check for the file name already exists
    for (int i = 0; i < numFiles; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            printf("File already exists\n");
            return -1;
        }
    }

    // Check for the available free blocks
    if (numFreeBlocks < size / MAX_BLOCK_SIZE) {
        printf("Not enough free space\n");
        return -1;
    }

    // Create the new file
    File file;
    file.filename = filename;
    file.size = size;

    // Allocate the blocks for the file
    for (int i = 0; i < size / MAX_BLOCK_SIZE; i++) {
        file.blocks[i] = freeBlocks[i];
        blocks[freeBlocks[i]].used = 1;
        freeBlocks[i] = -1;
        numFreeBlocks--;
    }

    // Add the file to the system and return success
    files[numFiles] = file;
    numFiles++;
    printf("File created successfully\n");
    return 0;
}

// Function to write to a file
int writeFile(char* filename, char* data, int size) {
    // Find the file from the file system
    int fileIndex = -1;
    for (int i = 0; i < numFiles; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            fileIndex = i;
            break;
        }
    }

    // Check for the file exists or not
    if (fileIndex == -1) {
        printf("File not found\n");
        return -1;
    }

    // Check for the available free blocks
    if (numFreeBlocks < (size / MAX_BLOCK_SIZE - files[fileIndex].size / MAX_BLOCK_SIZE)) {
        printf("Not enough free space\n");
        return -1;
    }

    // Write the data to the file
    int blockIndex = files[fileIndex].size / MAX_BLOCK_SIZE;
    for (int i = 0; i < size / MAX_BLOCK_SIZE; i++) {
        if (i < blockIndex) continue;
        files[fileIndex].blocks[i] = freeBlocks[i];
        blocks[freeBlocks[i]].used = 1;
        freeBlocks[i] = -1;
        numFreeBlocks--;
        strncpy(blocks[files[fileIndex].blocks[i]].data, data + i * MAX_BLOCK_SIZE, MAX_BLOCK_SIZE);
    }

    // Update the file size and return success
    files[fileIndex].size = size;
    printf("Data written to file successfully\n");
    return 0;
}

// Function to read from a file
int readFile(char* filename, char* data, int size) {
    // Find the file from the file system
    int fileIndex = -1;
    for (int i = 0; i < numFiles; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            fileIndex = i;
            break;
        }
    }

    // Check for the file exists or not
    if (fileIndex == -1) {
        printf("File not found\n");
        return -1;
    }

    // Copy the data from the blocks to the buffer
    int readSize = files[fileIndex].size < size ? files[fileIndex].size : size;
    int blockIndex = 0;
    for (int i = 0; i < readSize / MAX_BLOCK_SIZE; i++) {
        strncpy(data + i * MAX_BLOCK_SIZE, blocks[files[fileIndex].blocks[blockIndex]].data, MAX_BLOCK_SIZE);
        blockIndex++;
    }

    // Return the size of data read
    return readSize;
}

// Function to delete a file
void deleteFile(char* filename) {
    // Find the file from the file system
    int fileIndex = -1;
    for (int i = 0; i < numFiles; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            fileIndex = i;
            break;
        }
    }

    // Check for the file exists or not
    if (fileIndex == -1) {
        printf("File not found\n");
        return;
    }

    // Free the blocks used by the file
    for (int i = 0; i < files[fileIndex].size / MAX_BLOCK_SIZE; i++) {
        blocks[files[fileIndex].blocks[i]].used = 0;
        freeBlocks[numFreeBlocks] = files[fileIndex].blocks[i];
        numFreeBlocks++;
    }

    // Remove the file from the system
    for (int i = fileIndex; i < numFiles - 1; i++) {
        files[i] = files[i + 1];
    }
    numFiles--;

    // Print the success message
    printf("File deleted successfully\n");
}

// Function to print the file system
void printFileSystem() {
    printf("\nFile System\n");
    printf("-----------------------\n");

    for (int i = 0; i < numFiles; i++) {
        printf("File name: %s\n", files[i].filename);
        printf("File size: %d\n", files[i].size);
        printf("Blocks used:");
        for (int j = 0; j < files[i].size / MAX_BLOCK_SIZE; j++) {
            printf(" %d", files[i].blocks[j]);
        }
        printf("\n");
    }

    printf("\nFree Blocks: ");
    for (int i = 0; i < numFreeBlocks; i++) {
        printf("%d ", freeBlocks[i]);
    }
    printf("\n");
}