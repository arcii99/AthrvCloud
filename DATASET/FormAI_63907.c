//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 4096
#define MAX_CLIENTS 100

const int PORT = 8080;

int main() {
    int server_sock, client_sock, c, read_size;
    struct sockaddr_in server , client;
    char client_message[BUF_SIZE];

    // Creating socket
    server_sock = socket(AF_INET , SOCK_STREAM , 0);
    if (server_sock == -1) {
        printf("Could not create socket");
        return 1;
    }

    // Binding
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);
    if(bind(server_sock, (struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("bind failed. Error");
        return 1;
    }
    puts("Bind done");

    // Listen
    listen(server_sock, MAX_CLIENTS);
    puts("Waiting for incoming connections...");

    c = sizeof(struct sockaddr_in);
    
    // Accept incoming connection
    while ((client_sock = accept(server_sock, (struct sockaddr *)&client, (socklen_t*)&c))) {
        puts("Connection accepted");

        // Forking new process to handle multiple clients at the same time
        if (!fork()) {
            // Reading client request
            memset(client_message, 0, BUF_SIZE);
            if (recv(client_sock, client_message, BUF_SIZE, 0) < 0) {
                perror("recv failed. Error");
                return 1;
            }

            // Printing received request
            printf("Received:\n%s\n", client_message);

            // Replacing "Host:" header with proxy server IP
            char *host = strstr(client_message, "Host:");
            if (host == NULL) {
                perror("Host header not found");
                return 1;
            }
            host += 6;

            char *end_host = strstr(host, "\r\n");
            if (end_host == NULL) {
                perror("End of host header not found");
                return 1;
            }
            *end_host = '\0';

            printf("host = %s\n", host);

            if (send(client_sock, client_message, strlen(client_message), 0) < 0) {
                perror("send failed. Error");
                return 1;
            }

            // Closing socket
            close(client_sock);
            exit(0);
        }
    }

    if (client_sock < 0) {
        perror("accept failed");
        return 1;
    }

    return 0;
}