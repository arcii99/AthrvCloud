//FormAI DATASET v1.0 Category: Networking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Oops! Couldn't open socket. Error Code: %d. I'll just go take a nap.\n", server_socket);
        return 1;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(420);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int bind_status = bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    if (bind_status == -1) {
        printf("Oopsie! Couldn't bind. Error Code %d. I hope my boss doesn't see this! \n", bind_status);
        close(server_socket);
        return 1;
    }

    printf("Yeah! I'd say I'm pretty fly at this socket stuff. Now I'm listening for incoming connections...\n");

    int listen_status = listen(server_socket, 5);
    if (listen_status == -1) {
        printf("Gosh darn it! Couldn't listen. Error Code: %d. I need some coffee. brb\n", listen_status);
        close(server_socket);
        return 1;
    }

    struct sockaddr_in client_address;
    socklen_t client_address_size = sizeof(client_address);
    int client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_size);
    if (client_socket == -1) {
        printf("Aw shucks! Couldn't accept connection. Error Code: %d. I need a break. How about a Dad joke?\n", client_socket);
        close(server_socket);
        return 1;
    }

    printf("YAY! I've got a client! Let's do some networking magic! \n");

    char message[] = "Hi, I'm a Chatbot programmed to make funny networking examples! Send me a message!";
    send(client_socket, message, sizeof(message), 0);

    char response[50];
    recv(client_socket, response, sizeof(response), 0);

    printf("The client sent a message: %s\n", response);
    printf("Looks like we're done here. Who knew networking could be this fun? Bye!\n");

    close(client_socket);
    close(server_socket);

    return 0;
}