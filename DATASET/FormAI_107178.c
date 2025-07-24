//FormAI DATASET v1.0 Category: File system simulation ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCK_SIZE 512
#define NUM_BLOCKS 4096
#define FILE_NAME_SIZE 128
#define MAX_FILES 128

typedef struct {
    char file_name[FILE_NAME_SIZE];
    int start_block;
    int num_blocks;
} File;

char disk[NUM_BLOCKS][BLOCK_SIZE];
File files[MAX_FILES];
int num_files = 0;

void format_disk() {
    memset(disk, 0, sizeof(char) * NUM_BLOCKS * BLOCK_SIZE);
    num_files = 0;
}

int find_free_block(int size) {
    int blocks_needed = (size / BLOCK_SIZE) + 1;
    int count = 0;
    int start = -1;
    for(int i=0; i<NUM_BLOCKS; i++) {
        if(disk[i][0] == 0) {
            count++;
            if(start == -1) {
                start = i;
            }
        } else {
            count = 0;
            start = -1;
        }
        if(count == blocks_needed) {
            return start;
        }
    }
    return -1;
}

int create_file(char *file_name, int size) {
    if(num_files == MAX_FILES) {
        return -1;
    }
    int start = find_free_block(size);
    if(start == -1) {
        return -2;
    }
    File new_file;
    strncpy(new_file.file_name, file_name, FILE_NAME_SIZE);
    new_file.start_block = start;
    new_file.num_blocks = (size / BLOCK_SIZE) + 1;
    memcpy(disk[start], file_name, FILE_NAME_SIZE);
    return num_files++;
}

int write_to_file(char *file_name, char *data) {
    for(int i=0; i<num_files; i++) {
        if(strcmp(files[i].file_name, file_name) == 0) {
            int current_block = files[i].start_block;
            int data_len = strlen(data);
            int bytes_written = 0;
            while(bytes_written < data_len) {
                if(current_block == -1) {
                    return -1;
                }
                memcpy(disk[current_block], data+bytes_written, BLOCK_SIZE);
                current_block = strtol(disk[current_block], NULL, 10);
                bytes_written += BLOCK_SIZE;
            }
            return 0;
        }
    }
    return -2;
}

int read_file(char *file_name, char *buffer, int buffer_size) {
    for(int i=0; i<num_files; i++) {
        if(strcmp(files[i].file_name, file_name) == 0) {
            int current_block = files[i].start_block;
            int bytes_read = 0;
            while(bytes_read < buffer_size) {
                if(current_block == -1) {
                    return -1;
                }
                memcpy(buffer+bytes_read, disk[current_block], BLOCK_SIZE);
                current_block = strtol(disk[current_block], NULL, 10);
                bytes_read += BLOCK_SIZE;
            }
            return 0;
        }
    }
    return -2;
}

int main() {
    format_disk();
    int file1 = create_file("file1.txt", 1024);
    int file2 = create_file("file2.txt", 2048);
    int file3 = create_file("file3.txt", 3072);
    if(file1 == -1 || file2 == -1 || file3 == -1) {
        printf("Failed to create file.\n");
        return -1;
    }
    if(file1 == -2 || file2 == -2 || file3 == -2) {
        printf("Not enough space on disk.\n");
        return -1;
    }
    printf("Files created successfully.\n");
    char data[6144] = "This is some random data to write to the files.";
    int write_res1 = write_to_file("file1.txt", data);
    int write_res2 = write_to_file("file2.txt", data);
    int write_res3 = write_to_file("file3.txt", data);
    if(write_res1 != 0 || write_res2 != 0 || write_res3 != 0) {
        printf("Failed to write to file.\n");
        return -1;
    }
    printf("Data written to files successfully.\n");
    char buffer1[1025];
    char buffer2[2049];
    char buffer3[3073];
    int read_res1 = read_file("file1.txt", buffer1, 1025);
    int read_res2 = read_file("file2.txt", buffer2, 2049);
    int read_res3 = read_file("file3.txt", buffer3, 3073);
    if(read_res1 != 0 || read_res2 != 0 || read_res3 != 0) {
        printf("Failed to read from file.\n");
        return -1;
    }
    buffer1[1024] = '\0';
    buffer2[2048] = '\0';
    buffer3[3072] = '\0';
    printf("Data read from files:\n%s\n%s\n%s\n", buffer1, buffer2, buffer3);
    return 0;
}