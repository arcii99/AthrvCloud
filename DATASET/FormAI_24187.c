//FormAI DATASET v1.0 Category: Simple Web Server ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

#define MAX_CLIENTS 10

void handle_http_request(char *request, int socket_fd);

int main(int argc, char* argv[]){
    int socket_fd, client_socket, status;
    struct sockaddr_in server_address, client_address;
    char incoming_request[1024];

    //create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1){
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    //set server address and port
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    //bind socket to address
    status = bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address));
    if (status == -1){
        perror("Socket binding failed");
        exit(EXIT_FAILURE);
    }

    //listen for connections
    status = listen(socket_fd, MAX_CLIENTS);
    if (status == -1){
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port 8080\n");

    while(1){
        int client_address_length = sizeof(client_address);
        client_socket = accept(socket_fd, (struct sockaddr *)&client_address, (socklen_t*)&client_address_length);

        if (client_socket == -1){
            perror("Accepting client connection failed");
            continue;
        }

        printf("New client connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        memset(&incoming_request, '\0', sizeof(incoming_request));
        read(client_socket, incoming_request, sizeof(incoming_request));

        printf("%s", incoming_request);

        handle_http_request(incoming_request, client_socket);
    }

    return 0;
}

void handle_http_request(char *request, int socket_fd){
    char *status_code = NULL;
    char *content_type = NULL;

    if (strstr(request, "GET") != NULL){
        status_code = "200 OK";
        content_type = "text/plain";
    }
    else{
        status_code = "400 Bad Request";
        content_type = "text/html";
    }

    char *response_body = "<html><head><title>Simple Web Server</title></head><body><h1>Hello from Simple Web Server</h1></body></html>";
    char *response_headers = malloc(sizeof(char)*1024);
    memset(response_headers, '\0', sizeof(response_headers));
    sprintf(response_headers, "HTTP/1.1 %s\r\nContent-Type: %s\r\nContent-Length: %lu\r\n\r\n", status_code, content_type, strlen(response_body));

    write(socket_fd, response_headers, strlen(response_headers));
    write(socket_fd, response_body, strlen(response_body));
    close(socket_fd);
}