//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Romeo and Juliet
// Romeo and Juliet Style POP3 Client Example
// By: The AI Chatbot

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    int sock = 0, bytes_read = 0;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE] = {0};

    // "But, soft! what light through yonder window breaks?
    // It is the east, and Juliet is the sun."
    printf("POP3 Client: Initializing...\n");
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("POP3 Client: Error creating socket");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(110);

    // "Arise, fair sun, and kill the envious moon,
    // Who is already sick and pale with grief"
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("POP3 Client: Invalid address / Address not supported");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("POP3 Client: Connection failed");
        exit(EXIT_FAILURE);
    }
    
    // "O, speak again, bright angel! for thou art
    // As glorious to this night, being o'er my head"
    printf("POP3 Client: Connected to server...\n");
    bytes_read = read(sock, buffer, BUFFER_SIZE);
    if (bytes_read < 0) {
        perror("POP3 Client: Error reading from server");
        exit(EXIT_FAILURE);
    }

    // "Two of the fairest stars in all the heaven,
    // Having some business, do entreat her eyes"
    printf("POP3 Server: %s\n", buffer);
    bzero(buffer, BUFFER_SIZE);

    // "With love's light wings did I o'erperch these walls,
    // For stony limits cannot hold love out"
    char user_cmd[] = "USER example@domain.com\r\n";
    if (send(sock, user_cmd, strlen(user_cmd), 0) < 0) {
        perror("POP3 Client: Error sending username to server");
        exit(EXIT_FAILURE);
    }

    bytes_read = read(sock, buffer, BUFFER_SIZE);
    if (bytes_read < 0) {
        perror("POP3 Client: Error reading from server");
        exit(EXIT_FAILURE);
    }

    // "What's in a name? that which we call a rose
    // By any other name would smell as sweet"
    printf("POP3 Server: %s\n", buffer);
    bzero(buffer, BUFFER_SIZE);

    // "O, swear not by the moon, the inconstant moon,
    // That monthly changes in her circled orb,
    // Lest that thy love prove likewise variable."
    char pass_cmd[] = "PASS password123\r\n";
    if (send(sock, pass_cmd, strlen(pass_cmd), 0) < 0) {
        perror("POP3 Client: Error sending password to server");
        exit(EXIT_FAILURE);
    }

    bytes_read = read(sock, buffer, BUFFER_SIZE);
    if (bytes_read < 0) {
        perror("POP3 Client: Error reading from server");
        exit(EXIT_FAILURE);
    }

    // "Good night, good night! parting is such
    // Sweet sorrow, that I shall say good night
    // Till morrow."
    printf("POP3 Server: %s\n", buffer);
    bzero(buffer, BUFFER_SIZE);

    close(sock);
    printf("POP3 Client: Disconnected from server...\n");

    // "For never was a story of more woe
    // Than this of Juliet and her Romeo."
    return 0;
}