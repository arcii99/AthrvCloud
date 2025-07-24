//FormAI DATASET v1.0 Category: File system simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 1000
#define FILENAME_LENGTH 50
#define BLOCK_SIZE 512
#define NUM_BLOCKS 100
#define INVALID_BLOCK -1

// data structure to represent a file
typedef struct {
    char filename[FILENAME_LENGTH];
    int blocks[NUM_BLOCKS];
    int num_blocks;
} File;

// data structure to represent the file system
typedef struct {
    File files[MAX_FILES];
    int free_blocks[NUM_BLOCKS];
    int num_free_blocks;
    int next_free_block;
} FileSystem;

// initializes the file system
void init_file_system(FileSystem *fs) {
    int i;
    
    // initialize all files to empty
    for (i = 0; i < MAX_FILES; i++) {
        memset(fs->files[i].filename, 0, FILENAME_LENGTH * sizeof(char));
        memset(fs->files[i].blocks, INVALID_BLOCK, NUM_BLOCKS * sizeof(int));
        fs->files[i].num_blocks = 0;
    }
    
    // initialize all blocks to free
    for (i = 0; i < NUM_BLOCKS; i++) {
        fs->free_blocks[i] = i;
    }
    fs->num_free_blocks = NUM_BLOCKS;
    fs->next_free_block = 0;
}

// creates a new file
void create_file(FileSystem *fs, char *filename) {
    int i, j;
    
    // find the first empty slot for a file
    for (i = 0; i < MAX_FILES; i++) {
        if (fs->files[i].num_blocks == 0) {
            break;
        }
    }
    
    // assign blocks to the file
    int num_blocks_needed = 1; // at least one block needed for file data
    if (strlen(filename) > FILENAME_LENGTH) {
        num_blocks_needed++;
    }
    int blocks_assigned[num_blocks_needed];
    for (i = 0; i < num_blocks_needed; i++) {
        if (fs->num_free_blocks == 0) {
            fprintf(stderr, "Error: file system is full\n");
            return;
        }
        blocks_assigned[i] = fs->free_blocks[fs->next_free_block];
        fs->next_free_block++;
        if (fs->next_free_block == fs->num_free_blocks) {
            fs->next_free_block = 0;
        }
        fs->num_free_blocks--;
    }
    
    // update file details
    strcpy(fs->files[i].filename, filename);
    for (j = 0; j < num_blocks_needed; j++) {
        fs->files[i].blocks[j] = blocks_assigned[j];
    }
    fs->files[i].num_blocks = num_blocks_needed;
    
    printf("File '%s' created with %d block(s).\n", filename, num_blocks_needed);
}

// deletes an existing file
void delete_file(FileSystem *fs, char *filename) {
    int i, j;
    for (i = 0; i < MAX_FILES; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            for (j = 0; j < fs->files[i].num_blocks; j++) {
                fs->free_blocks[fs->num_free_blocks] = fs->files[i].blocks[j];
                fs->num_free_blocks++;
            }
            memset(fs->files[i].filename, 0, FILENAME_LENGTH * sizeof(char));
            memset(fs->files[i].blocks, INVALID_BLOCK, NUM_BLOCKS * sizeof(int));
            fs->files[i].num_blocks = 0;
            printf("File '%s' deleted.\n", filename);
            return;
        }
    }
    fprintf(stderr, "Error: file not found\n");
}

// displays information about an existing file
void show_file(FileSystem *fs, char *filename) {
    int i, j;
    for (i = 0; i < MAX_FILES; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            printf("File '%s' details:\n", filename);
            printf("Number of blocks: %d\n", fs->files[i].num_blocks);
            printf("Blocks allocated: ");
            for (j = 0; j < fs->files[i].num_blocks; j++) {
                printf("%d ", fs->files[i].blocks[j]);
            }
            printf("\n");
            return;
        }
    }
    fprintf(stderr, "Error: file not found\n");
}

// displays information about the file system
void show_file_system(FileSystem *fs) {
    int i, j;
    printf("File system details:\n");
    printf("Number of files: ");
    int num_files = 0;
    for (i = 0; i < MAX_FILES; i++) {
        if (fs->files[i].num_blocks > 0) {
            num_files++;
        }
    }
    printf("%d\n", num_files);
    printf("Number of free blocks: %d\n", fs->num_free_blocks);
    printf("Free blocks: ");
    for (i = 0; i < fs->num_free_blocks; i++) {
        printf("%d ", fs->free_blocks[i]);
    }
    printf("\n");
    for (i = 0; i < MAX_FILES; i++) {
        if (fs->files[i].num_blocks > 0) {
            printf("\nFile '%s' details:\n", fs->files[i].filename);
            printf("Number of blocks: %d\n", fs->files[i].num_blocks);
            printf("Blocks allocated: ");
            for (j = 0; j < fs->files[i].num_blocks; j++) {
                printf("%d ", fs->files[i].blocks[j]);
            }
            printf("\n");
        }
    }
}

int main() {
    FileSystem fs;
    init_file_system(&fs);
    
    printf("Welcome to the mind-bending file system simulation!\n");
    while (1) {
        printf("\nPlease enter a command:\n");
        printf("create <filename> - create a new file\n");
        printf("delete <filename> - delete an existing file\n");
        printf("show <filename> - show information about an existing file\n");
        printf("details - show information about the file system\n");
        printf("exit - exit the program\n");
        printf("> ");
        
        char command[10];
        char arg[FILENAME_LENGTH];
        scanf("%s", command);
        
        if (strcmp(command, "create") == 0) {
            scanf("%s", arg);
            create_file(&fs, arg);
        }
        else if (strcmp(command, "delete") == 0) {
            scanf("%s", arg);
            delete_file(&fs, arg);
        }
        else if (strcmp(command, "show") == 0) {
            scanf("%s", arg);
            show_file(&fs, arg);
        }
        else if (strcmp(command, "details") == 0) {
            show_file_system(&fs);
        }
        else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }
        else {
            fprintf(stderr, "Error: invalid command\n");
        }
    }
    
    return 0;
}