//FormAI DATASET v1.0 Category: File Backup System ; Style: decentralized
/*
Decentralized File Backup System
Author: Chatbot AI
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_SIZE 1000
#define FILE_NAME_LEN 50
#define BACKUP_DIR "backup/"

typedef struct File{
    char name[FILE_NAME_LEN];
    time_t modified_time;
    char content[MAX_SIZE];
} File;

typedef struct Node{
    File file;
    struct Node* prev;
    struct Node* next;
} Node;

Node* first = NULL;
Node* last = NULL;

// Create new node and add it to the end of the linked list
void add(File file){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->file = file;
    newNode->next = NULL;
    newNode->prev = last;
    if(first == NULL){
        first = newNode;
    }else{
        last->next = newNode;
    }
    last = newNode;
}

// Read file data and return as File object
File read_file(char* file_name){
    File file;
    strncpy(file.name, file_name, FILE_NAME_LEN);
    file.modified_time = time(NULL);
    char path[FILE_NAME_LEN + 7] = BACKUP_DIR; 
    strcat(path, file_name); 
    FILE* fp = fopen(path, "r"); 
    if(fp == NULL){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }else{
        fread(file.content, MAX_SIZE, 1, fp);
        fclose(fp);
    }
    return file;
}

// Write file data to backup directory
void backup_file(File file){
    char path[FILE_NAME_LEN + 7] = BACKUP_DIR;
    strcat(path, file.name);
    FILE * fp = fopen(path, "w+"); 
    if(fp == NULL){
        perror("Error creating backup file");
        exit(EXIT_FAILURE);
    }else{
        fwrite(file.content, MAX_SIZE, 1, fp);
        fclose(fp);
    }
}

// Delete file from backup directory
void delete_backup(char* file_name){
    char path[FILE_NAME_LEN + 7] = BACKUP_DIR;
    strcat(path, file_name);
    remove(path);
}

// Display backup directory files
void display_backups(){
    char command[MAX_SIZE] = "ls -al ";
    strcat(command, BACKUP_DIR);
    system(command);
}

// Main function
int main(){
    // Read files from backup directory
    char command[] = "ls " BACKUP_DIR;
    system(command);
    FILE *fp = popen(command, "r");
    if(fp == NULL){
        perror("Error in executing command");
        exit(EXIT_FAILURE);
    }
    char data[MAX_SIZE];
    while(fgets(data, MAX_SIZE, fp) != NULL){
        if(strlen(data) >= FILE_NAME_LEN && data[0] != '.'){
            char* file_name = strtok(data, "\n");
            File file = read_file(file_name);
            add(file);
        }
    }
    pclose(fp);

    // Display welcome message
    printf("Welcome to the Decentralized File Backup System\n");
    printf("Enter a command to begin, type help for list of available commands.\n");

    // Command line interface loop
    while(1){
        // Get user command
        printf("> ");
        char command[MAX_SIZE];
        fgets(command, MAX_SIZE, stdin);
        command[strcspn(command, "\n")] = 0;

        // Process command
        if(strcmp(command, "list") == 0){
            printf("Listing all files backed up:\n");
            for(Node* current = first; current != NULL; current = current->next){
                printf("%s\n", current->file.name);
            }
        }else if(strcmp(command, "backup") == 0){
            printf("Enter the name of the file to backup:\n");
            char file_name[FILE_NAME_LEN];
            fgets(file_name, FILE_NAME_LEN, stdin);
            file_name[strcspn(file_name, "\n")] = 0;

            // Read file and add to linked list
            File file = read_file(file_name);
            add(file);
            printf("Backing up file...\n");
            backup_file(file);
        }else if(strcmp(command, "delete") == 0){
            printf("Enter the name of the file to delete:\n");
            char file_name[FILE_NAME_LEN];
            fgets(file_name, FILE_NAME_LEN, stdin);
            file_name[strcspn(file_name, "\n")] = 0;

            // Remove file from linked list and delete from backup directory
            for(Node* current = first; current != NULL; current = current->next){
                if(strcmp(current->file.name, file_name) == 0){
                    printf("Deleting file...\n");
                    delete_backup(file_name);
                    if(current == first){
                        first = current->next;
                    }
                    if(current == last){
                        last = current->prev;
                    }
                    if(current->prev != NULL){
                        current->prev->next = current->next;
                    }
                    if(current->next != NULL){
                        current->next->prev = current->prev;
                    }
                    free(current);
                    break;
                }
            }
        }else if(strcmp(command, "display") == 0){
            printf("Displaying backup directory files:\n");
            display_backups();
        }else if(strcmp(command, "help") == 0){
            printf("List of available commands:\n");
            printf("list - list all backed up files\n");
            printf("backup - backup a file\n");
            printf("delete - delete a backed up file\n");
            printf("display - display backup directory files\n");
            printf("help - display this help message\n");
            printf("exit - exit the program\n");
        }else if(strcmp(command, "exit") == 0){
            printf("Exiting program...\n");
            break;
        }else{
            printf("Invalid command, type help for list of available commands.\n");
        }
    }

    return 0;
}