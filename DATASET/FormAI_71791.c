//FormAI DATASET v1.0 Category: Port Scanner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    //check command-line arguments
    if (argc != 2) {
        printf("\nUsage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    //create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("\nCould not create socket\n");
        exit(1);
    }

    //set up address structure
    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_port = htons(0); //set to 0 to let system choose automatically
    inet_pton(AF_INET, argv[1], &(target.sin_addr));

    //connect to target
    int status = connect(sock, (struct sockaddr *)&target, sizeof(target));
    if (status < 0) {
        printf("\nFailed to connect to target\n");
        exit(1);
    }

    //get port information
    struct sockaddr_in local;
    socklen_t len = sizeof(local);
    status = getsockname(sock, (struct sockaddr *)&local, &len);
    if (status < 0) {
        printf("\nError getting port information\n");
        exit(1);
    }

    printf("\nConnected to port %d on host %s\n", ntohs(local.sin_port), argv[1]);

    //scan ports
    for (int i = 1; i <= 65535; i++) {
        struct sockaddr_in test;
        test.sin_family = AF_INET;
        test.sin_port = htons(i);
        inet_pton(AF_INET, argv[1], &(test.sin_addr));
        int sock2 = socket(AF_INET, SOCK_STREAM, 0);
        status = connect(sock2, (struct sockaddr *)&test, sizeof(test));
        if (status == 0) {
            printf("\nPort %d is open\n", i);
            close(sock2);
        }
    }

    //close socket
    close(sock);

    return 0;
}