//FormAI DATASET v1.0 Category: File system simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_DIRECTORY_ENTRIES 10
#define MAX_FILE_SIZE 100

typedef enum {
    FILE_TYPE_FILE,
    FILE_TYPE_DIRECTORY
} FileType;

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    FileType type;
    int start_location;
    int size;
} FileSystemEntry;

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    int location;
} DirectoryEntry;

FileSystemEntry file_system[MAX_DIRECTORY_ENTRIES + 1];
DirectoryEntry current_directory[MAX_DIRECTORY_ENTRIES];
int num_files = 0;
int num_directories = 0;

char disk[MAX_FILE_SIZE];

void create_file_system_entry(char* name, FileType type, int start_location, int size) {
    FileSystemEntry entry;
    strncpy(entry.name, name, MAX_FILENAME_LENGTH);
    entry.type = type;
    entry.start_location = start_location;
    entry.size = size;
    file_system[num_files++] = entry;
}

void create_directory_entry(char* name, int location) {
    DirectoryEntry entry;
    strncpy(entry.name, name, MAX_FILENAME_LENGTH);
    entry.location = location;
    current_directory[num_directories++] = entry;
}

void print_directory() {
    printf("Current directory:\n");
    for (int i = 0; i < num_directories; i++) {
        printf("%s\n", current_directory[i].name);
    }
}

void create_file(char* name) {
    printf("Creating file %s\n", name);

    // Check if file already exists
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_system[i].name, name) == 0) {
            printf("File already exists\n");
            return;
        }
    }

    // Find a free location in the disk
    int free_location = -1;
    for (int i = 0; i < MAX_FILE_SIZE; i++) {
        if (disk[i] == 0) {
            free_location = i;
            break;
        }
    }
    if (free_location == -1) {
        printf("Disk is full\n");
        return;
    }

    // Create file system entry
    create_file_system_entry(name, FILE_TYPE_FILE, free_location, 0);

    printf("File created successfully\n");
}

void list_files() {
    printf("Files in current directory:\n");
    for (int i = 0; i < num_files; i++) {
        if (file_system[i].type == FILE_TYPE_FILE) {
            printf("%s\n", file_system[i].name);
        }
    }
}

void print_file_contents(char* name) {
    printf("Printing contents of file %s\n", name);

    // Find file system entry for the file
    int index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_system[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("File not found\n");
        return;
    }

    // Read file contents from disk
    int start_location = file_system[index].start_location;
    int size = file_system[index].size;
    char contents[MAX_FILE_SIZE];
    strncpy(contents, &disk[start_location], size);

    printf("%s", contents);
}

void save_file_contents(char* name, char* contents) {
    printf("Saving contents to file %s\n", name);

    // Find file system entry for the file
    int index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_system[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("File not found\n");
        return;
    }

    // Write contents to disk
    int start_location = file_system[index].start_location;
    int size = strlen(contents);
    strncpy(&disk[start_location], contents, size);
    file_system[index].size = size;

    printf("File saved successfully\n");
}

void change_directory(char* name) {
    printf("Changing directory to %s\n", name);

    // Find directory entry for the directory
    int index = -1;
    for (int i = 0; i < num_directories; i++) {
        if (strcmp(current_directory[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Directory not found\n");
        return;
    }

    printf("Directory changed successfully\n");

    // Update current_directory array
    num_directories = 0;
    for (int i = 0; i <= index; i++) {
        create_directory_entry(current_directory[i].name, current_directory[i].location);
    }
}

int main() {
    // Initialize file system
    create_file_system_entry("file1", FILE_TYPE_FILE, 0, 0);
    create_file_system_entry("file2", FILE_TYPE_FILE, 10, 0);
    create_file_system_entry("dir1", FILE_TYPE_DIRECTORY, 0, 0);
    create_file_system_entry("file3", FILE_TYPE_FILE, 20, 0);
    create_file_system_entry("dir2", FILE_TYPE_DIRECTORY, 30, 0);

    // Initialize current directory
    create_directory_entry("dir2", 30);

    // Main loop
    char input[100];
    while(1) {
        printf("\n> ");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }
        else if (strcmp(input, "ls") == 0) {
            list_files();
        }
        else if (strstr(input, "cat ") == input) {
            char* filename = input + 4;
            print_file_contents(filename);
        }
        else if (strstr(input, "touch ") == input) {
            char* filename = input + 6;
            create_file(filename);
        }
        else if (strstr(input, "echo ") == input) {
            char* rest = input + 5;
            char* filename = strtok(rest, " ");
            char* contents = strtok(NULL, "");
            save_file_contents(filename, contents);
        }
        else if (strstr(input, "cd ") == input) {
            char* dirname = input + 3;
            change_directory(dirname);
        }
        else {
            printf("Unknown command: %s\n", input);
        }

        print_directory();
    }

    return 0;
}