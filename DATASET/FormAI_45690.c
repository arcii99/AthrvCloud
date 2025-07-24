//FormAI DATASET v1.0 Category: Socket programming ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

#define PORT 8080

int main(){
    int socket_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    char buffer[256];

    printf("What's up! Let's create a server for a change.\n");

    printf("Creating a socket...\n");
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd < 0){
        printf("Something went wrong while creating socket. Check your code, mate!\n");
        exit(1);
    }

    printf("Setting server address...\n");
    bzero((char*)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    printf("Binding socket to server address...\n");
    if(bind(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        printf("Oops! Couldn't bind socket. Check if the port number is already in use.\n");
        exit(1);
    }

    printf("Listening for incoming connections...\n");
    listen(socket_fd, 5);

    printf("Client connecting...\n");
    client_len = sizeof(client_addr);
    client_fd = accept(socket_fd, (struct sockaddr*)&client_addr, &client_len);
    if(client_fd < 0){
        printf("Error while establishing a connection with client. Maybe they are too shy to talk to you.\n");
        exit(1);
    }

    printf("Oh, a client! Let's talk to them!\n");
    bzero(buffer, 256);
    read(client_fd, buffer, 255);
    printf("Client says: %s\n", buffer);

    printf("Hmm, let's reply with something funny...\n");
    char* reply = "Hello client! Did you hear about the new restaurant called Karma? There's no menu, you get what you deserve!\n";
    write(client_fd, reply, strlen(reply));

    printf("Closing the sockets...\n");
    close(client_fd);
    close(socket_fd);

    printf("Goodbye for now!\n");

    return 0;
}