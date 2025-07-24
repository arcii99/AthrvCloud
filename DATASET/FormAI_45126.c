//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Sherlock Holmes
/* "The Adventure of the TCP/IP Client" - a Sherlock Holmes Programming Tale */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define SERVER_PORT 8080

int main(int argc, char *argv[]) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from the client side!";
    char buffer[1024] = {0};

    // Step 1: Open the socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }

    // Step 2: Set server address and port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);

    // Convert the IP address from string to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        return -1;
    }

    // Step 3: Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Could not connect to server\n");
        return -1;
    }

    // Step 4: Send a message to the server
    send(sock, hello, strlen(hello), 0);
    printf("Client: %s\n", hello);

    // Step 5: Receive server's response and display it
    int valread = read(sock, buffer, 1024);
    printf("Server: %s\n", buffer);

    // Step 6: Close the socket
    close(sock);
    printf("\nConnection to server closed\n");

    return 0;
}