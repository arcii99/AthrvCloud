//FormAI DATASET v1.0 Category: Networking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main() {
    int client_socket = socket(AF_INET, SOCK_STREAM, 0); // create client socket
    if (client_socket == -1) { // check if creation failed
        printf("Could not create socket\n");
        return 1;
    }

    struct sockaddr_in server_address; // server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9001); // specific port number to connect to
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP address of the server to connect to

    int connection_status = connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)); // initiate connection
    if (connection_status == -1) { // check if connection failed
        printf("Could not connect to server\n");
        close(client_socket);
        return 1;
    }

    printf("Connected to server!\n");

    char input_message[256];
    printf("Enter a message to send to the server: ");
    fgets(input_message, sizeof(input_message), stdin);
    send(client_socket, input_message, sizeof(input_message), 0); // send message to server

    char server_response[256];
    recv(client_socket, &server_response, sizeof(server_response), 0); // receive response from server
    printf("Server response: %s", server_response);

    close(client_socket); // close connection
    return 0;
}