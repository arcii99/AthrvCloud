//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MAXBUFFER 1024

int main(int argc, char *argv[]) {

    // Create socket
    int socket_desc;
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);

    // Server details
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    server.sin_family = AF_INET;
    server.sin_port = htons( 993 );

    // Connect to server
    if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("Connection failed");
        return -1;
    }

    // Get initial response from server
    char server_response[MAXBUFFER];
    bzero(server_response, MAXBUFFER);
    read(socket_desc, server_response, MAXBUFFER);

    printf("%s", server_response);

    // Log in to server
    char username[50];
    char password[50];

    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    char authenticate[50] = {'\0'};
    sprintf(authenticate, "LOGIN %s %s\r\n", username, password);
    write(socket_desc, authenticate, strlen(authenticate));
    bzero(server_response, MAXBUFFER);
    read(socket_desc, server_response, MAXBUFFER);

    if (strstr(server_response, "OK LOGIN completed.")) {
        printf("Login successful!\n");
    }
    else {
        printf("Login failed. Please try again.\n");
        close(socket_desc);
        return -1;
    }

    // List all the folders
    char command[50] = {'\0'};
    sprintf(command, "LIST \"\" *\r\n");
    write(socket_desc, command, strlen(command));
    bzero(server_response, MAXBUFFER);
    read(socket_desc, server_response, MAXBUFFER);
    printf("%s", server_response);

    // Select a folder
    char folder[50];

    printf("Enter folder name: ");
    scanf("%s", folder);

    char select[50] = {'\0'};
    sprintf(select, "SELECT %s\r\n", folder);
    write(socket_desc, select, strlen(select));
    bzero(server_response, MAXBUFFER);
    read(socket_desc, server_response, MAXBUFFER);

    // Check if folder selection was successful
    if (strstr(server_response, "OK [READ-WRITE]")) {
        printf("Folder selection successful.\n");
    }
    else {
        printf("Folder selection failed. Please try again.\n");
        close(socket_desc);
        return -1;
    }

    // Get all the emails in the folder
    char fetch[50] = {'\0'};
    sprintf(fetch, "FETCH 1:* (FLAGS BODY[HEADER.FIELDS (SUBJECT FROM DATE)])\r\n");
    write(socket_desc, fetch, strlen(fetch));
    bzero(server_response, MAXBUFFER);
    read(socket_desc, server_response, MAXBUFFER);
    printf("%s", server_response);

    // Close the connection
    char logout[50] = {'\0'};
    sprintf(logout, "LOGOUT\r\n");
    write(socket_desc, logout, strlen(logout));
    bzero(server_response, MAXBUFFER);
    read(socket_desc, server_response, MAXBUFFER);
    printf("%s", server_response);
    close(socket_desc);

    return 0;
}