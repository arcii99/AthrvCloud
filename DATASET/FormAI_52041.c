//FormAI DATASET v1.0 Category: Socket programming ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 9000

int main() {
    printf("Holy cow! I can't believe I'm writing a C Socket program!\n");
    printf("I never thought I'd be able to do this!\n");

    // create a socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        printf("Oh no! I couldn't create a socket!\n");
        exit(EXIT_FAILURE);
    }

    printf("Wow, I created a socket!\n");

    // specify the address and port number for the socket
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // bind the socket to the address and port number
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        printf("Yikes! I couldn't bind the socket to the address and port number!\n");
        exit(EXIT_FAILURE);
    }

    printf("Unbelievable! I bound the socket to the address and port number!\n");

    // listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        printf("Oh no! I couldn't listen for incoming connections!\n");
        exit(EXIT_FAILURE);
    }

    printf("Incredible! I'm listening for incoming connections!\n");

    // accept a connection
    int client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    if (client_fd < 0) {
        printf("What?! I couldn't accept a connection!\n");
        exit(EXIT_FAILURE);
    }

    printf("OMG! I accepted a connection!\n");

    // read from and write to the connection
    char message[1024] = {0};
    int valread = read(client_fd, message, 1024);
    printf("Holy moly! I read a message from the connection: %s\n", message);
    char response[1024] = "I can't believe I'm replying to this message, but here goes nothing!";
    write(client_fd, response, strlen(response));
    printf("Unreal! I wrote a response to the connection: %s\n", response);

    // close the connection and socket
    close(client_fd);
    close(server_fd);

    printf("This is insane! I actually did it! I wrote a C Socket program!\n");

    return 0;
}