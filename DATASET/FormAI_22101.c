//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int serverSocket, clientSocket, connect_status;
    struct sockaddr_in serverAddress, clientAddress;
    char buffer[BUFFER_SIZE];

    //Creating proxy server socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket < 0) {
        printf("Error creating server socket\n");
        exit(1);
    }

    memset(&serverAddress, '\0', sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(8080);

    // Binding the socket to IP and port
    if (bind(serverSocket, (struct sockaddr*) &serverAddress, sizeof(serverAddress)) < 0) {
        printf("Error in binding\n");
        exit(1);
    }

    // Listening for client connections
    if (listen(serverSocket, 10) != 0) {
        printf("Error in listening\n");
        exit(1);
    }
    printf("Listening for incoming connections...\n");

    while (1) {

        socklen_t address_len = sizeof(clientAddress);
        clientSocket = accept(serverSocket, (struct sockaddr*) &clientAddress, &address_len);

        if (clientSocket < 0) {
            printf("Error in accepting connection\n");
            exit(1);
        }
        printf("Connected to client %s:%d\n",inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port));

        //Receiving the HTTP request from the client
        memset(buffer, '\0', BUFFER_SIZE);
        recv(clientSocket, buffer, BUFFER_SIZE, 0);
        printf("\nReceived request from client:\n%s", buffer);

        //Parsing the HTTP request header to get the website URL
        char* url = strtok(buffer, " ");
        url = strtok(NULL, " ");
        url = strtok(url, "/");

        //Create a new socket to connect to the website server
        int websiteSocket = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in websiteAddress;

        memset(&websiteAddress, '\0', sizeof(websiteAddress));
        websiteAddress.sin_family = AF_INET;
        websiteAddress.sin_addr.s_addr = inet_addr(url);
        websiteAddress.sin_port = htons(80);

        //Connecting to the website server
        connect_status = connect(websiteSocket, (struct sockaddr*) &websiteAddress, sizeof(websiteAddress));
        if (connect_status < 0) {
            printf("Error in connecting to website server\n");
            exit(1);
        }
        printf("Connected to website server %s\n", url);

        //Forwarding the HTTP request to the website server
        send(websiteSocket, buffer, strlen(buffer), 0);
        printf("\nForwarded request to website server:\n%s", buffer);

        //Receiving the HTTP response from the website server
        memset(buffer, '\0', BUFFER_SIZE);
        recv(websiteSocket, buffer, BUFFER_SIZE, 0);
        printf("\nReceived response from website server:\n%s", buffer);

        //Forwarding the HTTP response to the client
        send(clientSocket, buffer, strlen(buffer), 0);
        printf("\nForwarded response to client:\n%s", buffer);

        //Closing website server socket
        close(websiteSocket);

        //Closing client socket
        close(clientSocket);
    }

    //Closing server socket
    close(serverSocket);
    return 0;
}