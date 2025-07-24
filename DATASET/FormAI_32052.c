//FormAI DATASET v1.0 Category: File system simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512 // Define the size of each block in bytes
#define NUM_BLOCKS 4096 // Define the total number of blocks in the file system

// Define a structure representing a directory entry in the file system
typedef struct {
    char name[256]; // Name of the file or directory
    int start_block; // Starting block number of the file or directory
    int size; // Size of the file or directory in bytes
    int is_file; // Boolean flag to indicate whether this directory entry represents a file or directory
} DirEntry;

// Define a structure representing a block in the file system
typedef struct {
    char data[BLOCK_SIZE]; // Data stored in the block
    int next_block; // Number of the next block in the chain
} Block;

// Global variables to store the root directory and free block list
DirEntry root_directory[NUM_BLOCKS];
int free_block_list[NUM_BLOCKS];

// Function prototypes
void initialize_file_system();
void create_directory(char* name);
void create_file(char* name, char* data);
void delete_file_or_directory(char* name);
void list_directory_contents();
void write_block_to_file(Block* block, int block_num);
void read_block_from_file(Block* block, int block_num);

int main() {
    initialize_file_system(); // Call function to initialize the file system
    
    // Create some directories and files
    create_directory("folder1");
    create_directory("folder2");
    create_file("file1.txt", "This is a test file.");
    create_file("file2.txt", "This is another test file.");
    
    // Display the contents of the root directory
    list_directory_contents();
    
    // Delete one of the files
    delete_file_or_directory("file2.txt");
    
    // Display the contents of the root directory again
    list_directory_contents();
    
    return 0;
}

// Function to initialize the file system with an empty root directory and the free block list
void initialize_file_system() {
    int i;
    for (i = 0; i < NUM_BLOCKS; i++) {
        // Initialize the root directory with empty directory entries
        strcpy(root_directory[i].name, "");
        root_directory[i].start_block = -1;
        root_directory[i].size = -1;
        root_directory[i].is_file = -1;
        
        // Initialize the free block list with all blocks marked as free
        free_block_list[i] = 1;
    }
}

// Function to create a new directory in the file system
void create_directory(char* name) {
    int i;
    for (i = 0; i < NUM_BLOCKS; i++) {
        if (free_block_list[i] == 1) {
            // Initialize a new block for the directory
            Block* block = malloc(sizeof(Block));
            int j;
            for (j = 0; j < BLOCK_SIZE; j++) {
                block->data[j] = 0;
            }
            block->next_block = -1;
            write_block_to_file(block, i);
            free(block);
            
            // Add a new directory entry to the root directory for the new directory
            strcpy(root_directory[i].name, name);
            root_directory[i].start_block = i;
            root_directory[i].size = BLOCK_SIZE;
            root_directory[i].is_file = 0;
            
            // Mark the block as used and update the free block list
            free_block_list[i] = 0;
            break;
        }
    }
}

// Function to create a new file in the file system
void create_file(char* name, char* data) {
    int i;
    for (i = 0; i < NUM_BLOCKS; i++) {
        if (free_block_list[i] == 1) {
            // Initialize a new block for the file
            Block* block = malloc(sizeof(Block));
            strcpy(block->data, data);
            block->next_block = -1;
            write_block_to_file(block, i);
            free(block);
            
            // Add a new directory entry to the root directory for the new file
            strcpy(root_directory[i].name, name);
            root_directory[i].start_block = i;
            root_directory[i].size = strlen(data);
            root_directory[i].is_file = 1;
            
            // Mark the block as used and update the free block list
            free_block_list[i] = 0;
            break;
        }
    }
}

// Function to delete a file or directory from the file system
void delete_file_or_directory(char* name) {
    int i;
    for (i = 0; i < NUM_BLOCKS; i++) {
        if (strcmp(root_directory[i].name, name) == 0) {
            // Mark the block(s) used by the file or directory as free
            int block_num = root_directory[i].start_block;
            while (block_num != -1) {
                free_block_list[block_num] = 1;
                Block* block = malloc(sizeof(Block));
                read_block_from_file(block, block_num);
                block_num = block->next_block;
                free(block);
            }
            
            // Remove the directory entry from the root directory
            strcpy(root_directory[i].name, "");
            root_directory[i].start_block = -1;
            root_directory[i].size = -1;
            root_directory[i].is_file = -1;
            
            break;
        }
    }
}

// Function to list the contents of the root directory
void list_directory_contents() {
    int i;
    printf("Contents of Root Directory:\n");
    printf("------------------------------\n");
    for (i = 0; i < NUM_BLOCKS; i++) {
        if (root_directory[i].is_file == 1) {
            printf("%s (File, Size: %d bytes)\n", root_directory[i].name, root_directory[i].size);
        } else if (root_directory[i].is_file == 0) {
            printf("%s (Directory, Size: %d bytes)\n", root_directory[i].name, root_directory[i].size);
        }
    }
    printf("\n");
}

// Function to write a block of data to the file system
void write_block_to_file(Block* block, int block_num) {
    FILE* fp = fopen("filesystem.dat", "rb+");
    fseek(fp, block_num * BLOCK_SIZE, SEEK_SET);
    fwrite(block, 1, sizeof(Block), fp);
    fclose(fp);
}

// Function to read a block of data from the file system
void read_block_from_file(Block* block, int block_num) {
    FILE* fp = fopen("filesystem.dat", "rb+");
    fseek(fp, block_num * BLOCK_SIZE, SEEK_SET);
    fread(block, 1, sizeof(Block), fp);
    fclose(fp);
}