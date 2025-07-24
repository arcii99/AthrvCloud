//FormAI DATASET v1.0 Category: Client Server Application ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

void shapeShifter(char* str);

int main() {
    int socket_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char* welcome = "Welcome to the Shape Shifter Server!\n\n";
    char* prompt = "Enter a string to shape shift: ";

    // Creating socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding socket to port
    if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening on socket for incoming connections
    if (listen(socket_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("%s", welcome);

    while(1) {
        // Accept incoming connection
        if ((new_socket = accept(socket_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Send prompt to client
        send(new_socket, prompt, strlen(prompt), 0);

        // Receive string from client
        valread = read(new_socket, buffer, 1024);

        // Shape shift string and send back to client
        char* shifted = strdup(buffer);
        shapeShifter(shifted);
        send(new_socket, shifted, strlen(shifted), 0);

        // Close connection
        close(new_socket);
    }

    return 0;
}

void shapeShifter(char* str) {
    int len = strlen(str);

    // Randomize string transformation
    srand(time(NULL));
    int choose = rand() % 3;

    if(choose == 0) {
        // Reverse string
        for(int i = 0; i < len / 2; i++) {
            char temp = str[i];
            str[i] = str[len - i - 1];
            str[len - i - 1] = temp;
        }
    }
    else if(choose == 1) {
        // Convert to uppercase
        for(int i = 0; i < len; i++) {
            if(str[i] >= 'a' && str[i] <= 'z') {
                str[i] -= 32;
            }
        }
    }
    else {
        // Convert to lowercase
        for(int i = 0; i < len; i++) {
            if(str[i] >= 'A' && str[i] <= 'Z') {
                str[i] += 32;
            }
        }
    }
}