//FormAI DATASET v1.0 Category: Data recovery tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#define BLOCK_SIZE 512    // size of each block in bytes
#define NUM_BLOCKS 10000  // total number of blocks in the disk
#define NUM_FILES 100     // maximum number of files that can be recovered

// struct representing an individual block in the disk
typedef struct block {
    char data[BLOCK_SIZE];  // data stored in the block
    bool available;         // whether or not the block is available for use
    int next;               // index of the next block in the chain
} block;

// struct representing a file that can be recovered
typedef struct file {
    char name[20];        // name of the file
    int start;            // index of the first block in the file's chain
    int size;             // total size of the file in bytes
} file;

// global variables
block disk[NUM_BLOCKS];
file recovered_files[NUM_FILES];
int num_recovered_files = 0;

// prototypes for helper functions
int get_available_block();
int recover_files();
void reconstruct_file(char* filename, int start, int size);

// asynchronously recover files from the disk
int main() {
    int fd = open("disk.img", O_RDONLY);  // open the disk image file
    if (fd == -1) {
        perror("Error: cannot open disk image file");
        return 1;
    }
    off_t offset = 0;  // start reading from the beginning of the file

    // read in data from the disk image file and initialize the disk
    for (int i = 0; i < NUM_BLOCKS; i++) {
        ssize_t bytes_read = pread(fd, disk[i].data, BLOCK_SIZE, offset);
        if (bytes_read == -1) {
            perror("Error: cannot read from disk image file");
            return 1;
        }
        else if (bytes_read == 0) {
            // end of file reached
            break;
        }
        offset += BLOCK_SIZE;

        // initialize the block
        disk[i].available = (disk[i].data[0] == '\0');  // mark blocks with no data as available
        if (i == NUM_BLOCKS - 1) {
            disk[i].next = -1;  // last block in the chain has no next block
        }
        else {
            disk[i].next = i + 1;  // set the index of the next block in the chain
        }
    }

    // recover files from the disk
    int recovered = recover_files();
    if (recovered == -1) {
        printf("No files could be recovered\n");
    }
    else {
        printf("%d files recovered\n", recovered);
    }

    // close the disk image file
    if (close(fd) == -1) {
        perror("Error: cannot close disk image file");
        return 1;
    }

    return 0;
}

// helper function to find the index of an available block
int get_available_block() {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (disk[i].available) {
            return i;
        }
    }
    return -1;  // no available blocks found
}

// helper function to recover files from the disk
int recover_files() {
    int num_recovered = 0;
    int curr_block = 0;
    
    while (curr_block != -1 && num_recovered < NUM_FILES) {
        if (!disk[curr_block].available) {
            // start of a file found
            int start_block = curr_block;
            char filename[20];
            int filename_len = strlen(disk[curr_block].data);
            strncpy(filename, disk[curr_block].data, filename_len);
            filename[filename_len] = '\0';

            int size = 0;
            curr_block = disk[curr_block].next;
            while (curr_block != -1 && !disk[curr_block].available) {
                // middle or end of a file found
                size += BLOCK_SIZE;
                curr_block = disk[curr_block].next;
            }

            if (curr_block == -1) {
                // end of disk reached unexpectedly
                printf("Error: end of disk reached unexpectedly\n");
                return -1;
            }

            // keep track of the recovered file
            strncpy(recovered_files[num_recovered].name, filename, 20);
            recovered_files[num_recovered].start = start_block;
            recovered_files[num_recovered].size = size + BLOCK_SIZE;
            num_recovered++;

            // reconstruct the file on the local file system
            reconstruct_file(filename, start_block, size);
        }
        else {
            curr_block = disk[curr_block].next;
        }
    }

    return num_recovered;
}

// helper function to reconstruct a file from the disk
void reconstruct_file(char* filename, int start, int size) {
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (fd == -1) {
        perror("Error: cannot create recovered file");
        return;
    }

    char buffer[size + BLOCK_SIZE];
    int offset = 0;
    while (start != -1) {
        memcpy(buffer + offset, disk[start].data, BLOCK_SIZE);
        offset += BLOCK_SIZE;
        start = disk[start].next;
    }

    ssize_t bytes_written = write(fd, buffer, size + BLOCK_SIZE);
    if (bytes_written == -1) {
        perror("Error: cannot write to recovered file");
    }
    else {
        printf("File \"%s\" successfully recovered\n", filename);
    }

    if (close(fd) == -1) {
        perror("Error: cannot close recovered file");
    }
}