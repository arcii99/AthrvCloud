//FormAI DATASET v1.0 Category: File system simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define the size of the file system
#define FILE_SYSTEM_SIZE 100

// Define the file system structure
typedef struct {
    char name[20];
    int start;
    int end;
} File;

// Define the file system
char file_system[FILE_SYSTEM_SIZE];

// Define function prototypes
void display_file_system();
void create_file(char name[], int size);
void delete_file(char name[]);
void defragment();

int main() {
    int choice, file_size;
    char file_name[20];
    display_file_system();
    while (1) {
        printf("\n1. Create a file\n2. Delete a file\n3. Defragment the file system\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", file_name);
                printf("Enter file size: ");
                scanf("%d", &file_size);
                create_file(file_name, file_size);
                display_file_system();
                break;
            case 2:
                printf("Enter file name: ");
                scanf("%s", file_name);
                delete_file(file_name);
                display_file_system();
                break;
            case 3:
                defragment();
                display_file_system();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Function to display the file system
void display_file_system() {
    int i;
    printf("\n");
    for (i = 0; i < FILE_SYSTEM_SIZE; i++) {
        printf("%c", file_system[i]);
    }
    printf("\n");
}

// Function to create a new file
void create_file(char name[], int size) {
    int i, j, start = -1, end = -1, found = 0, free_size = 0;
    // Check if enough space is available in the file system
    for (i = 0; i < FILE_SYSTEM_SIZE; i++) {
        if (file_system[i] == '.') {
            free_size++;
            if (free_size == size) {
                found = 1;
                end = i;
                for (j = i - size + 1; j <= i; j++) {
                    file_system[j] = name[j - i + size - 1];
                }
                break;
            }
        } else {
            free_size = 0;
        }
    }
    if (found) {
        start = end - size + 1;
        printf("File created successfully!\n");
        printf("File name: %s\nFile size: %d\nStart position: %d\nEnd position: %d\n", name, size, start, end);
    } else {
        printf("Not enough space available to create the file!\n");
    }
}

// Function to delete a file
void delete_file(char name[]) {
    int i, found = 0;
    for (i = 0; i < FILE_SYSTEM_SIZE; i++) {
        if (file_system[i] == name[0]) {
            if (strncmp(file_system + i, name, strlen(name)) == 0) {
                found = 1;
                while (file_system[i] != '.') {
                    file_system[i++] = '.';
                }
                break;
            }
        }
    }
    if (found) {
        printf("File deleted successfully!\n");
    } else {
        printf("File not found!\n");
    }
}

// Function to defragment the file system
void defragment() {
    int i, j, free_size = 0;
    char temp[FILE_SYSTEM_SIZE];
    for (i = 0; i < FILE_SYSTEM_SIZE; i++) {
        if (file_system[i] == '.') {
            free_size++;
            if (free_size == 1) {
                temp[i] = file_system[i];
            }
        } else {
            free_size = 0;
            temp[i] = file_system[i];
            for (j = i - 1; j >= 0; j--) {
                if (temp[j] == '.') {
                    temp[j] = temp[i];
                    temp[i] = '.';
                    break;
                }
            }
        }
    }
    strcpy(file_system, temp);
    printf("File system defragmented successfully!\n");
}