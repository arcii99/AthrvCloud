//FormAI DATASET v1.0 Category: Socket programming ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_MESSAGES 10

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char messages[MAX_MESSAGES][1024];
    int msg_idx = 0;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding socket with the specified port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accepting incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Server loop
    while(1) {
        // Receiving message from client
        valread = read(new_socket, buffer, 1024);

        // Storing the message in messages array
        strncpy(messages[msg_idx++], buffer, 1024);
        if (msg_idx == MAX_MESSAGES) {
            msg_idx = 0;
        }

        // Printing the last 10 messages
        printf("===== Last 10 Messages =====\n");
        for (int i = 0; i < MAX_MESSAGES; i++) {
            if (strlen(messages[i]) > 0) {
                printf("%s", messages[i]);
            }
        }
        printf("============================\n");

        // Sending response to client
        char *response_message = "Message received successfully\n";
        send(new_socket, response_message, strlen(response_message), 0);

        // Clearing the buffer
        memset(buffer, 0, 1024);
        usleep(500000);
    }
    return 0;
}