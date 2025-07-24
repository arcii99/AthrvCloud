//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: statistical
//STATISTICAL TCP/IP PROGRAMMING EXAMPLE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

// Declare the variables to be used in the program
int socketServer, socketClient, readValue;
struct sockaddr_in server, client;
char messageToSend[100] = "Welcome to the Statistical TCP/IP Programming Example!";
unsigned int clientLength = sizeof(client);

// Create the function for error handling
void errorHandler(char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

// Create the main function
int main() {
    // Create the socket using socket() function
    socketServer = socket(AF_INET, SOCK_STREAM, 0);
    if (socketServer == -1) {
        errorHandler("Error! Socket creation failed.");
    }
    
    // Assign IP address and port to the server
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    // Bind the socket to the server address and port number
    if (bind(socketServer, (struct sockaddr *) &server, sizeof(server)) < 0) {
        errorHandler("Error! Socket binding failed.");
    }

    // Listen for incoming connections from the client
    if (listen(socketServer, 3) < 0) {
        errorHandler("Error! Listen failed.");
    }
    
    // Print out a message to let the user know the server is waiting for a client to connect
    printf("Server waiting for client to connect...\n");

    // Accept the client connection
    socketClient = accept(socketServer, (struct sockaddr *) &client, &clientLength);
    if (socketClient < 0) {
        errorHandler("Error! Accept failed.");
    }

    // Print out a message to let the user know the client has connected
    printf("Client connected!\n");

    // Send the welcome message to the client
    if (send(socketClient, messageToSend, strlen(messageToSend), 0) < 0) {
        errorHandler("Error! Send failed.");
    }

    // Create a loop to continuously read messages from the client
    while ((readValue = recv(socketClient, messageToSend, 100, 0)) > 0) {
        printf("Message Received: %s", messageToSend);
        
        // Break the loop if the client sends an "exit" message
        if (strcmp(messageToSend, "exit") == 0) {
            break;
        }
        
        // Generate a random number using statistical analysis
        int randomNum = (rand() % 100) + 1;
        char messageToReturn[100];
        
        // Convert the random number to a string and send it back to the client
        sprintf(messageToReturn, "Random Number: %d", randomNum);
        if (send(socketClient, messageToReturn, strlen(messageToReturn), 0) < 0) {
            errorHandler("Error! Send failed.");
        }
 
        // Clear the message buffer
        memset(messageToSend, 0, 100);
    }

    // Close the client and server sockets
    close(socketClient);
    close(socketServer);
    
    // Exit the program
    return 0;
}