//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    char message[BUFFER_SIZE] = {0};

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket\n");
        return -1;
    }

    // Setup server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) != 0) {
        printf("Could not connect to server\n");
        return -1;
    }

    // Send message to server
    strcpy(message, "Hello, World!");
    send(sock, message, strlen(message), 0);
    printf("Message sent: %s\n", message);
    memset(message, 0, sizeof(message)); // Clear message buffer

    // Receive message from server
    int valread = read(sock, buffer, BUFFER_SIZE);
    printf("Message received: %s\n", buffer);
    memset(buffer, 0, sizeof(buffer)); // Clear buffer

    // Close socket
    close(sock);
    return 0;
}