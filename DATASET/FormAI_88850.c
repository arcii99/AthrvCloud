//FormAI DATASET v1.0 Category: File system simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define BLOCK_SIZE 512
#define MAX_BLOCKS 1000

typedef struct {
    char *name;
    int size; 
    int blocks[10]; 
    int num_blocks; 
} File; 

typedef struct {
    int used_blocks; 
    int block_map[MAX_BLOCKS];
} Filesystem; 

Filesystem fs; 
File files[MAX_FILES]; 

void init_filesystem() {
    fs.used_blocks = 0;
    for(int i = 0; i < MAX_BLOCKS; i++) {
        fs.block_map[i] = 0; 
    }
}

int allocate_block() {
    int block = -1; 
    for(int i = 0; i < MAX_BLOCKS; i++) {
        if(fs.block_map[i] == 0) {
            block = i; 
            fs.block_map[i] = 1; 
            fs.used_blocks++; 
            break;
        }
    }
    return block;
}

void create_file(char *name, int size) {
    if(size > MAX_BLOCKS || fs.used_blocks + size > MAX_BLOCKS) {
        printf("Error: Not enough space for file\n");
        return;
    }
    int blocks[size];
    for(int i = 0; i < size; i++) {
        blocks[i] = allocate_block();
        if(blocks[i] == -1) {
            printf("Error: Not enough space for file\n");
            for(int j = 0; j < i; j++) {
                fs.block_map[blocks[j]] = 0; 
                fs.used_blocks--;
            }
            return;
        }
    }
    File file; 
    file.name = name;
    file.size = size;
    memcpy(file.blocks, blocks, size);
    file.num_blocks = size;
    files[size] = file; 
}

void delete_file(char *name) {
    int index = -1;
    for(int i = 0; i < MAX_FILES; i++) {
        if(files[i].name == name) {
            for(int j = 0; j < files[i].num_blocks; j++) {
                fs.block_map[files[i].blocks[j]] = 0; 
                fs.used_blocks--;
            }
            index = i; 
            break;
        }
    }
    if(index != -1) {
        for(int i = index; i < MAX_FILES - 1; i++) {
            files[i] = files[i+1];
        }
    } else {
        printf("Error: File not found\n");
    }
}

void print_filesystem() {
    printf("Filesystem:\n");
    printf("Total used blocks: %d\n", fs.used_blocks);
    printf("Block Map: ");
    for(int i = 0; i < MAX_BLOCKS; i++) {
        printf("%d", fs.block_map[i]);
    }
    printf("\nFiles:\n");
    for(int i = 0; i < MAX_FILES; i++) {
        if(files[i].name != NULL) {
            printf("Name: %s, Size: %d, Blocks: ", files[i].name, files[i].size);
            for(int j = 0; j < files[i].num_blocks; j++) {
                printf("%d ", files[i].blocks[j]);
            }
            printf("\n");
        }
    }
}

int main() {
    init_filesystem(); 

    create_file("foo.txt", 3);
    create_file("bar.txt", 2);
    create_file("baz.txt", 5);

    print_filesystem();

    delete_file("bar.txt");

    print_filesystem();

    create_file("qux.txt", 7);

    print_filesystem();

    return 0;
}