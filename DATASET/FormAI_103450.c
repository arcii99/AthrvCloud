//FormAI DATASET v1.0 Category: Socket programming ; Style: multivariable
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

#define PORT 8080 

int main() 
{ 
    int sock_fd, conn_fd; 
    struct sockaddr_in serv_addr, client_addr; 
    char buffer[1024]; 
    char *message = "Hello, client!"; 

    // Creating socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sock_fd == -1) { 
        printf("Socket creation failed...\n"); 
        exit(0); 
    } 
    printf("Socket successfully created..\n"); 

    memset(&serv_addr, 0, sizeof(serv_addr)); 

    // Filling server information
    serv_addr.sin_family = AF_INET;     
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
    serv_addr.sin_port = htons(PORT); 

    // Binding socket to the specified address and port
    if ((bind(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) != 0) { 
        printf("Socket bind failed...\n"); 
        exit(0); 
    } 
    printf("Socket successfully binded..\n"); 

    // Listening for incoming connections
    if ((listen(sock_fd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    printf("Server listening on port %d..\n", PORT); 

    while (1) { 
        socklen_t len = sizeof(client_addr); 

        // Accepting incoming connections
        conn_fd = accept(sock_fd, (struct sockaddr*)&client_addr, &len); 
        if (conn_fd < 0) { 
            printf("Server acccept failed...\n"); 
            exit(0); 
        } 
        printf("Server accepted the client connection from %s:%d\n", 
               inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port)); 

        // Sending the message to the client
        if (send(conn_fd, message, strlen(message), 0) < 0) { 
            printf("Send failed...\n"); 
            exit(0); 
        } 
        printf("Message sent to the client successfully...\n"); 

        // Receiving data from the client
        bzero(buffer, 1024); 
        if (recv(conn_fd, buffer, 1024, 0) < 0) { 
            printf("Receive failed...\n"); 
            exit(0); 
        } 
        printf("Received data: %s", buffer); 

        // Closing the connection
        close(conn_fd); 
        printf("Connection closed successfully...\n"); 
    } 

    return 0; 
}