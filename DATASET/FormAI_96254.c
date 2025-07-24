//FormAI DATASET v1.0 Category: Port Scanner ; Style: beginner-friendly
#include <stdio.h> 
#include <stdbool.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 

void scan_range(char* hostname, int start_port, int end_port) 
{ 
    struct sockaddr_in target; 
    int sockfd, result, i; 

    target.sin_family = AF_INET; 
    target.sin_addr.s_addr = inet_addr(hostname); 

    for (i = start_port; i <= end_port; i++) 
    { 
        target.sin_port = htons(i); 
        sockfd = socket(AF_INET, SOCK_STREAM, 0); 
        result = connect(sockfd, (struct sockaddr *)&target, sizeof(target)); 

        if (result == 0) 
        { 
            printf("Port %d is open\n", i); 
        } 

        close(sockfd); 
    } 
} 

int main() 
{ 
    char* hostname = "127.0.0.1"; 
    int start_port = 1, end_port = 1024; 

    scan_range(hostname, start_port, end_port); 

    return 0; 
}