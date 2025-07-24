//FormAI DATASET v1.0 Category: Chat server ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888

int main(int argc, char const *argv[]) {

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *welcome_message = "Welcome to the peaceful chat server!\n";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the specified port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Forcefully attaching socket to the specified port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    send(new_socket, welcome_message, strlen(welcome_message), 0);
    while(1) {
        valread = read(new_socket, buffer, 1024);
        buffer[valread] = '\0';
        printf("%s",buffer);
        if(strcmp(buffer, "peace") == 0) {
            char *peaceful_message = "In peace, there is truth.\n";
            send(new_socket, peaceful_message, strlen(peaceful_message), 0);
        } else if(strcmp(buffer, "love") == 0) {
            char *love_message = "Love and peace go hand in hand.\n";
            send(new_socket, love_message, strlen(love_message), 0);
        } else if(strcmp(buffer, "quit") == 0) {
            close(new_socket);
            break;
        } else {
            char *confused_message = "I'm sorry, I don't understand. Please try again.\n";
            send(new_socket, confused_message, strlen(confused_message), 0);
        }
        memset(buffer, 0, 1024);
    }

    return 0;
}