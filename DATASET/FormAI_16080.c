//FormAI DATASET v1.0 Category: File system simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_NAME_SIZE 20
#define BLOCK_SIZE 512
#define BLOCK_COUNT 100

typedef struct {
    char* name;
    int size;
    int* blocks;
} File;

typedef struct {
    int free_blocks[BLOCK_COUNT];
    File files[MAX_FILES];
    int total_blocks;
    int free_block_count;
} FileSystem;

void initFileSystem(FileSystem*);
int allocateBlock(FileSystem*);
void freeBlock(FileSystem*, int);
int createNewFile(FileSystem*, char*, int);
int deleteFile(FileSystem*, char*);
int writeFile(FileSystem*, char*, char*, int);
int readFile(FileSystem*, char*, char*, int);

int main() {
    printf("File System Simulation\n\n");

    FileSystem fs;
    initFileSystem(&fs);

    int option = -1;
    while (option != 0) {
        printf("Options:\n");
        printf("1. Create new file\n");
        printf("2. Delete file\n");
        printf("3. Write to file\n");
        printf("4. Read from file\n");
        printf("0. Exit\n");
        printf("Enter option: ");

        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter file name: ");
                char name[MAX_FILE_NAME_SIZE];
                int size;
                scanf("%s", name);
                printf("Enter file size: ");
                scanf("%d", &size);
                int result = createNewFile(&fs, name, size);
                if (result == -1) {
                    printf("Error creating file: not enough space\n");
                }
                else {
                    printf("File created successfully\n");
                }
                break;
            case 2:
                printf("Enter file name: ");
                char nameToDelete[MAX_FILE_NAME_SIZE];
                scanf("%s", nameToDelete);
                result = deleteFile(&fs, nameToDelete);
                if (result == -1) {
                    printf("Error deleting file: file not found\n");
                }
                else {
                    printf("File deleted successfully\n");
                }
                break;
            case 3:
                printf("Enter file name: ");
                char nameToWrite[MAX_FILE_NAME_SIZE];
                scanf("%s", nameToWrite);
                printf("Enter data to write: ");
                char dataToWrite[BLOCK_SIZE];
                scanf(" %[^\n]", dataToWrite);
                result = writeFile(&fs, nameToWrite, dataToWrite, strlen(dataToWrite));
                if (result == -1) {
                    printf("Error writing to file: file not found\n");
                }
                else {
                    printf("Data written successfully\n");
                }
                break;
            case 4:
                printf("Enter file name: ");
                char nameToRead[MAX_FILE_NAME_SIZE];
                scanf("%s", nameToRead);
                printf("Enter number of bytes to read: ");
                int bytesToRead;
                scanf("%d", &bytesToRead);
                char dataRead[BLOCK_SIZE];
                result = readFile(&fs, nameToRead, dataRead, bytesToRead);
                if (result == -1) {
                    printf("Error reading file: file not found\n");
                }
                else {
                    printf("Data read: %s\n", dataRead);
                }
                break;
            case 0:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }

        printf("\n");
    }

    return 0;
}

void initFileSystem(FileSystem* fs) {
    fs->total_blocks = BLOCK_COUNT;
    fs->free_block_count = BLOCK_COUNT;

    for (int i = 0; i < BLOCK_COUNT; i++) {
        fs->free_blocks[i] = 1;
    }

    for (int i = 0; i < MAX_FILES; i++) {
        fs->files[i].name = NULL;
    }
}

int allocateBlock(FileSystem* fs) {
    if (fs->free_block_count == 0) {
        return -1;
    }

    for (int i = 0; i < fs->total_blocks; i++) {
        if (fs->free_blocks[i] == 1) {
            fs->free_blocks[i] = 0;
            fs->free_block_count--;
            return i;
        }
    }

    return -1;
}

void freeBlock(FileSystem* fs, int block) {
    fs->free_blocks[block] = 1;
    fs->free_block_count++;
}

int createNewFile(FileSystem* fs, char* name, int size) {
    // Check if file with same name already exists
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i].name != NULL && strcmp(fs->files[i].name, name) == 0) {
            return -1;
        }
    }

    // Allocate blocks for file
    int block_count = (size % BLOCK_SIZE == 0) ? size / BLOCK_SIZE : size / BLOCK_SIZE + 1;
    int* blocks = (int*)malloc(block_count * sizeof(int));

    for (int i = 0; i < block_count; i++) {
        blocks[i] = allocateBlock(fs);
        if (blocks[i] == -1) {
            for (int j = 0; j < i; j++) {
                freeBlock(fs, blocks[j]);
            }
            free(blocks);
            return -1;
        }
    }

    // Create file
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i].name == NULL) {
            fs->files[i].name = (char*)malloc(MAX_FILE_NAME_SIZE * sizeof(char));
            strncpy(fs->files[i].name, name, MAX_FILE_NAME_SIZE);
            fs->files[i].size = size;
            fs->files[i].blocks = blocks;
            return i;
        }
    }

    // No space to create file
    return -1;
}

int deleteFile(FileSystem* fs, char* name) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i].name != NULL && strcmp(fs->files[i].name, name) == 0) {
            for (int j = 0; j < fs->files[i].size; j++) {
                freeBlock(fs, fs->files[i].blocks[j]);
            }
            free(fs->files[i].blocks);
            free(fs->files[i].name);
            fs->files[i].name = NULL;
            fs->files[i].size = 0;
            return i;
        }
    }

    // File not found
    return -1;
}

int writeFile(FileSystem* fs, char* name, char* data, int size) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i].name != NULL && strcmp(fs->files[i].name, name) == 0) {
            if (size > fs->files[i].size) {
                return -1;
            }

            // Write data
            int remaining_size = size;
            int current_block = 0;
            while (remaining_size > 0) {
                int bytes_to_write = (remaining_size <= BLOCK_SIZE) ? remaining_size : BLOCK_SIZE;
                memcpy(data + (current_block * BLOCK_SIZE), fs->files[i].blocks[current_block] * BLOCK_SIZE, bytes_to_write);
                remaining_size -= bytes_to_write;
                current_block++;
            }

            return i;
        }
    }

    // File not found
    return -1;
}

int readFile(FileSystem* fs, char* name, char* data, int size) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i].name != NULL && strcmp(fs->files[i].name, name) == 0) {
            if (size > fs->files[i].size) {
                return -1;
            }

            // Read data
            int remaining_size = size;
            int current_block = 0;
            while (remaining_size > 0) {
                int bytes_to_read = (remaining_size <= BLOCK_SIZE) ? remaining_size : BLOCK_SIZE;
                memcpy(data + (current_block * BLOCK_SIZE), fs->files[i].blocks[current_block] * BLOCK_SIZE, bytes_to_read);
                remaining_size -= bytes_to_read;
                current_block++;
            }

            return i;
        }
    }

    // File not found
    return -1;
}