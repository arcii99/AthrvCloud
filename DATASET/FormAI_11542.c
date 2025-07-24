//FormAI DATASET v1.0 Category: Client Server Application ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT_NUMBER 8080
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket, addr_len, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE] = {0};
    char client_message[BUFFER_SIZE] = {0};

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error: Socket creation failed\n");
        return -1;
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Error: Setsockopt failed\n");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT_NUMBER);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Bind failed\n");
        return -1;
    }

    if (listen(server_socket, 3) < 0) {
        printf("Error: Listen failed\n");
        return -1;
    }

    printf("Server is up and running!!!\n");

    while(1) {
        addr_len = sizeof(client_addr);

        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t *)&addr_len)) < 0) {
            printf("Error: Accept failed\n");
            return -1;
        }

        if (fork() == 0) {
            close(server_socket);

            while(1) {
                memset(buffer, 0, BUFFER_SIZE);
                if (read(client_socket, buffer, BUFFER_SIZE) <= 0) {
                    printf("Client disconnected\n");
                    break;
                } 

                printf("Received message from client: %s\n", buffer);

                if (strcmp(buffer, "Hello") == 0)
                    strcpy(client_message, "Hi, how can I help you?");
                else if (strcmp(buffer, "What time is it?") == 0)
                    strcpy(client_message, "Sorry, I don't have a watch!");
                else if (strcmp(buffer, "Knock knock") == 0)
                    strcpy(client_message, "Who's there?");
                else
                    strcpy(client_message, "I'm sorry, I didn't understand that.");

                send(client_socket, client_message , strlen(client_message) , 0);
            }

            close(client_socket);
            exit(0);
        }
    }

    return 0;
}