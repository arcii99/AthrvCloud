//FormAI DATASET v1.0 Category: File system simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME 20

// Directory Entry struct
typedef struct {
    int inode_number;
    char file_name[MAX_FILENAME];
} Directory_Entry;

// Inode struct
typedef struct {
    int inode_number;
    int file_size;
    int blocks[10]; // max blocks for a file is 10
} Inode;

// File System struct
typedef struct {
    int num_of_files;
    Directory_Entry directory[MAX_FILES];
    Inode inodes[MAX_FILES];
    char blocks[MAX_FILES][512];
} File_System;

File_System fs;

void initialize_directory() {
    fs.num_of_files = 0;
}

int create_new_file(char *filename) {
    // check if filename already exists
    for(int i=0; i < fs.num_of_files; i++) {
        if(strcmp(fs.directory[i].file_name, filename) == 0) {
            printf("Error: File with name '%s' already exists.\n", filename);
            return -1;
        }
    }

    // create new inode for the file
    Inode new_inode;
    new_inode.inode_number = fs.num_of_files;
    new_inode.file_size = 0;

    // add inode to the file system
    fs.inodes[fs.num_of_files] = new_inode;

    // add new directory entry
    Directory_Entry new_dir_entry;
    new_dir_entry.inode_number = fs.num_of_files;
    strcpy(new_dir_entry.file_name, filename);
    fs.directory[fs.num_of_files] = new_dir_entry;

    // update number of files in file system
    fs.num_of_files++;

    // return inode number
    return new_inode.inode_number;
}

int get_inode_number(char *filename) {
    // find inode number of file with matching filename
    for(int i=0; i < fs.num_of_files; i++) {
        if(strcmp(fs.directory[i].file_name, filename) == 0) {
            return fs.directory[i].inode_number;
        }
    }

    // file does not exist
    printf("Error: File with name '%s' does not exist.\n", filename);
    return -1;
}

int write_to_file(char *filename, char *content) {
    int inode_number = get_inode_number(filename); // get inode number of file
    if(inode_number == -1) {
        return -1; // file does not exist
    }

    Inode *inode = &fs.inodes[inode_number];
    int file_size = inode->file_size;
    int num_blocks = file_size / 512 + 1; // calculate number of blocks in use

    // check if file has enough space for new content
    if(num_blocks == 10) {
        printf("Error: File '%s' is already full.\n", filename);
        return -1;
    }

    // find first available block for writing
    int block_number = -1;
    for(int i=0; i < fs.num_of_files && block_number == -1; i++) {
        if(fs.blocks[i][0] == '\0') {
            block_number = i;
        }
    }

    // update inode and block
    inode->blocks[num_blocks] = block_number;
    inode->file_size += strlen(content);
    strcpy(fs.blocks[block_number], content);

    return strlen(content);
}

char* read_file(char *filename) {
    int inode_number = get_inode_number(filename); // get inode number of file
    if(inode_number == -1) {
        return NULL; // file does not exist
    }

    Inode *inode = &fs.inodes[inode_number];
    int file_size = inode->file_size;
    int num_blocks = file_size / 512 + 1; // calculate number of blocks in use

    char *content = (char*) malloc(file_size + 1);
    int index = 0;

    // read content from all blocks
    for(int i=0; i < num_blocks; i++) {
        strcpy(content + index, fs.blocks[inode->blocks[i]]);
        index += strlen(fs.blocks[inode->blocks[i]]);
    }

    content[file_size] = '\0'; // add end of line character

    return content;
}

int main() {
    initialize_directory(); // initialize file system

    // create new files
    int file1 = create_new_file("file1.txt");
    int file2 = create_new_file("file2.txt");
    int file3 = create_new_file("file3.txt");

    // add content to files
    write_to_file("file1.txt", "Hello world!");
    write_to_file("file1.txt", " This is a test file.");

    write_to_file("file2.txt", "This is another file.");

    write_to_file("file3.txt", "This is a third file.");

    // read content of files
    printf("Content of file1.txt: %s\n", read_file("file1.txt"));
    printf("Content of file2.txt: %s\n", read_file("file2.txt"));
    printf("Content of file3.txt: %s\n", read_file("file3.txt"));

    // try to add content to full file
    write_to_file("file1.txt", " This will not be added to the file.");

    // try to read content of non-existing file
    printf("Content of file4.txt: %s\n", read_file("file4.txt"));

    return 0;
}