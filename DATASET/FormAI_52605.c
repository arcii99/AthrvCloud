//FormAI DATASET v1.0 Category: Port Scanner ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s IP_Address\n", argv[0]);
        exit(1);
    }

    struct sockaddr_in target;
    int start_port = 1, end_port = 1024;
    int sock, res, i;
    char *host = argv[1];

    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(argv[1]);

    for(i=start_port;i<=end_port;i++) {
        sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if(sock == -1) {
            perror("Socket error.");
            exit(1);
        }

        target.sin_port = htons(i);
        res = connect(sock, (struct sockaddr *)&target, sizeof(target));

        if(res == 0) {
            printf("Port %d is open.\n", i);
        }
        close(sock);
    }
    return 0;
}