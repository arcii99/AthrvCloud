//FormAI DATASET v1.0 Category: File system simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024    // Block size of 1024 bytes
#define MAX_FILES 128      // Maximum of 128 files can be stored
#define FILENAME_SIZE 32   // Maximum filename size of 32 characters
#define MAX_BLOCKS 4096    // Maximum number of blocks in the file system
#define TOTAL_SIZE MAX_BLOCKS * BLOCK_SIZE  // Total size of file system

typedef struct {
    char filename[FILENAME_SIZE];   // Name of the file stored in the file system
    int size;                       // Size of the file
    int block_count;                // Number of blocks occupied by the file
    int block_ptr[1024];            // Pointer to the blocks occupied by the file
    int active;                     // Indicates if the file is active (1) or deleted (0)
} file_t;                           

char block_map[MAX_BLOCKS];         // Bit map to indicate which blocks are in use
file_t file_table[MAX_FILES];       // File table to store filename, size and block pointers
int total_files = 0;                // Keeps track of total number of files stored in file system

/*
 * Initializes the file system by initializing the block map and file table
 */
void init_file_system() {
    memset(block_map, 0, MAX_BLOCKS);
    memset(file_table, 0, sizeof(file_table));
}

/*
 * Allocates the requested number of blocks in the file system for the new file
 */
int allocate_blocks(int block_count) {
    int start = -1;

    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (block_map[i] == 0) {
            int j = i + 1;
            while (block_map[j] == 0 && (j - i) < block_count) {
                j++;
            }

            if ((j - i) == block_count) {
                start = i;
                for (int k = i; k <= j; k++) {
                    block_map[k] = 1;
                }
                break;
            }
        }
    }

    return start;
}

/*
 * Adds a new file to the file system
 */
void add_file(char *filename, int size) {
    if (total_files >= MAX_FILES) {
        printf("Cannot add file, maximum file limit reached!\n");
        return;
    }

    int block_count = size / BLOCK_SIZE;
    if (size % BLOCK_SIZE > 0) {
        block_count++;
    }

    int start_block = allocate_blocks(block_count);
    if (start_block == -1) {
        printf("Not enough space available to add file!\n");
        return;
    }

    file_table[total_files].active = 1;
    strcpy(file_table[total_files].filename, filename);
    file_table[total_files].size = size;
    file_table[total_files].block_count = block_count;

    int j = 0;
    for (int i = start_block; i < start_block + block_count; i++) {
        file_table[total_files].block_ptr[j] = i;
        j++;
    }

    total_files++;
    printf("File %s added successfully!\n", filename);
}

/*
 * Deletes the specified file from the file system
 */
void delete_file(char *filename) {
    int index = -1;
    for (int i = 0; i < MAX_FILES; i++) {
        if (file_table[i].active == 1 && strcmp(file_table[i].filename, filename) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Cannot delete file %s, file does not exist!\n", filename);
        return;
    }

    for (int i = 0; i < file_table[index].block_count; i++) {
        block_map[file_table[index].block_ptr[i]] = 0;
    }

    file_table[index].active = 0;
    total_files--;

    printf("File %s deleted successfully!\n", filename);
}

/*
 * Displays the list of all files stored in the file system
 */
void list_files() {
    printf("%-32s %-8s %-8s %-16s\n", "Filename", "Size", "Blocks", "Start Block Pointer");
    for (int i = 0; i < MAX_FILES; i++) {
        if (file_table[i].active == 1) {
            printf("%-32s %-8d %-8d ", file_table[i].filename, file_table[i].size, file_table[i].block_count);
            for (int j = 0; j < file_table[i].block_count; j++) {
                printf("%d ", file_table[i].block_ptr[j]);
            }
            printf("\n");
        }
    }
}

/*
 * Displays the file allocation table that holds the block allocation details for each file
 */
void display_fat() {
    printf("%-8s %-8s %-16s\n", "Block", "Status", "Filenames");
    for (int i = 0; i < MAX_BLOCKS; i++) {
        printf("%-8d %-8s ", i, block_map[i] == 1 ? "In use" : "Free");
        for (int j = 0; j < MAX_FILES; j++) {
            if (file_table[j].active == 1) {
                for (int k = 0; k < file_table[j].block_count; k++) {
                    if (file_table[j].block_ptr[k] == i) {
                        printf("%s ", file_table[j].filename);
                        break;
                    }
                }
            }
        }
        printf("\n");
    }
}

/*
 * The main function that runs the file system simulation
 */
int main() {
    init_file_system(); // Initialize the file system

    add_file("file1.txt", 4096); // Add file1, size 4096 bytes
    add_file("file2.txt", 8192); // Add file2, size 8192 bytes
    add_file("file3.txt", 1024); // Add file3, size 1024 bytes

    list_files(); // Display the list of all files
    display_fat(); // Display the file allocation table

    delete_file("file2.txt"); // Delete file2

    list_files(); // Display the list of all files
    display_fat(); // Display the file allocation table

    return 0;
}