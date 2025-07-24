//FormAI DATASET v1.0 Category: File system simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_NAME_LENGTH 20
#define BLOCK_SIZE 512
#define MAX_BLOCKS 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int start_block;
    int size;
} File;

int free_blocks[MAX_BLOCKS];
File files[MAX_FILES];
int num_files = 0;

int initialize_file_system();
int find_free_block();
void format();
void ls();
void create(char* name, int size);
void delete(char* name);
void write(char* name, char* data);
void read(char* name);

int main() {
    initialize_file_system();

    while (1) {
        char command[10], name[MAX_NAME_LENGTH], data[MAX_BLOCKS * BLOCK_SIZE];
        int size;

        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "ls") == 0) {
            ls();
        }

        else if (strcmp(command, "create") == 0) {
            scanf("%s %d", name, &size);
            create(name, size);
        }

        else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            delete(name);
        }

        else if (strcmp(command, "write") == 0) {
            scanf("%s %[^\n]s", name, data);
            write(name, data);
        }

        else if (strcmp(command, "read") == 0) {
            scanf("%s", name);
            read(name);
        }

        else if (strcmp(command, "quit") == 0) {
            break;
        }

        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}

int initialize_file_system() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        free_blocks[i] = 1;
    }

    format();
}

int find_free_block() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (free_blocks[i] == 1) {
            free_blocks[i] = 0;
            return i;
        }
    }

    return -1;
}

void format() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        free_blocks[i] = 1;
    }

    for (int i = 0; i < MAX_FILES; i++) {
        strcpy(files[i].name, "");
        files[i].start_block = -1;
        files[i].size = 0;
    }

    num_files = 0;
}

void ls() {
    if (num_files == 0) {
        printf("No files in directory.\n");
    }

    else {
        printf("Name\tSize\n");

        for (int i = 0; i < num_files; i++) {
            printf("%s\t%d\n", files[i].name, files[i].size);
        }
    }
}

void create(char* name, int size) {
    if (num_files == MAX_FILES) {
        printf("Max number of files reached.\n");
    }

    else {
        int start_block = find_free_block();

        if (start_block == -1) {
            printf("Not enough free space.\n");
        }

        else {
            File new_file;
            strcpy(new_file.name, name);
            new_file.start_block = start_block;
            new_file.size = size;
            files[num_files++] = new_file;
        }
    }
}

void delete(char* name) {
    int file_index = -1;

    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }

    if (file_index == -1) {
        printf("File not found.\n");
    }

    else {
        int start_block = files[file_index].start_block;
        int size = files[file_index].size;

        for (int i = start_block; i < start_block + size; i++) {
            free_blocks[i] = 1;
        }

        for (int i = file_index + 1; i < num_files; i++) {
            files[i - 1] = files[i];
        }

        num_files--;
    }
}

void write(char* name, char* data) {
    int file_index = -1;

    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }

    if (file_index == -1) {
        printf("File not found.\n");
    }

    else {
        int start_block = files[file_index].start_block;
        int size = files[file_index].size;

        if (strlen(data) > size * BLOCK_SIZE) {
            printf("Data too large for file.\n");
        }

        else {
            int data_index = 0;

            for (int i = start_block; i < start_block + size; i++) {
                if (data_index > strlen(data)) break;

                strncpy((char*)((long long)i * BLOCK_SIZE), &data[data_index], BLOCK_SIZE);
                data_index += BLOCK_SIZE;
            }
        }
    }
}

void read(char* name) {
    int file_index = -1;

    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }

    if (file_index == -1) {
        printf("File not found.\n");
    }

    else {
        int start_block = files[file_index].start_block;
        int size = files[file_index].size;
        char data[size * BLOCK_SIZE + 1];

        int data_index = 0;

        for (int i = start_block; i < start_block + size; i++) {
            strncpy(&data[data_index], (char*)((long long)i * BLOCK_SIZE), BLOCK_SIZE);
            data_index += BLOCK_SIZE;
        }

        data[data_index] = '\0';

        printf("%s\n", data);
    }
}