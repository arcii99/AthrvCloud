//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main() {
    int client_socket;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE] = { 0 };

    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(client_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        return -1;
    }

    // Setup server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Invalid server address");
        return -1;
    }

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        return -1;
    }

    while (1) {
        // Generate random message
        srand(time(0));
        int message_size = rand() % BUFFER_SIZE + 1;
        for (int i = 0; i < message_size; i++) {
            buffer[i] = rand() % 26 + 'a';
        }

        // Send message
        if (send(client_socket, buffer, strlen(buffer), 0) == -1) {
            perror("Send failed");
            return -1;
        }

        // Receive response
        if (recv(client_socket, buffer, BUFFER_SIZE, 0) == -1) {
            perror("Receive failed");
            return -1;
        }

        // Print response
        printf("Response received: %s\n", buffer);

        // Wait for random time
        int wait_time = rand() % 10 + 1;
        printf("Waiting for %d seconds...\n", wait_time);
        sleep(wait_time);
    }

    // Close socket
    close(client_socket);

    return 0;
}