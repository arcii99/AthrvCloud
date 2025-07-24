//FormAI DATASET v1.0 Category: Socket programming ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    char sendMessage[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return EXIT_FAILURE;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        perror("Invalid address/ Address not supported");
        return EXIT_FAILURE;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        return EXIT_FAILURE;
    }

    while(1) {
        printf("Enter message: ");
        scanf("%[^\n]s", sendMessage);
        getchar();
        send(sock, sendMessage, strlen(sendMessage), 0);
        printf("Message sent\n");
        valread = read(sock , buffer, 1024);
        printf("%s\n",buffer);
        memset(sendMessage, 0, sizeof(sendMessage));
        memset(buffer, 0, sizeof(buffer));
    }
    return EXIT_SUCCESS;
}