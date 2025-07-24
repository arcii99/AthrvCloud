//FormAI DATASET v1.0 Category: Port Scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Get command line arguments
    char *ip = argv[1];
    int starting_port = atoi(argv[2]);
    int ending_port = atoi(argv[3]);
    
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    inet_aton(ip, &address.sin_addr);
    
    // Scan ports
    for (int port = starting_port; port <= ending_port; port++) {
        int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        address.sin_port = htons(port);
        int connection = connect(socket_fd, (struct sockaddr *) &address, sizeof(address));
        if (connection == 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
        close(socket_fd);
    }
    
    return 0;
}