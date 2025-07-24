//FormAI DATASET v1.0 Category: File system simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512    //size of each block in bytes 
#define FAT_SIZE 4096    //number of blocks in FAT table
#define FILE_SIZE 2048   //number of data blocks for files 
#define DIR_SIZE 16      //number of entries in root directory 
#define FILENAME_SIZE 12 //size of filename 

typedef struct {
    char filename[FILENAME_SIZE];
    int start_block;
    int file_size;
} DirectoryEntry;

//function to intialize FAT table 
void init_fat(int *fat_table) {
    int i;
    for (i=0; i<FAT_SIZE; i++) {
        fat_table[i] = -1; //initialize each block as available (-1)
    }
    fat_table[0] = 0; //first block is reserved for root directory 
}

//function to allocate a block from FAT table 
int allocate_block(int *fat_table) {
    int i;
    for (i=1; i<FAT_SIZE; i++) { //start from second block 
        if (fat_table[i] == -1) {
            fat_table[i] = 0; //mark as used (0)
            return i;
        }
    }
    return -1; //no available blocks 
}

//function to free a block in FAT table 
void free_block(int *fat_table, int block_num) {
    fat_table[block_num] = -1; //mark as available (-1)
}

//function to add a new file to root directory 
void add_file(DirectoryEntry *root_dir, int *fat_table, char *filename, int file_size) {
    int i;
    for (i=0; i<DIR_SIZE; i++) {
        if (root_dir[i].file_size == 0) { //find empty entry 
            strcpy(root_dir[i].filename, filename); //add filename 
            int start_block = allocate_block(fat_table); //allocate first data block 
            root_dir[i].start_block = start_block;
            root_dir[i].file_size = file_size;
            if (file_size > BLOCK_SIZE) {
                int curr_block = start_block;
                int remaining_size = file_size - BLOCK_SIZE;
                while (remaining_size > 0) { //allocate additional data blocks 
                    int next_block = allocate_block(fat_table);
                    fat_table[curr_block] = next_block;
                    remaining_size -= BLOCK_SIZE;
                    curr_block = next_block;
                }
            }
            printf("File '%s' added to file system.\n", filename);
            return;
        }
    }
    printf("Root directory is full!\n");
}

//function to delete a file from root directory and free its data blocks 
void delete_file(DirectoryEntry *root_dir, int *fat_table, char *filename) {
    int i;
    for (i=0; i<DIR_SIZE; i++) {
        if (strcmp(root_dir[i].filename, filename) == 0) { //find file entry 
            int curr_block = root_dir[i].start_block;
            while (curr_block != 0) { //free all data blocks 
                int next_block = fat_table[curr_block];
                free_block(fat_table, curr_block);
                curr_block = next_block;
            }
            root_dir[i].filename[0] = '\0'; //clear filename 
            root_dir[i].start_block = -1; //mark deleted 
            root_dir[i].file_size = 0;
            printf("File '%s' deleted from file system.\n", filename);
            return;
        }
    }
    printf("File '%s' not found!\n", filename);
}

//function to print contents of root directory 
void print_root_dir(DirectoryEntry *root_dir) {
    printf("\nRoot Directory:\n");
    printf("------------------\n");
    int i;
    for (i=0; i<DIR_SIZE; i++) {
        if (root_dir[i].file_size != 0) { //only print used entries 
            printf("Filename: %s\n", root_dir[i].filename);
            printf("Start Block: %d\n", root_dir[i].start_block);
            printf("File Size: %d bytes\n", root_dir[i].file_size);
            printf("\n");
        }
    }
}

//function to print contents of FAT table 
void print_fat(int *fat_table) {
    printf("\nFAT Table:\n");
    printf("----------\n");
    int i;
    for (i=0; i<FAT_SIZE; i++) {
        if (fat_table[i] != -1) { //only print used blocks 
            printf("Block %d: %d\n", i, fat_table[i]);
        }
    }
}

int main() {
    int fat_table[FAT_SIZE];
    init_fat(fat_table);
    DirectoryEntry root_dir[DIR_SIZE];
    memset(&root_dir, 0, sizeof(root_dir)); //initialize all entries to 0 
    printf("File system initialized.\n");

    add_file(root_dir, fat_table, "file1.txt", 1024);
    add_file(root_dir, fat_table, "file2.mp3", 26624);
    add_file(root_dir, fat_table, "file3.pdf", 40960);
    print_root_dir(root_dir);
    print_fat(fat_table);

    delete_file(root_dir, fat_table, "file2.mp3");
    printf("\n");
    print_root_dir(root_dir);
    print_fat(fat_table);

    add_file(root_dir, fat_table, "file4.docx", 81920);
    print_root_dir(root_dir);
    print_fat(fat_table);

    return 0;
}