//FormAI DATASET v1.0 Category: Simple Web Server ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    int srv_socket, client_socket, valread;
    struct sockaddr_in addr;
    char buffer[1024] = {0};
    char *response = "<html><body><h1>Welcome to my Simple Web Server!</h1></body></html>";

    if ((srv_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        printf("Socket creation error!\n");
        exit(EXIT_FAILURE);
    }

    int opt = 1;
    if (setsockopt(srv_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        printf("Socket options error!\n");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    if (bind(srv_socket, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        printf("Socket binding error!\n");
        exit(EXIT_FAILURE);
    }

    if (listen(srv_socket, 3) < 0)
    {
        printf("Socket listening error!\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        if ((client_socket = accept(srv_socket, (struct sockaddr *)&addr, (socklen_t *)&addr)) < 0)
        {
            printf("Client accept error!\n");
            exit(EXIT_FAILURE);
        }

        valread = read(client_socket, buffer, 1024);
        printf("%s\n", buffer);

        char header[1024] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: ";
        strcat(header, response);
        char content_length[50];
        sprintf(content_length, "%zu\r\n\r\n", strlen(response));
        strcat(header, content_length);

        send(client_socket, header, strlen(header), 0);
        send(client_socket, response, strlen(response), 0);

        memset(buffer, 0, sizeof(buffer));
        close(client_socket);
    }

    return 0;
}