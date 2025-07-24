//FormAI DATASET v1.0 Category: File system simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512
#define MAX_BLOCKS 100
#define FILE_NAME_SIZE 20

typedef struct {
    int start_block;
    int num_blocks;
    char name[FILE_NAME_SIZE];
} File;

int blocks[MAX_BLOCKS];
File files[MAX_BLOCKS];
int num_files = 0;

void init_blocks() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        blocks[i] = 0;
    }
}

void init_files() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        files[i].start_block = -1;
        files[i].num_blocks = 0;
        files[i].name[0] = '\0';
    }
}

void create_file(char *name, int size) {
    int start_block = -1;
    int num_blocks_needed = (size / BLOCK_SIZE) + 1;

    for (int i = 0; i < MAX_BLOCKS - num_blocks_needed + 1; i++) {
        if (blocks[i] == 0) {
            int blocks_found = 1;
            for (int j = i + 1; j < i + num_blocks_needed; j++) {
                if (blocks[j] == 1) {
                    blocks_found = 0;
                    break;
                }
            }
            if (blocks_found) {
                start_block = i;
                break;
            }
        }
    }

    if (start_block == -1) {
        printf("Not enough space to create file.\n");
        return;
    }

    for (int i = start_block; i < start_block + num_blocks_needed; i++) {
        blocks[i] = 1;
    }

    File new_file;
    new_file.start_block = start_block;
    new_file.num_blocks = num_blocks_needed;
    strncpy(new_file.name, name, FILE_NAME_SIZE);

    files[num_files++] = new_file;

    printf("Created file %s with size %i.\n", name, size);
}

void delete_file(char *name) {
    int found_index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("File %s not found.\n", name);
        return;
    }

    int start_block = files[found_index].start_block;
    int num_blocks = files[found_index].num_blocks;

    for (int i = start_block; i < start_block + num_blocks; i++) {
        blocks[i] = 0;
    }

    for (int i = found_index; i < num_files - 1; i++) {
        files[i] = files[i + 1];
    }

    files[--num_files] = (File){-1, 0, ""};

    printf("Deleted file %s.\n", name);
}

void list_files() {
    printf("Files:\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s (%i blocks)\n", files[i].name, files[i].num_blocks);
    }
}

int main() {
    init_blocks();
    init_files();

    create_file("file1.txt", 1000);
    create_file("file2.txt", 2000);
    create_file("file3.txt", 500);

    list_files();

    delete_file("file2.txt");

    list_files();

    return 0;
}