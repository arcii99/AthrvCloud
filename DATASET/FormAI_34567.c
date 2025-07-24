//FormAI DATASET v1.0 Category: Port Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc != 2) { // check if user entered correct number of arguments
        printf("Please provide a target IP address.\n");
        return -1;
    }

    int start_port = 1; // start scanning from port 1
    int end_port = 65535; // scan up to port 65535

    char *target_ip = argv[1]; // get the target IP address from the user

    printf("Scanning %s...\n", target_ip);

    // loop through all the ports and attempt to connect to each one
    for (int port = start_port; port <= end_port; port++) {
        struct sockaddr_in target_addr;
        memset(&target_addr, 0, sizeof(target_addr));
        target_addr.sin_family = AF_INET;
        target_addr.sin_port = htons(port);
        target_addr.sin_addr.s_addr = inet_addr(target_ip);

        int sock = socket(AF_INET, SOCK_STREAM, 0); // create a new socket
        int connect_status = connect(sock, (struct sockaddr *)&target_addr, sizeof(target_addr));

        if (connect_status == 0) { // if the connection is successful, the port is open
            printf("Port %d is open.\n", port);
        }

        close(sock); // close the socket
    }

    printf("Scan complete.\n");

    return 0;
}