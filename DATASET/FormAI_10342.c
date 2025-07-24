//FormAI DATASET v1.0 Category: Port Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_PORT 65535
#define TIMEOUT_SEC 2

void usage(char *progname);
int scan_port(char *hostname, int portno);

int main(int argc, char *argv[]) {
    int opt;
    char *hostname;
    int start_port = 1;
    int end_port = MAX_PORT;

    // Parse command line arguments
    while ((opt = getopt(argc, argv, "h:s:e:")) != -1) {
        switch (opt) {
            case 'h':
                hostname = optarg;
                break;
            case 's':
                start_port = atoi(optarg);
                if (start_port < 1 || start_port > MAX_PORT) {
                    printf("Invalid start port\n");
                    usage(argv[0]);
                }
                break;
            case 'e':
                end_port = atoi(optarg);
                if (end_port < start_port || end_port > MAX_PORT) {
                    printf("Invalid end port\n");
                    usage(argv[0]);
                }
                break;
            default:
                usage(argv[0]);
        }
    }

    // Check if hostname argument was provided
    if (hostname == NULL) {
        usage(argv[0]);
    }

    // Scan ports and print open ports
    for (int port = start_port; port <= end_port; port++) {
        if (scan_port(hostname, port) == 0) {
            printf("Port %d is open\n", port);
        }
    }

    return 0;
}

void usage(char *progname) {
    printf("Usage: %s -h hostname [-s start_port] [-e end_port]\n", progname);
    exit(1);
}

int scan_port(char *hostname, int portno) {
    // Create socket and connect to host
    int sockfd = -1;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return -1;
    }

    struct hostent *host;
    if ((host = gethostbyname(hostname)) == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(portno);
    memcpy(&addr.sin_addr, host->h_addr_list[0], host->h_length);

    struct timeval timeout;
    timeout.tv_sec = TIMEOUT_SEC;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));

    if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) != 0) {
        if (errno == EINPROGRESS) {
            printf("Port %d is not open\n", portno);
            close(sockfd);
            return -1;
        }
        perror("connect");
        close(sockfd);
        return -1;
    }

    // Port is open
    close(sockfd);
    return 0;
}