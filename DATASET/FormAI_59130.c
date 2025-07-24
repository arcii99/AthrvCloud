//FormAI DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORT 65535 // Number of ports to be scanned

void print_ascii_art() {
    printf("\n");
    printf(" ██████╗██╗   ██╗██████╗ ████████╗██╗ ██████╗ ███╗   ██╗     \n");
    printf("██╔════╝██║   ██║██╔══██╗╚══██╔══╝██║██╔═══██╗████╗  ██║     \n");
    printf("██║     ██║   ██║██████╔╝   ██║   ██║██║   ██║██╔██╗ ██║     \n");
    printf("██║     ██║   ██║██╔═══╝    ██║   ██║██║   ██║██║╚██╗██║     \n");
    printf("╚██████╗╚██████╔╝██║        ██║   ██║╚██████╔╝██║ ╚████║     \n");
    printf(" ╚═════╝ ╚═════╝ ╚═╝        ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝     \n");
    printf("\n");
    printf("==== Happy Port Scanner v1.0 ====\n\n");
}

void scan_ports(char *ip_addr) {
    struct sockaddr_in server;
    int socket_desc;
    int port;

    for (port = 1; port <= MAX_PORT; port++) {
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr(ip_addr);
        server.sin_port = htons(port);

        socket_desc = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_desc == -1) {
            continue; // Couldn't create socket
        }

        if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d: Open\n", port);
        }

        close(socket_desc);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./port_scanner <ip_address>\n");
        return 1;
    }

    print_ascii_art();
    printf("Scanning ports on %s...\n\n", argv[1]);

    scan_ports(argv[1]);

    printf("\nScan completed!\n");
    return 0;
}