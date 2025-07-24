//FormAI DATASET v1.0 Category: Client Server Application ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_CLIENTS 10
#define MAX_BUFFER_SIZE 1024

typedef struct {
    int port;
    int max_clients;
    char config_file[100];
} config_t;

int read_config(config_t *config) {
    char buffer[MAX_BUFFER_SIZE];
    char *token;

    FILE *file = fopen(config->config_file, "r");

    if (file == NULL) {
        printf("Could not open configuration file %s: %s\n", config->config_file, strerror(errno));
        return -1;
    }

    while (fgets(buffer, MAX_BUFFER_SIZE, file)) {
        if (buffer[0] == '#') { // skip comments
            continue;
        }

        token = strtok(buffer, "=");

        if (strcmp(token, "port") == 0) {
            config->port = atoi(strtok(NULL, "="));
        } else if (strcmp(token, "max_clients") == 0) {
            config->max_clients = atoi(strtok(NULL, "="));
        }
    }

    fclose(file);

    return 0;
}

int main(int argc, char const *argv[]) {
    int server_fd, client_fd;
    int valread;
    struct sockaddr_in server_address;
    int addrlen = sizeof(server_address);
    char buffer[MAX_BUFFER_SIZE] = {0};
    char *hello_message = "Hello from server!";
    config_t config;

    // Default configuration
    config.port = 8080;
    config.max_clients = MAX_CLIENTS;
    strcpy(config.config_file, "config.txt");

    // Read configuration from file (if passed as argument)
    if (argc > 1) {
        printf("Reading configuration from file %s\n", argv[1]);
        strcpy(config.config_file, argv[1]);
        read_config(&config);
    }

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(config.port);

    // Bind server socket to address
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, config.max_clients) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d\n", config.port);

    while (1) {
        // Accept incoming connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&server_address, (socklen_t *)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Handle incoming message
        valread = read(client_fd, buffer, MAX_BUFFER_SIZE);
        printf("Received message: %s\n", buffer);
        send(client_fd, hello_message, strlen(hello_message), 0);

        close(client_fd);
    }

    return 0;
}