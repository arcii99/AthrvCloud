//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: distributed
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

#define PORT 587 
#define MAX 1024 

int main() 
{ 
    int sockfd; 
    char buffer[MAX]; 
    char command[MAX];
    struct sockaddr_in servaddr; 

    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("Socket creation failed.\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created.\n"); 

    bzero(&servaddr, sizeof(servaddr)); 

    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(PORT); 

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("Connection with the server failed.\n"); 
        exit(0); 
    } 
    else
        printf("Connected to the server.\n"); 

    printf("Enter the SMTP command you want to send (without ending dot):\n"); 
    printf("(e.g. HELO example.com)\n"); 
    fgets(command, MAX, stdin);
    command[strcspn(command, "\n")] = '\0';

    write(sockfd, command, strlen(command)); // send the SMTP command

    printf("Message sent to the server: %s\n", command);

    bzero(buffer, sizeof(buffer)); 

    read(sockfd, buffer, sizeof(buffer)); // receive response from the server 

    if (strncmp("250", buffer, 3) == 0) { 
        printf("Server response: %s\n", buffer); 
    } 
    else
        printf("Error in command execution.\n"); 

    close(sockfd); 
}