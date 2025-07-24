//FormAI DATASET v1.0 Category: File system simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 4096
#define FILE_NAME_LENGTH 128
#define NUM_BLOCKS 65536
#define BLOCKS_PER_FILE 32

// Define file type
typedef struct file_t {
    int size;
    char name[FILE_NAME_LENGTH];
    int block_ids[BLOCKS_PER_FILE];
} file_t;

// Define block type
typedef struct block_t {
    char data[BLOCK_SIZE];
} block_t;

// Define file system type
typedef struct file_system_t {
    block_t blocks[NUM_BLOCKS];
    int free_block_ids[NUM_BLOCKS];
    int num_free_blocks;
    file_t files[NUM_BLOCKS / BLOCKS_PER_FILE];
    int num_files;
} file_system_t;

void init_file_system(file_system_t *fs) {
    int i;
    fs->num_files = 0;
    fs->num_free_blocks = NUM_BLOCKS;

    // initialize free_block_ids array
    for (i = 0; i < NUM_BLOCKS; i++) {
        fs->free_block_ids[i] = i;
    }
}

int allocate_block(file_system_t *fs) {
    if (fs->num_free_blocks == 0) {
        printf("Error: file system is full\n");
        return -1;
    }

    int block_id = fs->free_block_ids[--fs->num_free_blocks];
    return block_id;
}

void free_block(file_system_t *fs, int block_id) {
    fs->free_block_ids[fs->num_free_blocks++] = block_id;
}

void write_to_block(file_system_t *fs, int block_id, char *data) {
    block_t *block = &(fs->blocks[block_id]);
    strcpy(block->data, data);
}

void create_file(file_system_t *fs, char *name) {
    int i, file_id = fs->num_files++;
    file_t *file = &(fs->files[file_id]);

    // allocate blocks for file
    for (i = 0; i < BLOCKS_PER_FILE; i++) {
        int block_id = allocate_block(fs);
        if (block_id == -1) {
            return;
        }
        file->block_ids[i] = block_id;
    }

    // set default attributes
    file->size = 0;
    strcpy(file->name, name);
}

void delete_file(file_system_t *fs, char *name) {
    int i, j;

    for (i = 0; i < fs->num_files; i++) {
        file_t *file = &(fs->files[i]);
        if (strcmp(file->name, name) == 0) {
            // free blocks used by file
            for (j = 0; j < BLOCKS_PER_FILE; j++) {
                int block_id = file->block_ids[j];
                free_block(fs, block_id);
            }

            // shift other files down
            for (j = i + 1; j < fs->num_files; j++) {
                fs->files[j - 1] = fs->files[j];
            }

            // decrement num_files
            fs->num_files--;

            return;
        }
    }

    printf("Error: file not found\n");
}

void write_to_file(file_system_t *fs, char *name, char *data) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        file_t *file = &(fs->files[i]);
        if (strcmp(file->name, name) == 0) {
            int num_blocks = strlen(data) / BLOCK_SIZE + 1;
            if (num_blocks > BLOCKS_PER_FILE) {
                printf("Error: file too large\n");
                return;
            }

            // free previous blocks used by file
            for (i = 0; i < BLOCKS_PER_FILE; i++) {
                int block_id = file->block_ids[i];
                free_block(fs, block_id);
            }

            // allocate new blocks
            for (i = 0; i < num_blocks; i++) {
                int block_id = allocate_block(fs);
                if (block_id == -1) {
                    return;
                }
                file->block_ids[i] = block_id;
            }

            // write data to blocks
            for (i = 0; i < num_blocks; i++) {
                int block_id = file->block_ids[i];
                char *block_data = &(data[i * BLOCK_SIZE]);
                write_to_block(fs, block_id, block_data);
            }

            // update file size attribute
            file->size = strlen(data);

            return;
        }
    }

    printf("Error: file not found\n");
}

void read_from_file(file_system_t *fs, char *name) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        file_t *file = &(fs->files[i]);
        if (strcmp(file->name, name) == 0) {
            int num_blocks = (file->size / BLOCK_SIZE) + 1;
            char data[file->size + 1];
            data[file->size] = '\0';

            // read data from blocks
            for (i = 0; i < num_blocks; i++) {
                int block_id = file->block_ids[i];
                block_t *block = &(fs->blocks[block_id]);
                strcat(data, block->data);
            }

            printf("%s\n", data);
            return;
        }
    }

    printf("Error: file not found\n");
}

int main() {
    file_system_t fs;
    init_file_system(&fs);

    create_file(&fs, "file1");
    write_to_file(&fs, "file1", "Hello World!\n");

    create_file(&fs, "file2");
    write_to_file(&fs, "file2", "This is a test file.\n");

    read_from_file(&fs, "file1");
    read_from_file(&fs, "file2");

    delete_file(&fs, "file1");
    delete_file(&fs, "file2");

    return 0;
}