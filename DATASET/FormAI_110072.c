//FormAI DATASET v1.0 Category: Socket programming ; Style: inquisitive
//Hey there! Are you interested in learning some socket programming? Let's explore a bit!
#include <stdio.h>
#include <stdlib.h> //for exit(0) function
#include <string.h> //for memset() function
#include <unistd.h> //for read() function
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> //for struct sockaddr_in
#include <arpa/inet.h> //for inet_ntoa() function

int main() {

    //first, let's create a socket
    int serverSocket;
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket < 0) {
        perror("Could not create socket. Try again!");
        exit(0);
    }
    else {
        printf("A socket has been created!\n");
    }

    //let's specify the server address and port number
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080); //port number 8080 (you can change it as per your convenience)
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    //now let's bind the socket to the server address
    if (bind(serverSocket, (struct sockaddr*) &serverAddress, sizeof(serverAddress)) == -1) {
        perror("Bind failed. Try again!");
        exit(0);
    }
    else {
        printf("Socket has been bound to desired address and port!\n");
    }

    //let's now listen for incoming connections
    if (listen(serverSocket, 5) == -1) { //we can handle upto 5 connections
        perror("Listen failed. Try again!");
        exit(0);
    }
    else {
        printf("Listening for incoming connections...\n");
    }

    //let's now accept an incoming connection (we will do it only once)
    struct sockaddr_in clientAddress;
    socklen_t clientLength = sizeof(clientAddress);

    int clientSocket;
    clientSocket = accept(serverSocket, (struct sockaddr*) &clientAddress, &clientLength);

    if (clientSocket == -1) {
        perror("Accept failed. Try again!");
        exit(0);
    }
    else {
        printf("A connection has been established with client %s.\n", inet_ntoa(clientAddress.sin_addr));
    }

    //let's now send a welcome message to the client
    char* welcomeMessage = "Hey! Welcome to the server.\n";
    send(clientSocket, welcomeMessage, strlen(welcomeMessage), 0);

    //now let's receive any message sent by the client
    char clientMessage[255];
    memset(clientMessage, 0, sizeof(clientMessage)); //initialize clientMessage to 0

    if (recv(clientSocket, clientMessage, sizeof(clientMessage), 0) == -1) {
        perror("Receive failed. Try again!");
        exit(0);
    }
    else {
        printf("Client %s says: %s\n", inet_ntoa(clientAddress.sin_addr), clientMessage);
    }

    //let's now close the sockets
    close(clientSocket);
    close(serverSocket);

    printf("Socket connection has been closed!\n");

    return 0;
}