//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: grateful
// Welcome to the Simple HTTP Proxy Program
// Here's a cool example in grateful style to get you started!

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFSIZE 1024
#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, new_sockfd;
    struct sockaddr_in serv_addr;
    char buf[BUFSIZE];

    // Create the socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // Setup the server address struct
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for connections
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Proxy server running on port %d...\n", PORT);

    while (1) {
        struct sockaddr_in client_addr;
        int client_len;

        // Accept a new connection
        if ((new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t *)&client_len)) < 0) {
            perror("accept");
            exit(1);
        }

        printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Read the request from the client
        if (recv(new_sockfd, buf, sizeof(buf), 0) < 0) {
            perror("recv");
            exit(1);
        }

        // Parse the request
        char *method = strtok(buf, " ");
        char *url = strtok(NULL, " ");
        char *http_version = strtok(NULL, "\r\n");

        printf("Request: %s %s %s\n", method, url, http_version);

        // Connect to the server
        int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80);
        server_addr.sin_addr.s_addr = inet_addr("216.58.194.174");
        if (connect(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("connect");
            exit(1);
        }

        // Forward the request to the server
        if (send(server_sockfd, buf, sizeof(buf), 0) < 0) {
            perror("send");
            exit(1);
        }

        // Read the response from the server and forward it to the client
        while (recv(server_sockfd, buf, sizeof(buf), 0) > 0) {
            if (send(new_sockfd, buf, sizeof(buf), 0) < 0) {
                perror("send");
                exit(1);
            }
        }

        printf("Request forwarded to server.\n");

        close(new_sockfd);
        close(server_sockfd);
    }

    close(sockfd);
    return 0;
}