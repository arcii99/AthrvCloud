//FormAI DATASET v1.0 Category: Port Scanner ; Style: minimalist
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int socket_desc;
    struct sockaddr_in server;
    int port;
    int start_port = 1;
    int end_port = 65535;
    
    printf("\n\n\t\tPort Scanner by YourName\n\n");

    if (argc < 2) {
        printf("Usage: %s <IPADDRESS>\n", argv[0]);
        return 1;
    }
    
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    
    for (port = start_port; port <= end_port; port++) {
        server.sin_port = htons(port);
        
        if (connect(socket_desc, (struct sockaddr *) &server , sizeof(server)) == 0) {
            printf("Port %d is open\n", port);
        }
        
        close(socket_desc);
    }
    
    printf("Scan completed\n");
    return 0;
}