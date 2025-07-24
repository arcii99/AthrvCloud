//FormAI DATASET v1.0 Category: File system simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 5
#define MAX_NAME_LENGTH 20

typedef struct file {
    char name[MAX_NAME_LENGTH];
    char contents[100];
} File;

typedef struct directory {
    char name[MAX_NAME_LENGTH];
    int num_files;
    File files[MAX_FILES];
} Directory;

Directory root_directory;
Directory current_directory;

void init() {
    strcpy(root_directory.name, "/");
    root_directory.num_files = 0;
    strcpy(current_directory.name, "/");
    current_directory.num_files = 0;
}

int find_file(char* name, Directory* directory) {
    int i;
    for (i = 0; i < directory->num_files; i++) {
        if (strcmp(directory->files[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void create_file(char* name) {
    int index = find_file(name, &current_directory);
    if (index != -1) {
        printf("Error: File already exists\n");
        return;
    }
    if (current_directory.num_files == MAX_FILES) {
        printf("Error: No more room for files\n");
        return;
    }
    strcpy(current_directory.files[current_directory.num_files].name, name);
    current_directory.num_files++;
    printf("File created successfully\n");
}

void delete_file(char* name) {
    int index = find_file(name, &current_directory);
    if (index == -1) {
        printf("Error: File does not exist\n");
        return;
    }
    int i;
    for (i = index; i < current_directory.num_files - 1; i++) {
        strcpy(current_directory.files[i].name, current_directory.files[i+1].name);
        strcpy(current_directory.files[i].contents, current_directory.files[i+1].contents);
    }
    current_directory.num_files--;
    printf("File deleted successfully\n");
}

void list_files() {
    int i;
    for (i = 0; i < current_directory.num_files; i++) {
        printf("%s\n", current_directory.files[i].name);
    }
}

void change_directory(char* name) {
    if (strcmp(name, "..") == 0) {
        if (strcmp(current_directory.name, "/") == 0) {
            printf("Error: Already at root directory\n");
            return;
        }
        int i;
        for (i = strlen(current_directory.name) - 1; i >= 0; i--) {
            if (current_directory.name[i] == '/') {
                break;
            }
        }
        current_directory.name[i] = '\0';
    }
    else {
        int i;
        for (i = 0; i < current_directory.num_files; i++) {
            if (strcmp(current_directory.files[i].name, name) == 0) {
                printf("Error: %s is a file, not a directory\n", name);
                return;
            }
        }
        Directory new_directory;
        strcpy(new_directory.name, current_directory.name);
        strcat(new_directory.name, "/");
        strcat(new_directory.name, name);
        new_directory.num_files = 0;
        current_directory = new_directory;
        printf("Directory changed to %s\n", current_directory.name);
    }
}

void print_help() {
    printf("Commands:\n");
    printf("create <filename> - create a new file in the current directory\n");
    printf("delete <filename> - delete a file in the current directory\n");
    printf("ls - list all files in the current directory\n");
    printf("cd <directoryname> - change to a directory in the current directory\n");
    printf("cd .. - change to the parent of the current directory\n");
    printf("help - print this help message\n");
    printf("exit - exit the program\n");
}

int main() {
    init();
    printf("Welcome to the File System Simulation\n");
    printf("Type \"help\" to see a list of commands\n");
    char input[100];
    while (1) {
        printf("%s> ", current_directory.name);
        fgets(input, 100, stdin);
        input[strlen(input) - 1] = '\0'; // remove newline character
        char* command = strtok(input, " ");
        char* argument = strtok(NULL, " ");
        if (strcmp(command, "create") == 0) {
            if (argument == NULL) {
                printf("Error: No filename specified\n");
            }
            else {
                create_file(argument);
            }
        }
        else if (strcmp(command, "delete") == 0) {
            if (argument == NULL) {
                printf("Error: No filename specified\n");
            }
            else {
                delete_file(argument);
            }
        }
        else if (strcmp(command, "ls") == 0) {
            list_files();
        }
        else if (strcmp(command, "cd") == 0) {
            if (argument == NULL) {
                printf("Error: No directory specified\n");
            }
            else {
                change_directory(argument);
            }
        }
        else if (strcmp(command, "help") == 0) {
            print_help();
        }
        else if (strcmp(command, "exit") == 0) {
            break;
        }
        else {
            printf("Error: Invalid command\n");
            print_help();
        }
    }
    printf("Goodbye!\n");
    return 0;
}