//FormAI DATASET v1.0 Category: Port Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_PORTS 65535

void usage() {
    printf("Usage:\n");
    printf("\t./portscanner hostname [-p start_port:end_port]\n");
    printf("\n");
    printf("Examples:\n");
    printf("\t./portscanner localhost\n");
    printf("\t./portscanner www.google.com -p 80:90\n");
    printf("\n");
}

bool is_valid_port(int port) {
    return (port >= 1 && port <= MAX_PORTS);
}

int scan_ports(const char* hostname, int start_port, int end_port) {
    struct hostent* host;
    struct sockaddr_in addr;
    int sockfd, res, port;
    char msg[1024];

    host = gethostbyname(hostname);
    if (host == NULL) {
        snprintf(msg, sizeof(msg), "Error: %s", hstrerror(h_errno));
        perror(msg);
        return -1;
    }

    memset(&addr, 0, sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = *(uint32_t*)host->h_addr_list[0];

    for (port = start_port; port <= end_port; port++) {
        if (!is_valid_port(port)) {
            continue;
        }

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("Error: could not create socket");
            return -1;
        }

        addr.sin_port = htons(port);

        res = connect(sockfd, (struct sockaddr*)&addr, sizeof(struct sockaddr_in));
        if (res == 0) {
            printf("Port %d open\n", port);
            close(sockfd);
        }
    }

    return 0;
}

int main(int argc, char* argv[]) {
    char* hostname;
    int opt;
    int start_port = 1;
    int end_port = MAX_PORTS;

    if (argc < 2) {
        usage();
        return -1;
    }

    hostname = argv[1];

    while ((opt = getopt(argc, argv, "p:")) != -1) {
        switch (opt) {
        case 'p':
            if (sscanf(optarg, "%d:%d", &start_port, &end_port) != 2) {
                printf("Error: invalid -p argument\n");
                usage();
                return -1;
            }
            break;
        default:
            printf("Error: invalid option\n");
            usage();
            return -1;
        }
    }

    printf("Scanning %s ports %d:%d\n", hostname, start_port, end_port);

    return scan_ports(hostname, start_port, end_port);
}