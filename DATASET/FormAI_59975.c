//FormAI DATASET v1.0 Category: Socket programming ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    int client_fd;
    struct sockaddr_in server_address;

    char *greetings = "Hi server, this is client!";
    char response_buffer[1024] = {0};

    // create socket file descriptor
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error!");
        exit(EXIT_FAILURE);
    }

    //initialize server address
    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    //connect with server
    if (connect(client_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error in connecting!");
        exit(EXIT_FAILURE);
    }

    //send message to server
    send(client_fd, greetings, strlen(greetings), 0);
    printf("Greetings sent to server...\n");

    //read server response
    read(client_fd, response_buffer, sizeof(response_buffer));
    printf("Response from server: %s\n", response_buffer);

    //close socket
    close(client_fd);
    return 0;
}