//FormAI DATASET v1.0 Category: Client Server Application ; Style: automated
/* This C Client Server Application program allows the client to send a message to the server and the server to respond with a reversed message */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

#define PORT 8080 

int main() 
{ 
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) 
    { 
        perror("Socket creation error"); 
        return EXIT_FAILURE; 
    } 
    
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    
    server_address.sin_family = AF_INET; 
    server_address.sin_port = htons(PORT); 
    server_address.sin_addr.s_addr = INADDR_ANY; 
    
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) 
    { 
        perror("Connection failed"); 
        return EXIT_FAILURE; 
    } 
    
    char message[1024];
    char buffer[1024] = { 0 };
    printf("Enter a message: ");
    fgets(message, 1024, stdin);
    
    if (send(sock, message, strlen(message), 0) < 0)  //sends message to server
    { 
        perror("Message send failure"); 
        return EXIT_FAILURE; 
    } 
    
    if (read(sock, buffer, 1024) < 0)   //reads message from server
    { 
        perror("Message read failure"); 
        return EXIT_FAILURE; 
    } 

    printf("Reversed message from server: %s\n", buffer); 

    close(sock); 
    return EXIT_SUCCESS; 
}