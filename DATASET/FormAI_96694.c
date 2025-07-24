//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <subnet>\n", argv[0]);
        exit(1);
    }

    struct in_addr addr;
    if (inet_aton(argv[1], &addr) == 0) {
        fprintf(stderr, "Invalid subnet: %s\n", argv[1]);
        exit(1);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_port = htons(80);

    int num_hosts = 0;

    for (unsigned char host = 1; host != 0; ++host) {
        addr.s_addr &= 0xff000000;
        addr.s_addr |= host;

        target.sin_addr = addr;

        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) != -1) {
            printf("%s\n", inet_ntoa(addr));
            ++num_hosts;
        }
    }

    printf("Scanning %s finished, %d hosts up\n", argv[1], num_hosts);

    close(sock);

    return 0;
}