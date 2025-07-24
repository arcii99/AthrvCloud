//FormAI DATASET v1.0 Category: File system simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512 // Block size
#define BLOCK_NUM 1024 // Number of blocks
#define FILE_NAME_LENGTH 20 // Maximum length of file name
#define MAX_FILES 20 // Maximum number of files in the file system
#define COMMAND_LENGTH 50 // Maximum length of a user command

// Define a data block structure
typedef struct {
    char data[BLOCK_SIZE];
} block_t;

// Define a file descriptor structure
typedef struct {
    int id;
    char name[FILE_NAME_LENGTH];
    int size;
    int block_count;
    int *block_ids;
} file_t;

// Define a file system structure
typedef struct {
    block_t blocks[BLOCK_NUM];
    file_t files[MAX_FILES];
    int file_count;
    int block_count;
} file_system_t;

// Initialize the file system
void init_file_system(file_system_t *fs) {
    // Set each block to zero
    for (int i = 0; i < BLOCK_NUM; i++) {
        memset(fs->blocks[i].data, 0, BLOCK_SIZE);
    }
    // Initialize the files array
    for (int i = 0; i < MAX_FILES; i++) {
        fs->files[i].id = -1;
    }
    fs->file_count = 0;
    fs->block_count = 0;
}

// Allocate a block in the file system
int allocate_block(file_system_t *fs) {
    // Check if there are any available blocks
    if (fs->block_count >= BLOCK_NUM) {
        return -1; // No more blocks available
    }
    // Find the first available block
    for (int i = 0; i < BLOCK_NUM; i++) {
        if (fs->blocks[i].data[0] == '\0') {
            fs->block_count++;
            return i;
        }
    }
}

// Create a new file in the file system
int create_file(file_system_t *fs, char *name, int size) {
    // Check if there are too many files in the file system
    if (fs->file_count >= MAX_FILES) {
        return -1; // File system is full
    }
    // Check if the file name is too long
    if (strlen(name) >= FILE_NAME_LENGTH) {
        return -2; // File name is too long
    }
    // Check if the file size is valid
    if (size <= 0) {
        return -3; // Invalid file size
    }
    // Allocate blocks for the file
    int block_count = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    if (fs->block_count + block_count > BLOCK_NUM) {
        return -4; // Not enough blocks available
    }
    int *block_ids = malloc(sizeof(int) * block_count);
    for (int i = 0; i < block_count; i++) {
        block_ids[i] = allocate_block(fs);
        if (block_ids[i] == -1) {
            // Error allocating block, free the already allocated blocks
            for (int j = 0; j < i; j++) {
                fs->blocks[block_ids[j]].data[0] = '\0';
                fs->block_count--;
            }
            free(block_ids);
            return -4; // Not enough blocks available
        }
    }
    // Create the file descriptor
    file_t file;
    file.id = fs->file_count++;
    strcpy(file.name, name);
    file.size = size;
    file.block_count = block_count;
    file.block_ids = block_ids;
    // Add the file to the file system
    fs->files[file.id] = file;
    fs->block_count += block_count;
    return file.id;
}

// Write data to a file in the file system
void write_file(file_system_t *fs, int id, char *data, int size) {
    // Find the file descriptor
    file_t *file = NULL;
    for (int i = 0; i < fs->file_count; i++) {
        if (fs->files[i].id == id) {
            file = &fs->files[i];
            break;
        }
    }
    if (file == NULL) {
        return; // File not found
    }
    // Write the data to the file
    int offset = 0;
    for (int i = 0; i < file->block_count; i++) {
        int bytes_to_write = size - offset;
        if (bytes_to_write > BLOCK_SIZE) {
            bytes_to_write = BLOCK_SIZE;
        }
        memcpy(fs->blocks[file->block_ids[i]].data, data + offset, bytes_to_write);
        offset += bytes_to_write;
        if (offset >= size) {
            break;
        }
    }
}

