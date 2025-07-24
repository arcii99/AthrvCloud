//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: multi-threaded
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_NUMBER 12345
#define BUFFER_SIZE 4096

void *handle_client(void *);

int main(int argc, char *argv[]) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Failed to create socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT_NUMBER);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to bind socket\n");
        return 1;
    }

    if (listen(server_socket, 5) == -1) {
        printf("Failed to listen to socket\n");
        return 1;
    }

    printf("Server listening on port %d...\n", PORT_NUMBER);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_size);
        if (client_socket == -1) {
            printf("Failed to accept new connection\n");
            continue;
        }

        pthread_t client_thread;
        if (pthread_create(&client_thread, NULL, handle_client, (void *) client_socket) != 0) {
            printf("Failed to create client thread\n");
            continue;
        }

        printf("New client connected\n");
    }

    close(server_socket);

    return 0;
}

void *handle_client(void *arg) {
    int client_socket = (int) arg;
    char buffer[BUFFER_SIZE];
    ssize_t n_read;

    while ((n_read = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        if (send(client_socket, buffer, n_read, 0) == -1) {
            printf("Failed to send data to client\n");
            break;
        }
    }

    close(client_socket);
    return NULL;
}