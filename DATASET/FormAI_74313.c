//FormAI DATASET v1.0 Category: Socket programming ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char message[100];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(8888);

    bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    listen(server_socket, 5);

    printf("Waiting for a client...\n");

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr*)&client_address, (socklen_t*)&client_address);

        printf("Connected with client %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        while (1) {
            printf("Waiting for client's message...\n");
            memset(message, 0, sizeof(message));
            recv(client_socket, message, sizeof(message), 0);

            if (strlen(message) == 0) {
                printf("Client has disconnected.\n");
                break;
            }

            printf("Received message from client: %s\n", message);

            if (strncmp(message, "love", 4) == 0) {
                char* reply = "I feel the same! <3\n";
                printf("Replying with romantic message: %s", reply);
                send(client_socket, reply, strlen(reply), 0);
            } else {
                char* reply = "Sorry, I don't understand.\n";
                printf("Replying with apologetic message: %s", reply);
                send(client_socket, reply, strlen(reply), 0);
            }
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}