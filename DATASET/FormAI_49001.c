//FormAI DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORT 65535

bool is_port_open(int port_number, char *server_address) {
    int client_socket;
    struct sockaddr_in server_address_struct;

    // creation of socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // specify an address for the socket
    server_address_struct.sin_family = AF_INET;
    server_address_struct.sin_port = htons(port_number);
    inet_aton(server_address, &server_address_struct.sin_addr);

    // connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_address_struct, sizeof(server_address_struct)) == 0) {
        // Close the socket and return true if connection is successful
        close(client_socket);
        return true;
    } else {
        // Close the socket and return false if connection fails
        close(client_socket);
        return false;
    }
}

void print_open_ports(char *server_address) {
    printf("Scanning ports on %s...\n", server_address);
    for (int i = 0; i <= MAX_PORT; i++) {
        if (is_port_open(i, server_address)) {
            printf("Port %d is open.\n", i);
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: ./portscanner [IP address]\n");
        exit(EXIT_FAILURE);
    }

    char *server_address = argv[1];
    print_open_ports(server_address);

    return 0;
}