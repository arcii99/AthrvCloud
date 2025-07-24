//FormAI DATASET v1.0 Category: File system simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_FILE_COUNT 100

typedef struct file {
    char name[MAX_FILENAME_LENGTH];
    int size;
} File;

File file_system[MAX_FILE_COUNT];
int file_count = 0;
int total_size = 0;

void create_file(char* name, int size) {
    if (file_count == MAX_FILE_COUNT) {
        printf("Error: file system full\n");
        return;
    }

    if (total_size + size > MAX_FILE_COUNT) {
        printf("Error: not enough space in file system\n");
        return;
    }

    File new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    file_system[file_count] = new_file;
    file_count++;
    total_size += size;

    printf("File \"%s\" of size %d created successfully\n", name, size);
}

void delete_file(char* name) {
    for (int i = 0; i < file_count; i++) {
        if (strcmp(file_system[i].name, name) == 0) {
            int size = file_system[i].size;
            for (int j = i; j < file_count - 1; j++) {
                file_system[j] = file_system[j+1];
            }
            file_count--;
            total_size -= size;
            printf("File \"%s\" deleted successfully\n", name);
            return;
        }
    }

    printf("Error: file \"%s\" not found\n", name);
}

void list_files() {
    printf("Total size of file system: %d\n", total_size);
    printf("Number of files in file system: %d\n", file_count);
    printf("List of files:\n");

    for (int i = 0; i < file_count; i++) {
        printf("%s - %d bytes\n", file_system[i].name, file_system[i].size);
    }
}

int main() {
    create_file("test.txt", 10);
    list_files();
    create_file("document.docx", 20);
    list_files();
    delete_file("test.txt");
    list_files();
    create_file("notes.txt", 5);
    list_files();
    create_file("presentation.pptx", 15);
    list_files();
    create_file("image.png", 30);
    create_file("audio.mp3", 25);
    list_files();
    
    return 0;
}