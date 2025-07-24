//FormAI DATASET v1.0 Category: File system simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100 //Maximum command length allowed

//Data structure for file node
typedef struct file_node {
    char *name;
    char *content;
    bool is_directory;
    struct file_node *next;
} FileNode;

//Global variables
FileNode *root_directory = NULL; //Pointer to root directory 
FileNode *current_directory = NULL; //Pointer to current directory 
char current_path[100] = "/"; //String to hold current directory path

//Function to create a new file node
FileNode *create_file_node(char *name, bool is_directory) {
    FileNode *new_node = (FileNode *)malloc(sizeof(FileNode));
    new_node->name = strdup(name);
    new_node->content = NULL;
    new_node->is_directory = is_directory;
    new_node->next = NULL;

    return new_node;
}

//Function to add a new file/directory to current directory
void add_file(char *name, bool is_directory) {
    FileNode *new_node = create_file_node(name, is_directory);

    if (current_directory == NULL) { //If current directory is root directory
        root_directory = new_node;
        current_directory = root_directory;
    } else { //If current directory is not root directory
        current_directory->next = new_node;
        current_directory = new_node;
    }
}

//Function to search for a node in directory
FileNode *search_node(char *name, FileNode *directory) {
    FileNode *temp = directory;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

//Function to change directory
void change_directory(char *path) {
    FileNode *temp_directory;
    char *delimiter = "/";
    char *token = strtok(path, delimiter);

    if (strcmp(token, "") == 0) { //If path starts with "/"
        current_directory = root_directory;
    }

    while (token != NULL) {
        if (strcmp(token, "..") == 0) { //If token is ".." ("go up" one directory)
            temp_directory = root_directory;
            FileNode *parent_directory = NULL;

            //Finding parent directory
            while (temp_directory != NULL) {
                if (temp_directory == current_directory) {
                    current_directory = parent_directory;
                    break;
                }
                parent_directory = temp_directory;
                temp_directory = temp_directory->next;
            }
        } else { //If token is not ".."
            temp_directory = search_node(token, current_directory);

            if (temp_directory != NULL && temp_directory->is_directory) {
                current_directory = temp_directory;
            } else {
                printf("Directory '%s' does not exist\n", token);
            }
        }

        token = strtok(NULL, delimiter);
    }
}

//Function to print current directory path
void print_directory_path() {
    printf("%s\n", current_path);
}

//Function to print files and directories in current directory
void print_directory_list() {
    FileNode *temp = current_directory;

    while (temp != NULL) {
        printf("%s", temp->name);
        if (temp->is_directory) {
            printf("/");
        }
        printf("\n");
        temp = temp->next;
    }
}

//Function to delete a file/directory
void delete_node(char *name) {
    FileNode *temp_directory = root_directory;
    FileNode *temp_node = NULL;

    //Finding parent directory of node to be deleted
    while (temp_directory != current_directory) {
        temp_node = temp_directory;
        temp_directory = temp_directory->next;
    }

    temp_node->next = NULL;

    //Finding node to be deleted
    temp_node = search_node(name, current_directory);

    if (temp_node != NULL) {
        //Deleting node
        if (current_directory == temp_node) { //If node to be deleted is current directory
            current_directory = temp_directory; //Change current directory to parent directory
            strcat(current_path, "../"); //Updating current path
        }
        free(temp_node->name);
        free(temp_node->content);
        free(temp_node);
    } else {
        printf("'\"%s\"' does not exist\n", name);
    }

    temp_node = current_directory;
    while (temp_node->next != NULL) {
        temp_node = temp_node->next;
    }
    temp_node->next = temp_directory;
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    printf("File System Simulator\n");
    printf("Enter 'help' to view list of commands\n\n");

    while (true) {
        printf("%s> ", current_path);
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0;

        if (strncmp(command, "create", 6) == 0) {
            char file_name[50];
            printf("Enter file name: ");
            scanf("%s", file_name);
            getchar();

            //Checking if file already exists
            FileNode *temp = current_directory;
            while (temp != NULL) {
                if (strcmp(temp->name, file_name) == 0) {
                    printf("File '%s' already exists\n", file_name);
                    goto skip;
                }
                temp = temp->next;
            }

            //Creating file
            add_file(file_name, false);
            printf("File '%s' created successfully\n", file_name);

        } else if (strncmp(command, "create_dir", 10) == 0) {
            char dir_name[50];
            printf("Enter directory name: ");
            scanf("%s", dir_name);
            getchar();

            //Checking if directory already exists
            FileNode *temp = current_directory;
            while (temp != NULL) {
                if (strcmp(temp->name, dir_name) == 0) {
                    printf("Directory '%s' already exists\n", dir_name);
                    goto skip;
                }
                temp = temp->next;
            }

            //Creating directory
            add_file(dir_name, true);
            printf("Directory '%s' created successfully\n", dir_name);

        } else if (strncmp(command, "cd", 2) == 0) {
            char path[100];
            printf("Enter path: ");
            fgets(path, 100, stdin);
            path[strcspn(path, "\n")] = 0;

            change_directory(path);

            //Updating current path
            strcpy(current_path, "/");
            FileNode *temp_directory = root_directory;
            while (temp_directory != current_directory) {
                strcat(current_path, temp_directory->name);
                strcat(current_path, "/");
                temp_directory = temp_directory->next;
            }

        } else if (strncmp(command, "ls", 2) == 0) {
            print_directory_list();
            printf("\n");

        } else if (strncmp(command, "delete", 6) == 0) {
            char file_name[50];
            printf("Enter file/directory name: ");
            scanf("%s", file_name);
            getchar();

            delete_node(file_name);

        } else if (strncmp(command, "help", 4) == 0) {
            printf("Commands:\n");
            printf("create - Create a new file\n");
            printf("create_dir - Create a new directory\n");
            printf("cd - Change directory\n");
            printf("ls - List files and directories in current directory\n");
            printf("delete - Delete a file or directory\n");
            printf("help - Display list of commands\n\n");

        } else if (strncmp(command, "exit", 4) == 0) {
            break;
        }

        skip:
            continue;
    }

    return 0;
}