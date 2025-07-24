//FormAI DATASET v1.0 Category: Client Server Application ; Style: shape shifting
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 

int main() 
{ 
    int sockfd, newsockfd, portno, clilen, n; 
    char buffer[256]; 
    struct sockaddr_in serv_addr, cli_addr; 

    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd < 0) 
       printf("Error opening socket\n");

    bzero((char *) &serv_addr, sizeof(serv_addr)); 

    portno = 5001; 

    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_addr.s_addr = INADDR_ANY; 
    serv_addr.sin_port = htons(portno); 

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        printf("Error on binding\n");

    listen(sockfd, 5);

    clilen = sizeof(cli_addr); 

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen); 
    if (newsockfd < 0) 
        printf("Error on accept\n");

    bzero(buffer, 256);

    n = read(newsockfd, buffer, 255); 
    if (n < 0) 
        printf("Error reading from socket\n");

    printf("Message from client: %s\n", buffer);
    printf("Enter your response: ");

    bzero(buffer, 256); 

    fgets(buffer, 255, stdin); 

    n = write(newsockfd, buffer, strlen(buffer)); 
    if (n < 0) 
        printf("Error writing to socket\n");

    close(newsockfd); 
    close(sockfd); 

    return 0; 
}