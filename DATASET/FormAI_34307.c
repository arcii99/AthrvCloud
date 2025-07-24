//FormAI DATASET v1.0 Category: Simple Web Server ; Style: distributed
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 

#define PORT 8080 
#define BUFSIZE 1024 

int main() { 
    int sockfd, connfd, n; 
    char buffer[BUFSIZE]; 
    struct sockaddr_in servaddr, cliaddr; 
    socklen_t len = sizeof(cliaddr); 

    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("Socket creation failed...\n"); 
        exit(0); 
    } 

    memset(&servaddr, 0, sizeof(servaddr)); 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 

    if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("Socket bind failed...\n"); 
        exit(0); 
    } 

    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 

    printf("Server listening on port %d...\n", PORT); 

    // loop to accept incoming connections
    while (1) { 
        connfd = accept(sockfd, (struct sockaddr*)&cliaddr, &len); 
        if (connfd < 0) { 
            printf("Accept failed...\n"); 
            exit(0); 
        } 

        pid_t pid = fork();
        if (pid==0) { // child process
            close(sockfd);
            
            char msg[] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\nHello, World!\n";
            write(connfd, msg, strlen(msg)); 
            
            close(connfd);
            exit(0);
        }

        close(connfd);
    } 

    close(sockfd); 

    return 0;
}