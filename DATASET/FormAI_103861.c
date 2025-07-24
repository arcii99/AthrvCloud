//FormAI DATASET v1.0 Category: Socket programming ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char* argv[]) {

    int client_socket, server_socket, result;
    struct sockaddr_in cli_addr, serv_addr;
    char message[50] = "Hello, from client!";

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(8888);

    bind(server_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    listen(server_socket, 1);

    printf("Server waiting on port 8888 for incoming connections...\n");

    socklen_t clilen = sizeof(cli_addr);
    client_socket = accept(server_socket, (struct sockaddr *)&cli_addr, &clilen);
    printf("Client connects to server with IP: %s and port: %d\n",
            inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

    result = write(client_socket, message, strlen(message));
    if(result < 0) {
        printf("Error sending message.\n");
    }

    close(client_socket);
    close(server_socket);

    return 0;
}