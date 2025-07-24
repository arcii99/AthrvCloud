//FormAI DATASET v1.0 Category: Port Scanner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Define some colors for a cyberpunk style output
#define COLOR_CYAN "\x1b[36m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_RESET "\x1b[0m"

// Function to print the usage instructions
void usage(char *program_name) {
    printf(COLOR_CYAN "Usage: %s <ip_address>\n" COLOR_RESET, program_name);
    printf(COLOR_CYAN "Scans for open ports on the given IP address.\n" COLOR_RESET);
    printf(COLOR_CYAN "Example: %s 192.168.0.1\n" COLOR_RESET, program_name);
}

// Function to create a socket and connect to the given port
int check_port(char *ip_address, int port) {
    int sock;
    struct sockaddr_in server;

    // Create the socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf(COLOR_YELLOW "[-] Error: Could not create socket\n" COLOR_RESET);
        return 1;
    }

    // Configure the server address
    server.sin_addr.s_addr = inet_addr(ip_address);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // Try to connect to the port
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        // Port is closed
        close(sock);
        return 0;
    }
    
    // Port is open
    close(sock);
    return 1;
}

int main(int argc, char *argv[]) {
    char *ip_address;
    int ports[] = {21, 22, 23, 80, 443, 3306, 8080, 9999}; // List of common ports to scan
    int i;

    // Check if the correct number of arguments are provided
    if (argc != 2) {
        usage(argv[0]);
        return 1;
    }

    // Get the IP address to scan
    ip_address = argv[1];

    // Scan the ports
    printf(COLOR_CYAN "[*] Scanning %s...\n" COLOR_RESET, ip_address);
    printf(COLOR_CYAN "-----------------------\n" COLOR_RESET);
    for (i = 0; i < sizeof(ports) / sizeof(ports[0]); i++) {
        printf(COLOR_CYAN "[*] Checking port %d..." COLOR_RESET, ports[i]);
        if (check_port(ip_address, ports[i])) {
            printf(COLOR_CYAN " OPEN\n" COLOR_RESET);
        } else {
            printf(COLOR_YELLOW " CLOSED\n" COLOR_RESET);
        }
    }
    printf(COLOR_CYAN "-----------------------\n" COLOR_RESET);

    return 0;
}