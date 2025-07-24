//FormAI DATASET v1.0 Category: File system simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_FILESYSTEM_SIZE 1024

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    int size;
    int start_index;
    bool is_deleted;
} File;

File filesystem[MAX_FILESYSTEM_SIZE];
int filesystem_size = 0;

void print_menu() {
    printf("\nSelect an option: \n");
    printf("1. Create a new file\n");
    printf("2. Delete a file\n");
    printf("3. List all files\n");
    printf("4. Exit\n");
}

void create_file(char* name, int size) {
    if (size > MAX_FILESYSTEM_SIZE - filesystem_size) {
        printf("Filesystem too small\n");
        return;
    }
    for (int i = 0; i < filesystem_size; i++) {
        if (strcmp(filesystem[i].name, name) == 0 && !filesystem[i].is_deleted) {
            printf("File already exists\n");
            return;
        }
    }
    int index = 0;
    while (filesystem[index].start_index != -1) {
        index++;
    }
    strcpy(filesystem[index].name, name);
    filesystem[index].size = size;
    filesystem[index].start_index = index;
    filesystem[index].is_deleted = false;
    filesystem_size += size;
    printf("File created\n");
}

void delete_file(char* name) {
    for (int i = 0; i < filesystem_size; i++) {
        if (strcmp(filesystem[i].name, name) == 0 && !filesystem[i].is_deleted) {
            filesystem[i].is_deleted = true;
            filesystem_size -= filesystem[i].size;
            printf("File deleted\n");
            return;
        }
    }
    printf("File not found\n");
}

void list_files() {
    printf("%-20s %-10s\n", "Name", "Size");
    for (int i = 0; i < filesystem_size; i++) {
        if (!filesystem[i].is_deleted) {
            printf("%-20s %-10d\n", filesystem[i].name, filesystem[i].size);
        }
    }
}

int main() {
    for (int i = 0; i < MAX_FILESYSTEM_SIZE; i++) {
        filesystem[i].start_index = -1;
        filesystem[i].is_deleted = true;
    }
    int option;
    do {
        print_menu();
        scanf("%d", &option);
        switch(option) {
            case 1: {
                char name[MAX_FILENAME_LENGTH];
                int size;
                printf("Enter file name: ");
                scanf("%s", name);
                printf("Enter file size: ");
                scanf("%d", &size);
                create_file(name, size);
                break;
            }
            case 2: {
                char name[MAX_FILENAME_LENGTH];
                printf("Enter file name: ");
                scanf("%s", name);
                delete_file(name);
                break;
            }
            case 3:
                list_files();
                break;
            case 4:
                printf("Goodbye\n");
                break;
            default:
                printf("Invalid option\n");
        }
    } while(option != 4);

    return 0;
}