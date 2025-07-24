//FormAI DATASET v1.0 Category: Networking ; Style: distributed
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>

#define MAX_MSG_LENGTH 1024
#define SERVER_PORT 8080

int main() {
    int socket_desc, new_socket, c;
    struct sockaddr_in server, client;
    char message[MAX_MSG_LENGTH];
     
    //Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(SERVER_PORT);

    //Bind
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed. Error");
        return 1;
    }

    //Listen
    listen(socket_desc, 3);

    //Accept and incoming connection
    printf("Waiting for incoming connections...\n");
    c = sizeof(struct sockaddr_in);
    while(1) {
        new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
        if (new_socket < 0) {
            perror("accept failed");
            return 1;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        //Receive a message from client
        while(1) {
            memset(message, 0, MAX_MSG_LENGTH);
            if (recv(new_socket, message, MAX_MSG_LENGTH, 0) == 0) {
                printf("Client disconnected\n");
                break;
            }

            printf("Message received from client %s:%d: %s\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port), message);

            //Echo back the message to client
            if (send(new_socket, message, strlen(message), 0) < 0) {
                perror("send failed");
                return 1;
            }

            printf("Message echoed back to client %s:%d: %s\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port), message);
        }
    }

    close(socket_desc);
    return 0;
}