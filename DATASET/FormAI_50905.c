//FormAI DATASET v1.0 Category: Socket programming ; Style: introspective
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 

#define PORT 8080 

int main() 
{ 
    int sockfd, ret; 
    struct sockaddr_in serverAddr; 

    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if(sockfd < 0) { 
        printf("Error in connection.\n"); 
        exit(1); 
    } 
    printf("Socket creation successful.\n"); 

    memset(&serverAddr, '\0', sizeof(serverAddr)); 

    serverAddr.sin_family = AF_INET; 
    serverAddr.sin_port = htons(PORT); 
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 

    ret = connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)); 
    if(ret < 0) { 
        printf("Error in connection.\n"); 
        exit(1); 
    } 
    printf("Connection successful.\n"); 

    char buffer[1024]; 
    memset(buffer, '\0', sizeof(buffer)); 
    printf("Enter message to send:"); 
    fgets(buffer, 1024, stdin); 

    send(sockfd, buffer, strlen(buffer), 0); 

    if((recv(sockfd, buffer, 1024, 0)) > 0) { 
        printf("Received message: %s\n", buffer); 
    } 

    close(sockfd); 

    return 0; 
}