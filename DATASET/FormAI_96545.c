//FormAI DATASET v1.0 Category: File system simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_FILE_COUNT 10
#define MAX_FILE_SYSTEM_SIZE 100

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    int starting_block;
    int size;
} File;

File file_table[MAX_FILE_COUNT];
char file_system[MAX_FILE_SYSTEM_SIZE];
int next_free_block = 0;

void print_file_table() {
    printf("\n\nFile Table:\n");
    printf("Name\tSize\tStarting Block\n");
    for (int i = 0; i < MAX_FILE_COUNT; i++) {
        if (file_table[i].size > 0) {
            printf("%s\t%d\t%d\n", file_table[i].filename, file_table[i].size, file_table[i].starting_block);
        }
    }
}

int find_free_block(int size) {
    int n = 0;
    int free_count = 0;
    int last_free_block = -1;
    for (int i = 0; i < MAX_FILE_SYSTEM_SIZE; i++) {
        if (file_system[i] == 0) {
            free_count++;
            if (free_count == size) {
                return last_free_block + 1;
            }
        } else {
            free_count = 0;
            last_free_block = i;
        }
    }
    return -1;
}

int create_file(char* filename, int size) {
    for (int i = 0; i < MAX_FILE_COUNT; i++) {
        if (strcmp(file_table[i].filename, filename) == 0) {
            printf("\n\nError: File with name %s already exists.", filename);
            print_file_table();
            return -1;
        }
    }
    if (size > MAX_FILE_SYSTEM_SIZE) {
        printf("\n\nError: File size is too large for file system.");
        print_file_table();
        return -1;
    }
    int starting_block = find_free_block(size);
    if (starting_block == -1) {
        printf("\n\nError: No free blocks available for file.");
        print_file_table();
        return -1;
    }
    file_table[next_free_block].size = size;
    file_table[next_free_block].starting_block = starting_block;
    strcpy(file_table[next_free_block].filename, filename);
    for (int i = starting_block; i < starting_block + size; i++) {
        file_system[i] = 1;
    }
    next_free_block++;
    print_file_table();
    return 0;
}

int delete_file(char* filename) {
    for (int i = 0; i < MAX_FILE_COUNT; i++) {
        if (strcmp(file_table[i].filename, filename) == 0) {
            for (int j = file_table[i].starting_block; j < file_table[i].starting_block + file_table[i].size; j++) {
                file_system[j] = 0;
            }
            file_table[i].size = 0;
            file_table[i].starting_block = 0;
            strcpy(file_table[i].filename, "");
            next_free_block--;
            print_file_table();
            return 0;
        }
    }
    printf("\n\nError: File with name %s not found.", filename);
    print_file_table();
    return -1;
}

int main() {
    // initialize file system to all zeroes
    memset(file_system, 0, MAX_FILE_SYSTEM_SIZE);
    
    // create some test files
    create_file("file1", 5);
    create_file("file2", 2);
    create_file("file3", 3);
    
    // delete a file
    delete_file("file2");
    
    return 0;
}