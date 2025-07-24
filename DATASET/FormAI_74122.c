//FormAI DATASET v1.0 Category: Socket programming ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 8080

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    const char *authentication_key = "paranoid-demo-key";
    char input_key[1024] = {0};

    // create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // attach socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // bind the socket to the IP address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen to incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("\nWaiting for connections ...\n");

        // accept a new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted!\n");

        // prompt the authentication key from the client
        send(new_socket, "Enter the authentication key: ", strlen("Enter the authentication key: "), 0);
        valread = read(new_socket, input_key, 1024);

        // verify authentication key
        input_key[valread] = '\0';
        if (strcmp(input_key, authentication_key) != 0) {
            send(new_socket, "Authentication failed! Disconnecting...\n", strlen("Authentication failed! Disconnecting...\n"), 0);
            close(new_socket);
            continue;
        }

        // send welcome message to the client
        send(new_socket, "Welcome to the paranoid demo!\n", strlen("Welcome to the paranoid demo!\n"), 0);

        // receive client's message
        valread = read(new_socket, buffer, 1024);

        // encrypt the message
        for (int i=0; i<valread; i++) {
            buffer[i] ^= authentication_key[i % strlen(authentication_key)];
        }

        // print the encrypted message
        printf("Encrypted message: %s\n", buffer);

        // send the encrypted message back to the client
        send(new_socket, buffer, strlen(buffer), 0);

        // close the connection
        close(new_socket);
    }

    return 0;
}