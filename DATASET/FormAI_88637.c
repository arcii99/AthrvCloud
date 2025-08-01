//FormAI DATASET v1.0 Category: Client Server Application ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *hello = "Hello from server";
    
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Connection established\n");

    while (1) {
        memset(buffer, 0, sizeof(buffer));

        int valread = read(new_socket, buffer, BUFFER_SIZE);

        if (valread == 0) {
            printf("Client disconnected\n");
            break;
        }

        printf("Client says: %s\n", buffer);

        if (strcmp(buffer, "quit") == 0) {
            printf("Closing connection...\n");
            break;
        }

        send(new_socket, hello, strlen(hello), 0);
    }

    close(new_socket);
    close(server_fd);

    return 0;
}