//FormAI DATASET v1.0 Category: Networking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG_SIZE 4096
#define PORT 8080

int main(int argc, char const *argv[]) {
    int sock = 0, read_val;
    struct sockaddr_in serv_addr;
    char buffer[MAX_MSG_SIZE] = {0};

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPV4 and IPV6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        exit(EXIT_FAILURE);
    }

    // Establishing connection with the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Starting chat
    printf("Chat started...\n");

    while (1) {
        printf("You: ");
        fgets(buffer, MAX_MSG_SIZE, stdin);
        send(sock, buffer, strlen(buffer), 0);
        memset(buffer, 0, sizeof(buffer));

        read_val = read(sock, buffer, MAX_MSG_SIZE);
        buffer[read_val] = '\0';
        printf("Server: %s", buffer);
    }

    close(sock);

    return 0;
}