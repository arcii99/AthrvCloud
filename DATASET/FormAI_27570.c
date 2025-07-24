//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: ultraprecise
#include <stdio.h> 
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 25
#define MAX 1000

int main() 
{ 
    int sockfd; 
    char buffer[MAX];
    char *msg = "EHLO gmail.com\r\n";
    struct sockaddr_in serv_addr; 

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd < 0) 
    { 
        perror("Error creating socket"); 
        exit(EXIT_FAILURE); 
    } 

    // set server information
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
    serv_addr.sin_addr.s_addr = inet_addr("74.125.68.109"); 

    // connect to server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) != 0) 
    { 
        perror("Error connecting to server"); 
        exit(EXIT_FAILURE); 
    } 

    // write message to server
    write(sockfd, msg, strlen(msg)); 

    // read response from server
    bzero(buffer, MAX); 
    read(sockfd, buffer, sizeof(buffer)); 
    printf("Server Response: %s", buffer); 

    // close socket
    close(sockfd); 

    return 0; 
}