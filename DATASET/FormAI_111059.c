//FormAI DATASET v1.0 Category: File Backup System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure of a file
struct file {
    char name[20];
    int size;
    char content[50];
};

// Structure of a client
struct client {
    char name[20];
    int id;
    struct file files[10];
};

// Array of clients
struct client clients[4];

// Function to backup a file
void backup_file(int client_id, char file_name[20], char content[50]) {
    int i, found = 0;
    
    // Loop through the files of the client
    for(i=0; i<10; i++) {
        // Check if the file exists
        if(strcmp(clients[client_id].files[i].name, file_name) == 0) {
            found = 1;
            // Update the file content
            strcpy(clients[client_id].files[i].content, content);
            printf("File updated successfully.\n");
            break;
        }
    }
    
    // If the file does not exist, create a new file
    if(found == 0) {
        for(i=0; i<10; i++) {
            // Look for an empty slot to create a new file
            if(clients[client_id].files[i].size == 0) {
                strcpy(clients[client_id].files[i].name, file_name);
                strcpy(clients[client_id].files[i].content, content);
                clients[client_id].files[i].size = strlen(content);
                printf("File created successfully.\n");
                break;
            }
        }
    }
}

// Function to retrieve a file
void retrieve_file(int client_id, char file_name[20]) {
    int i, found = 0;
    
    // Loop through the files of the client
    for(i=0; i<10; i++) {
        // Check if the file exists
        if(strcmp(clients[client_id].files[i].name, file_name) == 0) {
            found = 1;
            printf("File content: %s\n", clients[client_id].files[i].content);
            break;
        }
    }
    
    // If the file does not exist, display an error message
    if(found == 0) {
        printf("File not found.\n");
    }
}

int main() {
    int i, option, client_id;
    char file_name[20], content[50];
    
    // Initialize the clients
    strcpy(clients[0].name, "Alice");
    clients[0].id = 0;
    strcpy(clients[1].name, "Bob");
    clients[1].id = 1;
    strcpy(clients[2].name, "Charlie");
    clients[2].id = 2;
    strcpy(clients[3].name, "David");
    clients[3].id = 3;
    
    // Display the options to the user
    printf("Welcome to the C File Backup System.\n");
    printf("Please enter your client ID (0-3): ");
    scanf("%d", &client_id);
    printf("\nEnter 1 to backup a file.\nEnter 2 to retrieve a file.\n");
    printf("Enter your option: ");
    scanf("%d", &option);
    
    // Based on the option selected by the user, perform the appropriate action
    switch(option) {
        case 1:
            printf("\nEnter the name of the file to backup: ");
            scanf("%s", file_name);
            printf("Enter the content of the file: ");
            scanf("%s", content);
            backup_file(client_id, file_name, content);
            break;
            
        case 2:
            printf("\nEnter the name of the file to retrieve: ");
            scanf("%s", file_name);
            retrieve_file(client_id, file_name);
            break;
            
        default:
            printf("\nInvalid option.\n");
            break;
    }
    
    return 0;
}