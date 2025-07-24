//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_PORT 65535
#define MAX_IP 16

void scan_ports(char *ip_address) {
    struct sockaddr_in remote_address;
    struct hostent *host;

    host = gethostbyname(ip_address);
    if (host == NULL) {
        fprintf(stderr, "Unable to resolve host %s\n", ip_address);
        return;
    }

    printf("Scanning ports for %s (%s):\n", host->h_name, ip_address);

    int sock_fd;
    for (int port=1; port<MAX_PORT+1; port++) {
        sock_fd = socket(AF_INET, SOCK_STREAM, 0);

        memset(&remote_address, 0, sizeof(remote_address));
        remote_address.sin_family = AF_INET;
        remote_address.sin_addr = *((struct in_addr*) host->h_addr);
        remote_address.sin_port = htons(port);

        if (connect(sock_fd, (struct sockaddr*) &remote_address, sizeof(remote_address)) < 0) {
            close(sock_fd);
            continue;
        }

        printf("Port %d is open\n", port);
        close(sock_fd);
    }
}

void usage(char *program_name) {
    printf("Usage: %s [-t target_ip]\n", program_name);
}

int main(int argc, char *argv[]) {
    char target_ip[MAX_IP];

    memset(target_ip, 0, MAX_IP);

    int option;
    while ((option = getopt(argc, argv, ":t:")) != -1) {
        switch (option) {
            case 't':
                strncpy(target_ip, optarg, MAX_IP);
                break;
            case '?':
                printf("Unknown option: %c\n", optopt);
                usage(argv[0]);
                return EXIT_FAILURE;
            case ':':
                printf("Missing argument for option: %c\n", optopt);
                usage(argv[0]);
                return EXIT_FAILURE;
        }
    }

    if (strlen(target_ip) == 0) {
        printf("Please specify a target IP address.\n");
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    scan_ports(target_ip);

    return EXIT_SUCCESS;
}