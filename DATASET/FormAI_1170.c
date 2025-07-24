//FormAI DATASET v1.0 Category: File system simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define NUM_BLOCKS 1024
#define FILENAME_SIZE 20

typedef struct {
    char name[FILENAME_SIZE];
    int size;
    int first_block;
} file_descriptor;

typedef struct {
    int is_free;
    int next_block;
} block;

file_descriptor files[NUM_BLOCKS];
block blocks[NUM_BLOCKS];
int num_files = 0;

void initialize_blocks() {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        blocks[i].is_free = 1;
        blocks[i].next_block = -1;
    }
}

int allocate_blocks(int num_blocks) {
    int first_block = -1;
    int last_block = -1;
    int count = 0;
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (blocks[i].is_free) {
            if (first_block == -1) {
                first_block = i;
            }
            blocks[i].is_free = 0;
            if (last_block != -1) {
                blocks[last_block].next_block = i;
            }
            last_block = i;
            count++;
        }
        if (count == num_blocks) {
            break;
        }
    }
    if (count == num_blocks) {
        return first_block;
    } else {
        return -1;
    }
}

void free_blocks(int first_block) {
    int i = first_block;
    while (i != -1) {
        blocks[i].is_free = 1;
        int next_block = blocks[i].next_block;
        blocks[i].next_block = -1;
        i = next_block;
    }
}

void format() {
    initialize_blocks();
    num_files = 0;
}

int create_file(char* name, int size) {
    if (num_files == NUM_BLOCKS) {
        return -1;
    }
    int first_block = allocate_blocks((size + BLOCK_SIZE - 1) / BLOCK_SIZE);
    if (first_block == -1) {
        return -1;
    }
    strcpy(files[num_files].name, name);
    files[num_files].size = size;
    files[num_files].first_block = first_block;
    num_files++;
    return num_files - 1;
}

void delete_file(int file_num) {
    free_blocks(files[file_num].first_block);
    for (int i = file_num; i < num_files - 1; i++) {
        files[i] = files[i + 1];
    }
    num_files--;
}

void list_files() {
    printf("Index\tName\tSize\n");
    for (int i = 0; i < num_files; i++) {
        printf("%d\t%s\t%d\n", i, files[i].name, files[i].size);
    }
}

int main() {
    char input[100];
    while (1) {
        printf("File system command: ");
        fgets(input, 100, stdin);
        if (strncmp(input, "format", 6) == 0) {
            format();
        } else if (strncmp(input, "create", 6) == 0) {
            char name[FILENAME_SIZE];
            int size;
            sscanf(input + 7, "%s%d", name, &size);
            int file_num = create_file(name, size);
            if (file_num == -1) {
                printf("Error: not enough space to create file\n");
            } else {
                printf("File created with index %d\n", file_num);
            }
        } else if (strncmp(input, "delete", 6) == 0) {
            int file_num;
            sscanf(input + 7, "%d", &file_num);
            if (file_num < 0 || file_num >= num_files) {
                printf("Error: invalid file index\n");
            } else {
                delete_file(file_num);
            }
        } else if (strncmp(input, "list", 4) == 0) {
            list_files();
        } else if (strncmp(input, "quit", 4) == 0) {
            break;
        } else {
            printf("Error: invalid command\n");
        }
    }
    return 0;
}