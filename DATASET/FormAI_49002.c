//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUF_SIZE 1024
#define BACKLOG 5
#define PORT 8080

void * handle_request(void *arg) {
    int client_sock = (int)(long)arg;
    char buffer[BUF_SIZE];

    // Read the client request
    if (read(client_sock, buffer, BUF_SIZE) < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    // Extract the host and port from the request
    char *host_start = strstr(buffer, "Host:") + 6;
    char *host_end = strstr(host_start, "\r\n");
    char *port_start = strchr(host_start, ':');
    char *port_end = strstr(host_start, "\r\n");
    int port = 80; // Default HTTP port

    if (port_start != NULL) {
        port = atoi(port_start + 1);
        *port_end = 0;
    }

    // Connect to the remote server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, host_start, &serv_addr.sin_addr) <= 0) {
        perror("ERROR converting IP address");
        exit(1);
    }

    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    if (server_sock < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    if (connect(server_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting to remote server");
        exit(1);
    }

    // Forward the client request to the remote server
    if (write(server_sock, buffer, strlen(buffer)) < 0) {
        perror("ERROR writing to remote server");
        exit(1);
    }

    // Forward the response from the remote server to the client
    while (1) {
        int bytes_read = read(server_sock, buffer, BUF_SIZE);

        if (bytes_read < 0) {
            perror("ERROR reading from remote server");
            exit(1);
        } else if (bytes_read == 0) {
            break;
        }

        if (write(client_sock, buffer, bytes_read) < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
    }

    // Close the sockets
    close(client_sock);
    close(server_sock);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int server_sock, client_sock;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_len = sizeof(cli_addr);
    pthread_t threads[BACKLOG];

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    if (listen(server_sock, BACKLOG) < 0) {
        perror("ERROR on listening");
        exit(1);
    }

    printf("Proxy server started on port %d...\n", PORT);

    while (1) {
        client_sock = accept(server_sock, (struct sockaddr *)&cli_addr, &cli_len);

        if (client_sock < 0) {
            perror("ERROR on accept");
            continue;
        }

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_request, (void *)(long)client_sock) < 0) {
            perror("ERROR creating thread");
            close(client_sock);
            continue;
        }

        // Detach the thread so its resources can be automatically cleaned up
        pthread_detach(thread_id);
    }

    close(server_sock);

    return 0;
}