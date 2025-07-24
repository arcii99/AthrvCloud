//FormAI DATASET v1.0 Category: Client Server Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_MESSAGE_LENGTH 1024

void puzzle(char *message) {
    char result[MAX_MESSAGE_LENGTH];
    int index = 0;
    for(int i = 0; message[i] != '\0'; i++) {
        if(i % 2 == 0) {
            result[index] = message[i] - 1;
        } else {
            result[index] = message[i] + 1;
        }
        index++;
    }
    result[index] = '\0';
    strcpy(message, result);
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_MESSAGE_LENGTH];
    char *hello = "Hello! What is the answer to this puzzle? Answer with the same punctuation (!, ?, .)\nL kdyh wdnh dqg grq'w vrphrqh zlwk \n+rz rq wkhuh wr gr  xvlqb.?\n";
    char *answer = "I think I got it! The answer is: \n";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed.");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the PORT
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Forcefully attaching socket to the PORT
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Send the puzzle to the client
    send(new_socket, hello, strlen(hello), 0);

    // Receive the answer and puzzle back the response
    valread = read(new_socket , buffer, MAX_MESSAGE_LENGTH);
    puzzle(buffer);

    // Send the answer back to the client
    char output[MAX_MESSAGE_LENGTH];
    sprintf(output, "%s%s", answer, buffer);
    send(new_socket, output, strlen(output), 0);
    printf("Answer was sent to the client.\n");
    return 0;
}