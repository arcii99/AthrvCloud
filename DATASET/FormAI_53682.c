//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(int argc, char *argv[]){
    int client_socket, ret;
    struct sockaddr_in server_address;
    char *server_ip = "127.0.0.1";
    int server_port = 8080;
    char request_buffer[1024];

    // Create the socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(client_socket < 0){
        printf("Error while creating the socket\n");
        return -1;
    }
    printf("Socket created successfully\n");

    // Connect to the server
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &server_address.sin_addr);

    ret = connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    if(ret < 0){
        printf("Error while connecting to the server\n");
        return -1;
    }
    printf("Connected to the server\n");

    // Build the HTTP GET request
    snprintf(request_buffer, sizeof(request_buffer), "GET / HTTP/1.1\r\nHost: %s:%d\r\n\r\n", server_ip, server_port);

    // Send the request to the server
    ret = send(client_socket, request_buffer, strlen(request_buffer), 0);

    if(ret < 0){
        printf("Error while sending the request\n");
        return -1;
    }

    printf("HTTP GET request sent to the server\n");

    // Receive the response from the server
    char response_buffer[1024];

    while(1){
        memset(response_buffer, 0, sizeof(response_buffer));
        ret = recv(client_socket, response_buffer, sizeof(response_buffer), 0);

        if(ret < 0){
            printf("Error while receiving the response\n");
            return -1;
        }

        if(ret == 0){
            break;
        }

        printf("%s", response_buffer);
    }

    // Close the socket
    close(client_socket);

    return 0;
}