//FormAI DATASET v1.0 Category: Port Scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <errno.h>

#define MAX_PORTS 65535

void handle_error(char *msg) {
    fprintf(stderr, "Error: %s, errno = %d\n", msg, errno);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: %s <host> [timeout (in seconds)]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *host = argv[1];
    int timeout = argc == 3 ? atoi(argv[2]) : 1;

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_CANONNAME;

    if (getaddrinfo(host, NULL, &hints, &res) != 0) {
        handle_error("getaddrinfo");
    }

    int sockfd, rc, ports_scanned = 0;
    struct sockaddr_in sa;
    struct hostent *ptr;

    ptr = gethostbyname(host);
    if (ptr == NULL) {
        handle_error("gethostbyname");
    }

    printf("Scanning ports on %s (%s):\n", ptr->h_name, inet_ntoa(*(struct in_addr *)ptr->h_addr_list[0]));

    for (int i = 1; i <= MAX_PORTS; i++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            handle_error("socket");
        }

        sa.sin_family = AF_INET;
        sa.sin_port = htons(i);
        sa.sin_addr.s_addr = *(long*)(res->ai_addr->sa_data + 2);

        // Set socket options to timeout after `timeout` seconds
        struct timeval timeout_tv = {
            .tv_sec = timeout,
            .tv_usec = 0
        };

        if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout_tv, sizeof(timeout_tv)) < 0) {
            handle_error("setsockopt");
        }

        rc = connect(sockfd, (const struct sockaddr*)&sa, sizeof(sa));
        if (rc == 0) {
            char *service = getservbyport(htons(i), "tcp")->s_name;
            printf("\tPort %d (%s) is open\n", i, service);
        } else {
            if (errno == ECONNREFUSED) {
                // Port is closed
            } else {
                // Error occurred, print error message
                printf("\tPort %d: error (%s)\n", i, strerror(errno));
            }
        }

        close(sockfd);

        ports_scanned++;
        if (ports_scanned % 100 == 0) {
            printf("Scanned %d ports...\n", ports_scanned);
        }
    }

    freeaddrinfo(res);

    return EXIT_SUCCESS;
}