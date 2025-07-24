//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Romeo and Juliet
/* A Romeo and Juliet style HTTP client program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int client_socket;
    char *message, server_reply[2000];
    struct sockaddr_in server_address;
 
    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Could not create socket\n");
        return 1;
    }
    
    // Set server address and port
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80); // HTTP port
 
    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Could not connect to server\n");
        return 1;
    }
    
    printf("My dear server, I am thine HTTP client;\n");
    printf("And, local machine being a network\n");
    printf("My socket shall reach to thee,\n");
    printf("And for your reply, I wilst wait with glee.\n\n");

    // Send request to server
    message = "GET / HTTP/1.1\r\n\r\n";
    if (send(client_socket, message, strlen(message), 0) < 0) {
        printf("Could not send request to server\n");
        return 1;
    }
    printf("I hereby present my request to thee:\n%s\n\n", message);
 
    // Receive reply from server
    if (recv(client_socket, server_reply, 2000, 0) < 0) {
        printf("Failed to receive reply from server\n");
        return 1;
    }
    printf("And the server replies, I heareth its sound:\n%s\n", server_reply);
    
    close(client_socket);
    printf("\nFarewell, my dear server, until we meet again.\n\n");
    return 0;
}