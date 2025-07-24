//FormAI DATASET v1.0 Category: Chat server ; Style: romantic
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
 
#define MAX_LEN 1024 

int main(int argc, char *argv[]) 
{ 
    int listenfd, connfd; 
    struct sockaddr_in servaddr, clientaddr; 
    char buffer[1024]; 
    char *welcome_message = "Hello, my love! Welcome to our chat server...\n"; 
    int clientlen = sizeof(clientaddr); 
    
    // Create a socket
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) { 
        printf("Failed to create socket.\n"); 
        exit(EXIT_FAILURE); 
    } 
      
    // Bind the socket to a port
    memset(&servaddr, 0, sizeof(servaddr)); 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(8080);
    
    if( bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 ) { 
        perror("Bind failed");
        exit(EXIT_FAILURE); 
    } 
    
    // Listen for incoming connections
    if( listen(listenfd, 10) < 0) { 
        perror("Listen failed");
        exit(EXIT_FAILURE); 
    } 
    
    // Accept incoming connections
    connfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clientlen); 
    if (connfd < 0) { 
        perror("Accept failed");
        exit(EXIT_FAILURE); 
    } 
    
    // Send a welcome message to the client
    if (send(connfd, welcome_message, strlen(welcome_message), 0) != strlen(welcome_message)) { 
        perror("Send failed");
        exit(EXIT_FAILURE); 
    } 
    
    // Chat with the client
    while (1) { 
        
        // Receive data from the client
        int nbytes = recv(connfd, buffer, MAX_LEN, 0); 
        if (nbytes < 0) { 
            perror("Recv failed");
            exit(EXIT_FAILURE); 
        } 
        else if (nbytes == 0) { 
            printf("Connection closed by the client.\n"); 
            break; 
        } 
        
        // Print the received message
        buffer[nbytes] = '\0'; 
        printf("Client: %s\n", buffer); 
        
        // Send a response to the client
        char *response_message; 
        if(strcmp(buffer, "I love you, my chatbot!")==0){
            response_message = "I love you too, my love! Let's chat more...\n"; 
        }else{
            response_message = "You're so sweet, my love! But let's talk about something else...\n"; 
        }
        if (send(connfd, response_message, strlen(response_message), 0) != strlen(response_message)) { 
            perror("Send failed");
            exit(EXIT_FAILURE); 
        } 
    } 
    
    // Close the connection
    close(connfd); 
    close(listenfd); 
    
    return 0; 
}