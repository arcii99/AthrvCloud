//FormAI DATASET v1.0 Category: Port Scanner ; Style: Alan Touring
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in target;
    
    // Check if IP address and port number were provided
    if (argc != 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        return 1;
    }
    
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket");
        return 1;
    }
    
    // Fill in target information
    target.sin_family = AF_INET;
    target.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &target.sin_addr) <= 0) {
        printf("Invalid IP address provided");
        return 1;
    }
    
    // Connect to target
    if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
        printf("Port %d open\n", atoi(argv[2]));
    } else {
        printf("Port %d closed\n", atoi(argv[2]));
    }
    
    return 0;
}