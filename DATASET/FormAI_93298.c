//FormAI DATASET v1.0 Category: Client Server Application ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return -1;
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt))) {
        perror("setsockopt");
        return -1;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Binding the socket to the specified port
    if (bind(server_fd, (struct sockaddr *)&address,
                                 sizeof(address))<0) {
        perror("bind failed");
        return -1;
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        return -1;
    }

    // Accepting incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                       (socklen_t*)&addrlen))<0) {
        perror("accept");
        return -1;
    }

    // Handling incoming messages from clients
    while(1) {
        char buffer[1024] = {0};
        char* message = "How may I assist you today?";

        valread = read( new_socket , buffer, 1024);

        if (strcmp(buffer, "quit") == 0) {
            send(new_socket, "Goodbye, have a peaceful day.", strlen("Goodbye, have a peaceful day."), 0);
            break;
        }

        printf("%s\n", buffer);
        send(new_socket , message , strlen(message) , 0 );
    }

    // Closing the server socket
    close(server_fd);

    return 0;
}