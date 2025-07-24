//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: recursive
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

// Recursive function to send and receive messages between the client and server
void communicate(int sockfd, char* buffer) {
    memset(buffer, 0, BUFFER_SIZE); // clear the buffer
    printf("Enter a message: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    // Send the message to the server
    write(sockfd, buffer, strlen(buffer));

    // Receive the response from the server
    int message_size = read(sockfd, buffer, BUFFER_SIZE);
    if (message_size > 0) {
        buffer[message_size] = '\0'; // ensure buffer is null terminated
        printf("Received message: %s\n", buffer);
        communicate(sockfd, buffer); // recursive call to keep the communication going
    } else {
        printf("Error: Failed to receive message\n");
    }
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // localhost
    server_address.sin_port = htons(8080); // port to connect to

    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    communicate(sockfd, buffer); // start the recursive communication

    close(sockfd);
    return 0;
}