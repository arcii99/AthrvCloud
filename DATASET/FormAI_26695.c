//FormAI DATASET v1.0 Category: Networking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// define port number
#define PORT 8080

int main() {
    int socket_fd = 0;
    struct sockaddr_in serv_addr;
    char message[1024] = {0};
    char response[1024] = {0};

    // create socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed.");
        exit(EXIT_FAILURE);
    }

    // set up the server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // convert IP address from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        perror("Invalid address.");
        exit(EXIT_FAILURE);
    }

    // connect to the server
    if (connect(socket_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed.");
        exit(EXIT_FAILURE);
    }

    printf("Enter a message: ");
    fgets(message, 1024, stdin);

    // send message to server
    send(socket_fd, message, strlen(message), 0);
    printf("Message sent to server.\n");

    // receive response from server
    read(socket_fd, response, 1024);
    printf("Response from server: %s\n", response);

    // close the socket
    close(socket_fd);

    return 0;
}