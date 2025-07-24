//FormAI DATASET v1.0 Category: Port Scanner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    // check that an IP address is provided as argument
    if (argc != 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }

    // create a socket
    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }

    // set the timeout value for connecting
    struct timeval timeout;
    timeout.tv_sec = 2; // 2 seconds
    timeout.tv_usec = 0;
    if (setsockopt(socket_desc, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
        printf("Could not set socket options");
        return 1;
    }

    // create a structure for the socket address
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;

    // loop through all possible ports and try to connect to them
    int is_open;
    for (int port = 1; port <= 65535; port++) {

        server.sin_port = htons(port); // set the port number

        // try to connect to the port
        is_open = connect(socket_desc, (struct sockaddr *)&server, sizeof(server));

        // if the connect was successful, print the port number
        if (is_open == 0) {
            printf("Port %d is open\n", port);
        }

        // sleep for 10 milliseconds between each port connection attempt
        usleep(10000);
    }

    // close the socket
    close(socket_desc);

    return 0;
}