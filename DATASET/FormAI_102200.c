//FormAI DATASET v1.0 Category: Port Scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// define the number of ports we want to scan
#define NUM_PORTS 100

int main(int argc, char *argv[]) {

    // check the user has provided an IP address to scan
    if (argc < 2) {
        printf("Please provide an IP address to scan.\n");
        return 1;
    }

    // allocate memory for an array of sockets(hint the size is NUM_PORTS)
    int *sockets = malloc(sizeof(int) * NUM_PORTS);
    if (sockets == NULL) {
        perror("Failed to allocate memory for sockets");
        return 1;
    }

    // initialize all of the sockets to be invalid (hint use loop to this operation)
    for (int i = 0; i < NUM_PORTS; i++) {
        sockets[i] = -1;
    }

    // create a loop that iterates over each port we want to scan(1 to NUM_PORTS)
    for (int port = 1; port < NUM_PORTS; port++) {
        
        // create a new socket for this port (hint use the socket() function)
        int sock = socket(AF_INET , SOCK_STREAM , 0);
        if (sock == -1) {
            perror("Failed to create socket");
            continue;
        }

        // configure the socket to allow reusing the address (hint use setsockopt() function)
        int opt = 1;
        if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
            perror("Failed to set socket options");
            continue;
        }

        // create a sockaddr_in structure for this port and IP address (hint use the inet_addr() function)
        struct sockaddr_in server;
        server.sin_addr.s_addr = inet_addr(argv[1]);
        server.sin_family = AF_INET;
        server.sin_port = htons(port);

        // attempt to connect to the port (hint use the connect() function)
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) != -1) {
            // if we connect successfully, print a message to the user
            printf("Port %d is open.\n", port);

            // add the socket to our array of open sockets
            sockets[port] = sock;
        }
    }

    // now we wait for the user to press a key to close the program
    printf("Press enter to close the program.\n");
    getchar();

    // close any open sockets
    for (int i = 0; i < NUM_PORTS; i++) {
        if (sockets[i] != -1) {
            close(sockets[i]);
        }
    }

    // free the memory used by our array of sockets
    free(sockets);

    return 0;
}