//FormAI DATASET v1.0 Category: File system simulation ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILES 10
#define FILE_NAME_LENGTH 20

struct file {
    char name[FILE_NAME_LENGTH];
    char data[100];
    int size;
    int is_free;
};

struct file files[MAX_FILES];

void initialize_files() {
    for(int i=0; i<MAX_FILES; i++) {
        files[i].is_free = 1;
        files[i].size = 0;
    }
}

int create_file(char* name) {
    int i;
    for(i=0; i<MAX_FILES; i++) {
        if (files[i].is_free == 1) {
            strcpy(files[i].name, name);
            files[i].size = 0;
            files[i].is_free = 0;
            return i;
        }
    }
    return -1;
}

int find_file(char* name) {
    int i;
    for(i=0; i<MAX_FILES; i++) {
        if (strcmp(files[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void delete_file(char* name) {
    int i = find_file(name);
    if (i != -1) {
        files[i].is_free = 1;
    }
}

void write_file(char* name, char* data) {
    int i = find_file(name);
    if (i != -1) {
        strcpy(files[i].data, data);
        files[i].size = strlen(data);
    }
}

void read_file(char* name, char* output) {
    int i = find_file(name);
    if (i != -1) {
        strcpy(output, files[i].data);
    }
}

void print_files() {
    printf("\nFile List\n");
    printf("========================\n");
    for(int i=0; i<MAX_FILES; i++) {
        if (files[i].is_free == 0) {
            printf("%s\t%d Bytes\n", files[i].name, files[i].size);
        }
    }
    printf("========================\n");
}

int main() {
    initialize_files();
    int choice = 0;
    char name[FILE_NAME_LENGTH];

    while(choice != 5) {
        printf("\n\n-----------------------\n");
        printf("File System Simulation\n");
        printf("-----------------------\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Write to File\n");
        printf("4. Read File\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the name of the file: ");
                scanf("%s", name);
                if (create_file(name) == -1) {
                    printf("Could not create file.\n");
                } else {
                    printf("File created successfully.\n");
                }
                break;
            case 2:
                printf("Enter the name of the file: ");
                scanf("%s", name);
                delete_file(name);
                printf("File deleted successfully.\n");
                break;
            case 3:
                printf("Enter the name of the file: ");
                scanf("%s", name);
                char file_data[100];
                printf("Enter the data: ");
                scanf("%s", file_data);
                write_file(name, file_data);
                printf("Data written successfully.\n");
                break;
            case 4:
                printf("Enter the name of the file: ");
                scanf("%s", name);
                char output[100];
                read_file(name, output);
                printf("File content: %s\n", output);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
        print_files();
    }
    return 0;
}