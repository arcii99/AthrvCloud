//FormAI DATASET v1.0 Category: File system simulation ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILENAME_LENGTH 20
#define FILE_SYSTEM_SIZE 50000
#define BLOCK_SIZE 100

struct inode {
    int size;
    int blocks[10];
};

struct file {
    char name[MAX_FILENAME_LENGTH];
    struct inode inode;
};

char file_system[FILE_SYSTEM_SIZE];
struct file files[10];
int num_files = 0;

// Function declarations
void create_file(char* name, char* contents, int size);
void delete_file(char* name);
void read_file(char* name);
void write_file(char* name, char* contents, int size);

int main() {
    // Initialize file system
    for(int i=0; i<FILE_SYSTEM_SIZE; i++) file_system[i] = 0;

    // Example usage of file system commands
    create_file("file1", "This is the contents of file 1.", 30);

    char* contents = malloc(sizeof(char)*30);
    contents = "New contents for file 1.";
    write_file("file1", contents, 25);

    read_file("file1");

    delete_file("file1");

    return 0;
}

// Helper function to find free blocks in the file system
int find_free_block() {
    for(int i=0; i<FILE_SYSTEM_SIZE; i+=BLOCK_SIZE) {
        if(file_system[i] == 0) return i;
    }
    return -1;
}

// Helper function to get the size of a file
int get_file_size(char* contents) {
    int size = 0;
    for(int i=0; i<strlen(contents); i++) size++;
    return size;
}

// Helper function to add a file to the file system
void add_file_to_system(char* name, char* contents, int size, int starting_block) {
    struct inode new_inode = {
        .size = size,
        .blocks = {starting_block}
    };
    struct file new_file = {
        .inode = new_inode
    };

    strcpy(new_file.name, name);

    files[num_files++] = new_file;
}

// Helper function to delete a file from the file system
void delete_file_from_system(int index) {
    for(int i=index; i<num_files-1; i++) {
        files[i] = files[i+1];
    }

    num_files--;
}

// Function for creating a file
void create_file(char* name, char* contents, int size) {
    int starting_block = find_free_block();

    if(starting_block == -1) {
        printf("Error: No space on the file system.\n");
        return;
    }

    memcpy(&file_system[starting_block], contents, size);

    add_file_to_system(name, contents, size, starting_block);

    printf("File created successfully.\n");
}

// Function for deleting a file
void delete_file(char* name) {
    for(int i=0; i<num_files; i++) {
        if(strcmp(files[i].name, name) == 0) {
            memset(&file_system[files[i].inode.blocks[0]], 0, files[i].inode.size);
            delete_file_from_system(i);
            printf("File deleted successfully.\n");
            return;
        }
    }

    printf("Error: File not found.\n");
}

// Function for reading a file
void read_file(char* name) {
    for(int i=0; i<num_files; i++) {
        if(strcmp(files[i].name, name) == 0) {
            char* contents = malloc(sizeof(char)*files[i].inode.size);
            memcpy(contents, &file_system[files[i].inode.blocks[0]], files[i].inode.size);
            printf("%s\n", contents);
            free(contents);
            return;
        }
    }

    printf("Error: File not found.\n");
}

// Function for writing to a file
void write_file(char* name, char* contents, int size) {
    for(int i=0; i<num_files; i++) {
        if(strcmp(files[i].name, name) == 0) {
            if(size > files[i].inode.size) {
                printf("Error: New contents are too large for file.\n");
                return;
            }

            memcpy(&file_system[files[i].inode.blocks[0]], contents, size);
            files[i].inode.size = size;

            printf("File written to successfully.\n");
            return;
        }
    }

    printf("Error: File not found.\n");
}