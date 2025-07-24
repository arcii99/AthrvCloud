//FormAI DATASET v1.0 Category: File system simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants
#define BLOCK_SIZE 512
#define MAX_FILENAME_LENGTH 20
#define MAX_NUM_FILES 10
#define MAX_FILE_SIZE (2 * BLOCK_SIZE)

// define file struct
typedef struct {
    char name[MAX_FILENAME_LENGTH];
    int size;
    int blocks[2];
} File;

// define file system struct
typedef struct {
    int num_blocks;
    int block_size;
    int num_files;
    File files[MAX_NUM_FILES];
    char* data;
} FileSystem;

// function to initialize the file system
void initialize_file_system(FileSystem* fs, int num_blocks, int block_size) {
    fs->num_blocks = num_blocks;
    fs->block_size = block_size;
    fs->num_files = 0;
    fs->data = (char*) calloc(num_blocks * block_size, sizeof(char));
}

// function to add a file to the file system
int add_file(FileSystem* fs, const char* name, const char* contents) {
    // make sure there is room for the file
    if (fs->num_files >= MAX_NUM_FILES) {
        printf("Error: file system is full\n");
        return -1;
    }
    
    // make sure the file does not already exist
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            printf("Error: file already exists\n");
            return -1;
        }
    }
    
    // calculate number of blocks needed for file
    int num_blocks = strlen(contents) / fs->block_size;
    if (strlen(contents) % fs->block_size != 0) {
        num_blocks++;
    }
    if (num_blocks > 2) {
        printf("Error: file is too large\n");
        return -1;
    }
    
    // find free blocks for file
    int blocks[2];
    int found_blocks = 0;
    for (int i = 0; i < fs->num_blocks; i++) {
        if (fs->data[i * fs->block_size] == 0) {
            if (found_blocks == num_blocks) {
                break;
            }
            blocks[found_blocks] = i;
            found_blocks++;
        }
    }
    if (found_blocks != num_blocks) {
        printf("Error: not enough free blocks\n");
        return -1;
    }
    
    // add file to file system
    File file;
    strncpy(file.name, name, MAX_FILENAME_LENGTH);
    file.size = strlen(contents);
    file.blocks[0] = blocks[0];
    file.blocks[1] = num_blocks == 2 ? blocks[1] : -1;
    strncpy(&fs->data[file.blocks[0] * fs->block_size], contents, fs->block_size);
    if (num_blocks == 2) {
        strncpy(&fs->data[file.blocks[1] * fs->block_size], contents + fs->block_size, fs->block_size);
    }
    fs->files[fs->num_files] = file;
    fs->num_files++;
    printf("File added successfully\n");
    return 0;
}

// function to remove a file from the file system
int remove_file(FileSystem* fs, const char* name) {
    // find file in file system
    int file_index = -1;
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index == -1) {
        printf("Error: file not found\n");
        return -1;
    }
    
    // remove file from file system
    int blocks[2];
    blocks[0] = fs->files[file_index].blocks[0];
    blocks[1] = fs->files[file_index].blocks[1];
    fs->data[blocks[0] * fs->block_size] = 0;
    if (blocks[1] != -1) {
        fs->data[blocks[1] * fs->block_size] = 0;
    }
    for (int i = file_index; i < fs->num_files - 1; i++) {
        fs->files[i] = fs->files[i + 1];
    }
    fs->num_files--;
    printf("File removed successfully\n");
    return 0;
}

// function to get the contents of a file
char* get_file_contents(FileSystem* fs, const char* name) {
    // find file in file system
    int file_index = -1;
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index == -1) {
        printf("Error: file not found\n");
        return NULL;
    }
    
    // get contents of file
    char* contents = (char*) malloc(fs->files[file_index].size + 1);
    strncpy(contents, &fs->data[fs->files[file_index].blocks[0] * fs->block_size], fs->block_size);
    if (fs->files[file_index].blocks[1] != -1) {
        strncpy(contents + fs->block_size, &fs->data[fs->files[file_index].blocks[1] * fs->block_size], fs->block_size);
    }
    contents[fs->files[file_index].size] = '\0';
    printf("File contents:\n%s\n", contents);
    return contents;
}

// main function for testing file system
int main() {
    // create file system
    FileSystem fs;
    initialize_file_system(&fs, 10, BLOCK_SIZE);
    
    // add files to file system
    add_file(&fs, "file1", "hello world");
    add_file(&fs, "file2", "this is a test");
    add_file(&fs, "file3", "abc");
    
    // get contents of file
    char* file2_contents = get_file_contents(&fs, "file2");
    
    // remove file from file system
    remove_file(&fs, "file1");
    
    // add file to file system that is too large
    add_file(&fs, "file4", "0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
    
    // add file to file system when file system is full
    add_file(&fs, "file5", "123");
    
    // remove file from file system that does not exist
    remove_file(&fs, "file6");
    
    // free memory
    free(file2_contents);
    free(fs.data);
    
    return 0;
}