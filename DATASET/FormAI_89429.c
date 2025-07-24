//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    int socket_desc;
    struct sockaddr_in server;
    char message[MAX_SIZE], server_reply[MAX_SIZE];

    //Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }

    //server address initialization
    server.sin_addr.s_addr = inet_addr("pop3.server.com");
    server.sin_family = AF_INET;
    server.sin_port = htons( 110 );

    //Connect to remote server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        puts("Connect error");
        return 1;
    }

    //Receive welcome message
    if (recv(socket_desc, server_reply, MAX_SIZE, 0) < 0) {
        puts("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    //Send user name
    printf("Username: ");
    fgets(message, MAX_SIZE, stdin);
    message[strcspn(message, "\n")] = 0; //remove newline character
    strcat(message, "\r\n"); //add carriage return and newline characters
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }

    //Receive response
    if (recv(socket_desc, server_reply, MAX_SIZE, 0) < 0) {
        puts("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    //Send password
    printf("Password: ");
    fgets(message, MAX_SIZE, stdin);
    message[strcspn(message, "\n")] = 0; //remove newline character
    strcat(message, "\r\n"); //add carriage return and newline characters
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }

    //Receive response
    if (recv(socket_desc, server_reply, MAX_SIZE, 0) < 0) {
        puts("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    //Send command to list messages
    strcpy(message, "LIST\r\n");
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }

    //Receive response
    if (recv(socket_desc, server_reply, MAX_SIZE, 0) < 0) {
        puts("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    //Close socket
    close(socket_desc);
    return 0;
}