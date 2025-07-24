//FormAI DATASET v1.0 Category: File system simulation ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILES 100 // Maximum files in the filesystem
#define MAX_NAME_LENGTH 50 // Maximum length of filenames
#define BLOCK_SIZE 512 // Block size for the filesystem

struct file{
    char name[MAX_NAME_LENGTH];
    int size;
    int blocks[10];
    int block_count;
    int is_deleted;
};

struct file_system{
    struct file files[MAX_FILES];
    int block_count;
    int used_blocks;
    int free_blocks;
    char blocks[MAX_FILES * BLOCK_SIZE];
};

void init_file_system(struct file_system *fs){
    fs->block_count = MAX_FILES * BLOCK_SIZE;
    fs->used_blocks = 0;
    fs->free_blocks = MAX_FILES * BLOCK_SIZE;

    for(int i = 0; i < MAX_FILES; i++){
        fs->files[i].is_deleted = 1;
    }
}

void format_file_system(struct file_system *fs){
    init_file_system(fs);

    // Zero out all the blocks
    memset(fs->blocks, 0, fs->block_count);
}

int get_free_block(struct file_system *fs){
    // Check if there are any free blocks left
    if(fs->free_blocks < BLOCK_SIZE){
        return -1;
    }

    for(int i = 0; i < MAX_FILES; i++){
        if(fs->files[i].is_deleted){
            int block_num = fs->used_blocks;
            fs->used_blocks += BLOCK_SIZE;
            fs->free_blocks -= BLOCK_SIZE;

            fs->files[i].is_deleted = 0;
            fs->files[i].size = 0;
            fs->files[i].block_count = 0;
            for(int j = 0; j < 10; j++){
                fs->files[i].blocks[j] = -1;
            }

            return block_num;
        }
    }

    // No free blocks available
    return -1;
}

void release_block(struct file_system *fs, int block_num){
    int i, j;

    // Find the file that contains this block
    for(i = 0; i < MAX_FILES; i++){
        for(j = 0; j < fs->files[i].block_count; j++){
            if(fs->files[i].blocks[j] == block_num){
                // Remove the block from the file
                fs->files[i].blocks[j] = -1;
                fs->files[i].block_count--;

                // Mark the block as free
                memset(fs->blocks + block_num, 0, BLOCK_SIZE);
                fs->free_blocks += BLOCK_SIZE;

                // Check if the file is now empty
                if(fs->files[i].block_count == 0){
                    fs->files[i].is_deleted = 1;
                }

                return;
            }
        }
    }
}

int create_file(struct file_system *fs, const char *name){
    // Find a free file slot
    int i;
    for(i = 0; i < MAX_FILES; i++){
        if(fs->files[i].is_deleted){
            break;
        }
    }

    if(i == MAX_FILES){
        return -1;
    }

    // Get a free block for the file
    int block_num = get_free_block(fs);
    if(block_num == -1){
        return -1;
    }

    // Set the file properties
    strcpy(fs->files[i].name, name);
    fs->files[i].blocks[0] = block_num;
    fs->files[i].block_count = 1;

    return i;
}

int delete_file(struct file_system *fs, int idx){
    // Release all blocks associated with the file
    for(int i = 0; i < fs->files[idx].block_count; i++){
        release_block(fs, fs->files[idx].blocks[i]);
    }

    // Mark the file as deleted
    fs->files[idx].is_deleted = 1;

    return 0;
}

int write_file(struct file_system *fs, int idx, const void *data, int size){
    int block_size = BLOCK_SIZE;
    int block_count = (size + block_size - 1) / block_size;

    // Check if we need to allocate more blocks for the file
    if(block_count > fs->files[idx].block_count){
        int diff = block_count - fs->files[idx].block_count;
        for(int i = 0; i < diff; i++){
            int block_num = get_free_block(fs);
            if(block_num == -1){
                return -1;
            }

            // Add the block to the file
            fs->files[idx].blocks[fs->files[idx].block_count] = block_num;
            fs->files[idx].block_count++;
        }
    }

    // Write the data to the file blocks
    int idx_block_num = 0;
    int block_idx = 0;
    int data_idx = 0;

    while(data_idx < size){
        if(block_idx == BLOCK_SIZE){
            // Move to the next block
            idx_block_num++;
            block_idx = 0;
        }

        // Find the block address
        int block_num = fs->files[idx].blocks[idx_block_num];
        char *block = fs->blocks + block_num;

        // Write the current byte of data to the block
        block[block_idx] = ((char *)data)[data_idx];

        data_idx++;
        block_idx++;
    }

    // Update the size of the file
    fs->files[idx].size = size;

    return 0;
}

int read_file(struct file_system *fs, int idx, void *data, int size){
    int block_size = BLOCK_SIZE;
    int block_count = (fs->files[idx].size + block_size - 1) / block_size;

    if(size > fs->files[idx].size){
        return -1;
    }

    // Read the data from the file blocks
    int idx_block_num = 0;
    int block_idx = 0;
    int data_idx = 0;

    while(data_idx < size){
        if(block_idx == BLOCK_SIZE){
            // Move to the next block
            idx_block_num++;
            block_idx = 0;
        }

        // Find the block address
        int block_num = fs->files[idx].blocks[idx_block_num];
        char *block = fs->blocks + block_num;

        // Read the current byte of data from the block
        ((char *)data)[data_idx] = block[block_idx];

        data_idx++;
        block_idx++;
    }

    return 0;
}

int main(){
    struct file_system fs;
    format_file_system(&fs);

    // Create a file
    int file_idx = create_file(&fs, "file1.txt");
    if(file_idx == -1){
        printf("Failed to create file\n");
        return -1;
    }

    // Write data to the file
    char data[] = "This is the first line.\nThis is the second line.\nThis is the third line.";
    write_file(&fs, file_idx, data, strlen(data) + 1);

    // Read data from the file
    char buffer[100];
    read_file(&fs, file_idx, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    // Delete the file
    delete_file(&fs, file_idx);

    return 0;
}