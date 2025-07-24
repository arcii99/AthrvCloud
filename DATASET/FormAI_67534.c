//FormAI DATASET v1.0 Category: File system simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILENAME_SIZE 50
#define BLOCK_SIZE 512
#define NUM_BLOCKS 1000
#define MAGIC_NUMBER 0xCAFEBABE

typedef struct {
    int magic_number;
    char name[FILENAME_SIZE];
    time_t creation_time;
    int size;
    int start_block;
} file_entry;

struct block {
    char data[BLOCK_SIZE];
};

struct block disk[NUM_BLOCKS];
file_entry file_table[NUM_BLOCKS];
int free_block_count = NUM_BLOCKS;

void format_fs() {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        memset(disk[i].data, 0, BLOCK_SIZE);
    }
    for (int i = 0; i < NUM_BLOCKS; i++) {
        file_table[i].magic_number = 0;
    }
    free_block_count = NUM_BLOCKS;
    printf("File system formatted.\n");
}

int find_free_block() {
    if (free_block_count == 0) {
        return -1;
    }
    int index = rand() % NUM_BLOCKS;
    while (file_table[index].magic_number != 0) {
        index = rand() % NUM_BLOCKS;
    }
    free_block_count--;
    return index;
}

void create_file(char* name, int size) {
    if (strlen(name) > FILENAME_SIZE) {
        printf("Error: filename is too long\n");
        return;
    }
    if (size > free_block_count * BLOCK_SIZE) {
        printf("Error: not enough free space\n");
        return;
    }
    int start_block = find_free_block();
    if (start_block == -1) {
        printf("Error: not enough free space\n");
        return;
    }
    time_t creation_time = time(NULL);
    file_entry file;
    file.magic_number = MAGIC_NUMBER;
    strcpy(file.name, name);
    file.creation_time = creation_time;
    file.size = size;
    file.start_block = start_block;
    file_table[start_block] = file;
    int remaining_size = size;
    while (remaining_size > 0) {
        int block = find_free_block();
        if (block == -1) {
            printf("Warning: not enough free space for entire file\n");
            break;
        }
        disk[block].data[0] = 'F'; // mark block as part of file
        file_table[block].magic_number = MAGIC_NUMBER;
        if (remaining_size <= BLOCK_SIZE) {
            memcpy(disk[block].data, "EOF", 3);
            remaining_size = 0;
        } else {
            remaining_size -= BLOCK_SIZE;
        }
    }
    printf("File created.\n");
}

void delete_file(char* name) {
    int deleted = 0;
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (file_table[i].magic_number == MAGIC_NUMBER && strcmp(file_table[i].name, name) == 0) {
            deleted++;
            file_table[i].magic_number = 0;
            free_block_count++;
            int block = i;
            while (strcmp(disk[block].data, "EOF") != 0) {
                file_table[block].magic_number = 0;
                free_block_count++;
                block++;
            }
            memset(disk[i].data, 0, BLOCK_SIZE);
        }
    }
    if (deleted == 0) {
        printf("Error: file not found\n");
    } else {
        printf("%d file(s) deleted.\n", deleted);
    }
}

void list_files() {
    printf("Name\tSize\tCreation Time\n");
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (file_table[i].magic_number == MAGIC_NUMBER) {
            printf("%s\t%d\t%s", file_table[i].name, file_table[i].size, ctime(&file_table[i].creation_time));
        }
    }
}

void print_disk_info() {
    int used_blocks = NUM_BLOCKS - free_block_count;
    printf("\nDisk info:\n");
    printf("Total blocks: %d\n", NUM_BLOCKS);
    printf("Used blocks: %d\n", used_blocks);
    printf("Free blocks: %d\n", free_block_count);
    printf("Total size: %d bytes\n", NUM_BLOCKS * BLOCK_SIZE);
    printf("Used size: %d bytes\n", used_blocks * BLOCK_SIZE);
    printf("Free size: %d bytes\n\n", free_block_count * BLOCK_SIZE);
}

int main() {
    srand(time(NULL));
    format_fs();
    while (1) {
        char command[20], arg1[FILENAME_SIZE], arg2[20];
        printf("Enter a command: ");
        scanf("%s %s %s", command, arg1, arg2);
        if (strcmp(command, "create") == 0) {
            int size;
            sscanf(arg2, "%d", &size);
            create_file(arg1, size);
        } else if (strcmp(command, "delete") == 0) {
            delete_file(arg1);
        } else if (strcmp(command, "list") == 0) {
            list_files();
        } else if (strcmp(command, "info") == 0) {
            print_disk_info();
        } else if (strcmp(command, "format") == 0) {
            format_fs();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}