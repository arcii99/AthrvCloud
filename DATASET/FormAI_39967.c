//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

char response_body[] = "<html><body><h1>Welcome to the Simple Web Server!</h1></body></html>";

int main(int argc, char **argv)
{
    int server_socket, client_socket, opt = 1;
    struct sockaddr_in server_address, client_address;
    int address_len = sizeof(server_address);
    char buffer[1024] = {0};
    int bytes_received;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) < 0)
    {
        perror("Error listening to socket");
        exit(EXIT_FAILURE);
    }

    printf("Simple Web Server is listening on port 8080...\n");

    while (1)
    {
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&address_len)) < 0)
        {
            perror("Error accepting client socket");
            exit(EXIT_FAILURE);
        }

        bytes_received = read(client_socket, buffer, 1024);

        if (bytes_received < 0)
        {
            perror("Error receiving data from client");
            exit(EXIT_FAILURE);
        }

        printf("Request:\n%s\n", buffer);

        char *response_headers = "HTTP/1.1 200 OK\r\nContent-Type: text/html; charset=UTF-8\r\n\r\n";
        int response_headers_len = strlen(response_headers);
        int response_body_len = strlen(response_body);

        char response[response_headers_len + response_body_len + 1];
        strcpy(response, response_headers);
        strcat(response, response_body);

        if (write(client_socket, response, response_headers_len + response_body_len) < 0)
        {
            perror("Error sending data to client");
            exit(EXIT_FAILURE);
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}