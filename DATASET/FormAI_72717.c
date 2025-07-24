//FormAI DATASET v1.0 Category: Simple Web Server ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORT 8000
#define RESPONSE_SIZE 1024

char *create_response(char *request) {
    char *response = malloc(RESPONSE_SIZE);
    sprintf(response, "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html>\n<body>\n<h1>Hello World!</h1>\n</body>\n</html>\n");
    return response;
}

int main(int argc, char **argv) {
    struct sockaddr_in server_addr, client_addr;
    int server_sock, client_sock, c, read_size;
    char *response;

    // create socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // bind socket to address
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket to address");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    listen(server_sock, 3);

    printf("Server is running on port %d\n", SERVER_PORT);

    // accept incoming connections
    c = sizeof(struct sockaddr_in);
    while ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, (socklen_t *)&c))) {
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(client_addr.sin_addr), client_ip, INET_ADDRSTRLEN);
        printf("Client %s connected\n", client_ip);

        // read client request
        char request[1024] = { 0 };
        read_size = read(client_sock, request, 1024);

        if (read_size > 0) {
            printf("Received Request: %s\n", request);

            // create response
            response = create_response(request);

            // send response to client
            write(client_sock, response, strlen(response));
            printf("Response Sent:\n%s", response);

            // free response memory
            free(response);
        }

        // close client connection
        close(client_sock);
        printf("Client %s disconnected\n", client_ip);
    }

    return 0;
}