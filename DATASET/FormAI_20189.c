//FormAI DATASET v1.0 Category: Socket programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080

struct Message {
    char sender[30];
    char receiver[30];
    char content[200];
};

int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from the other side";
    char buffer[1024] = {0};
    struct Message message;

    // create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\nSocket creation error\n");
        exit(EXIT_FAILURE);
    }

    // set up the server address
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported\n");
        exit(EXIT_FAILURE);
    }

    // establish connection with the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed\n");
        exit(EXIT_FAILURE);
    }

    // send a message to the server
    send(sock, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    // receive a response from the server
    valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);

    // send a message from one user to another user
    strcpy(message.sender, "Alice");
    strcpy(message.receiver, "Bob");
    strcpy(message.content, "Hey Bob, what's up?");
    send(sock, &message, sizeof(message), 0);
    printf("Message sent to %s\n", message.receiver);

    // close the socket
    close(sock);
    return 0;
}