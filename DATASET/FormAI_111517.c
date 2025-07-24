//FormAI DATASET v1.0 Category: Socket programming ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

int main(){
    int client_socket, connection_status;
    struct sockaddr_in server_address;
    char server_response[256];
    char *message = "Hello from client!";

    // Create a socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Specify server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    connection_status = connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    if(connection_status == -1){
        printf("Connection error!\n");
        return 1;
    }

    // Send a message to server
    send(client_socket, message, strlen(message), 0);

    // Receive a response from server
    recv(client_socket, &server_response, sizeof(server_response), 0);

    // Display response from server
    printf("Server response: %s\n", server_response);

    // Close the socket
    close(client_socket);
    return 0;
}