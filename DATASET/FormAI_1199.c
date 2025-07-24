//FormAI DATASET v1.0 Category: Socket programming ; Style: immersive
// You are now entering the world of network programming with C Socket.
// Your mission is to create a client-server chat application using sockets. 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 

#define PORT 8080 

void error(char *msg) 
{
    perror(msg);
    exit(EXIT_FAILURE);
}

int main()
{
    int sockfd = 0, new_sockfd = 0; 
    struct sockaddr_in serv_addr; 

    char buffer[1024] = {0}; 

    // Create the socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
        error("socket creation failed"); 
    
    memset(&serv_addr, '0', sizeof(serv_addr)); 

    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
    serv_addr.sin_port = htons(PORT); 
    
    // Bind the socket to the port
    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) 
        error("bind failed"); 
    
    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) 
        error("listen failed"); 
    
    // Accept the incoming connection
    if ((new_sockfd = accept(sockfd, (struct sockaddr*)NULL, NULL)) < 0) 
        error("accept failed"); 

    while(1)
    {
        // Read data from the client
        if (read(new_sockfd, buffer, 1024) < 0) 
            error("read failed"); 
        
        printf("Client: %s\n",buffer); // Display the client's message 

        // Send a reply to the client
        printf("Server: ");
        bzero(buffer, 1024);
        fgets(buffer,1024,stdin);
        
        if (write(new_sockfd, buffer, strlen(buffer)) < 0) 
            error("write failed");
    }
    
    // Close the sockets and exit
    close(new_sockfd);
    close(sockfd);
    return 0;
}