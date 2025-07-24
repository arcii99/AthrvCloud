//FormAI DATASET v1.0 Category: Simple Web Server ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define RESPONSE_SIZE 1024

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char response[RESPONSE_SIZE] = "Greetings traveler! This is the medieval web server.\n";
    char client_message[RESPONSE_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Attaching socket to the specified port
    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Medieval web server is listening on port %d...\n", PORT);

    //Accepting incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    printf("New connection from a brave knight!\n");

    // Generating a response and sending to the client
    while (1) {
        send(new_socket, response, strlen(response), 0);
        memset(client_message, 0, RESPONSE_SIZE);
        valread = read(new_socket, client_message, RESPONSE_SIZE);
        if (valread <= 0) {
            break;
        }
        printf("Client sent: %s\n", client_message);
        snprintf(response, RESPONSE_SIZE, "I am impressed by your bravery, honorable knight!\n");
    }

    printf("Knight has left the kingdom\n");
    return 0;
}