//FormAI DATASET v1.0 Category: Data recovery tool ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DISK_SIZE 1024
#define BLOCK_SIZE 32
#define MAX_FILENAME_LEN 16
#define MAX_FILES 32

// each block
typedef struct _block {
    int id;
    char data[BLOCK_SIZE];
    int next_block_id;
} Block;

// each file
typedef struct _file {
    int start_block_id;
    int size_in_blocks;
    char filename[MAX_FILENAME_LEN];
} File;

Block disk[DISK_SIZE];
int free_block_id = 0;
int file_count = 0;
File files[MAX_FILES];

void initialize_disk() {
    for (int i = 0; i < DISK_SIZE; i++) {
        disk[i].id = i;
        disk[i].next_block_id = i + 1; // link all blocks together
    }
    // last block does not link to any other block
    disk[DISK_SIZE - 1].next_block_id = -1;
}

void create_file(char* filename, char* data) {
    int data_len = strlen(data);
    int file_size_in_blocks = data_len / BLOCK_SIZE + 1;

    if (file_count == MAX_FILES || free_block_id == -1 || file_size_in_blocks > DISK_SIZE) {
        printf("Failed to create file.\n");
        return;
    }

    File new_file;
    strcpy(new_file.filename, filename);
    new_file.start_block_id = free_block_id;
    new_file.size_in_blocks = file_size_in_blocks;
    files[file_count++] = new_file;

    int block_id = free_block_id;
    for (int i = 0; i < file_size_in_blocks; i++) {
        strncpy(disk[block_id].data, &data[i * BLOCK_SIZE], BLOCK_SIZE);
        block_id = disk[block_id].next_block_id;
    }
    // set the last block of the file to point to -1 (end of file)
    disk[block_id].next_block_id = -1;

    // update free_block_id to next available block
    free_block_id = disk[block_id].next_block_id;
}

void print_file_data(char* filename) {
    for (int i = 0; i < file_count; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            int block_id = files[i].start_block_id;
            while (block_id != -1) {
                printf("%s", disk[block_id].data);
                block_id = disk[block_id].next_block_id;
            }
            printf("\n");
            return;
        }
    }
    printf("File not found.\n");
}

int main() {
    initialize_disk();

    char* data1 = "This is a test file.";
    char* data2 = "This is another test file.";

    create_file("file1.txt", data1);
    create_file("file2.txt", data2);

    printf("Printing file data...\n");
    print_file_data("file1.txt");
    print_file_data("file2.txt");

    return 0;
}