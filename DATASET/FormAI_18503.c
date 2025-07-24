//FormAI DATASET v1.0 Category: Socket programming ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_MSG_LEN 1024

int main(int argc, char const *argv[]) {
    int sock = 0;
    struct sockaddr_in server_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\nSocket creation error\n");
        return -1;
    }

    memset(&server_addr, '0', sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported\n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("\nConnection Failed\n");
        return -1;
    }

    char message[MAX_MSG_LEN] = {0};

    printf("Enter message: ");
    fgets(message, MAX_MSG_LEN, stdin);

    if (send(sock, message, strlen(message), 0) < 0) {
        printf("\nSend Failed\n");
        return -1;
    }

    printf("Message sent: %s\n", message);

    char buffer[MAX_MSG_LEN] = {0};
    if (read(sock, buffer, MAX_MSG_LEN) < 0) {
        printf("\nRead Failed\n");
        return -1;
    }

    printf("Server response: %s\n", buffer);

    close(sock);

    return 0;
}