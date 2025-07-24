//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to handle incoming connections
void handle_client(int client_socket) {

    char message[4096];
    int read_size;

    //Receive a message from client
    while((read_size = recv(client_socket, message, 4096, 0)) > 0 ) {

        // Send the message back to client
        write(client_socket, message, strlen(message));

        // Clean up the message buffer
        memset(message, 0, 4096);

    }

    // Close the socket
    close(client_socket);
}


int main(int argc, char *argv[]) {

    int socket_desc, client_sock, c;
    struct sockaddr_in server, client;

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket.\n");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(8888);

    // Bind
    if(bind(socket_desc, (struct sockaddr *)&server , sizeof(server)) < 0) {
        printf("Binding Failed.\n");
        exit(EXIT_FAILURE);
    }

    // Listen
    listen(socket_desc , 3);

    printf("Server Running on %s:%d\n", inet_ntoa(server.sin_addr), ntohs(server.sin_port));

    // Accept incoming connections
    c = sizeof(struct sockaddr_in);
    while((client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c))) {
        printf("Connection Accepted.\n");

        // Create a new thread to handle incoming connection
        pthread_t sniffer_thread;
        if(pthread_create(&sniffer_thread, NULL, handle_client, (void*) &client_sock) < 0) {
            printf("Could not create thread.\n");
            exit(EXIT_FAILURE);
        }

        // Join the thread
        pthread_join(sniffer_thread, NULL);
    }

    if(client_sock < 0) {

        printf("Could not accept incoming connection.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}