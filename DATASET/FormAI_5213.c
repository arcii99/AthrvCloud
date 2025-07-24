//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAXSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Invalid Arguments\n");
        printf("Usage: ./ftpclient <IP> <Port>\n");
        return -1;
    }
    char *serverIP = argv[1];
    int port = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(serverIP);
    serverAddr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
        printf("Failed to Connect to Server\n");
        return -1;
    }

    printf("Connected to %s:%d\n", serverIP, port);

    char command[MAXSIZE];
    printf("Enter FTP Command: ");
    fgets(command, MAXSIZE, stdin);
    command[strcspn(command, "\n")] = 0;

    send(sock, command, strlen(command), 0);

    char response[MAXSIZE];
    int len = recv(sock, response, MAXSIZE, 0);
    response[len] = '\0';
    printf("%s\n", response);

    close(sock);

    return 0;
}