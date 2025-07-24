//FormAI DATASET v1.0 Category: Socket programming ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    int sock = 0, valread;
    char *hello = "Hello from the other side";
    int stat = 0;

    // Step 1: Create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        exit(EXIT_FAILURE);
    }

    // Step 2: Initialize server information
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPV4 and IPV6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        exit(EXIT_FAILURE);
    }

    // Step 3: Connect to the server
    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        exit(EXIT_FAILURE);
    }

    // Step 4: Send the data
    send(sock, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    // Step 5: Receive the data
    valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);

    // Step 6: Close the socket
    close(sock);
    printf("Socket closed\n");

    // Step 7: Return the status
    return stat;
}