//FormAI DATASET v1.0 Category: File system simulation ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCK_SIZE 32 // Each block size is allocated 32 bytes.

struct file_system {
    char file_name[16];
    int file_size;
    int alloc_blocks;
    int *block;
} fs[10];

char memory[1000];
int allocated_blocks[1000/BLOCK_SIZE];

void create_file(char *name, int size) {
    int i, num_blocks, flag = 0, count = 0;
    char *ptr = memory;

    num_blocks = size / BLOCK_SIZE;  // Total number of blocks to be allocated.

    if((size % BLOCK_SIZE) != 0) {
        num_blocks++;
    }

    for(i = 0; i < 1000; i += BLOCK_SIZE) {
        if(!allocated_blocks[i/BLOCK_SIZE]) {
            count++;
        } else {
            count = 0;
        }

        if(count == num_blocks) {
            flag = 1;
            break;
        }
    }

    if(flag) {  // Successful allocation of memory blocks.
        int j = 0;
        for(i = 0; i < 1000; i += BLOCK_SIZE) {
            if(!allocated_blocks[i/BLOCK_SIZE] && j < num_blocks) {
                allocated_blocks[i/BLOCK_SIZE] = 1;
                fs[size].block[j] = i;
                j++;
            }
        }

        strcpy(fs[size].file_name, name);
        fs[size].file_size = size;
        fs[size].alloc_blocks = num_blocks;

        printf("\nFile created successfully with name \"%s\".\n", name);
    } else {  // Error condition if memory allocation fails.
        printf("\nMemory allocation failed for file with name \"%s\".\n", name);
    }
}

void delete_file(char *name) {
    int i, j;
    for(i = 0; i < 10; i++) {
        if(strcmp(fs[i].file_name, name) == 0) {
            for(j = 0; j < fs[i].alloc_blocks; j++) {
                allocated_blocks[fs[i].block[j]/BLOCK_SIZE] = 0;
            }
            strcpy(fs[i].file_name, "");
            fs[i].file_size = 0;
            fs[i].alloc_blocks = 0;

            printf("\nFile with name \"%s\" deleted successfully.\n", name);

            return;
        }
    }

    printf("\nFile with name \"%s\" not found.\n", name);
}

void display_files() {
    int i, j;
    printf("\n%-16s %-12s %-20s\n", "File Name", "File Size", "Allocated Blocks");
    printf("---------------------------------------------------------\n");
    for(i = 0; i < 10; i++) {
        if(strcmp(fs[i].file_name, "") != 0) {
            printf("%-16s %-12d ", fs[i].file_name, fs[i].file_size);
            for(j = 0; j < fs[i].alloc_blocks; j++) {
                printf("%d ", fs[i].block[j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int i, option, size;
    char name[16];

    for(i = 0; i < 10; i++) {
        fs[i].block = (int*)malloc(sizeof(int));
    }

    do {
        printf("\n-----------------------------\n");
        printf("Choose an option:\n");
        printf("1. Create a new file\n");
        printf("2. Delete a file\n");
        printf("3. Display all files\n");
        printf("4. Exit\n");
        printf("-----------------------------\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nEnter the name of the file: ");
                scanf("%s", name);
                printf("Enter the size in bytes: ");
                scanf("%d", &size);
                create_file(name, size);
                break;
            case 2:
                printf("\nEnter the name of the file: ");
                scanf("%s", name);
                delete_file(name);
                break;
            case 3:
                display_files();
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid option. Try again.\n");
        }
    } while(option != 4);

    for(i = 0; i < 10; i++) {
        free(fs[i].block);
    }

    return 0;
}