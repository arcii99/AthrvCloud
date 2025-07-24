//FormAI DATASET v1.0 Category: Simple Web Server ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>

#define PORT 8000 // define the port number

// define the function to handle client request
void *client_handler(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket, buffer, sizeof(buffer), 0); // receive the request from client

    // handle the request and send the response back to the client
    char response[1024] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Welcome to the Future Web Server!</h1></body></html>";
    send(client_socket, response, strlen(response), 0);

    // close the client socket
    close(client_socket);
    pthread_exit(NULL);
}

int main() {
    int server_socket, client_socket, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // create a new socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // set socket options
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    // bind the socket to the address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));

    // listen for incoming connections
    listen(server_socket, 5);
    printf("Server started at port %d\n", PORT);

    // accept incoming client connections and handle them using threads
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_len);
        printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        pthread_t client_thread;
        pthread_create(&client_thread, NULL, client_handler, &client_socket);
        pthread_detach(client_thread);
    }

    // close the server socket
    close(server_socket);

    return 0;
}