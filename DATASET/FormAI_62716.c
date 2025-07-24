//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

const int BUFFER_SIZE = 1024;

bool connect_to_server(int* sock_fd, char* server_address) {
    struct sockaddr_in server;

    *sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sock_fd == -1) {
        printf("Could not create socket.\n");
        return false;
    }

    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    if (connect(*sock_fd, (struct sockaddr*) &server, sizeof(server)) < 0) {
        printf("Could not connect to server.\n");
        return false;
    }

    return true;
}

bool send_request(int sock_fd, char* request) {
    if (send(sock_fd, request, strlen(request), 0) < 0) {
        printf("Failed to send request.\n");
        return false;
    }

    printf("Request sent.\n");

    return true;
}

bool receive_response(int sock_fd, char** response) {
    char buffer[BUFFER_SIZE];

    *response = malloc(1);
    if (*response == NULL) {
        printf("Failed to allocate memory for response.\n");
        return false;
    }

    bool headers_complete = false;
    int bytes_received;

    while ((bytes_received = recv(sock_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        *response = realloc(*response, strlen(*response) + bytes_received);
        if (*response == NULL) {
            printf("Failed to reallocate memory for response.\n");
            return false;
        }

        strncat(*response, buffer, bytes_received);

        if (!headers_complete) {
            if (strstr(*response, "\r\n\r\n") != NULL) {
                headers_complete = true;
            }
        } else {
            if (strstr(*response, "</html>") != NULL) {
                break;
            }
        }
    }

    if (bytes_received < 0) {
        printf("Error while receiving response.\n");
        return false;
    }

    return true;
}

int main() {
    char* server_address = "93.184.216.34"; // example.com
    int sock_fd;
    char* request =
        "GET / HTTP/1.1\r\n"
        "Host: example.com\r\n"
        "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:94.0) Gecko/20100101 Firefox/94.0\r\n"
        "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\n"
        "\r\n";
    char* response;
    bool success;

    success = connect_to_server(&sock_fd, server_address);
    if (!success) {
        exit(EXIT_FAILURE);
    }

    success = send_request(sock_fd, request);
    if (!success) {
        exit(EXIT_FAILURE);
    }

    success = receive_response(sock_fd, &response);
    if (!success) {
        exit(EXIT_FAILURE);
    }

    printf("Response:\n%s", response);

    free(response);
    close(sock_fd);

    return EXIT_SUCCESS;
}