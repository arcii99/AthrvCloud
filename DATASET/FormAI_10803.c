//FormAI DATASET v1.0 Category: Socket programming ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int socket_desc, client_sock, c;
    struct sockaddr_in server, client;
    char message[2000], client_reply[2000];

    //Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }
    puts("Socket created!");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    //Bind
    if (bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0) {
        puts("Bind failed. Error");
        return 1;
    }
    puts("Bind done!");

    //Listen
    listen(socket_desc , 3);

    //Accept incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0) {
        puts("Accept failed");
    }
    puts("Connection accepted!");

    //Receive a message from the client
    while(recv(client_sock, client_reply, 2000, 0) > 0) {
        printf("Client reply: %s\n", client_reply);
        bzero(client_reply, 2000);

        //Send a message to the client
        printf("Enter message: ");
        fgets(message, sizeof(message), stdin);
        send(client_sock, message, strlen(message), 0);
    }

    if(recv(client_sock, client_reply, 2000, 0) < 0) {
        puts("Client disconnected");
    }

    close(client_sock);
    close(socket_desc);

    return 0;
}