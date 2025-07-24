//FormAI DATASET v1.0 Category: Client Server Application ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

void surreal_print(char *message) {
    for (int i = 0; i < strlen(message); i++) {
        if (i % 2 == 0) {
            printf("%c", message[i]+1);
        } else {
            printf("%c", message[i]-1);
        }
    }
    printf("\n");
}

void surreal_server() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    listen(server_socket, 5);

    int client_socket = accept(server_socket, NULL, NULL);

    char message[256];
    read(client_socket, message, sizeof(message));
    surreal_print(message);

    close(client_socket);
    close(server_socket);
}

void surreal_client() {
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(client_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    char message[256];
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    write(client_socket, message, strlen(message)+1);

    close(client_socket);
}

int main() {
    surreal_server();
    surreal_client();

    return 0;
}