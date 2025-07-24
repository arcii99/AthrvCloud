//FormAI DATASET v1.0 Category: File system simulation ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCK_SIZE 4096
#define MAX_FILES 100

typedef struct {
    char file_name[50];
    int block_num;
    int file_size;
} file_entry;

typedef struct {
    char data[BLOCK_SIZE];
    int free;
} block;

typedef struct { 
    file_entry files[MAX_FILES];
    int free;
} directory;

block disk[1000];
directory dir;

int next_free_block() {
    int i;
    for(i=1; i<1000; i++) {
        if(disk[i].free) return i;
    }
    return -1; 
}

void format_disk() {
    int i, j;

    for(i=0; i<1000; i++) {
        for(j=0; j<BLOCK_SIZE; j++) {
            disk[i].data[j] = '\0';
        }
        disk[i].free = 1;
    }
}

void list_files() {
    int i;

    printf("File Name\t\tFile Size\n");
    printf("-------------------------------------------------------\n");
    for (i=0; i<MAX_FILES; i++) {
        if(strlen(dir.files[i].file_name) > 0) {
            printf("%-20s\t\t%d\n",dir.files[i].file_name, dir.files[i].file_size);
        }
    }
    printf("\n");
}

void create_file(char *name, int size) {
    int i;

    for(i=0; i<MAX_FILES; i++) {
        if(strlen(dir.files[i].file_name) == 0) 
            break;
    }

    if(i==MAX_FILES) {
        printf("File limit exceeded\n");
        return;
    }

    if(size > (next_free_block() * BLOCK_SIZE)) {
        printf("Not enough disk space\n");
        return;
    }

    dir.files[i].block_num = next_free_block();
    dir.files[i].file_size = size;
    strcpy(dir.files[i].file_name, name);
    disk[dir.files[i].block_num].free = 0;

    printf("File created successfully\n");
}

void write_file(char *name, char *data) {
    int i;
    for(i=0; i<MAX_FILES; i++) {
        if(strcmp(name, dir.files[i].file_name) == 0) 
            break;
    }
    if(i==MAX_FILES) {
        printf("File does not exist\n");
        return;
    }

    if(strlen(data) > dir.files[i].file_size) {
        printf("Data size exceeds file size\n");
        return;
    }

    strcpy(disk[dir.files[i].block_num].data, data);
}

void read_file(char *name) {
    int i;
    for(i=0; i<MAX_FILES; i++) {
        if(strcmp(name, dir.files[i].file_name) == 0) 
            break;
    }
    if(i==MAX_FILES) {
        printf("File does not exist\n");
        return;
    }

    printf("%s\n", disk[dir.files[i].block_num].data);
}

int main() {

    int choice;
    char name[50], data[4096];

    format_disk();

    while(1) {

        printf("What would you like to do?\n");
        printf("1. Create a new file\n");
        printf("2. List all files\n");
        printf("3. Read a file\n");
        printf("4. Write to a file\n");
        printf("5. Exit\n");
        printf("Your Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            
            case 1:
                printf("Enter file name: ");
                scanf("%s", name);
                printf("Enter file size: ");
                int size;
                scanf("%d", &size);
                create_file(name, size);
                break;

            case 2:
                list_files();
                break;

            case 3:
                printf("Enter file name: ");
                scanf("%s", name);
                read_file(name);
                break;

            case 4:
                printf("Enter file name: ");
                scanf("%s", name);
                printf("Enter data: ");
                scanf("%s", data);
                write_file(name, data);
                break;

            case 5:
                printf("Goodbye\n");
                exit(0);
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}