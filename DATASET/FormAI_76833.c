//FormAI DATASET v1.0 Category: Port Scanner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 1024

void print_usage(char *name)
{
    printf("Usage: %s <target>\n", name);
}

int main(int argc, char *argv[])
{
    char *target;
    int sockfd, i, num_ports = 0;
    struct sockaddr_in dest;

    if (argc < 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    target = argv[1];

    if (inet_aton(target, &dest.sin_addr) == 0) {
        printf("Invalid IP address: %s\n", target);
        return EXIT_FAILURE;
    }

    dest.sin_family = AF_INET;

    for (i = 1; i <= MAX_PORTS; i++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockfd < 0) {
            perror("socket");
            return EXIT_FAILURE;
        }

        dest.sin_port = htons(i);

        if (connect(sockfd, (struct sockaddr *)&dest, sizeof(dest)) == 0) {
            printf("Port %d is open\n", i);
            num_ports++;
        }

        close(sockfd);
    }

    printf("Scan complete. %d port(s) open on %s\n", num_ports, target);

    return EXIT_SUCCESS;
}