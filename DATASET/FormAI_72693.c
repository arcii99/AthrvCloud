//FormAI DATASET v1.0 Category: File system simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_LENGTH 20
#define BLOCK_SIZE 512
#define FS_SIZE 10240
#define MAX_FILES 20

typedef struct FileInfo {
    char name[FILE_NAME_LENGTH];
    int size;
    int start_block;
} FileInfo;

struct Block {
    unsigned char contents[BLOCK_SIZE];
};

struct FileSystem {
    struct Block blocks[FS_SIZE/BLOCK_SIZE];
    struct FileInfo files[MAX_FILES];
};

void initialize_file_system(struct FileSystem* fs) {
    for(int i=0; i<MAX_FILES; i++)
        fs->files[i].start_block = -1;
}

int add_file(struct FileSystem* fs, char* name, int size) {
    for(int i=0; i<MAX_FILES; i++) {
        if(fs->files[i].start_block == -1) { // Found an empty slot
            fs->files[i].size = size;
            strncpy(fs->files[i].name, name, FILE_NAME_LENGTH);
            for(int j=0; j<FS_SIZE/BLOCK_SIZE; j++) {
                if(fs->blocks[j].contents[0] == '\0' && size > 0) { // Found an empty block
                    fs->files[i].start_block = j;
                    int bytes_to_copy = (size < BLOCK_SIZE) ? size : BLOCK_SIZE;
                    memcpy(fs->blocks[j].contents, name, bytes_to_copy);
                    size -= bytes_to_copy;
                }
            }
            if(size > 0) {
                printf("File too large: %d bytes remaining\n", size);
                return -1;
            }
            return 0;
        }
    }
    printf("File system full\n");
    return -1;
}

int remove_file(struct FileSystem* fs, char* name) {
    for(int i=0; i<MAX_FILES; i++) {
        if(fs->files[i].start_block != -1 && strcmp(fs->files[i].name, name) == 0) {
            int start_block = fs->files[i].start_block;
            int num_blocks = (fs->files[i].size / BLOCK_SIZE) + ((fs->files[i].size % BLOCK_SIZE) == 0 ? 0 : 1);
            for(int j=start_block; j<start_block+num_blocks; j++)
                memset(fs->blocks[j].contents, 0, BLOCK_SIZE);
            fs->files[i].start_block = -1;
            return 0;
        }
    }
    printf("File not found: %s\n", name);
    return -1;
}

void list_files(struct FileSystem* fs) {
    printf("%-20s %10s %15s\n", "NAME", "SIZE", "START BLOCK");
    for(int i=0; i<MAX_FILES; i++) {
        if(fs->files[i].start_block != -1)
            printf("%-20s %10d %15d\n", fs->files[i].name, fs->files[i].size, fs->files[i].start_block);
    }
}

int main() {
    struct FileSystem fs;
    initialize_file_system(&fs);
    
    // Test add_file
    printf("Adding files...\n");
    add_file(&fs, "file1.txt", 1023);
    add_file(&fs, "file2.txt", 4096);
    add_file(&fs, "file3.txt", 8192);
    add_file(&fs, "file4.txt", 4096);
    add_file(&fs, "file5.txt", 8192);
    
    // Test list_files
    printf("Files in file system:\n");
    list_files(&fs);
    
    // Test remove_file
    printf("Removing file...\n");
    remove_file(&fs, "file2.txt");

    // Test list_files again
    printf("Files in file system after removal:\n");
    list_files(&fs);
    
    return 0;
}