//FormAI DATASET v1.0 Category: Socket programming ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MESSAGE_SIZE 1024

int main(int argc, char *argv[]) {
    int socket_desc, new_socket, c, read_size;
    struct sockaddr_in server, client;
    char *message;
    char client_message[MESSAGE_SIZE] = {0};

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }
    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    // Bind
    if (bind(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Error binding socket");
        return 1;
    }
    puts("Socket bound!");
    // Listen
    listen(socket_desc, 3);
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    while ((new_socket = accept(socket_desc, (struct sockaddr *) &client, (socklen_t *) &c))) {
        puts("Connection accepted...");
        // Welcome message
        message = "Welcome to the last surviving server on Earth. What do you want to do?\n";
        write(new_socket, message, strlen(message));

        // Communication with client loop
        while ((read_size = recv(new_socket, client_message, MESSAGE_SIZE, 0)) > 0) {
            // Null-terminate received message
            client_message[read_size] = '\0';

            // Check for different actions in message
            if (strstr(client_message, "survivors") != NULL) {
                message = "There are a few of us left, but we're doing okay. How about you?\n";
            } else if (strstr(client_message, "water") != NULL) {
                message = "Water is scarce, but we've got a few wells that keep us going. How about you?\n";
            } else if (strstr(client_message, "food") != NULL) {
                message = "Food is even scarcer than water, but we've got a few farms that keep us fed. Haven't you heard? The cows are all mutants now, they don't need water or food to survive.\n";
            } else if (strstr(client_message, "weapons") != NULL) {
                message = "The only weapon we've got left is a club made of a mutated tree branch. What about you?\n";
            } else if (strstr(client_message, "exit") != NULL) {
                message = "Goodbye, stay safe out there!\n";
                write(new_socket, message, strlen(message));
                break;
            } else {
                message = "Sorry, I don't understand. Please ask me about survivors, water, food, weapons, or say exit to leave.\n";
            }
            // Send response message
            write(new_socket, message, strlen(message));
            memset(client_message, 0, MESSAGE_SIZE);
        }

        // Connection terminated
        if (read_size == 0) {
            puts("Client disconnected");
            fflush(stdout);
        } else if (read_size == -1) {
            perror("Error receiving from client");
        }
    }

    if (new_socket < 0) {
        perror("Error accepting connection");
        return 1;
    }
    return 0;
}