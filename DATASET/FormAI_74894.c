//FormAI DATASET v1.0 Category: Port Scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

#define MAX_PORTS 65535

// Function to print the welcome message
void welcome_message() {
    printf("Welcome to Sherlock Holmes' Port Scanner\n");
    printf("Let's find out the open ports of your target...\n");
}

// Function to scan the ports
void port_scanner(char* ip_address) {
    struct sockaddr_in target;
    int sock, err, open_ports=0;
    socklen_t len = sizeof(err);
    uint16_t port;

    // Create socket to scan the ports
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(0);
    }

    // Set the target IP address and family
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip_address);

    // Scan the possible ports of target IP
    for (port = 1; port <= MAX_PORTS; port++) {
        target.sin_port = htons(port);

        // Connect to the target IP and port
        err = connect(sock, (struct sockaddr *)&target, sizeof(target));

        // If the port is open, print the port and increment the open_ports
        if (err == 0) {
            printf("%d :: Open\n", port);
            open_ports++;
            close(sock);
            sock = socket(AF_INET, SOCK_STREAM, 0);
            if (sock < 0) {
                perror("Socket creation failed");
                exit(0);
            }
        }
    }

    // Print the result of the scan
    if (open_ports > 0) {
        printf("\n\nThe target %s has %d open ports\n", ip_address, open_ports);
    } else {
        printf("\n\nNo open ports found in the target %s\n", ip_address);
    }

    // Close the socket
    close(sock);
}

int main(int argc, char** argv) {
    // Check if the IP address is provided
    if (argc != 2) {
        printf("Usage : ./port_scanner [IP Address]\n");
        return 0;
    }

    // Print welcome message and scan the ports
    welcome_message();
    port_scanner(argv[1]);

    return 0;
}