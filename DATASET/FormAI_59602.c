//FormAI DATASET v1.0 Category: System administration ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum length of input commands */
#define MAX_INPUT_LENGTH 100

/* Define the maximum number of users that this system can handle */
#define MAX_USERS 5

/* Define the maximum length of a username */
#define MAX_USERNAME_LENGTH 20

/* Define the maximum length of a password */
#define MAX_PASSWORD_LENGTH 20

/* Define the maximum length of a system message */
#define MAX_SYSTEM_MESSAGE_LENGTH 100

/* Define the maximum length of a file name */
#define MAX_FILE_NAME_LENGTH 50

/* Define the maximum length of a file content */
#define MAX_FILE_CONTENT_LENGTH 500

/* Define the user struct */
struct user {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int uid;
};

/* Declare a global users array */
struct user users[MAX_USERS];

/* Declare a global loggedInUser variable */
int loggedInUser = -1;

/* Declare a global system message variable */
char systemMessage[MAX_SYSTEM_MESSAGE_LENGTH];

/* Declare a global file content variable */
char fileContent[MAX_FILE_CONTENT_LENGTH];

/* Define the function prototypes */
int addUser(char *username, char *password);
int login(char *username, char *password);
void logout();
void showSystemMessage();
void createFile(char *fileName);
void writeFile(char *fileName);
void readFile(char *fileName);
void deleteFile(char *fileName);

/* The main function */
int main() {

    /* Declare the command buffer */
    char command[MAX_INPUT_LENGTH];

    /* Initialize the users array */
    for(int i=0; i<MAX_USERS; i++) {
        strcpy(users[i].username, "");
        strcpy(users[i].password, "");
        users[i].uid = -1;
    }

    while(1) {
        /* Display the prompt */
        printf("> ");

        /* Read the command */
        fgets(command, sizeof(command), stdin);

        /* Remove the new line character */
        command[strcspn(command, "\n")] = 0;

        /* Determine the command */
        if(strcmp(command, "help") == 0) {
            printf("available commands: addUser, login, logout, showSystemMessage, createFile, writeFile, readFile, deleteFile\n");
        }
        else if(strncmp(command, "addUser", 7) == 0) {
            char *username = strtok(command+8, ",");
            char *password = strtok(NULL, ",");
            int result = addUser(username, password);
            if(result == 0) {
                printf("user %s added successfully!\n", username);
            } else if(result == -1) {
                printf("cannot add another user: maximum number of users reached!\n");
            } else {
                printf("cannot add user %s: the username is already taken!\n", username);
            }
        }
        else if(strncmp(command, "login", 5) == 0) {
            char *username = strtok(command+6, ",");
            char *password = strtok(NULL, ",");
            int result = login(username, password);
            if(result == -1) {
                printf("invalid username or password!\n");
            } else {
                printf("welcome, %s!\n", username);
            }
        }
        else if(strcmp(command, "logout") == 0) {
            logout();
            printf("you have been logged out!\n");
        }
        else if(strcmp(command, "showSystemMessage") == 0) {
            showSystemMessage();
        }
        else if(strncmp(command, "createFile", 10) == 0) {
            char *fileName = strtok(command+11, ",");
            createFile(fileName);
        }
        else if(strncmp(command, "writeFile", 9) == 0) {
            char *fileName = strtok(command+10, ",");
            writeFile(fileName);
        }
        else if(strncmp(command, "readFile", 8) == 0) {
            char *fileName = strtok(command+9, ",");
            readFile(fileName);
        }
        else if(strncmp(command, "deleteFile", 10) == 0) {
            char *fileName = strtok(command+11, ",");
            deleteFile(fileName);
        }
        else {
            printf("unknown command %s! type help for a list of available commands.\n", command);
        }
    }
}

/* Add a new user to the system */
int addUser(char *username, char *password) {
    /* Check if the maximum number of users has been reached */
    int added = 0;
    for(int i=0; i<MAX_USERS; i++) {
        if(strcmp(users[i].username, "") == 0) {
            strcpy(users[i].username, username);
            strcpy(users[i].password, password);
            users[i].uid = i;
            added = 1;
            break;
        }
    }
    if(!added) {
        return -1;
    }

    /* Check if the username already exists */
    for(int i=0; i<MAX_USERS; i++) {
        if(strcmp(users[i].username, username) == 0) {
            return 1;
        }
    }

    return 0;
}

/* Attempt to log in a user */
int login(char *username, char *password) {
    /* Find the user with the given username and password */
    int result = -1;
    for(int i=0; i<MAX_USERS; i++) {
        if(strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            loggedInUser = users[i].uid;
            result = 0;
            break;
        }
    }
    return result;
}

/* Log out the currently logged in user */
void logout() {
    loggedInUser = -1;
}

/* Show the current system message */
void showSystemMessage() {
    printf("%s\n", systemMessage);
}

/* Create a new file */
void createFile(char *fileName) {
    FILE *file = fopen(fileName, "w");
    fclose(file);
}

/* Write to an existing file */
void writeFile(char *fileName) {
    FILE *file = fopen(fileName, "w");
    printf("start writing the file: (press CTRL+D to finish)\n");
    while(fgets(fileContent, sizeof(fileContent), stdin)) {
        fprintf(file, "%s", fileContent);
    }
    fclose(file);
}

/* Read an existing file */
void readFile(char *fileName) {
    FILE *file = fopen(fileName, "r");
    if(file == NULL) {
        printf("file not found!\n");
        return;
    }
    char line[MAX_FILE_CONTENT_LENGTH];
    while(fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

/* Delete an existing file */
void deleteFile(char *fileName) {
    remove(fileName);
}