//FormAI DATASET v1.0 Category: Port Scanner ; Style: standalone
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/socket.h> 
#include <arpa/inet.h>
#include <unistd.h> 

int main(int argc, char *argv[]) { 
    int port1, port2, sockfd; 
    struct sockaddr_in servaddr; 
  
    if (argc != 3) { 
        printf("Usage: %s <port1> <port2>\n", argv[0]); 
        exit(1); 
    } 
  
    port1 = atoi(argv[1]); 
    port2 = atoi(argv[2]); 
  
    for (int port = port1; port <= port2; port++) { 
        sockfd = socket(AF_INET, SOCK_STREAM, 0); 
        if (sockfd < 0) { 
            perror("Could not create socket\n"); 
            exit(1); 
        } 
  
        servaddr.sin_family = AF_INET; 
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
        servaddr.sin_port = htons(port); 
  
        if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == 0) { 
            printf("Port %d is open\n", port); 
        } 
  
        close(sockfd); 
    } 
  
    return 0; 
}