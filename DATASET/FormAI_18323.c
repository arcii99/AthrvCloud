//FormAI DATASET v1.0 Category: Socket programming ; Style: optimized
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>
#include<signal.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int server_sock, client_sock, c, read_size;
    struct sockaddr_in server, client;
    char *message, *client_message, buffer[BUFFER_SIZE];
    ssize_t len;
    signal(SIGPIPE, SIG_IGN); // Ignore SIGPIPE signal to prevent program from crashing

    // create socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        printf("Could not create socket\n");
        return 1;
    }

    // prepare sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    // bind: assign IP, port to socket
    if (bind(server_sock,(struct sockaddr *)&server,sizeof(server)) < 0) {
        printf("Bind failed\n");
        return 1;
    }

    // listen: wait for client connection
    listen(server_sock, 3);

    // accept connection from an incoming client
    printf("Waiting for incoming client connection...\n");
    c = sizeof(struct sockaddr_in);
    client_sock = accept(server_sock, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0) {
        printf("Accept failed\n");
        return 1;
    }
    printf("Connection accepted from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

    while(1) {
        // receive message from client
        bzero(buffer, BUFFER_SIZE);
        len = read(client_sock, buffer, BUFFER_SIZE);
        if (len < 0) {
            printf("Read failed\n");
            break;
        }
        printf("Received: %s", buffer);

        // prepare message to be sent to client
        message = "Hello from server!\n";
        len = strlen(message);

        // send message to client
        if (send(client_sock, message, len, 0) != len) {
            printf("Send failed\n");
            break;
        }
    }

    close(client_sock);
    close(server_sock);
    return 0;
}