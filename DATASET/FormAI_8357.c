//FormAI DATASET v1.0 Category: Port Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORT 65535

void exit_with_error(char* error_msg)
{
    perror(error_msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }

    int sock;
    int port;
    int connection_status;
    struct sockaddr_in server_address;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        exit_with_error("Could not create socket");
    }

    printf("Scanning ports on %s\n", argv[1]);

    // Loop through all ports
    for (port = 1; port <= MAX_PORT; port++)
    {
        // Set up server address
        server_address.sin_family = AF_INET;
        server_address.sin_addr.s_addr = inet_addr(argv[1]);
        server_address.sin_port = htons(port);

        // Attempt to connect to the port
        connection_status = connect(sock, (struct sockaddr*) &server_address, sizeof(server_address));
        if (connection_status == 0)
        {
            printf("Port %d is open\n", port);
        }

        // Close the connection
        close(sock);
        sock = socket(AF_INET, SOCK_STREAM, 0);
    }

    printf("Scan completed\n");

    return 0;
}