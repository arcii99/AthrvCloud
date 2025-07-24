//FormAI DATASET v1.0 Category: Networking ; Style: innovative
#include <stdio.h>
#include <stdlib.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <string.h> 

int main(){
    int sock = socket(AF_INET, SOCK_STREAM, 0); // Creating Socket
    
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9000);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(sock, (struct sockaddr *) &server_address, sizeof(server_address)); // Binding socket to the address
    
    listen(sock, 5); // Listening to incoming connections, max queue size of 5
    
    while(1) {
        int client_socket = accept(sock, NULL, NULL);  // Accepting connection request
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer)); // Clearing buffer
        read(client_socket, buffer, sizeof(buffer)); // Reading client message
        printf("Client Message: %s\n", buffer);
        write(client_socket, "Hello from server", strlen("Hello from server")); // Sending message to client
        close(client_socket); // Closing client socket
    }

    close(sock); // Closing server socket
    return 0;
}