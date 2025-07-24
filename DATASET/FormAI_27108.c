//FormAI DATASET v1.0 Category: Client Server Application ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 7777

void *connection_handler(void *);

int main(int argc, char *argv[]) {
    int socket_desc, new_socket, c;
    struct sockaddr_in server, client;

    //Creating the socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }

    //Preparing the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    //Binding the socket to IP and port
    if (bind(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("bind failed. Error");
        return 1;
    }

    //Listen to incoming connections
    listen(socket_desc, 3);

    puts("Waiting for incoming connections...");

    c = sizeof(struct sockaddr_in);
    while ((new_socket = accept(socket_desc, (struct sockaddr *) &client, (socklen_t *) &c))) {
        puts("Connection accepted");

        pthread_t sniffer_thread;
        if (pthread_create(&sniffer_thread, NULL, connection_handler, (void *) &new_socket) < 0) {
            perror("could not create thread");
            return 1;
        }

        //Join the thread
        pthread_join(sniffer_thread, NULL);

        puts("Handler assigned");
    }

    if (new_socket < 0) {
        perror("accept failed");
        return 1;
    }

    return 0;
}

void *connection_handler(void *socket_desc) {
    int sock = *(int *) socket_desc;
    int read_size;
    char *message, client_message[2000];

    //Send some messages to the client
    message = "Greetings! I am your connection handler\n";
    write(sock, message, strlen(message));
    message = "Now type something and I shall repeat what you typed \n";
    write(sock, message, strlen(message));

    //Receive client message
    while ((read_size = recv(sock, client_message, 2000, 0)) > 0) {
        //Send the message back to client
        write(sock, client_message, strlen(client_message));
    }

    if (read_size == 0) {
        printf("client disconnected");
        fflush(stdout);
    } else if (read_size == -1) {
        perror("recv failed");
    }

    //Free the socket pointer
    free(socket_desc);

    return 0;
}