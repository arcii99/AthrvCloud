//FormAI DATASET v1.0 Category: Client Server Application ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[]) {
    int client_socket;
    char server_response[256], client_message[256];
    struct sockaddr_in server_address;

    //Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    //Set server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    //Connect to server
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        printf("Error connecting to server\n");
        return -1;
    }

    //Send message to server
    printf("Enter message: ");
    fgets(client_message, 256, stdin);
    send(client_socket, client_message, strlen(client_message), 0);

    //Receive response from server
    if (recv(client_socket, server_response, 256, 0) == -1) {
        printf("Error receiving response from server\n");
        return -1;
    }

    printf("Server Response: %s\n", server_response);

    //Close socket
    close(client_socket);

    return 0;
}