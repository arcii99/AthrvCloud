//FormAI DATASET v1.0 Category: Client Server Application ; Style: brave
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 

#define MAX 100 
#define PORT 8080 
#define SA struct sockaddr 

// Function for the client 
void func(int sockfd) 
{ 
    char buff[MAX]; 
    int n; 

    // Infinte loop for chatting 
    for (;;) { 
        bzero(buff, sizeof(buff)); 
        printf("Enter the message: "); 
        n = 0; 
        // Reading message from the user
        while ((buff[n++] = getchar()) != '\n') 
            ; 
        // Writing message to the server
        write(sockfd, buff, sizeof(buff)); 
        bzero(buff, sizeof(buff)); 
        // Reading message from the server
        read(sockfd, buff, sizeof(buff)); 
        printf("From Server : %s", buff); 
        // If message "exit" is received, come out of the loop
        if ((strncmp(buff, "exit", 4)) == 0) { 
            printf("Client Exit...\n"); 
            break; 
        } 
    } 
} 

// Driver function 
int main() 
{ 
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli; 

    // Creating Socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("Socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created...\n"); 

    bzero(&servaddr, sizeof(servaddr)); 

    // Assigning IP address and PORT
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(PORT); 

    // Connecting server to the client
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("Connection with the server failed...\n"); 
        exit(0); 
    } 
    else
        printf("Connected to the server...\n"); 

    // Function for chat 
    func(sockfd); 

    // Closing the socket
    close(sockfd); 
}