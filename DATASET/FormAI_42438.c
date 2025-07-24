//FormAI DATASET v1.0 Category: File system simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_LENGTH 50
#define BLOCK_SIZE 1024
#define NUM_BLOCKS 100

typedef struct {
    char file_name[FILE_NAME_LENGTH];
    int block_number;
} File;

typedef struct {
    char data[BLOCK_SIZE];
    int next_block;
} Block;

File file_table[NUM_BLOCKS];
Block disk[NUM_BLOCKS];

void initialize_file_table() {
    int i;
    for (i = 0; i < NUM_BLOCKS; i++) {
        file_table[i].block_number = -1;
    }
}

void create_file(char file_name[FILE_NAME_LENGTH]) {
    int i;
    for (i = 0; i < NUM_BLOCKS; i++) {
        if (file_table[i].block_number == -1) {
            strcpy(file_table[i].file_name, file_name);
            file_table[i].block_number = i;
            disk[i].next_block = -1;
            printf("File created successfully!\n");
            return;
        }
    }
    printf("No space on disk to create file!\n");
}

void write_to_file(char file_name[FILE_NAME_LENGTH], char data[BLOCK_SIZE]) {
    int i;
    for (i = 0; i < NUM_BLOCKS; i++) {
        if (strcmp(file_table[i].file_name, file_name) == 0) {
            int block_number = file_table[i].block_number;
            while (disk[block_number].next_block != -1) {
                block_number = disk[block_number].next_block;
            }
            int j;
            for (j = 0; j < BLOCK_SIZE; j++) {
                disk[block_number].data[j] = data[j];
            }
            int k;
            for (k = 0; k < NUM_BLOCKS; k++) {
                if (file_table[k].block_number == -1) {
                    disk[block_number].next_block = k;
                    file_table[k].block_number = k;
                    strcpy(file_table[k].file_name, file_name);
                    disk[k].next_block = -1;
                    printf("Data written successfully!\n");
                    return;
                }
            }
            printf("No space on disk to write more data!\n");
            return;
        }
    }
    printf("File not found!\n");
}

void read_file(char file_name[FILE_NAME_LENGTH]) {
    int i;
    for (i = 0; i < NUM_BLOCKS; i++) {
        if (strcmp(file_table[i].file_name, file_name) == 0) {
            int block_number = file_table[i].block_number;
            printf("Data in file:\n");
            while (block_number != -1) {
                printf("%s", disk[block_number].data);
                block_number = disk[block_number].next_block;
            }
            return;
        }
    }
    printf("File not found!\n");
}

int main() {
    initialize_file_table();
    create_file("example.txt");
    write_to_file("example.txt", "This is some test data to be written to the file.");
    read_file("example.txt");
    return 0;
}