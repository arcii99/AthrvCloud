//FormAI DATASET v1.0 Category: Socket programming ; Style: imaginative
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#define PORT 8080 

int main() 
{ 
    int sockfd, new_sockfd, valread; 
    struct sockaddr_in servaddr; 
    char *message = "Welcome to the imaginary chat room!\n"; 
    char buffer[1024] = {0}; 
    
    // Creating socket file descriptor 
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("Socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    memset(&servaddr, '0', sizeof(servaddr)); 
    
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    servaddr.sin_port = htons(PORT); 
    
    // Binding socket to port 
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) 
    { 
        perror("Binding failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Listening for incoming connections 
    if (listen(sockfd, 3) < 0) 
    { 
        perror("Listening failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    printf("Waiting for incoming connections...\n"); 
    
    // Accepting incoming connection 
    if ((new_sockfd = accept(sockfd, (struct sockaddr *)&servaddr, (socklen_t*)&servaddr)) < 0) 
    { 
        perror("Accepting connection failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    printf("Incoming connection accepted!\n"); 
    
    // Sending welcome message 
    send(new_sockfd, message, strlen(message), 0); 
    
    // Receiving messages from client 
    while(1) 
    { 
        valread = read(new_sockfd, buffer, 1024); 
        
        // If client disconnects, break the loop 
        if (valread == 0) 
        { 
            printf("Client disconnected\n"); 
            break; 
        } 
        
        printf("Client: %s", buffer); 
        memset(buffer, 0, sizeof(buffer)); 
        
        // Sending reply to client 
        printf("You: "); 
        fgets(buffer, sizeof(buffer), stdin); 
        send(new_sockfd, buffer, strlen(buffer), 0); 
    } 
    
    close(new_sockfd); 
    close(sockfd); 
    
    return 0; 
}