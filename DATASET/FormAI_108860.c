//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define server_addr "mail.example.com"
#define server_port 993
#define BUF_SIZE 1024

int main() {
    int sock, bytes_recv;
    struct sockaddr_in server;
    char buf[BUF_SIZE];
    char username[] = "example@email.com";
    char password[] = "password123";

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket.");
        exit(1);
    }

    printf("Socket created successfully.\n");

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_addr);
    server.sin_port = htons(server_port);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Could not connect to server.");
        exit(1);
    }

    printf("Connected to server successfully.\n");

    bytes_recv = recv(sock, buf, BUF_SIZE, 0);

    printf("%s\n", buf);

    sprintf(buf, "A001 LOGIN %s %s\r\n", username, password);
    send(sock, buf, strlen(buf), 0);

    bytes_recv = recv(sock, buf, BUF_SIZE, 0);

    printf("%s\n", buf);

    sprintf(buf, "A002 LIST \"\" *\r\n");
    send(sock, buf, strlen(buf), 0);

    bytes_recv = recv(sock, buf, BUF_SIZE, 0);

    printf("%s\n", buf);

    sprintf(buf, "A003 LOGOUT\r\n");
    send(sock, buf, strlen(buf), 0);

    bytes_recv = recv(sock, buf, BUF_SIZE, 0);

    printf("%s\n", buf);

    close(sock);

    printf("Disconnected from server.\n");

    return 0;
}