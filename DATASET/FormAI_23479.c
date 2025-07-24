//FormAI DATASET v1.0 Category: Chat server ; Style: Claude Shannon
/* Welcome to the Shannon Chat Server!*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

typedef struct {
    char message[1024];
} Message;

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int socket_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    Message message;
    char buffer[1024];

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        error("Error opening socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("Error binding socket");
    }

    if (listen(socket_fd, 1) < 0) {
        error("Error listening to socket");
    }

    printf("Shannon Chat Server is running on port %d...\n", PORT);

    client_fd = accept(socket_fd, (struct sockaddr *) &client_addr, &addr_len);
    if (client_fd < 0) {
        error("Error accepting client");
    }

    printf("Connected to client %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    while (1) {
        memset(&message, 0, sizeof(message));
        memset(buffer, 0, sizeof(buffer));
        if (read(client_fd, buffer, sizeof(buffer)) < 0) {
            error("Error reading from client");
        }
        strncpy(message.message, buffer, sizeof(message.message));
        printf("Message from client: %s\n", message.message);

        printf("Enter your message: ");
        fgets(message.message, sizeof(message.message), stdin);

        if (write(client_fd, message.message, strlen(message.message)) < 0) {
            error("Error writing to client");
        }
    }

    close(client_fd);
    close(socket_fd);
    return 0;
}