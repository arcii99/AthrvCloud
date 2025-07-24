//FormAI DATASET v1.0 Category: Port Scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORT 65535

int main(int argc, char *argv[]) {
    char *ip = argv[1];
    int ports[MAX_PORT+1];
    memset(ports, 0, sizeof(ports));
    
    int i, j, sock;
    struct sockaddr_in dest;
    for (i = 1; i < MAX_PORT; i++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            perror("socket()");
            exit(EXIT_FAILURE);
        }
        
        dest.sin_family = AF_INET;
        dest.sin_addr.s_addr = inet_addr(ip);
        dest.sin_port = htons(i);

        j = connect(sock, (struct sockaddr *)&dest, sizeof(dest));
        if (j == 0) {
            printf("Port %d - OPEN\n", i);
            ports[i] = 1;
        }

        close(sock);
    }

    printf("Open ports on %s:\n", ip);
    for (i = 1; i <= MAX_PORT; i++) {
        if (ports[i] != 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}