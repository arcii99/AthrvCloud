//FormAI DATASET v1.0 Category: Port Scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define MAX_PORTS 65535
#define TIMEOUT 3
#define NUM_THREADS 256

void scan_port(char *ip, int port);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <ip>\n", argv[0]);
        return 1;
    }
    int i;
    printf("Scanning %s...\n", argv[1]);
    for(i=1; i<=MAX_PORTS/NUM_THREADS; i++) {
        pid_t pid = fork();
        if(pid == -1) {
            perror("fork");
            return 1;
        } else if(pid == 0) {
            int j, k;
            for(j=(i-1)*NUM_THREADS+1; j<=i*NUM_THREADS; j++) {
                scan_port(argv[1], j);
            }
            exit(0);
        }
    }
    for(i=((MAX_PORTS/NUM_THREADS)*NUM_THREADS)+1; i<=MAX_PORTS; i++) {
        scan_port(argv[1], i);
    }
    for(i=0; i<MAX_PORTS/NUM_THREADS; i++) {
        wait(NULL);
    }
    printf("Done!\n");
    return 0;
}

void scan_port(char *ip, int port) {
    int sock;
    struct sockaddr_in addr;
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(sock, &read_fds);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        perror("socket");
        exit(1);
    }
    fcntl(sock, F_SETFL, O_NONBLOCK);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_aton(ip, &addr.sin_addr);
    connect(sock, (struct sockaddr*)&addr, sizeof(addr));
    if(select(sock+1, NULL, &read_fds, NULL, &timeout) == 1) {
        int err = 0;
        socklen_t err_len = sizeof(err);
        getsockopt(sock, SOL_SOCKET, SO_ERROR, &err, &err_len);
        if(err == 0) {
            printf("Port %d is open\n", port);
        }
    }
    close(sock);
}