//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: medieval
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define HOST "imap.gmail.com"
#define PORT 993

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;

    server.sin_addr.s_addr = inet_addr(HOST);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connect failed");
        return 1;
    }

    char buffer[1024];
    int count = recv(sock, buffer, sizeof(buffer), 0);
    if (count >= 0) {
        buffer[count] = '\0';
        printf("Received: %s", buffer);
    }

    close(sock);
    return 0;
}