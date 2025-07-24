//FormAI DATASET v1.0 Category: System administration ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearScreen();
void runCommand();
void checkPermissions();

int main(){
    printf("Paranoid Administrator Console v1.0\n");
    printf("Please enter your credentials:\n");
    checkPermissions();

    while(1){
        clearScreen();
        printf("Welcome to the paranoid administrator console.\n");
        printf("Enter a command to execute or type 'exit' to quit.\n");

        runCommand();
    }

    return 0;
}

void clearScreen(){
    // Clear the screen securely to prevent revealing sensitive information
    system("@cls || clear");
}

void runCommand(){
    char command[100];
    printf("> ");
    scanf("%99[^\n]", command);

    // Check if command contains potentially harmful characters
    char* c = command;
    while(*c){
        if(*c == '|' || *c == '&' || *c == ';'){
            printf("Invalid command.\n");
            return;
        }
        c++;
    }

    // Check if command is 'exit'
    if(strcmp(command, "exit") == 0){
        printf("Goodbye.\n");
        exit(0);
    }

    // Run the command
    printf("Running command: %s\n", command);
    system(command);
}

void checkPermissions(){
    // Check if the user is root or sudo
    char username[20];
    getlogin_r(username, 20);
    if(strcmp(username, "root") != 0){
        char *sudo_user = getenv("SUDO_USER");
        if(sudo_user == NULL){
            printf("You do not have sufficient privileges to access this console.\n");
            exit(0);
        }
        printf("Running as sudo user: %s\n", sudo_user);
    }
    else{
        printf("Running as root.\n");
    }
}