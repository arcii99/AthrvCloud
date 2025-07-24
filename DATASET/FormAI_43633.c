//FormAI DATASET v1.0 Category: Client Server Application ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 8888

int main()
{
    int sockfd, newsockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[1024];
    
    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    
    // set socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                   &opt, sizeof(opt)))
    {
        perror("Failed to set socket options");
        exit(EXIT_FAILURE);
    }
    
    // set server address
    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    // bind socket to address
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Failed to bind socket to address");
        exit(EXIT_FAILURE);
    }
    
    // listen for clients
    if (listen(sockfd, 5) < 0)
    {
        perror("Failed to listen for clients");
        exit(EXIT_FAILURE);
    }
    
    printf("Server is listening for clients on port %d...\n", PORT);
    
    // accept client connections
    addr_size = sizeof(client_addr);
    newsockfd = accept(sockfd, (struct sockaddr*)&client_addr, &addr_size);
    if(newsockfd < 0)
    {
        perror("Failed to accept client connection");
        exit(EXIT_FAILURE);
    }
    
    printf("Client connected with IP address %s and port %d.\n", 
            inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    
    while(1)
    {
        // receive message from client
        memset(buffer, 0, sizeof(buffer));
        recv(newsockfd, buffer, sizeof(buffer), 0);
        
        // check for client disconnect
        if(strncmp(buffer, "exit", 4) == 0)
            break;
        
        // process message from client
        printf("Message received from client: %s\n", buffer);
        strcat(buffer, " (processed by server)");
        
        // send message to client
        send(newsockfd, buffer, strlen(buffer), 0);
    }
    
    // close sockets
    close(newsockfd);
    close(sockfd);
    
    return 0;
}