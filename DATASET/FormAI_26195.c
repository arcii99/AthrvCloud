//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char message[1024] = {0};
    char *hello = "Hello from the other side";

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Oh no! Socket creation error , are you connected to the internet?\n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("Ha! Invalid address/ Address not supported, don't worry, please try again\n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Oops! Connection Failed, make sure you have the right port\n");
        return -1;
    }

    send(sock, hello, strlen(hello), 0);
    printf("Delivered! I just said, '%s'\n", hello);
    read(sock, message, 1024);
    printf("Server Replied: '%s'\n", message);
    printf("You have completed the TCP/IP Programming assignment! You rock! Now go treat yourself, maybe with a cookie🍪\n");
    return 0;
}