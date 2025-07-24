//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int proxy_fd, cli_fd, read_size;
    struct sockaddr_in proxy_addr, cli_addr;
    char buf[BUFFER_SIZE];

    // Creating proxy socket
    proxy_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_fd == -1) {
        perror("Unable to create proxy socket");
        exit(EXIT_FAILURE);
    }

    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(PORT);

    // Binding the socket to the specified port
    if (bind(proxy_fd, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Unable to bind to specified port");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(proxy_fd, 3) < 0) {
        perror("Unable to listen on specified port");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int cli_addr_len = sizeof(cli_addr);

        // Accepting incoming connection from client
        if ((cli_fd = accept(proxy_fd, (struct sockaddr *)&cli_addr, (socklen_t *)&cli_addr_len)) < 0) {
            perror("Unable to accept incoming connection");
            exit(EXIT_FAILURE);
        }

        // Forking the process to handle incoming connection in a separate process
        if (fork() == 0) {
            close(proxy_fd);

            // Receiving data from client
            while ((read_size = recv(cli_fd, buf, BUFFER_SIZE, 0)) > 0) {
                // Modifying header to replace original host with proxy host
                char *host = strstr(buf, "Host: ");
                if (host != NULL) {
                    char *newline = strchr(host, '\r');
                    if (newline != NULL) {
                        *newline = '\0';
                        char *colon = strchr(host, ':');
                        if (colon != NULL) {
                            strcpy(host + 6, "127.0.0.1");
                        }
                    }
                }

                // Sending modified data to server
                if (send(cli_fd, buf, read_size, 0) < 0) {
                    perror("Unable to send data to server");
                    exit(EXIT_FAILURE);
                }
            }

            // Closing the client socket
            close(cli_fd);
            exit(EXIT_SUCCESS);
        } else {
            close(cli_fd);
        }
    }

    return 0;
}