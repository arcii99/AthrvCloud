//FormAI DATASET v1.0 Category: Networking ; Style: irregular
//Welcome to the Chatbot's Unique Networking Example Program!
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    //In this program, we will be creating a client-server communication using sockets.
    printf("Starting up server...\n");

    //First, we need to set up the server socket.
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        //If the socket creation fails, we print an error message and exit the program.
        printf("Error: could not create server socket!");
        exit(1);
    }

    //Now, we need to bind the server socket to an IP address and a port.
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY; //This sets the IP address to the local machine's address.
    server_address.sin_port = htons(9002); //This sets the port number to 9002.

    int bind_result = bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    if (bind_result == -1) {
        //If the binding fails, we print an error message and exit the program.
        printf("Error: could not bind server socket to IP address and port!");
        exit(1);
    }

    //Now, we need to listen for incoming connections on the server socket.
    int listen_result = listen(server_socket, 5);
    if (listen_result == -1) {
        //If the listening fails, we print an error message and exit the program.
        printf("Error: could not listen on server socket!");
        exit(1);
    }

    printf("Server is now listening for incoming connections...\n");

    //Now, we wait for incoming connections, and when we receive one, we accept it and create a client socket.
    struct sockaddr_in client_address;
    socklen_t client_address_size = sizeof(client_address);

    int client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_size);
    if (client_socket == -1) {
        //If the accepting fails, we print an error message and exit the program.
        printf("Error: could not accept incoming connection!");
        exit(1);
    }

    //Now that we have a client socket, we can start sending and receiving data.

    //Let's start by sending a message to the client.
    char message[] = "Hello, client! This is the server speaking.";
    int send_result = send(client_socket, message, sizeof(message), 0);
    if (send_result == -1) {
        //If the sending fails, we print an error message and exit the program.
        printf("Error: could not send message to client!");
        exit(1);
    }

    printf("Message sent to client: %s\n", message);

    //Now, let's receive a message from the client.
    char buffer[1024];
    int recv_result = recv(client_socket, buffer, sizeof(buffer), 0);
    if (recv_result == -1) {
        //If the receiving fails, we print an error message and exit the program.
        printf("Error: could not receive message from client!");
        exit(1);
    }

    printf("Message received from client: %s\n", buffer);

    //Finally, we close both sockets and exit the program.
    close(client_socket);
    close(server_socket);

    printf("Program complete! Goodbye.\n");

    return 0;
}