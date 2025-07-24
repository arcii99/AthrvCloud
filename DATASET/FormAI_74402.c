//FormAI DATASET v1.0 Category: Browser Plugin ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void to_lower(char *str){
    int i = 0;
    while (str[i]){
        str[i] = tolower(str[i]);
        i++;
    }
}

typedef struct {
    char *name;
    char *description;
    void (*function)();
} command;

void help(){
    printf("Available commands:\n");
    printf("- help: displays this help message.\n");
    printf("- search: searches the current page for a given string.\n");
    printf("- print: prints the current page.\n");
    printf("- exit: exits the plugin.\n");
}

void search(){
    char search_string[BUFFER_SIZE];
    printf("Enter the string to search: ");
    fgets(search_string, BUFFER_SIZE, stdin);
    strtok(search_string, "\n");
    
    to_lower(search_string);
    printf("Searching for '%s'...\n", search_string);
    // Code to search the page goes here
}

void print(){
    printf("Printing current page...\n");
    // Code to print the page goes here
}

void exit_plugin(){
    printf("Exiting plugin...\n");
    exit(0);
}

int main() {
    int client_socket, valread;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE] = {0};
    char *hello = "Hello from client";
    
    command commands[] = {
        {"help", "displays this help message", help},
        {"search", "searches the current page for a given string", search},
        {"print", "prints the current page", print},
        {"exit", "exits the plugin", exit_plugin}
    };

    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
  
    memset(&server_address, '0', sizeof(server_address));
  
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
      
    if(inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
  
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    
    printf("Connected to server.\n");
    help();
    
    while(true){
        memset(buffer, 0, BUFFER_SIZE);
        printf("\nEnter command: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        strtok(buffer, "\n");
        
        to_lower(buffer);
        bool valid_command = false;
        for(int i=0; i<sizeof(commands)/sizeof(command); i++){
            if(strcmp(commands[i].name, buffer)==0){
                commands[i].function();
                valid_command = true;
                break;
            }
        }
        
        if(!valid_command)
            printf("Invalid command. Type 'help' for a list of valid commands.\n");
    }
    
    close(client_socket);
    
    return 0;
}