//FormAI DATASET v1.0 Category: Firewall ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFLEN 64

#define ALLOWED_IPS "allowed_ips.conf"

#define PORT 12345

int main(void) {
    int fd, nfds, len, i, optval;
    fd_set readfds;
    struct sockaddr_in serv_addr, cli_addr;
    char buf[BUFLEN];

    // Open socket
    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    // Set options
    optval = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int));
    fcntl(fd, F_SETFL, O_NONBLOCK);

    // Bind to port
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);
    if (bind(fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding to port");
        exit(EXIT_FAILURE);
    }

    // Open allowed ips file
    FILE *allowed_ips_file = fopen(ALLOWED_IPS, "r");
    if(allowed_ips_file == NULL) {
        perror("Error opening allowed ips file");
        exit(EXIT_FAILURE);
    }

    // Get allowed ips
    char allowed_ips[BUFLEN];
    fgets(allowed_ips, BUFLEN, allowed_ips_file);
    fclose(allowed_ips_file);

    // Create array of allowed ips
    char *allowed_ips_arr[BUFLEN];
    int num_allowed_ips = 0;
    char *p = strtok(allowed_ips, ",");
    while(p != NULL) {
        allowed_ips_arr[num_allowed_ips++] = p;
        p = strtok(NULL, ",");
    }

    printf("Listening for UDP packets on port %d\n", PORT);

    while(1) {
        FD_ZERO(&readfds);
        FD_SET(fd, &readfds);

        nfds = select(fd+1, &readfds, NULL, NULL, NULL);
        if(nfds < 0) {
            if(errno != EINTR) {
                perror("Error selecting");
                exit(EXIT_FAILURE);
            } else {
                continue;
            }
        }

        if(FD_ISSET(fd, &readfds)) {
            len = sizeof(cli_addr);

            // Receive packet
            if(recvfrom(fd, buf, BUFLEN, 0, (struct sockaddr *) &cli_addr, &len) < 0) {
                perror("Error receiving packet");
                continue;
            }

            // Convert client IP to string
            char cli_ip[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &cli_addr.sin_addr, cli_ip, INET_ADDRSTRLEN);

            // Check if client IP is allowed
            int allowed = 0;
            for(i = 0; i < num_allowed_ips; i++) {
                if(strcmp(allowed_ips_arr[i], cli_ip) == 0) {
                    allowed = 1;
                }
            }

            if(allowed) {
                // Packet is allowed, forward it
                printf("Forwarding packet from %s\n", cli_ip);
                // Forward packet here
            } else {
                // Packet is not allowed, drop it
                printf("Dropping packet from %s\n", cli_ip);
            }
        }
    }

    // Close socket
    close(fd);

    return 0;
}