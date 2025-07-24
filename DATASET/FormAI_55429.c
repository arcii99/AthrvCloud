//FormAI DATASET v1.0 Category: Client Server Application ; Style: surprised
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
  
#define PORT 8080 

int main(int argc, char const *argv[]) 
{ 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char *hello = "Hello from client"; 
    char buffer[1024] = {0}; 

    // Introduce yourself to the server
    printf("Greetings, I am a client!\n"); 

    // Create socket file descriptor 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("Error: Socket creation failed!\n"); 
        return -1; 
    } 

    // Create server address
    memset(&serv_addr, '0', sizeof(serv_addr)); 
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 

    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("Error: Invalid address/ Address not supported!\n"); 
        return -1; 
    } 

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("Error: Failed to connect to server %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port)); 
        return -1; 
    } 

    // Send message to server
    send(sock , hello , strlen(hello) , 0 ); 
    printf("Message sent to server: %s\n", hello); 

    // Receive message from server
    valread = read( sock , buffer, 1024); 
    printf("Message received from server: %s\n",buffer ); 

    // Close socket
    close(sock); 
    printf("Connection to server closed.\n");
    return 0; 
}