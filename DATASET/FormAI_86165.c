//FormAI DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 2) { // Checks if only one command-line argument is provided
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 1; 
    }

    char *ip_address = argv[1]; // Store the IP address in a variable
    struct sockaddr_in target; // Create a socket address structure
    int start_port = 1, end_port = 65535; // Define the range of ports to scan (1-65535)

    // Convert the IP address to binary format and store it in the socket address structure
    if (inet_pton(AF_INET, ip_address, &target.sin_addr) <= 0) {
        perror("inet_pton error");
        return 1;
    }

    // Loop through each port in the specified range and print the open ports
    for (int port = start_port; port <= end_port; port++) {
        target.sin_family = AF_INET; // Set the socket family type
        target.sin_port = htons(port); // Convert the port number to network byte order

        int sock = socket(AF_INET, SOCK_STREAM, 0); // Create a TCP socket
        if (sock < 0) {
            perror("socket error");
            return 1;
        }

        // Connect to the target IP address and port
        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %d is open on %s\n", port, ip_address);
        }

        close(sock); // Close the socket once the port is checked
    }

    return 0; // Exit the program
}