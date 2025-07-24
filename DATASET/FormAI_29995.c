//FormAI DATASET v1.0 Category: File system simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_FILE_COUNT 10
#define BLOCK_SIZE 512
#define MAX_BLOCKS 300

typedef struct {
    int used;
    int start_block;
    int num_blocks;
    char name[MAX_FILENAME_LENGTH];
} File;

char fs[MAX_BLOCKS][BLOCK_SIZE];
File files[MAX_FILE_COUNT];

void initialize_file_system() {
    for (int i = 0; i < MAX_FILE_COUNT; i++) {
        files[i].used = 0;
        files[i].num_blocks = 0;
        files[i].start_block = -1;
        memset(files[i].name, 0, sizeof(files[i].name));
    }

    for (int i = 0; i < MAX_BLOCKS; i++) {
        memset(fs[i], 0, sizeof(fs[i]));
    }
}

int find_free_block(int num_blocks) {
    int consecutive_blocks_found = 0;

    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (fs[i][0] == '\0') {
            consecutive_blocks_found += 1;

            if (consecutive_blocks_found == num_blocks) {
                return i - num_blocks + 1;
            }
        } else {
            consecutive_blocks_found = 0;
        }
    }

    return -1;
}

int find_file_by_name(char* name) {
    for (int i = 0; i < MAX_FILE_COUNT; i++) {
        if (strcmp(files[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

int create_file(char* name, int size) {
    if (find_file_by_name(name) != -1) {
        printf("Error: File with name %s already exists\n", name);
        return -1;
    }

    int num_blocks = (size / BLOCK_SIZE) + (size % BLOCK_SIZE == 0 ? 0 : 1);

    int start_block = find_free_block(num_blocks);
    if (start_block == -1) {
        printf("Error: Not enough space to create file\n");
        return -1;
    }

    File new_file;
    new_file.used = 1;
    new_file.start_block = start_block;
    new_file.num_blocks = num_blocks;
    strcpy(new_file.name, name);

    files[find_file_by_name("")] = new_file;

    return 0;
}

int delete_file(char* name) {
    int file_index = find_file_by_name(name);

    if (file_index == -1) {
        printf("Error: File not found\n");
        return -1;
    }

    for (int i = 0; i < files[file_index].num_blocks; i++) {
        int block_index = files[file_index].start_block + i;
        memset(fs[block_index], 0, BLOCK_SIZE);
    }

    files[file_index].used = 0;
    files[file_index].start_block = -1;
    files[file_index].num_blocks = 0;
    memset(files[file_index].name, 0, sizeof(files[file_index].name));

    return 0;
}

int read_file(char* name, char* buffer, int size) {
    int file_index = find_file_by_name(name);

    if (file_index == -1) {
        printf("Error: File not found\n");
        return -1;
    }

    int bytes_to_read = size > (files[file_index].num_blocks * BLOCK_SIZE) ?
                        files[file_index].num_blocks * BLOCK_SIZE :
                        size;

    memcpy(buffer, &fs[files[file_index].start_block], bytes_to_read);

    return bytes_to_read;
}

int write_file(char* name, char* buffer, int size) {
    int file_index = find_file_by_name(name);

    if (file_index == -1) {
        printf("Error: File not found\n");
        return -1;
    }

    int bytes_to_write = size > (files[file_index].num_blocks * BLOCK_SIZE) ?
                         files[file_index].num_blocks * BLOCK_SIZE :
                         size;

    memcpy(&fs[files[file_index].start_block], buffer, bytes_to_write);

    return bytes_to_write;
}

int main() {
    initialize_file_system();

    create_file("file1", 2048);
    create_file("file2", 1024);
    create_file("file3", 4096);

    int file1_size = read_file("file1", fs[0], 2048);
    int file2_size = read_file("file2", fs[5], 1024);

    char* file3_data = malloc(4096);
    memset(file3_data, 'a', 4096);

    write_file("file3", file3_data, 1000);

    free(file3_data);

    delete_file("file1");

    return 0;
}