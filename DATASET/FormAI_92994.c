//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is waiting for incoming connections...\n");

    struct sockaddr_in client_addr;
    int client_sock = accept(sock, (struct sockaddr *)&client_addr, (socklen_t*)&client_addr);

    if (client_sock < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    char *message = "Hello! This is mind-bending server.\n";
    write(client_sock, message, strlen(message));

    char client_message[2000];
    int read_size;

    while ((read_size = recv(client_sock, client_message, 2000, 0)) > 0) {
        printf("Received message from client: %s\n", client_message);
        if (strcmp(client_message, "exit\n") == 0) {
            char *message = "Goodbye!\n";
            write(client_sock, message, strlen(message));
            break;
        }
        write(client_sock, client_message, strlen(client_message));
        memset(client_message, 0, 2000);
    }

    if (read_size == 0) {
        printf("Client disconnected.\n");
    }
    else if (read_size == -1) {
        perror("recv failed");
    }

    close(client_sock);
    close(sock);

    return 0;
}