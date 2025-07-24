//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

int main(int argc, char **argv){

    if (argc != 3){
        printf("Usage: %s <ip address> <port>\n", argv[0]);
        exit(0);
    }

    char *ip_address = argv[1];
    int port = atoi(argv[2]);

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = inet_addr(ip_address);

    int connection_status = connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    if(connection_status == -1){
        printf("Could not connect to server!\n");
        exit(0);
    }

    char request[2048];
    char response[4096];

    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", ip_address);

    send(client_socket, request, strlen(request), 0);

    recv(client_socket, response, sizeof(response), 0);

    printf("%s", response);

    close(client_socket);

    return 0;
}