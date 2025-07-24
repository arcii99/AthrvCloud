//FormAI DATASET v1.0 Category: Port Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

// Define the maximum number of ports to scan
#define MAX_PORT 65535

// Function to check if a port is open on a given IP address
int port_scan(char *ip_address, int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip_address);
    target.sin_port = htons(port);
    int status = connect(sock, (struct sockaddr *)&target, sizeof(target));
    close(sock);
    return !status;
}

// Handle Ctrl-C signal
void sigint_handler(int sig)
{
    printf("\nScanning stopped.\n");
    exit(0);
}

int main(int argc, char *argv[])
{
    // Check correct number of arguments
    if (argc != 2)
    {
        printf("Usage: ./portscanner <ip_address>\n");
        return 1;
    }

    // Register Ctrl-C signal handler
    signal(SIGINT, sigint_handler);

    char *ip_address = argv[1];
    printf("Scanning ports on: %s\n", ip_address);

    // Scan each port
    for (int port = 1; port <= MAX_PORT; port++)
    {
        if (port_scan(ip_address, port))
        {
            printf("%d open\n", port);
        }
    }

    printf("Scanning complete.\n");
    return 0;
}