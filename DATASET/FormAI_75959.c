//FormAI DATASET v1.0 Category: Socket programming ; Style: systematic
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <errno.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

#define PORT 8080 

int main() 
{ 
    int sockfd, ret, newsockfd; 
    struct sockaddr_in serverAddr; 
    struct sockaddr_in newAddr; 
    socklen_t addr_size; 
    char buffer[1024]; 

    // Socket creation
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd < 0) { 
        printf("\nError creating socket.\n"); 
        return 1; 
    } 
    printf("\nSocket created successfully.\n"); 

    memset(&serverAddr, '\0', sizeof(serverAddr)); 

    // Setting server address
    serverAddr.sin_family = AF_INET; 
    serverAddr.sin_port = htons(PORT); 
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //"127.0.0.1" represents localhost IP address

    // Binding socket to the port
    ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)); 
    if (ret < 0) { 
        printf("\nError binding socket.\n"); 
        return 1; 
    } 
    printf("\nSocket binding successful.\n"); 

    // Listening for incoming connections
    if (listen(sockfd, 10) == 0) { 
        printf("\nListening....\n"); 
    } 
    else { 
        printf("\nError in listening.\n"); 
        return 1; 
    } 

    addr_size = sizeof(newAddr); 
    newsockfd = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size); 
    if (newsockfd < 0) { 
        printf("\nError on accepting connection.\n"); 
        return 1; 
    } 
    printf("\nConnection accepted from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port)); 

    // Sending message to client
    strcpy(buffer, "\nHello from server.\n"); 
    send(newsockfd, buffer, strlen(buffer), 0); 

    // Receiving message from client
    memset(buffer, '\0', sizeof(buffer)); 
    recv(newsockfd, buffer, 1024, 0); 
    printf("\nMessage from client: %s\n", buffer); 

    // Closing the socket connections
    close(newsockfd); 
    close(sockfd); 

    return 0; 
}