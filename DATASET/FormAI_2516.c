//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char **argv){
    int sock, count;
    struct sockaddr_in sin;
    struct hostent *host;
    int start, end, port;

    if (argc < 2){
        printf("Please provide an IP address\n");
        return 0;
    }

    if ((host = gethostbyname(argv[1])) == NULL){
        printf("Could not resolve %s\n", argv[1]);
        return 0;
    }

    sin.sin_family = AF_INET;
    bcopy(host->h_addr, &(sin.sin_addr.s_addr), host->h_length);

    start = 0;
    end = 1024;
    port = start;

    for (port = start; port <= end; port++){
        sock = socket(AF_INET, SOCK_STREAM, 0);
        sin.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) == 0){
            printf("Port %d is open\n", port);
            close(sock);
        }
    }

    printf("Scan complete\n");

    return 0;
}