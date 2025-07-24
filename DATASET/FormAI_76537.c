//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#define PORT 8080

int main(int argc, char const *argv[]) {
    int proxy_fd, client_fd;
    struct sockaddr_in proxy_address, client_address;
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    // Create socket for proxy server
    proxy_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_fd < 0) {
        perror("Could not create socket for proxy server\n");
        return EXIT_FAILURE;
    }
    printf("Socket for proxy server created successfully! 🎉\n");

    // Set up the address for the proxy server
    memset(&proxy_address, 0, sizeof(proxy_address));
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_addr.s_addr = INADDR_ANY;
    proxy_address.sin_port = htons(PORT);

    // Bind the address to the socket
    if (bind(proxy_fd, (struct sockaddr *)&proxy_address, sizeof(proxy_address)) < 0) {
        perror("Could not bind address to socket for proxy server\n");
        close(proxy_fd);
        return EXIT_FAILURE;
    }
    printf("Address bound to socket for proxy server successfully! 🎉\n");

    // Listen for incoming connections
    if (listen(proxy_fd, 10) < 0) {
        perror("Could not listen for incoming connections\n");
        close(proxy_fd);
        return EXIT_FAILURE;
    }
    printf("Proxy server now listening! 🎉\n");

    while (1) {
        unsigned int client_len = sizeof(client_address);
        memset(&client_address, 0, client_len);

        // Accept incoming connection from client
        client_fd = accept(proxy_fd, (struct sockaddr *)&client_address, &client_len);
        if (client_fd < 0) {
            perror("Could not accept incoming connection from client\n");
            close(proxy_fd);
            return EXIT_FAILURE;
        }
        printf("Connection accepted from client! 🎉\n");

        // Read HTTP request from client
        int n = read(client_fd, buffer, sizeof(buffer));
        if (n < 0) {
            perror("Could not read HTTP request from client\n");
            close(client_fd);
            continue;
        }
        printf("HTTP request received from client: %s\n", buffer);

        // Send HTTP request to web server
        int web_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (web_fd < 0) {
            perror("Could not create socket for web server\n");
            close(client_fd);
            continue;
        }

        // Set up address for web server
        struct sockaddr_in web_address;
        memset(&web_address, 0, sizeof(web_address));
        web_address.sin_family = AF_INET;
        web_address.sin_port = htons(80);

        // Convert IP address of web server from string to binary
        if (inet_pton(AF_INET, "216.58.194.174", &web_address.sin_addr) <= 0) {
            perror("Could not convert IP address of web server from string to binary\n");
            close(client_fd);
            close(web_fd);
            continue;
        }

        // Connect to web server
        if (connect(web_fd, (struct sockaddr *)&web_address, sizeof(web_address)) < 0) {
            perror("Could not connect to web server\n");
            close(client_fd);
            close(web_fd);
            continue;
        }
        printf("Connected to web server! 🎉\n");

        // Forward HTTP request to web server
        if (write(web_fd, buffer, strlen(buffer)) < 0) {
            perror("Could not forward HTTP request to web server\n");
            close(client_fd);
            close(web_fd);
            continue;
        }
        printf("HTTP request forwarded to web server: %s\n", buffer);

        // Read HTTP response from web server
        memset(buffer, 0, sizeof(buffer));
        if (read(web_fd, buffer, sizeof(buffer)) < 0) {
            perror("Could not read HTTP response from web server\n");
            close(client_fd);
            close(web_fd);
            continue;
        }
        printf("HTTP response received from web server: %s\n", buffer);

        // Forward HTTP response to client
        if (write(client_fd, buffer, strlen(buffer)) < 0) {
            perror("Could not forward HTTP response to client\n");
            close(client_fd);
            close(web_fd);
            continue;
        }
        printf("HTTP response forwarded to client: %s\n", buffer);

        // Close sockets
        close(client_fd);
        close(web_fd);
    }

    close(proxy_fd);
    return EXIT_SUCCESS;
}