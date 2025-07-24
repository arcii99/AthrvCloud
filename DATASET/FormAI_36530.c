//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

#define PORT 80 // Define the port number for HTTP
#define MAX_SIZE 1024 // Define the max size for the response

int main(int argc, char *argv[]) {
    int socket_desc;
    struct sockaddr_in server;
    char message[MAX_SIZE], server_reply[MAX_SIZE], *hostname, *path;
    hostname = "www.example.com";
    path = "/index.html";

    // Create a socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);

    if (socket_desc == -1) {
        printf("Could not create socket");
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Set localhost as the IP
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    // Connect to remote server
    if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0) {
        puts("connect error");
        return 1;
    }

    printf("Connected to %s\n", hostname);

    // Prepare the message to send to the server
    sprintf(message, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    // Send the message to the server
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }

    printf("Request sent:\n%s", message);

    // Receive the response from the server
    if (recv(socket_desc, server_reply, MAX_SIZE, 0) < 0) {
        puts("recv failed");
        return 1;
    }

    printf("Response received:\n%s", server_reply);

    close(socket_desc);

    return 0;
}