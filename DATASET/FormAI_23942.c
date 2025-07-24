//FormAI DATASET v1.0 Category: Port Scanner ; Style: single-threaded
#include <stdio.h> 
#include <string.h> 
#include <stdbool.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 

#define MIN_PORT 1 
#define MAX_PORT 65535 

bool check_port(char *host, int port) 
{ 
    int sockfd, response; 
    struct sockaddr_in address; 

    sockfd = socket(AF_INET, SOCK_STREAM, 0); 

    memset(&address, 0, sizeof(address)); 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = inet_addr(host); 
    address.sin_port = htons(port); 

    response = connect(sockfd, (struct sockaddr *)&address, sizeof(address)); 
    close(sockfd); 

    if (response == 0) { 
        return true; 
    } 
    return false; 
} 

void scan_ports(char *host, int start_port, int end_port) { 
    for (int port = start_port; port <= end_port; port++) { 
        if (check_port(host, port)) { 
            printf("Port %d is open\n", port); 
        } 
    } 
} 

int main(int argc, char *argv[]) 
{ 
    if (argc != 2) {
        printf("Usage: %s <ip_address>\n", argv[0]); 
        return 1; 
    } 

    char *host = argv[1]; 
    int start_port = MIN_PORT; 
    int end_port = MAX_PORT; 

    printf("Scanning ports on %s...\n", host); 
    scan_ports(host, start_port, end_port); 
    printf("Scan complete.\n"); 

    return 0; 
}