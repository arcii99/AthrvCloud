//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *host = "localhost";
    char buffer[1024] = {0};
    char command[100] = {0};

    // Create socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    // Set server information
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, host, &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sock);
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        return -1;
    }

    // Enter command loop
    while (1) {
        printf("CyberTerminal:> ");
        fgets(command, 100, stdin);
        command[strcspn(command, "\n")] = '\0'; // Remove newline character

        // Send command to server
        send(sock, command, strlen(command), 0);

        // Receive response from server
        valread = read(sock, buffer, 1024);
        buffer[valread] = '\0'; // Set null terminator

        // Print response to terminal
        printf("Server Response: %s\n", buffer);
    }

    // Close socket connection
    close(sock);
    
    return 0;
}