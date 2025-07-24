//FormAI DATASET v1.0 Category: Port Scanner ; Style: safe
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(int argc, char **argv)
{
    int sock, port, i;
    struct sockaddr_in sin;
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [IP address]\n", argv[0]);
        return 1;
    }
    
    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }
    
    // Set the IP address and port number of the server
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(argv[1]);
    
    // Scan ports 1 through 65536
    for (port = 1; port <= 65536; port++) {
        sin.sin_port = htons(port);
        
        if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) == 0) {
            // Port is open
            printf("Port %d is open\n", port);
        }
    }
    
    return 0;
}