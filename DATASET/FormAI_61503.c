//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#define MAX_DEVICES 1000  // Maximum devices on the network 
#define MAX_PORTS 200     // Max ports to be checked 

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <IP Address>", argv[0]);
        exit(0);
    }

    struct sockaddr_in device_addr;
    int device_socket, port_number, open_ports[MAX_PORTS], count = 0;
    char *ip_addr = argv[1];
    memset(&device_addr, 0, sizeof(device_addr));
    device_addr.sin_family = AF_INET;
    device_addr.sin_addr.s_addr = inet_addr(ip_addr);
    
    // Start scanning from port 1 to 65535
    for(port_number = 1; port_number <= 65535; port_number++) {
        device_addr.sin_port = htons(port_number);
        device_socket = socket(AF_INET, SOCK_STREAM, 0); // Create a socket for each port 
        if(device_socket < 0) {
            printf("\nCould not create socket for port %d", port_number);
            continue;
        }
        if(connect(device_socket, (struct sockaddr *)&device_addr, sizeof(device_addr)) < 0) {
            close(device_socket); // Connection is not successful, close the socket 
            continue;
        }
        // Connection is successful, save the port number in open_ports array 
        open_ports[count] = port_number;
        count++;
        close(device_socket);
    }
    printf("\nPort Scanning completed!\n");
    printf("Total %d open ports found on %s\n", count, ip_addr);
    printf("List of open ports:\n");
    for(int i = 0; i < count; i++) {
        printf("Port %d is open\n", open_ports[i]);
    }
    return 0;
}