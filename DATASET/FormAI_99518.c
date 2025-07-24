//FormAI DATASET v1.0 Category: Port Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
    struct sockaddr_in serverAddr;
    int sock, i, j, start_port, end_port;
    char targetIP[20], target[50];

    if (argc < 2) {
        printf("Usage: %s targetIP [start port] [end port]", argv[0]);
        exit(1);
    }
    strcpy(targetIP, argv[1]);
    sprintf(target, "%s", targetIP);

    if (argc == 2)
        start_port = 1, end_port = 65535;
    else if (argc == 3)
        start_port = atoi(argv[2]), end_port = 65535;
    else
        start_port = atoi(argv[2]), end_port = atoi(argv[3]);

    printf("Scanning %s ...\n", targetIP);
    for (i = start_port; i <= end_port; i++) {
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
            perror("socket");

        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(i);
        serverAddr.sin_addr.s_addr = inet_addr(targetIP);

        if (connect(sock, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) == 0)
            printf("[+] %s:%d open\n", target, i);

        close(sock);
    }
    printf("Scan finished\n");
    return 0;
}