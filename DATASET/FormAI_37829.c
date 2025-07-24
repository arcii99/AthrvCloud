//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: shape shifting
/* Shape-shifting TCP/IP example program*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int socket_desc, client_sock, c, i = 0;
    struct sockaddr_in server, client;
    char *greeting = "Hello, I am a TCP/IP chatbot!";
    char message[2000];
    char shape = 'S'; // Default shape

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );

    // Bind
    if( bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen
    listen(socket_desc, 3);

    // Accept and incoming connection
    printf("Waiting for incoming connections...\n");
    c = sizeof(struct sockaddr_in);
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }

    // Send greeting
    write(client_sock, greeting, strlen(greeting));

    // Receive message and shape shift it
    while (strcmp(message, "quit\n") != 0) {
        bzero(message, sizeof(message));
        read(client_sock, message, sizeof(message));
        if (strcmp(message, "shift\n") == 0) {
            shape = 'L' + i % 5;
            char msg[] = "Shape shifted to: X";
            msg[18] = shape;
            write(client_sock, msg, strlen(msg));
            i++;
        } else {
            for (int j = 0; j < strlen(message); j++) {
                message[j] = message[j] ^ shape;
            }
            write(client_sock, message, strlen(message));
        }
    }

    // Close socket
    close(socket_desc);

    return 0;
}