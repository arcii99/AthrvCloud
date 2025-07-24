//FormAI DATASET v1.0 Category: File system simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILES 10
#define BLOCK_SIZE 512
#define MAX_BLOCKS 10000
#define FILE_NAME_LENGTH 20
#define FILE_CONTENT_LENGTH 500

// Define the structure for file blocks
typedef struct block{
    int block_num;
    char data[BLOCK_SIZE];
} Block;

// Define the structure for a file
typedef struct file{
    int num_blocks;
    int block_ptrs[10];
    char name[FILE_NAME_LENGTH];
    int size;
} File;

// Define the simulated filesystem
Block file_system[MAX_BLOCKS];
File *files[MAX_FILES];
int num_files = 0;
int num_blocks_used = 0;

// Helper function to find a free block in the file system
int find_free_block(){
    int i;
    for(i = 0; i < MAX_BLOCKS; i++){
        if(file_system[i].block_num == -1){
            return i;
        }
    }
    return -1; // No free block found
}

// Helper function to initialize a file block
void init_block(Block *block){
    block->block_num = -1;
    memset(block->data, 0, BLOCK_SIZE);
}

// Helper function to allocate new blocks to a file
void allocate_blocks(File *file, int num_blocks){
    int i;
    for(i = 0; i < num_blocks; i++){
        int block_num = find_free_block();
        if(block_num == -1){
            printf("Sorry, not enough space in the file system to allocate blocks for this file\n");
            return;
        }
        file_system[block_num].block_num = block_num;
        file->block_ptrs[i] = block_num;
        num_blocks_used++;
    }
    file->num_blocks = num_blocks;
}

// Function to create a new file in the file system
void create_file(char *name, char *content, int size){
    // Check if the file already exists
    int i;
    for(i = 0; i < num_files; i++){
        if(strcmp(files[i]->name, name) == 0){
            printf("Sorry, a file with the same name already exists in the file system\n");
            return;
        }
    }
    // Create a new file
    File *file = (File*)malloc(sizeof(File));
    file->size = size;
    strcpy(file->name, name);
    // Allocate blocks to the file
    int num_blocks = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    allocate_blocks(file, num_blocks);
    // Write the content of the file to the file blocks
    int content_index = 0;
    for(i = 0; i < file->num_blocks; i++){
        char *data = file_system[file->block_ptrs[i]].data;
        int j;
        for(j = 0; j < BLOCK_SIZE && content_index < size; j++){
            data[j] = content[content_index++];
        }
    }
    // Add the file to the file system
    files[num_files++] = file;
}

// Function to read the content of a file from the file system
char* read_file(char *name){
    int i;
    for(i = 0; i < num_files; i++){
        if(strcmp(files[i]->name, name) == 0){
            int size = files[i]->size;
            char *content = (char*)malloc(sizeof(char) * (size+1));
            int content_index = 0;
            int j;
            for(j = 0; j < files[i]->num_blocks; j++){
                Block block = file_system[files[i]->block_ptrs[j]];
                int k;
                for(k = 0; k < BLOCK_SIZE && content_index < size; k++){
                    content[content_index++] = block.data[k];
                }
            }
            content[size] = '\0';
            return content;
        }
    }
    printf("Sorry, no such file found in the file system\n");
    return NULL;
}

// Function to delete a file from the file system
void delete_file(char *name){
    int i;
    for(i = 0; i < num_files; i++){
        if(strcmp(files[i]->name, name) == 0){
            int j;
            for(j = 0; j < files[i]->num_blocks; j++){
                file_system[files[i]->block_ptrs[j]].block_num = -1;
                num_blocks_used--;
            }
            free(files[i]);
            // Remove the file from the files array
            for(j = i + 1; j < num_files; j++){
                files[j-1] = files[j];
            }
            num_files--;
            return;
        }
    }
    printf("Sorry, no such file found in the file system\n");
}

int main(){
    // Initialize the file system
    int i;
    for(i = 0; i < MAX_BLOCKS; i++){
        init_block(&file_system[i]);
    }
    // Create some files
    create_file("file1", "Hello, world!", 13);
    create_file("file2", "The quick brown fox jumps over the lazy dog.", 44);
    create_file("file3", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco labor", 200);
    // Read the content of a file
    char *content = read_file("file2");
    printf("Content of file2:\n%s\n", content);
    free(content);
    // Delete a file
    delete_file("file1");
    // Create a new file with too much content
    create_file("file4", "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()", 65);
    return 0;
}