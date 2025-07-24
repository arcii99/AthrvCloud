//FormAI DATASET v1.0 Category: Socket programming ; Style: synchronous
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

int main() 
{ 
    //Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
    { 
        perror("Socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 

    //Socket address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr)); 
    addr.sin_family = AF_INET; 
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    addr.sin_port = htons(8888); 

    //Connect to server
    int conn_status = connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    if (conn_status < 0) 
    { 
        perror("Connection Failed"); 
        exit(EXIT_FAILURE); 
    } 

    char buffer[1024] = {0}; 
    int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0); 
    printf("%s", buffer); 

    //Close socket
    close(sockfd);
    return 0; 
}