//FormAI DATASET v1.0 Category: Port Scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <ip address>\n", argv[0]);
        exit(0);
    }
    struct sockaddr_in target;
    int sd;
    int start_port = 1, end_port = 65535;
    int curr_port = 0;
    int open_ports = 0;

    // Create a socket
    sd = socket(AF_INET, SOCK_STREAM, 0);
    if(sd < 0) {
        perror("socket() error");
        exit(-1);
    }

    // Set target IP and family
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(argv[1]);

    // Iterate over possible port range and scan for open ports
    printf("Scanning ports %d-%d on %s...\n", start_port, end_port, argv[1]);
    for(curr_port = start_port; curr_port <= end_port; curr_port++) {
        target.sin_port = htons(curr_port);
        if(connect(sd, (struct sockaddr *)&target, sizeof(target)) == 0) {
            open_ports++;
            printf("[+] Port %d is open\n", curr_port);
        }
        close(sd); // reset socket for the next iteration
        sd = socket(AF_INET, SOCK_STREAM, 0);
        if(sd < 0) {
            perror("socket() error");
            exit(-1);
        }
    }
    printf("Scan complete! Found %d open ports\n", open_ports);
    return 0;
}