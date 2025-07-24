//FormAI DATASET v1.0 Category: Port Scanner ; Style: calm
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to scan ports
void scan_port(const char* ip_addr, int start_port, int end_port) {
    int sock, conn_status;
    struct sockaddr_in target;

    // Initialize the target server info
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip_addr);

    // Loop through the ports to scan
    for(int port = start_port; port <= end_port; port++) {
        // Initialize the port info
        target.sin_port = htons(port);

        // Create a socket
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock == -1) {
            printf("Error: Could not create socket");
            return;
        }

        // Connect to server
        conn_status = connect(sock, (struct sockaddr *)&target, sizeof(target));
        if(conn_status == -1) {
            printf("Port %d: Closed\n", port);
        } else {
            printf("Port %d: Open\n", port);
        }

        // Close the socket
        close(sock);
    }
}

int main() {
    // Define the IP address to scan
    char ip_addr[] = "127.0.0.1";

    // Define the range of ports to scan
    int start_port = 1;
    int end_port = 65535;

    // Call the scan_port function
    scan_port(ip_addr, start_port, end_port);

    return 0;
}