//FormAI DATASET v1.0 Category: Networking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

// function to handle incoming messages from clients
void *handle_client(void *socket_desc) {
    int sock = *(int*)socket_desc;
    char buffer[256];
    int msg_size;

    while((msg_size = recv(sock, buffer, 256, 0)) > 0) {
        printf("Client says: %s\n", buffer);
        memset(buffer, 0, 256);
    }

    if(msg_size == 0) {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(msg_size == -1) {
        perror("recv() failed");
    }

    close(sock);
    free(socket_desc);

    return 0;
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // create a TCP socket
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // bind the socket to a port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if(listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // accept incoming connections
    while((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))) {
        printf("Connection accepted from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        pthread_t sniffer_thread;
        int *new_sock = malloc(1);
        *new_sock = new_socket;

        // create a thread to handle the new client
        if(pthread_create(&sniffer_thread, NULL, handle_client, (void*)new_sock) < 0) {
            perror("pthread_create() failed");
            exit(EXIT_FAILURE);
        }

        // detach the thread since we don't need to join them later
        pthread_detach(sniffer_thread);
    }

    if(new_socket < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}