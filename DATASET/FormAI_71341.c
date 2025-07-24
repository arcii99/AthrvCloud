//FormAI DATASET v1.0 Category: Port Scanner ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

// function to scan open ports on a given IP address
void port_scan(char* ip_address, int start_port, int end_port) {
    int sock;
    struct sockaddr_in server;
    // socket creation
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }
    // set up server address and port range
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip_address);
    for (int port = start_port; port <= end_port; port++) {
        server.sin_port = htons(port);
        // attempt to connect to specified port
        if (connect(sock, (struct sockaddr*)&server, sizeof(server)) == 0) {
            printf("Port %d open on %s\n", port, ip_address);
        }
    }
    // close the socket
    close(sock);
}

int main(int argc, char *argv[]) {
    // check for correct number of arguments
    if (argc != 4) {
        printf("Usage: %s <IP address> <starting port> <ending port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    // parse command line arguments
    char* ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);
    // scan ports
    printf("Scanning ports on %s...\n", ip_address);
    port_scan(ip_address, start_port, end_port);
    printf("Scan complete.\n");
    return 0;
}