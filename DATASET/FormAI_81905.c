//FormAI DATASET v1.0 Category: File system simulation ; Style: paranoid
#include <stdio.h>

#define MAX_BLOCKS 1024
#define MAX_FILE_SIZE 1048576 // 1 MB
#define FILENAME_SIZE 20

// Block structure
struct block {
    char data[1024]; // Each block has a size of 1 KB
};

// Superblock structure
struct superblock {
    int total_blocks;
    int free_blocks;
    int first_free_block;
};

// File Metadata structure
struct file {
    char name[FILENAME_SIZE];
    int size;
    int first_block_index;
};

struct block blocks[MAX_BLOCKS];
struct superblock super;
struct file files[MAX_BLOCKS];

void initialize_filesystem() {
    super.total_blocks = MAX_BLOCKS;
    super.free_blocks = MAX_BLOCKS;
    super.first_free_block = 0;
}

void create_file(char* filename, int size) {
    if (super.free_blocks == 0) {
        printf("Error: Filesystem full!\n");
        return;
    }

    // Find first free block
    int index = super.first_free_block;
    while (index < MAX_BLOCKS && blocks[index].data[0] != '\0') {
        index++;
    }

    if (index == MAX_BLOCKS) {
        printf("Error: Filesystem full!\n");
        return;
    }

    // Update first free block
    for (int i = index + 1; i < MAX_BLOCKS; i++) {
        if (blocks[i].data[0] == '\0') {
            super.first_free_block = i;
            break;
        }
    }

    // Update filesystem metadata
    super.free_blocks--;
    struct file new_file;
    strcpy(new_file.name, filename);
    new_file.size = size;
    new_file.first_block_index = index;
    files[index] = new_file;

    printf("File created successfully!\n");
}

void read_file(char* filename) {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (strcmp(files[i].name, filename) == 0) {
            printf("Reading file '%s'...\n", filename);

            // Check file size
            int size = files[i].size;
            if (size > MAX_FILE_SIZE) {
                printf("Error: File size exceeds maximum size supported!\n");
                return;
            }

            // Read file contents
            int block_index = files[i].first_block_index;
            while (size > 0) {
                printf("%s", blocks[block_index].data);
                size -= 1024;
                block_index++;
            }

            printf("\n");
            return;
        }
    }

    printf("Error: File '%s' not found!\n", filename);
}

void delete_file(char* filename) {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (strcmp(files[i].name, filename) == 0) {
            printf("Deleting file '%s'...\n", filename);

            // Free file blocks
            int size = files[i].size;
            int block_index = files[i].first_block_index;
            while (size > 0) {
                blocks[block_index].data[0] = '\0';
                super.free_blocks++;
                size -= 1024;
                block_index++;
            }

            // Clear file metadata
            memset(&files[i], 0, sizeof(struct file));

            printf("File deleted successfully!\n");
            return;
        }
    }

    printf("Error: File '%s' not found!\n", filename);
}

int main() {
    initialize_filesystem();

    printf("Creating file 'file1.txt'...\n");
    create_file("file1.txt", 2048);

    printf("Creating file 'file2.txt'...\n");
    create_file("file2.txt", 4096);

    printf("Reading file 'file1.txt'...\n");
    read_file("file1.txt");

    printf("Deleting file 'file1.txt'...\n");
    delete_file("file1.txt");

    printf("Reading file 'file1.txt'...\n");
    read_file("file1.txt");

    printf("Creating file 'file3.txt'...\n");
    create_file("file3.txt", 8192);

    printf("Creating file 'file4.txt'...\n");
    create_file("file4.txt", 10485760);

    printf("Reading file 'file3.txt'...\n");
    read_file("file3.txt");

    printf("Deleting file 'file2.txt'...\n");
    delete_file("file2.txt");

    printf("Deleting file 'file3.txt'...\n");
    delete_file("file3.txt");

    printf("Deleting file 'file4.txt'...\n");
    delete_file("file4.txt");

    printf("Creating file 'file5.txt'...\n");
    create_file("file5.txt", 1337);

    printf("Reading file 'file5.txt'...\n");
    read_file("file5.txt");

    return 0;
}