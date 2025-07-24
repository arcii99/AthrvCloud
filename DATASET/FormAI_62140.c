//FormAI DATASET v1.0 Category: File system simulation ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DISK_BLOCKS 8192 // Total number of blocks on the disk
#define BLOCK_SIZE 512   // Size of each block on the disk
#define FILE_NAME_LENGTH 100 // Maximum length of file name

// File structure
struct file{
    char name[FILE_NAME_LENGTH]; // Name of the file
    int size; // Size of the file in bytes
    int block_num; // Starting block number of the file
};

// Disk structure
struct disk{
    char data[DISK_BLOCKS][BLOCK_SIZE]; // Data stored on each block of the disk
    int free_blocks; // Number of blocks free on the disk
};

// Function to initialize the disk
void init_disk(struct disk *d){
    memset(d->data, 0, sizeof(d->data)); // Initialize all blocks to zero
    d->free_blocks = DISK_BLOCKS; // Set all blocks as free
}

// Function to create a new file
void create_file(struct disk *d, struct file *f, char *name, int size){
    int i;
    for(i=0; i<DISK_BLOCKS; i++){
        if(d->free_blocks > 0){
            if(d->data[i][0] == '\0'){
                strcpy(f->name, name); // Copy the file name to the file structure
                f->size = size; // Set the size of the file
                f->block_num = i; // Set the starting block number of the file
                strcpy(d->data[i], "FILE"); // Store the file tag in the block header
                d->free_blocks--; // Decrement the number of free blocks on the disk
                break;
            }
        }
        else{
            printf("Disk is full!\n"); // No free blocks available on the disk
            break;
        }
    }
}

// Function to read a file from the disk
void read_file(struct disk *d, struct file *f){
    int i, j, size, block;
    char fname[FILE_NAME_LENGTH];
    printf("Enter the name of the file to read: ");
    scanf("%s", fname);
    for(i=0; i<DISK_BLOCKS; i++){
        if(strcmp(d->data[i], "FILE") == 0){
            struct file *temp = (struct file*)malloc(sizeof(struct file)); // Allocate memory for the new file structure
            if(temp == NULL){
                printf("Out of memory!\n");
                return;
            }
            temp->block_num = i; // Set the starting block number of the file
            strcpy(temp->name, fname); // Copy the file name to the file structure
            memcpy(&(temp->size), &(d->data[i][5]), sizeof(int)); // Copy the size of the file from the block header
            if(strcmp(temp->name, f->name) == 0){ // If the file matches the input name
                size = temp->size; // Get the size of the file
                block = temp->block_num; // Get the starting block number of the file
                printf("File size: %d bytes\n", size); // Print the size of the file
                printf("File content:\n"); 
                for(j=0; j<size; j+=BLOCK_SIZE){
                    printf("%s", d->data[block+j]); // Print the file content block by block
                }
                printf("\n");
                free(temp); // Free the memory allocated for the temporary file structure
                return;
            }
            free(temp); // Free the memory allocated for the temporary file structure
        }
    }
    printf("File not found!\n"); // File not found on the disk
}

// Function to delete a file from the disk
void delete_file(struct disk *d, struct file *f){
    int i, size, block;
    char fname[FILE_NAME_LENGTH];
    printf("Enter the name of the file to delete: ");
    scanf("%s", fname);
    for(i=0; i<DISK_BLOCKS; i++){
        if(strcmp(d->data[i], "FILE") == 0){
            struct file *temp = (struct file*)malloc(sizeof(struct file)); // Allocate memory for the new file structure
            if(temp == NULL){
                printf("Out of memory!\n");
                return;
            }
            temp->block_num = i; // Set the starting block number of the file
            strcpy(temp->name, fname); // Copy the file name to the file structure
            memcpy(&(temp->size), &(d->data[i][5]), sizeof(int)); // Copy the size of the file from the block header
            if(strcmp(temp->name, f->name) == 0){ // If the file matches the input name
                size = temp->size; // Get the size of the file
                block = temp->block_num; // Get the starting block number of the file
                for(i=block; i<block+(size/BLOCK_SIZE)+(size%BLOCK_SIZE!=0); i++){
                    memset(d->data[i], 0, BLOCK_SIZE); // Clear all blocks used by the file
                    strcpy(d->data[i], ""); // Update the block header to indicate it is free
                    d->free_blocks++; // Increment the number of free blocks on the disk
                }
                printf("File deleted successfully!\n");
                free(temp); // Free the memory allocated for the temporary file structure
                return;
            }
            free(temp); // Free the memory allocated for the temporary file structure
        }
    }
    printf("File not found!\n"); // File not found on the disk
}

// Main Function
int main(){
    struct disk d; // Declare disk structure
    struct file f; // Declare file structure
    int option, size;
    char name[FILE_NAME_LENGTH];
    init_disk(&d); // Initialize the disk
    printf("Welcome to the Disk File System!\n");
    do{
        printf("Please select an option:\n");
        printf("1. Create a new file\n");
        printf("2. Read a file\n");
        printf("3. Delete a file\n");
        printf("4. Quit\n");
        printf("Enter option number: ");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("Enter the name of the file to create: ");
                scanf("%s", name);
                printf("Enter the size of the file in bytes: ");
                scanf("%d", &size);
                create_file(&d, &f, name, size); // Create a new file
                break;
            case 2:
                read_file(&d, &f); // Read a file
                break;
            case 3:
                delete_file(&d, &f); // Delete a file
                break;
            case 4:
                printf("Goodbye!\n"); // Exit the program
                break;
            default:
                printf("Invalid option!\n");
        }
    }while(option!=4);
    return 0;
}