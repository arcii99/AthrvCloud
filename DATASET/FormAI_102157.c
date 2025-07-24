//FormAI DATASET v1.0 Category: File system simulation ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// File System Constants
#define MAX_FILES 50
#define MAX_FILE_NAME 20
#define BLOCK_SIZE 512
#define NUM_BLOCKS 1024

// File System Entry Structure
struct file_entry{
    char file_name[MAX_FILE_NAME];
    int start_block; // starting block number of the file
    int num_blocks; // number of blocks occupied by the file
};

// Globals
char disk[NUM_BLOCKS][BLOCK_SIZE];
int free_blocks = NUM_BLOCKS;
struct file_entry file_table[MAX_FILES];
int num_files = 0;

// Function Declarations
int allocate_blocks(int num_blocks);
void deallocate_blocks(int start_block, int num_blocks);
void ls();
int create_file(char *file_name, char *data, int size);
int write_file(char *file_name, char *data, int size);
int read_file(char *file_name, char *output_buffer, int size);
int delete_file(char *file_name);

// Main Function
int main(){
    // Your Code Here
    return 0;
}