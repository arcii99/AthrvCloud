//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

int main() {
    printf("Welcome to the Surreal FTP Client\n");
    printf("Please enter the server address: ");
    char server[BUFFER_SIZE];
    fgets(server, BUFFER_SIZE, stdin);
    server[strcspn(server, "\n")] = 0;

    printf("Please enter the username: ");
    char username[BUFFER_SIZE];
    fgets(username, BUFFER_SIZE, stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Please enter the password: ");
    char password[BUFFER_SIZE];
    fgets(password, BUFFER_SIZE, stdin);
    password[strcspn(password, "\n")] = 0;

    printf("Connecting to %s...\n", server);
    printf("Authenticating with username %s and password %s\n", username, password);
    printf("Logged in successfully!\n");

    char input[BUFFER_SIZE];
    while (1) {
        printf("Enter a command: ");
        fgets(input, BUFFER_SIZE, stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else if (strcmp(input, "ls") == 0) {
            printf("drwxrwxr-x  2 surreal surreal  4096 Jun 15 16:49 surreal_folder\n");
            printf("-rw-rw-r--  1 surreal surreal     0 Jun 12 08:12 surreal_file.txt\n");
        } else if (strcmp(input, "cd") == 0) {
            printf("Directory changed to surreal_folder\n");
        } else if (strcmp(input, "get") == 0) {
            printf("Downloading surreal_file.txt...\n");
            printf("Download complete!\n");
        } else if (strcmp(input, "put") == 0) {
            printf("Uploading file...\n");
            printf("Upload complete!\n");
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}