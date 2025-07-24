//FormAI DATASET v1.0 Category: File system simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define BLOCK_COUNT 1024

typedef struct _filesystem {
    char data[BLOCK_SIZE];
    int block_pointer;
} FileSystem;

int main() {
    FileSystem fs[BLOCK_COUNT];
    char input[BLOCK_SIZE];
    int file_size, i, j, block_count;
    char name[50];
    
    printf("Enter file name: ");
    fgets(name, 50, stdin);
    name[strlen(name) - 1] = '\0';
    
    printf("Enter file size (in bytes): ");
    scanf("%d", &file_size);
    
    block_count = file_size / BLOCK_SIZE;
    if (file_size % BLOCK_SIZE != 0) {
        block_count++;
    }
    
    if (block_count > BLOCK_COUNT) {
        printf("Error: File too large to fit in file system.\n");
        return 1;
    }
    
    // Find free blocks
    int free_blocks[block_count];
    int found_blocks = 0;
    for (i = 0; i < BLOCK_COUNT && found_blocks < block_count; i++) {
        if (fs[i].block_pointer == 0) {
            free_blocks[found_blocks] = i;
            found_blocks++;
        }
    }
    
    if (found_blocks < block_count) {
        printf("Error: Not enough free blocks to create file.\n");
        return 1;
    }
    
    // Write data to free blocks
    printf("Enter file data:\n");
    for (i = 0; i < block_count; i++) {
        fgets(input, BLOCK_SIZE, stdin);
        strncpy(fs[free_blocks[i]].data, input, BLOCK_SIZE);
        fs[free_blocks[i]].block_pointer = 1;
    }

    printf("File created successfully.\n");
    
    return 0;
}