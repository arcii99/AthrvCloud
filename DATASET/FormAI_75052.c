//FormAI DATASET v1.0 Category: File system simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME 20
#define BLOCK_SIZE 512

typedef struct {
    int id;
    char name[MAX_FILE_NAME];
    int size;
    int blocks[10];
} file_t;

file_t file_table[MAX_FILES];
char *disk; // pointer to the disk

void init_file_table() {
    for (int i = 0; i < MAX_FILES; i++) {
        file_table[i].id = -1; // -1 indicates a free entry
    }
}

int find_free_entry() {
    for (int i = 0; i < MAX_FILES; i++) {
        if (file_table[i].id == -1) {
            return i; // return the index of the free entry
        }
    }
    return -1; // no free entry found
}

int allocate_blocks(int size) {
    int num_blocks = size / BLOCK_SIZE + (size % BLOCK_SIZE != 0);
    int allocated_blocks = 0;
    for (int i = 0; i < 1000; i++) {
        if (!disk[i]) {
            disk[i] = 1; // mark the block as allocated
            allocated_blocks++;
            if (allocated_blocks == num_blocks) {
                return i - num_blocks + 1; // return the index of the first allocated block
            }
        }
    }
    return -1; // not enough free blocks
}

void free_blocks(int start_block, int size) {
    int num_blocks = size / BLOCK_SIZE + (size % BLOCK_SIZE != 0);
    for (int i = start_block; i < start_block + num_blocks; i++) {
        disk[i] = 0; // mark the block as free
    }
}

void create_file() {
    char name[MAX_FILE_NAME];
    int size;
    printf("Enter the name of the file: ");
    scanf("%s", name);
    printf("Enter the size of the file: ");
    scanf("%d", &size);
    int i = find_free_entry();
    if (i == -1) {
        printf("Error: no free entry in the file table\n");
        return;
    }
    int start_block = allocate_blocks(size);
    if (start_block == -1) {
        printf("Error: not enough free space on the disk\n");
        return;
    }
    file_table[i].id = i;
    strcpy(file_table[i].name, name);
    file_table[i].size = size;
    for (int j = 0; j < size / BLOCK_SIZE; j++) {
        file_table[i].blocks[j] = start_block + j;
    }
    if (size % BLOCK_SIZE != 0) {
        file_table[i].blocks[size / BLOCK_SIZE] = start_block + size / BLOCK_SIZE;
    }
    printf("File '%s' created with size %d bytes\n", name, size);
}

void delete_file() {
    char name[MAX_FILE_NAME];
    printf("Enter the name of the file: ");
    scanf("%s", name);
    file_t *file = NULL;
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(file_table[i].name, name) == 0) {
            file = &file_table[i];
            break;
        }
    }
    if (file == NULL) {
        printf("Error: file not found\n");
        return;
    }
    free_blocks(file->blocks[0], file->size);
    file->id = -1;
    printf("File '%s' deleted\n", name);
}

void list_files() {
    printf("File ID\tName\tSize\n");
    for (int i = 0; i < MAX_FILES; i++) {
        file_t file = file_table[i];
        if (file.id != -1) {
            printf("%d\t%s\t%d\n", file.id, file.name, file.size);
        }
    }
}

int main() {
    disk = (char *) calloc(1000, 1); // allocate a 1000-block disk
    init_file_table();
    while (1) {
        printf("Enter a command (create/delete/list/quit): ");
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "create") == 0) {
            create_file();
        } else if (strcmp(command, "delete") == 0) {
            delete_file();
        } else if (strcmp(command, "list") == 0) {
            list_files();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Error: invalid command\n");
        }
    }
    free(disk); // free the memory used by the disk
    return 0;
}