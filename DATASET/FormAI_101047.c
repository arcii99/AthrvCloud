//FormAI DATASET v1.0 Category: Chat server ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Create Socket
    int serversocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    if (serversocket < 0) {
        perror("Socket Create Error");
        exit(EXIT_FAILURE);
    }

    // Bind
    struct sockaddr_in serveraddress;
    memset(&serveraddress, 0, sizeof(serveraddress));
    serveraddress.sin_family = AF_INET;
    serveraddress.sin_port = htons(8888);
    serveraddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(serversocket, (struct sockaddr *)&serveraddress, sizeof(serveraddress)) < 0) {
        perror("Bind Error");
        exit(EXIT_FAILURE);
    }

    // Listen
    if (listen(serversocket, 5) < 0) {
        perror("Listen Error");
        exit(EXIT_FAILURE);
    }

    // Accept
    struct sockaddr_in client_address;
    socklen_t client_address_len;

    int client_socket = accept(serversocket, (struct sockaddr *)&client_address, &client_address_len);

    if (client_socket < 0) {
        perror("Accept Error");
        exit(EXIT_FAILURE);
    }

    printf("Connected to client: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    while (1) {

        char buffer[1024] = {0};
        int valread = read(client_socket, buffer, 1024);

        if (valread < 0) {
            perror("Read Error");
            exit(EXIT_FAILURE);
        }
        else if (valread == 0) {
            printf("Client Disconnected\n");
            close(client_socket);
            exit(EXIT_SUCCESS);
        }

        printf("Client: %s", buffer);

        memset(buffer, 0, sizeof(buffer));

        printf("Server: ");
        fgets(buffer, sizeof(buffer), stdin);

        send(client_socket, buffer, strlen(buffer), 0);
    }

    return 0;
}