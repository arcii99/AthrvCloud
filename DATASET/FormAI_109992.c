//FormAI DATASET v1.0 Category: Client Server Application ; Style: Cyberpunk
// CYBERPUNK CLIENT-SERVER APPLICATION

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8888
#define BUFFER_SIZE 1024

int main() {

    int socket_fd, client_fd, val_read;
    struct sockaddr_in server_address;

    char buffer[BUFFER_SIZE] = {0};
    char response[] = "*** WELCOME TO THE CYBERPUNK SERVER ***\n";

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("ERROR: SOCKET CREATION FAILED");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("ERROR: BINDING FAILED");
        exit(EXIT_FAILURE);
    }

    if (listen(socket_fd, 3) < 0) {
        printf("ERROR: LISTENING FAILED");
        exit(EXIT_FAILURE);
    }

    printf("CYBERPUNK SERVER LISTENING ON PORT %d...\n", PORT);

    while (1) {
        client_fd = accept(socket_fd, (struct sockaddr *)&server_address, (socklen_t*)&server_address);
        if (client_fd < 0) {
            printf("ERROR: ACCEPT FAILED");
            exit(EXIT_FAILURE);
        }

        send(client_fd, response, strlen(response), 0);

        val_read = read(client_fd, buffer, BUFFER_SIZE);
        printf("RECEIVED MESSAGE FROM CLIENT: %s\n", buffer);
        memset(buffer, 0, BUFFER_SIZE);

        snprintf(buffer, BUFFER_SIZE, "ACKNOWLEDGED: %s", buffer);
        send(client_fd, buffer, strlen(buffer), 0);

        close(client_fd);
    }

    return 0;
}