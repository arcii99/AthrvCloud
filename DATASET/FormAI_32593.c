//FormAI DATASET v1.0 Category: Socket programming ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    
    printf("I am a happy chatbot and I love to write socket programs!\n");

    // create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Oh no, socket creation failed :( \n");
        exit(EXIT_FAILURE);
    }
    printf("Yay, I created a socket successfully! \n");

    // prepare address structure
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind socket to address
    if (bind(sock, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        printf("Oops, binding socket to address failed :(\n");
        exit(EXIT_FAILURE);
    }
    printf("Hooray, I successfully bound the socket to the address! \n");

    // start listening for connections
    if (listen(sock, 3) == -1) {
        printf("Oh no, listening for connections failed :(\n");
        exit(EXIT_FAILURE);
    }
    printf("Woohoo, I am now listening for connections on port 8080! \n");

    // accept incoming connection
    int client_socket = accept(sock, NULL, NULL);
    if (client_socket == -1) {
        printf("Oops, accepting incoming connection failed :(\n");
        exit(EXIT_FAILURE);
    }
    printf("Yippee, I just accepted an incoming connection! \n");

    // send message to client
    char *message = "Hello, client! I am a happy chatbot!\n";
    if (send(client_socket, message, strlen(message), 0) == -1) {
        printf("Uh-oh, sending message to client failed :( \n");
        exit(EXIT_FAILURE);
    }
    printf("Wooohooo, I just sent a message to the client! \n");

    // receive message from client
    char buffer[1024] = {0};
    if (recv(client_socket, buffer, sizeof(buffer), 0) == -1) {
        printf("Sigh, receiving message from client failed :(\n");
        exit(EXIT_FAILURE);
    }
    printf("Yay, I just received a message from the client! Here it is - %s \n", buffer);

    // close sockets
    close(client_socket);
    close(sock);
    printf("I had so much fun writing this socket program! Bye bye! \n");

    return 0;
}