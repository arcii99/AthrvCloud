//FormAI DATASET v1.0 Category: Chat server ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_socket, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *surrealist_phrases[] = {"The moon is a giant banana.", 
                                  "I have a pet dragon who likes to eat bubble wrap.", 
                                  "I once saw a pigeon playing hopscotch.", 
                                  "My hat is made of cheese.", 
                                  "My feet are made of marshmallows.", 
                                  "The grass is made of spaghetti.",
                                  "The clouds are made of cotton candy."};

    // Creating socket file descriptor
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to port 8080
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Bind the socket to the address and port
    if (bind(server_socket, (struct sockaddr *)&address, 
                                 sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Keep accepting connections and generating surrealistic phrases
    while(1) {
        if ((new_socket = accept(server_socket, (struct sockaddr *)&address,
                           (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        int index = rand() % (sizeof(surrealist_phrases) / sizeof(char *));
        char *message = surrealist_phrases[index];
        send(new_socket, message, strlen(message), 0);
        printf("Surrealist phrase sent: %s\n", message);
        close(new_socket);
    }

    return 0;
}