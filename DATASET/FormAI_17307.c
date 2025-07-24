//FormAI DATASET v1.0 Category: Simple Web Server ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define RESPONSE_HTML "<html><body><h1>Hello, World!</h1></body></html>"

int main(int argc, char *argv[]) {
    int sock, client_sock, read_size;
    struct sockaddr_in server, client;
    char client_message[2000];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    // Bind
    if (bind(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("bind failed. Error");
        return 1;
    }

    // Listen
    listen(sock, 3);

    // Accept and incoming connection
    puts("Waiting for incoming connections...");
    int c = sizeof(struct sockaddr_in);
    while ((client_sock = accept(sock, (struct sockaddr *) &client, (socklen_t *) &c))) {
        puts("Connection accepted");

        // Receive client request
        char request[1000] = {0};
        read_size = recv(client_sock, request, 1000, 0);
        printf("Request: %s \n", request);

        // Send response
        char response[2000] = {0};
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n%s", RESPONSE_HTML);
        write(client_sock, response, strlen(response));

        // Close connection
        printf("Closing connection\n");
        close(client_sock);
    }

    if (client_sock < 0) {
        perror("accept failed");
        return 1;
    }

    return 0;
}