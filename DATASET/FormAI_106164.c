//FormAI DATASET v1.0 Category: Port Scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    char *hostname;
    int start_port, end_port, sock, conn_status;
    struct hostent *host;
    struct sockaddr_in addr;

    printf("Enter hostname: ");
    scanf("%s", hostname);
    host = gethostbyname(hostname);

    printf("Enter starting port number: ");
    scanf("%d", &start_port);

    printf("Enter ending port number: ");
    scanf("%d", &end_port);

    for (int port = start_port; port <= end_port; port++) {
        memset(&addr, 0, sizeof(struct sockaddr_in));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        bcopy((char *) host->h_addr, &addr.sin_addr.s_addr, host->h_length);

        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            printf("Socket creation error!");
            exit(1);
        }

        conn_status = connect(sock, (struct sockaddr *) &addr, sizeof(addr));
        if (conn_status == 0) {
            printf("Port %d is open!\n", port);
        }

        close(sock);
    }

    printf("\nAll ports have been scanned!");

    return 0;
}