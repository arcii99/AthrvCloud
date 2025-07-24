//FormAI DATASET v1.0 Category: Networking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char message[1000];
    char server_reply[2000];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
    }

    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection error");
        return 1;
    }

    printf("Connected to Server\n");

    while(1) {
        printf("Enter message: ");
        fgets(message, 1000, stdin);

        if(send(sock, message, strlen(message), 0) < 0) {
            perror("Send failed");
            return 1;
        }

        if(recv(sock, server_reply, 2000, 0) < 0) {
            perror("Receive failed");
            break;
        }

        printf("Server Reply: %s\n", server_reply);
        memset(server_reply, 0, sizeof(server_reply));
    }

    close(sock);
    return 0;
}