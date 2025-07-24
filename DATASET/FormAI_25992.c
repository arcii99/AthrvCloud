//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFF 512
#define PORT 8888
#define IP_ADDRESS "127.0.0.1"

int main() {
    int sockfd, len;
    char buff[MAX_BUFF];
    struct sockaddr_in serv_addr;
    
    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    
    // set server details
    memset(&serv_addr, 0, sizeof(serv_addr)); 
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
    serv_addr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
    
    // connect to server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }
    
    // receive data from server
    len = read(sockfd, buff, sizeof(buff));
    if (len < 0) {
        perror("Error receiving data from server");
        exit(EXIT_FAILURE);
    }
    
    // print received data
    printf("Wireless Network Scanner Results: %s\n", buff);
    
    // close socket
    close(sockfd);
    
    return 0;
}