//FormAI DATASET v1.0 Category: File system simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512 
#define FILE_NAME_SIZE 20 
#define MAX_FILE_SYSTEM_SIZE 4096 

// Structure to represent each file
typedef struct{
    int start_block; // Start block of the file
    int num_blocks; // Total number of blocks used by the file
    char file_name[FILE_NAME_SIZE]; // Name of the file
    int file_size; // Size of the file in bytes
} FileDescriptor;

// Structure to represent each block in the file system
typedef struct{
    char data[BLOCK_SIZE]; // Data stored in the block
    int next_block; // Index of the next block in the file
} Block;

// Global variables
Block file_system[MAX_FILE_SYSTEM_SIZE]; // Array to represent the file system blocks
FileDescriptor fd_table[MAX_FILE_SYSTEM_SIZE]; // Array to hold file descriptors
int next_block_index = 0; // Index of the next free block
int next_fd_index = 0; // Index of the next free file descriptor

// Function to write data to a block
void write_block(int block_index, char *data, int size, int next_block){
    memcpy(file_system[block_index].data, data, size); // Copy the data to the block
    file_system[block_index].next_block = next_block; // Set the index of the next block in the file
}

// Function to read data from a block
void read_block(int block_index, char *data, int size){
    memcpy(data, file_system[block_index].data, size); // Copy data from block to data buffer
}

// Function to create a file
int create_file(char *file_name, int file_size){
    if(next_block_index == 0){
        // This is the first file in the system. We'll initialize the first block as the root block.
        // The root block will hold the index of the first block of every file in the system.
        write_block(next_block_index++, (char*)&next_block_index, sizeof(next_block_index), -1);
    }
    else{
        // Check if a file with the same name already exists
        int i;
        for(i=0;i<next_fd_index;i++){
            if(strcmp(fd_table[i].file_name,file_name) == 0){
                printf("Error: File with the same name already exists.\n");
                return -1;
            }
        }
    }
    int num_blocks = file_size/BLOCK_SIZE + (file_size%BLOCK_SIZE!=0); // Calculate the number of blocks required for the file
    if(num_blocks > MAX_FILE_SYSTEM_SIZE - next_block_index - 1){
        printf("Error: File system is full. Cannot create file.\n");
        return -1;
    }
    // Allocate the required blocks for the file
    int start_block = next_block_index;
    int i;
    for(i=0;i<num_blocks-1;i++){
        write_block(next_block_index++, "", 0, next_block_index);
    }
    write_block(next_block_index++, "", 0, -1);
    // Add an entry in the file descriptor table
    FileDescriptor fd;
    fd.start_block = start_block;
    fd.num_blocks = num_blocks;
    strcpy(fd.file_name,file_name);
    fd.file_size = file_size;
    fd_table[next_fd_index++] = fd;
    printf("%s created successfully with size %d bytes.\n", file_name, file_size);
    return 0;
}

// Function to write data to a file
int write_to_file(char *file_name, char *data, int size){
    int i;
    for(i=0;i<next_fd_index;i++){
        if(strcmp(fd_table[i].file_name,file_name) == 0){
            // File found. Write data to its blocks
            int block_index = fd_table[i].start_block;
            int remaining_size = size;
            while(block_index != -1){
                if(remaining_size > BLOCK_SIZE){
                    write_block(block_index, &data[size-remaining_size], BLOCK_SIZE, block_index+1);
                    remaining_size -= BLOCK_SIZE;
                    block_index = file_system[block_index].next_block;
                }
                else{
                    write_block(block_index, &data[size-remaining_size], remaining_size, -1);
                    remaining_size = 0;
                }
            }
            if(remaining_size > 0){
                printf("Error: File system is full. Cannot write %d bytes to the file.\n", remaining_size);
                return -1;
            }
            fd_table[i].file_size += size;
            printf("%d bytes written to %s.\n", size, file_name);
            return 0;
        }
    }
    printf("Error: File not found.\n");
    return -1;
}

// Function to read data from a file
int read_from_file(char *file_name, char *data, int size){
    int i;
    for(i=0;i<next_fd_index;i++){
        if(strcmp(fd_table[i].file_name,file_name) == 0){
            // File found. Read data from its blocks
            int block_index = fd_table[i].start_block;
            int remaining_size = size < fd_table[i].file_size ? size : fd_table[i].file_size;
            while(block_index != -1 && remaining_size > 0){
                if(remaining_size > BLOCK_SIZE){
                    read_block(block_index, &data[size-remaining_size], BLOCK_SIZE);
                    remaining_size -= BLOCK_SIZE;
                    block_index = file_system[block_index].next_block;
                }
                else{
                    read_block(block_index, &data[size-remaining_size], remaining_size);
                    remaining_size = 0;
                }
            }
            printf("%d bytes read from %s.\n", size-remaining_size, file_name);
            return 0;
        }
    }
    printf("Error: File not found.\n");
    return -1;
}

// Function to delete a file
int delete_file(char *file_name){
    int i,j;
    for(i=0;i<next_fd_index;i++){
        if(strcmp(fd_table[i].file_name,file_name) == 0){
            // File found. Delete its blocks
            int block_index = fd_table[i].start_block;
            int num_blocks = fd_table[i].num_blocks;
            for(j=0;j<num_blocks;j++){
                int temp = file_system[block_index].next_block;
                file_system[block_index].next_block = -2; // Mark the block as free
                block_index = temp;
            }
            // Delete the file descriptor from the table
            for(j=i+1;j<next_fd_index;j++){
                fd_table[j-1] = fd_table[j];
            }
            next_fd_index--;
            printf("%s deleted successfully.\n", file_name);
            return 0;
        }
    }
    printf("Error: File not found.\n");
    return -1;
}

int main(){
    // Demo
    char data[500];
    int size = 500;
    for(int i=0;i<500;i++){
        data[i] = 'a'+i%26;
    }
    create_file("file1.txt", 1000);
    create_file("file2.txt", 2000);
    write_to_file("file1.txt", data, size);
    write_to_file("file2.txt", data, size);
    char read_data[1000];
    read_from_file("file1.txt", read_data, size);
    delete_file("file2.txt");
    return 0;
}