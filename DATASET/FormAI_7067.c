//FormAI DATASET v1.0 Category: Simple Web Server ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define RESPONSE_SIZE 2048

char *responses[] = {"Hello World!", "Welcome!", "Goodbye!", "404 Not Found"};

int main(int argc, char const *argv[]) {

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *response;

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    while(1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Receive client request
        valread = read(new_socket, buffer, 1024);
        printf("Request from client: %s\n", buffer);

        // Generate a response to client's request
        if(strstr(buffer, "GET /hello") != NULL) {
            response = responses[0];
        } else if (strstr(buffer, "GET /welcome") != NULL) {
            response = responses[1];
        } else if (strstr(buffer, "GET /goodbye") != NULL) {
            response = responses[2];
        } else {
            response = responses[3];
        }

        // Send response to client
        char *http_response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n";
        char client_response[RESPONSE_SIZE];
        sprintf(client_response, "%s%s", http_response, response);
        send(new_socket, client_response, strlen(client_response), 0);
        printf("Response sent to client: %s\n", client_response);

        close(new_socket);
    }

    return 0;
}