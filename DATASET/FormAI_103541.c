//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: dynamic
//This is a C program to build an IMAP Client using sockets

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

#define MAXSIZE 1000

int main(void){

    char *server_address = "127.0.0.1";
    int connection_socket, ret_val;
    struct sockaddr_in server_addr;
    char message[MAXSIZE], server_message[MAXSIZE];
    memset(server_message, '0', MAXSIZE);

    //Create Socket
    connection_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (connection_socket < 0){
        printf("Error creating socket\n");
        return 1;
    }
    printf("Socket created successfully\n");

    //Initialize Server Address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(143);
    server_addr.sin_addr.s_addr = inet_addr(server_address);

    //Connect to Server
    ret_val = connect(connection_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret_val < 0){
        printf("Error connecting to server\n");
        close(connection_socket);
        return 1;
    }
    printf("Connected to IMAP Server\n");

    //Receive Server Welcome Message
    if (recv(connection_socket, server_message, MAXSIZE, 0) < 0){
        printf("Error receiving message from server\n");
        close(connection_socket);
        return 1;
    }
    printf("%s\n", server_message);

    //Authenticate User
    printf("Enter your username: ");
    fgets(message, MAXSIZE, stdin);
    sprintf(message, "1 LOGIN %s\n", strtok(message, "\n"));
    if (send(connection_socket, message, strlen(message), 0) < 0){
        printf("Error sending message to server\n");
        close(connection_socket);
        return 1;
    }
    if (recv(connection_socket, server_message, MAXSIZE, 0) < 0){
        printf("Error receiving message from server\n");
        close(connection_socket);
        return 1;
    }
    printf("%s\n", server_message);

    //Select Mailbox
    printf("Enter the name of the mailbox you want to open: ");
    fgets(message, MAXSIZE, stdin);
    sprintf(message, "2 SELECT %s\n", strtok(message, "\n"));
    if (send(connection_socket, message, strlen(message), 0) < 0){
        printf("Error sending message to server\n");
        close(connection_socket);
        return 1;
    }
    if (recv(connection_socket, server_message, MAXSIZE, 0) < 0){
        printf("Error receiving message from server\n");
        close(connection_socket);
        return 1;
    }
    printf("%s\n", server_message);

    //Logout and Close Connection
    sprintf(message, "3 LOGOUT\n");
    if (send(connection_socket, message, strlen(message), 0) < 0){
        printf("Error sending message to server\n");
        close(connection_socket);
        return 1;
    }
    if (recv(connection_socket, server_message, MAXSIZE, 0) < 0){
        printf("Error receiving message from server\n");
        close(connection_socket);
        return 1;
    }
    printf("%s\n", server_message);
    close(connection_socket);
    return 0;
}