// Read data from a file in the file system
void read_file(file_system_t *fs, int id, char *data, int size) {
    // Find the file descriptor
    file_t *file = NULL;
    for (int i = 0; i < fs->file_count; i++) {
        if (fs->files[i].id == id) {
            file = &fs->files[i];
            break;
        }
    }
    if (file == NULL) {
        return; // File not found
    }
    // Read the data from the file
    int offset = 0;
    for (int i = 0; i < file->block_count; i++) {
        int bytes_to_read = size - offset;
        if (bytes_to_read > BLOCK_SIZE) {
            bytes_to_read = BLOCK_SIZE;
        }
        memcpy(data + offset, fs->blocks[file->block_ids[i]].data, bytes_to_read);
        offset += bytes_to_read;
        if (offset >= size) {
            break;
        }
    }
}

// Delete a file from the file system
void delete_file(file_system_t *fs, int id) {
    // Find the file descriptor
    file_t *file = NULL;
    for (int i = 0; i < fs->file_count; i++) {
        if (fs->files[i].id == id) {
            file = &fs->files[i];
            break;
        }
    }
    if (file == NULL) {
        return; // File not found
    }
    // Free all the blocks used by the file
    for (int i = 0; i < file->block_count; i++) {
        fs->blocks[file->block_ids[i]].data[0] = '\0';
        fs->block_count--;
    }
    free(file->block_ids);
    // Remove the file from the file system
    fs->file_count--;
    for (int i = file->id; i < fs->file_count; i++) {
        fs->files[i] = fs->files[i+1];
    }
    fs->files[fs->file_count].id = -1;
}

// Print the contents of the file system
void print_file_system(file_system_t *fs) {
    printf("Block count: %d / %d\n", fs->block_count, BLOCK_NUM);
    printf("File count: %d / %d\n", fs->file_count, MAX_FILES);
    printf("Files:\n");
    for (int i = 0; i < fs->file_count; i++) {
        file_t *file = &fs->files[i];
        printf("  %s (%d bytes)\n", file->name, file->size);
    }
}

int main() {
    char command[COMMAND_LENGTH];
    file_system_t fs;
    init_file_system(&fs);
    while (1) {
        // Read a user command
        printf("> ");
        fgets(command, COMMAND_LENGTH, stdin);
        if (command[strlen(command)-1] == '\n') {
            command[strlen(command)-1] = '\0';
        }
        // Parse the command
        char *tokens[10];
        int token_count = 0;
        char *token = strtok(command, " ");
        while (token != NULL && token_count < 10) {
            tokens[token_count++] = token;
            token = strtok(NULL, " ");
        }
        if (token_count == 0) {
            continue; // Empty command
        }
        if (strcmp(tokens[0], "create") == 0 && token_count == 3) {
            int id = create_file(&fs, tokens[1], atoi(tokens[2]));
            if (id == -1) {
                printf("Error: file system is full\n");
            } else if (id == -2) {
                printf("Error: file name is too long\n");
            } else if (id == -3) {
                printf("Error: invalid file size\n");
            } else if (id == -4) {
                printf("Error: not enough blocks available\n");
            } else {
                printf("File created: %s (%d bytes)\n", tokens[1], atoi(tokens[2]));
            }
        } else if (strcmp(tokens[0], "write") == 0 && token_count == 3) {
            char data[BLOCK_SIZE];
            printf("> ");
            fgets(data, BLOCK_SIZE, stdin);
            if (data[strlen(data)-1] == '\n') {
                data[strlen(data)-1] = '\0';
            }
            write_file(&fs, atoi(tokens[1]), data, atoi(tokens[2]));
        } else if (strcmp(tokens[0], "read") == 0 && token_count == 3) {
            char data[BLOCK_SIZE];
            read_file(&fs, atoi(tokens[1]), data, atoi(tokens[2]));
            printf("%s\n", data);
        } else if (strcmp(tokens[0], "delete") == 0 && token_count == 2) {
            delete_file(&fs, atoi(tokens[1]));
        } else if (strcmp(tokens[0], "ls") == 0 && token_count == 1) {
            print_file_system(&fs);
        } else if (strcmp(tokens[0], "exit") == 0 && token_count == 1) {
            break;
        } else {
            printf("Error: invalid command\n");
        }
    }
    return 0;
}