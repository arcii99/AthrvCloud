//FormAI DATASET v1.0 Category: Networking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
    printf("Thank you for choosing our networking program!\n");

    int server_socket, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char send_buffer[1024] = {0};
    char receive_buffer[1024] = {0};
    char* gratitude_message = "Thank you for connecting with us!";

    // Creating a TCP socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( 8080 );

    // Binding the socket to the port
    if (bind(server_socket, (struct sockaddr *)&address,
                                 sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accepting incoming connection
    if ((new_socket = accept(server_socket, (struct sockaddr *)&address,
                       (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Receiving message from client
    valread = read( new_socket , receive_buffer, 1024);
    printf("Client: %s\n",receive_buffer );

    // Sending gratitude message to the client
    send(new_socket , gratitude_message , strlen(gratitude_message) , 0 );
    printf("%s\n",gratitude_message );

    // Closing sockets
    close(new_socket);
    close(server_socket);

    printf("Have a nice day!\n");
    return 0;
}