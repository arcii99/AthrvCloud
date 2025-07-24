//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define BUFSIZ 1024
#define PORT 80

int main()
{
    int server_socket, client_socket;
    char buffer[BUFSIZ];
    struct sockaddr_in server_address, client_address;
    socklen_t client_length = sizeof(client_address);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if(bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind");
        exit(1);
    }

    if(listen(server_socket, 5) < 0) {
        perror("Failed to listen");
        exit(1);
    }

    while(1) {
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_length);

        if(client_socket < 0) {
            perror("Failed to accept");
            exit(1);
        }

        memset(buffer, 0, BUFSIZ);
        read(client_socket, buffer, BUFSIZ);

        char *response_body = "<html><body><h1>Hello, World!</h1></body></html>";
        char *response_headers = "HTTP/1.1 200 OK\r\nServer: Ken's Webserver\r\nContent-Type: text/html\r\nContent-Length: %d\r\nDate: %sGMT\r\nConnection: close\r\n\r\n";
        int response_body_len = strlen(response_body);
        time_t rawtime;
        struct tm *info;
        char time_string[80];
        time(&rawtime);
        info = gmtime(&rawtime);
        strftime(time_string, 80, "%a, %d %b %Y %T ", info);

        char response[BUFSIZ];
        sprintf(response, response_headers, response_body_len, time_string);
        write(client_socket, response, strlen(response));
        write(client_socket, response_body, response_body_len);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}