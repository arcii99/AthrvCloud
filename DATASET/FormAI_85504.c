//FormAI DATASET v1.0 Category: Client Server Application ; Style: cheerful
// Hey there! Welcome to my Client Server Application Example program!
// This program will demonstrate a cheerful chat between a client and a server
// Let's start by including the necessary libraries

#include <stdio.h>      // For input/output operations
#include <stdlib.h>     // For memory allocation
#include <stdbool.h>    // For boolean operations
#include <string.h>     // For string operations
#include <sys/socket.h> // For socket creation and communication
#include <arpa/inet.h>  // For internet operations

#define PORT 8080       // This is the port we'll be using for communication

void serverFunc() {
    // Let's start with the server code
    
    // Step 1: Create a socket
    int server_fd;
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Step 2: Set up the address and port on which the server will listen
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Step 3: Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Step 4: Start listening for connections
    if (listen(server_fd, 3) < 0) { // Allow up to 3 connections at a time
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    // Step 5: Accept incoming connections and communicate with the client
    
    struct sockaddr_in client_addr;
    int addrlen = sizeof(client_addr);
    int new_socket;
    while ((new_socket = accept(server_fd, (struct sockaddr*)&client_addr, &addrlen))>0) {
        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        
        char* message = "Hello there! How can I assist you today?";
        send(new_socket, message, strlen(message), 0);
        
        char buffer[1024] = {0};
        int valread;
        while ((valread = read(new_socket, buffer, 1024))) {
            printf("Client: %s\n", buffer);
            if (strcmp(buffer, "bye") == 0) { // The client wants to end the chat
                send(new_socket, "Goodbye! Have a nice day!", 24, 0);
                printf("Connection closed\n");
                break;
            }
            
            // Here's where you can add code for processing the client input and generating a response
            // Let's keep it simple for now
            message = "I'm sorry, I didn't understand. Could you please repeat?";
            send(new_socket, message, strlen(message), 0);
            memset(buffer, 0, 1024);
        }
        
        // Close the socket and wait for another client to connect
        close(new_socket);
    }
}

void clientFunc() {
    // Now let's take a look at the client code
    
    // Step 1: Create a socket
    int sock = 0;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return;
    }
    
    // Step 2: Set up the address and port of the server to which the client will connect
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }
    
    // Step 3: Connect to the server
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return;
    }
    
    // Step 4: Communicate with the server
    char buffer[1024] = {0};
    int valread;
    while ((valread = read(sock, buffer, 1024)) > 0) {
        printf("Server: %s\n", buffer);
        
        // Here's where you can add code for processing the server response and generating an input to send back
        // Let's keep it simple for now
        char message[1024];
        printf("You: ");
        fgets(message, 1024, stdin);
        
        send(sock, message, strlen(message), 0);
        memset(buffer, 0, 1024);
        
        if (strcmp(message, "bye\n") == 0) { // The client wants to end the chat
            valread = read(sock, buffer, 1024);
            printf("Server: %s\n", buffer);
            printf("Connection closed\n");
            break;
        }
    }
    
    // Close the socket and end the client program
    close(sock);
}

int main() {
    // Finally, let's set up the main program
    
    printf("Welcome to the Chatbot Client Server Application!\n");
    printf("Would you like to start the server or the client?\nEnter 's' for server or 'c' for client: ");
    
    char input[10];
    fgets(input, 10, stdin);
    
    if (strcmp(input, "s\n") == 0) {
        printf("\nStarting Server...\n");
        serverFunc();
    }
    else if (strcmp(input, "c\n") == 0) {
        printf("\nStarting Client...\n");
        clientFunc();
    }
    else {
        printf("\nInvalid input. Program terminated.\n");
        return 0;
    }
    
    return 0;
}