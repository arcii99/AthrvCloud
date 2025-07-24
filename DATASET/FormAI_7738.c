//FormAI DATASET v1.0 Category: File system simulation ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_FILE_COUNT 25
#define FILE_NAME_LIMIT 20
#define BLOCK_SIZE 512
#define BLOCK_COUNT 2048
#define ADDRESS_SIZE 3
#define ADDRESS_COUNT 150

struct directory_entry {
    char file_name[FILE_NAME_LIMIT];
    int start_address;
    int file_size;
};

// Function to print the welcome message
void welcome_message() {
    printf("Welcome to File System Simulation program!\n");
}

// Function to initialize the blocks of the file system 
void initialize_blocks(char* blocks[]) {
    for(int i = 0; i < BLOCK_COUNT; i++) {
        blocks[i] = (char*) malloc(BLOCK_SIZE * sizeof(char));
        memset(blocks[i], '\0', BLOCK_SIZE);
    }
}

// Function to print available and allocated blocks
void print_blocks_status(char* blocks[], int allocated_blocks[]) {
    printf("\nBLOCKS STATUS:\n\n");
    for(int i = 0; i < BLOCK_COUNT; i++) {
        if(allocated_blocks[i] == 1) {
            printf("[X] "); // Block is allocated
        } else {
            printf("[ ] "); // Block is available
        }
    }
    printf("\n\n");
}

// Function to allocate blocks for a file
void allocate_blocks(int file_size, int* allocated_blocks) {
    int count = 0;
    for(int i = 0; i < BLOCK_COUNT; i++) {
        if(allocated_blocks[i] == 0) {
            allocated_blocks[i] = 1;
            count++;
        }
        if(count == file_size) {
            break;
        }
    }
}

// Function to deallocate blocks of a file
void deallocate_blocks(int start_address, int file_size, int* allocated_blocks) {
    for(int i = start_address; i < start_address + file_size; i++) {
        allocated_blocks[i] = 0;
    }
}

// Function to create a new file in the directory
void create_file(struct directory_entry* directory, int* file_count, char* file_name, int file_size, int* allocated_blocks) {
    // Check if maximum number of files reached
    if(*file_count == MAX_FILE_COUNT) {
        printf("\nMaximum number of files reached!\n");
        return;
    }

    // Check if file size exceeds available blocks
    int available_blocks = 0;
    for(int i = 0; i < BLOCK_COUNT; i++) {
        if(allocated_blocks[i] == 0) {
            available_blocks++;
        }
    }
    if(file_size > available_blocks) {
        printf("\nNot enough available blocks to create file!\n");
        return;
    }

    // Allocate blocks for the file
    allocate_blocks(file_size, allocated_blocks);

    // Add file entry to directory
    struct directory_entry new_entry;
    strcpy(new_entry.file_name, file_name);
    new_entry.file_size = file_size;
    for(int i = 0; i < BLOCK_COUNT; i++) {
        if(allocated_blocks[i] == 1) {
            new_entry.start_address = i;
            break;
        }
    }
    directory[*file_count] = new_entry;

    (*file_count)++;

    printf("\nFile created successfully!\n");
}

// Function to delete an existing file from the directory
void delete_file(struct directory_entry* directory, int* file_count, char* file_name, int* allocated_blocks) {
    for(int i = 0; i < *file_count; i++) {
        if(strcmp(directory[i].file_name, file_name) == 0) {
            // Deallocate blocks of file
            deallocate_blocks(directory[i].start_address, directory[i].file_size, allocated_blocks);

            // Remove file entry from directory
            for(int j=i; j<(*file_count)-1; j++) {
                directory[j] = directory[j+1];
            }

            (*file_count)--;

            printf("\nFile deleted successfully!\n");
            return;
        }
    }

    printf("\nFile not found!\n");
}

// Function to print the directory
void print_directory(struct directory_entry* directory, int file_count) {
    printf("\nDIRECTORY:\n\n");
    if(file_count == 0) {
        printf("Directory is empty!\n");
        return;
    }
    for(int i = 0; i < file_count; i++) {
        printf("File Name: %s, Start Address: %d, File Size: %d\n", directory[i].file_name, directory[i].start_address, directory[i].file_size);
    }
}

// Function to execute file system operations
void execute_operations(struct directory_entry* directory, int* file_count, char* blocks[]) {
    int allocated_blocks[BLOCK_COUNT] = {0}; // Initialize to zero
    int operation_choice, file_size;
    char file_name[FILE_NAME_LIMIT];

    // Print available/allocated blocks and directory
    print_blocks_status(blocks, allocated_blocks);
    print_directory(directory, *file_count);

    // Get operation choice from user
    printf("\nChoose an operation:\n1. Create a new file\n2. Delete an existing file\n3. Exit program\n");
    scanf("%d", &operation_choice);

    if(operation_choice == 1) {
        // Get file name and size from user
        printf("\nEnter file name (max length %d): ", FILE_NAME_LIMIT);
        scanf("%s", file_name);
        printf("Enter file size (in number of blocks): ");
        scanf("%d", &file_size);

        // Create new file
        create_file(directory, file_count, file_name, file_size, allocated_blocks);

    } else if(operation_choice == 2) {
        // Get file name to delete from user
        printf("\nEnter file name to delete: ");
        scanf("%s", file_name);

        // Delete the file from directory and deallocate its blocks
        delete_file(directory, file_count, file_name, allocated_blocks);

    } else if(operation_choice == 3) {
        // Exit program
        printf("\nExiting program...\n");
        exit(0);
    } else {
        // Invalid input
        printf("\nInvalid choice. Please choose again.\n");
    }

    execute_operations(directory, file_count, blocks); // Recurse to execute next operation
}

int main() {
    char* blocks[BLOCK_COUNT];
    initialize_blocks(blocks);

    struct directory_entry directory[MAX_FILE_COUNT];
    int file_count = 0;

    welcome_message(); // Print welcome message
    execute_operations(directory, &file_count, blocks); // Execute file system operations

    return 0;
}