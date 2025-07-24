//FormAI DATASET v1.0 Category: Simple Web Server ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int server_fd, client_fd, valread;
    struct sockaddr_in server_address;
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: 17\n\n<H1>Hello World!</H1>";

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error: Failed to create socket\n");
        return 1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error: Failed to bind socket\n");
        return 1;
    }

    printf("Server running at http://localhost:8080/\n");

    while (1) {
        if (listen(server_fd, 3) < 0) {
            printf("Error: Failed to listen\n");
            return 1;
        }

        if ((client_fd = accept(server_fd, NULL, NULL)) < 0) {
            printf("Error: Failed to accept\n");
            return 1;
        }

        printf("Connection accepted\n");

        char buffer[30000] = {0};
        valread = read(client_fd, buffer, 30000);
        if (valread <= 0) {
            printf("Error: Failed to read from socket\n");
            return 1;
        }

        printf("%s\n", buffer);

        send(client_fd, response, strlen(response), 0);
        printf("Response sent\n");
        close(client_fd);
    }

    close(server_fd);
    return 0;
}