//FormAI DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // Print a happy message to the user
    printf("Welcome to the Happy Port Scanner!\n");

    // Check if user provided enough arguments
    if (argc < 2) {
        printf("Usage: %s <IP Address>\n",argv[0]);
        return 1;
    }

    // Get IP address from user input
    char *target_ip = argv[1];

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        return 1;
    }

    // Loop through all port numbers and try to connect to each one
    for (int port = 1; port <= 65535; port++) {
        struct sockaddr_in server;
        server.sin_addr.s_addr = inet_addr(target_ip);
        server.sin_family = AF_INET;
        server.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0 ) {
            // Port is closed, print a happy message and move on to the next port
            printf("Happiness! Port %d is closed :(\n", port);
        } else {
            // Port is open, print a happy message and close the connection
            printf("Woohoo! Port %d is open :)\n", port);
            close(sock); // Close the connection so we can try the next port
            sock = socket(AF_INET, SOCK_STREAM, 0); // Create a new socket to try the next port
        }
    }

    // Print a happy message to close the program
    printf("Thank you for using the Happy Port Scanner!\n");

    return 0;
}