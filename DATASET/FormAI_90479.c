//FormAI DATASET v1.0 Category: File system simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants */
#define BLOCK_SIZE 512
#define MAX_BLOCKS 1024 
#define MAX_NAME_LENGTH 256

/* File data structure */
typedef struct {
    char name[MAX_NAME_LENGTH];
    int size;
    int blocks[MAX_BLOCKS];
    int num_blocks;
} file_t;

/* Global variables */
char disk[MAX_BLOCKS][BLOCK_SIZE];
int free_blocks[MAX_BLOCKS];
file_t files[MAX_BLOCKS];
int num_files = 0;

/* Function declarations */
int get_free_block();
void free_block(int block_num);
void create_file(char* name, int size);
void delete_file(char* name);
void write_file(char* name, char* data);
void read_file(char* name, char* buffer);
void display_files();
void display_disk_usage();

/* Main function */
int main() {
    // Initialize free block list
    for (int i=0; i<MAX_BLOCKS; i++) {
        free_blocks[i] = 1;
    }

    // Print menu
    printf("C File System Simulation\n");
    printf("========================\n");
    printf("Commands:\n");
    printf("create <filename> <size>\n");
    printf("delete <filename>\n");
    printf("write <filename> <data>\n");
    printf("read <filename>\n");
    printf("display\n");
    printf("exit\n\n");

    // Get and process user commands
    char command[100];
    char arg1[100];
    char arg2[100];
    while (1) {
        printf("> ");
        scanf("%s", command);
        if (strcmp(command, "create") == 0) {
            scanf("%s %s", arg1, arg2);
            int size = atoi(arg2);
            create_file(arg1, size);
        }
        else if (strcmp(command, "delete") == 0) {
            scanf("%s", arg1);
            delete_file(arg1);
        }
        else if (strcmp(command, "write") == 0) {
            scanf("%s", arg1);
            fgets(arg2, sizeof(arg2), stdin);
            write_file(arg1, arg2);
        }
        else if (strcmp(command, "read") == 0) {
            scanf("%s", arg1);
            char buffer[MAX_BLOCKS*BLOCK_SIZE];
            read_file(arg1, buffer);
            printf("%s\n", buffer);
        }
        else if (strcmp(command, "display") == 0) {
            display_files();
            display_disk_usage();
        }
        else if (strcmp(command, "exit") == 0) {
            break;
        }
        else {
            printf("Invalid command\n");
        }
    }

    return 0;
}

/* Helper function to get a free block */
int get_free_block() {
    for (int i=0; i<MAX_BLOCKS; i++) {
        if (free_blocks[i] == 1) {
            free_blocks[i] = 0;
            return i;
        }
    }
    return -1;
}

/* Helper function to free a block */
void free_block(int block_num) {
    free_blocks[block_num] = 1;
}

/* Function to create a new file */
void create_file(char* name, int size) {
    // Check if file with same name already exists
    for (int i=0; i<num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("File with same name already exists\n");
            return;
        }
    }

    // Allocate blocks for file
    int blocks_needed = size / BLOCK_SIZE + 1;
    if (blocks_needed > MAX_BLOCKS) {
        printf("File size too large\n");
        return;
    }
    int block_nums[blocks_needed];
    for (int i=0; i<blocks_needed; i++) {
        block_nums[i] = get_free_block();
        if (block_nums[i] == -1) {
            printf("Not enough free space\n");
            for (int j=0; j<i; j++) {
                free_block(block_nums[j]);
            }
            return;
        }
    }

    // Add file to list of files
    file_t new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    new_file.num_blocks = blocks_needed;
    for (int i=0; i<blocks_needed; i++) {
        new_file.blocks[i] = block_nums[i];
    }
    files[num_files++] = new_file;

    printf("File created successfully\n");
}

/* Function to delete a file */
void delete_file(char* name) {
    int file_index = -1;
    for (int i=0; i<num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index == -1) {
        printf("File not found\n");
        return;
    }
    for (int i=0; i<files[file_index].num_blocks; i++) {
        free_block(files[file_index].blocks[i]);
    }
    for (int i=file_index; i<num_files-1; i++) {
        files[i] = files[i+1];
    }
    num_files--;
    printf("File deleted successfully\n");
}

/* Function to write to a file */
void write_file(char* name, char* data) {
    int file_index = -1;
    for (int i=0; i<num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index == -1) {
        printf("File not found\n");
        return;
    }
    int data_size = strlen(data);
    if (data_size > files[file_index].size) {
        printf("Data size exceeds file size\n");
        return;
    }
    int block_size = sizeof(disk[0]);
    char* buffer = malloc(block_size);
    int block_index;
    int byte_index;
    for (int i=0; i<data_size; i++) {
        block_index = files[file_index].blocks[i / block_size];
        byte_index = i % block_size;
        disk[block_index][byte_index] = data[i];
    }
    printf("File updated successfully\n");
}

/* Function to read from a file */
void read_file(char* name, char* buffer) {
    int file_index = -1;
    for (int i=0; i<num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index == -1) {
        printf("File not found\n");
        return;
    }
    int data_size = files[file_index].size;
    int block_size = sizeof(disk[0]);
    int block_index;
    int byte_index;
    for (int i=0; i<data_size; i++) {
        block_index = files[file_index].blocks[i / block_size];
        byte_index = i % block_size;
        buffer[i] = disk[block_index][byte_index];
    }
    buffer[data_size] = '\0';
}

/* Function to display list of files */
void display_files() {
    printf("Files:\n");
    for (int i=0; i<num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

/* Function to display disk usage */
void display_disk_usage() {
    int used_blocks = 0;
    for (int i=0; i<MAX_BLOCKS; i++) {
        if (free_blocks[i] == 0) {
            used_blocks++;
        }
    }
    printf("Disk usage: %d/%d blocks used\n", used_blocks, MAX_BLOCKS);
}