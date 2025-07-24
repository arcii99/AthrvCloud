//FormAI DATASET v1.0 Category: Port Scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *host = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);
    struct sockaddr_in target;
    int sock;

    if(argc != 4) {
        printf("\nInvalid arguments! Usage: ./port_scanner <IP> <starting port> <ending port>\n");
        exit(1);
    }

    printf("\nLet's see which ports are open on %s...\n", host);

    for(int port=start_port; port<=end_port; port++) {
        // create TCP socket
        sock = socket(AF_INET , SOCK_STREAM , 0);
        if (sock == -1) {
            printf("Could not create socket");
            continue;
        }

        target.sin_family = AF_INET;
        target.sin_addr.s_addr = inet_addr(host);
        target.sin_port = htons(port);

        // connect to the target
        if (connect(sock , (struct sockaddr *)&target , sizeof(target)) < 0 ) {
            close(sock);
            continue;
        }

        // print out result
        printf("Port %d is open! \n", port);

        close(sock);
    }

    printf("\nPort scanning complete!\n");

    return 0;
}