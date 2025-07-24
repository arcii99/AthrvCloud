//FormAI DATASET v1.0 Category: Port Scanner ; Style: standalone
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
    // Create a TCP socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sock == -1) {
        printf("Could not create socket");
    }
    
    // Get the IP address of the host
    char *host = argv[1];
    struct in_addr ip;
    inet_pton(AF_INET, host, &ip);
    
    // Scan specified range of ports
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);
    int port;
    struct sockaddr_in server;
    
    for (port = start_port; port <= end_port; port++) {
        server.sin_addr.s_addr = ip.s_addr;
        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        
        // Try to connect to port
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
    }
    
    // Close the socket
    close(sock);
    
    return 0;
}