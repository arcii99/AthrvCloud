//FormAI DATASET v1.0 Category: File system simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_FILE_SIZE 1000000
#define BLOCK_SIZE 512
#define NUM_BLOCKS 4096

typedef struct {
    char name[MAX_FILE_NAME];
    int size;
    int blocks[10];
} File;

typedef struct {
    int num_files;
    File files[100];
} FileSystem;

FileSystem fs;
char disk[NUM_BLOCKS][BLOCK_SIZE];

void create_file(char *name, int size) {
    if (fs.num_files >= 100) {
        printf("Cannot create file: Maximum number of files reached\n");
        return;
    }
    if (size > MAX_FILE_SIZE) {
        printf("Cannot create file: File size too large\n");
        return;
    }
    int num_blocks = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    int blocks[num_blocks];
    for (int i = 0; i < NUM_BLOCKS && num_blocks > 0; i++) {
        if (!disk[i][0]) {
            blocks[num_blocks - 1] = i;
            disk[i][0] = 1;
            num_blocks--;
        }
    }
    if (num_blocks > 0) {
        printf("Cannot create file: Not enough space on disk\n");
        return;
    }
    File new_file = {0};
    strncpy(new_file.name, name, MAX_FILE_NAME - 1);
    new_file.size = size;
    memcpy(new_file.blocks, blocks, sizeof(int) * strlen(blocks));
    fs.files[fs.num_files++] = new_file;
    printf("File '%s' created with size %d\n", name, size);
}

void delete_file(char *name) {
    int found = 0;
    for (int i = 0; i < fs.num_files; i++) {
        if (!strncmp(fs.files[i].name, name, MAX_FILE_NAME)) {
            found = 1;
            for (int j = 0; j < strlen(fs.files[i].blocks); j++) {
                disk[fs.files[i].blocks[j]][0] = 0;
                memset(disk[fs.files[i].blocks[j]], 0, BLOCK_SIZE);
            }
            printf("File '%s' deleted\n", name);
            for (int j = i; j < fs.num_files - 1; j++) {
                fs.files[j] = fs.files[j + 1];
            }
            fs.num_files--;
            break;
        }
    }
    if (!found) {
        printf("Cannot delete file: File '%s' not found\n", name);
    }
}

void list_files() {
    printf("Name\t\tSize\tBlocks\n");
    for (int i = 0; i < fs.num_files; i++) {
        printf("%s\t\t%d\t", fs.files[i].name, fs.files[i].size);
        for (int j = 0; j < strlen(fs.files[i].blocks); j++) {
            printf("%d ", fs.files[i].blocks[j]);
        }
        printf("\n");
    }
}

void write_to_file(char *name, char *data) {
    int found = 0;
    for (int i = 0; i < fs.num_files; i++) {
        if (!strncmp(fs.files[i].name, name, MAX_FILE_NAME)) {
            found = 1;
            int bytes_written = 0;
            for (int j = 0; j < strlen(fs.files[i].blocks); j++) {
                int block_num = fs.files[i].blocks[j];
                for (int k = 0; k < BLOCK_SIZE && bytes_written < strlen(data); k++) {
                    disk[block_num][k] = data[bytes_written];
                    bytes_written++;
                }
            }
            if (bytes_written < strlen(data)) {
                printf("Warning: Not all data written to file '%s'\n", name);
            }
            printf("%d bytes written to file '%s'\n", bytes_written, name);
            break;
        }
    }
    if (!found) {
        printf("Cannot write to file: File '%s' not found\n", name);
    }
}

void read_from_file(char *name) {
    int found = 0;
    for (int i = 0; i < fs.num_files; i++) {
        if (!strncmp(fs.files[i].name, name, MAX_FILE_NAME)) {
            found = 1;
            for (int j = 0; j < strlen(fs.files[i].blocks); j++) {
                printf("%.512s", disk[fs.files[i].blocks[j]]);
            }
            printf("\n");
            break;
        }
    }
    if (!found) {
        printf("Cannot read from file: File '%s' not found\n", name);
    }
}

int main() {
    printf("Initializing file system...\n");
    memset(disk, 0, sizeof(disk));
    fs.num_files = 0;

    printf("Creating files...\n");
    create_file("hello.txt", 20);
    create_file("world.txt", 30);
    create_file("test.txt", 100);
    printf("\n");

    printf("Listing files...\n");
    list_files();
    printf("\n");

    printf("Deleting files...\n");
    delete_file("world.txt");
    delete_file("nonexistent_file.txt");
    printf("\n");

    printf("Listing files again...\n");
    list_files();
    printf("\n");

    printf("Writing data to files...\n");
    write_to_file("hello.txt", "Hello, world!\n");
    write_to_file("test.txt", "This is a test file.\nIt has multiple lines.\n");
    printf("\n");

    printf("Reading data from files...\n");
    read_from_file("hello.txt");
    read_from_file("world.txt");
    read_from_file("nonexistent_file.txt");
    printf("\n");

    return 0;
}