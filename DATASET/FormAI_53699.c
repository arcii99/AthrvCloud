//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    int sock = 0, client_sock = 0;
    struct sockaddr_in serv_addr, client_addr;
    int addrlen = sizeof(serv_addr);
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Binding socket to the specified port
    if (bind(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        return -1;
    }

    // Setting socket to listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen failed");
        return -1;
    }

    printf("Listening on port %d...\n", PORT);

    while (1) {
        // Accepting incoming connections
        if ((client_sock = accept(sock, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            return -1;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Sending a welcome message to the client
        char* welcome_message = "Welcome to my server!\n";
        send(client_sock, welcome_message, strlen(welcome_message), 0);

        // Receiving messages from the client and sending responses
        while (1) {
            memset(buffer, 0, sizeof(buffer));
            int valread = read(client_sock, buffer, sizeof(buffer));

            if (valread == 0) break;

            printf("Message received: %s", buffer);

            // Checking if the client wants to close the connection
            if (strcmp(buffer, "exit\n") == 0) {
                char* exit_message = "Closing connection...\n";
                send(client_sock, exit_message, strlen(exit_message), 0);
                break;
            }

            // Sending a response to the client
            char response[1024] = {0};
            sprintf(response, "You said: %s", buffer);
            send(client_sock, response, strlen(response), 0);
        }

        // Closing the connection with the client
        close(client_sock);
        printf("Connection closed with %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    }

    return 0;
}