//FormAI DATASET v1.0 Category: Port Scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // Check if the user provides enough input arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the IP address provided by the user
    char *ip_address = argv[1];

    // Create a socket for our connection
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        fprintf(stderr, "Error creating socket\n");
        exit(EXIT_FAILURE);
    }

    // Specify the address to scan
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = 0;
    sin.sin_addr.s_addr = inet_addr(ip_address);

    // Set the timeout for our connection
    struct timeval timeout;
    timeout.tv_sec = 2;
    timeout.tv_usec = 0;
    setsockopt(sock_fd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout, sizeof(timeout));
    setsockopt(sock_fd, SOL_SOCKET, SO_SNDTIMEO, (const char *)&timeout, sizeof(timeout));

    // Scan ports from 1 to 65535
    for (int port = 1; port <= 65535; ++port) {
        sin.sin_port = htons(port);
        int conn_status = connect(sock_fd, (struct sockaddr *)&sin, sizeof(sin));

        if (conn_status != -1) {
            char *service_name;

            // Get the service name based on the port
            switch (port) {
                case 20:
                case 21:
                    service_name = "FTP";
                    break;
                case 22:
                    service_name = "SSH";
                    break;
                case 23:
                    service_name = "Telnet";
                    break;
                case 25:
                    service_name = "SMTP";
                    break;
                case 53:
                    service_name = "DNS";
                    break;
                case 80:
                    service_name = "HTTP";
                    break;
                case 110:
                    service_name = "POP3";
                    break;
                case 143:
                    service_name = "IMAP";
                    break;
                case 443:
                    service_name = "HTTPS";
                    break;
                default:
                    service_name = "Unknown";
                    break;
            }

            printf("Port %d open (%s)\n", port, service_name);
            close(sock_fd); // Close the connection
            sock_fd = socket(AF_INET, SOCK_STREAM, 0); // Create a new socket for the next scan
        }
    }

    return 0;
}