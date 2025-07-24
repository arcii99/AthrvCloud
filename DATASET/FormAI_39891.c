//FormAI DATASET v1.0 Category: File system simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1024
#define MAX_FILENAME 256

typedef struct {
    char name[MAX_FILENAME];
    int size;
    time_t modified;
} file;

typedef struct {
    char name[MAX_FILENAME];
    int size;
    time_t created;
    file files[MAX_SIZE];
} directory;

directory root;

void initialize_file_system() {
    strcpy(root.name, "/");
    root.size = 0;
    root.created = time(NULL);
}

void print_files(directory dir) {
    printf("Directory: %s\n", dir.name);
    printf("Size: %d bytes\n", dir.size);
    printf("Created: %s", ctime(&dir.created));
    printf("Files:\n");
    for(int i = 0; i < dir.size; i++) {
        printf("%s (%d bytes, modified %s)", dir.files[i].name, dir.files[i].size, ctime(&dir.files[i].modified));
    }
}

void create_file(directory *dir) {
    file new_file;
    printf("Enter file name: ");
    scanf("%s", new_file.name);
    printf("Enter file size in bytes (up to %d): ", MAX_SIZE - dir->size);
    scanf("%d", &(new_file.size));
    if(new_file.size + dir->size > MAX_SIZE) {
        printf("Not enough space in directory.\n");
        return;
    }
    new_file.modified = time(NULL);
    dir->files[dir->size++] = new_file;
    printf("File created successfully.\n");
}

void delete_file(directory *dir) {
    char filename[MAX_FILENAME];
    printf("Enter file name to delete: ");
    scanf("%s", filename);
    int index = -1;
    for(int i = 0; i < dir->size; i++) {
        if(strcmp(dir->files[i].name, filename) == 0) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("File not found.\n");
        return;
    }
    for(int i = index; i < dir->size - 1; i++) {
        dir->files[i] = dir->files[i+1];
    }
    dir->size--;
    printf("File successfully deleted.\n");
}

int main() {
    initialize_file_system();
    int choice;
    do {
        printf("\n\nSelect an option:\n");
        printf("1. Print files and directories\n");
        printf("2. Create a new file\n");
        printf("3. Delete a file\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: print_files(root); break;
            case 2: create_file(&root); break;
            case 3: delete_file(&root); break;
            case 4: break;
            default: printf("Invalid choice\n");
        }
    } while(choice != 4);
    return 0;
}