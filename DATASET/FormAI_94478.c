//FormAI DATASET v1.0 Category: Chat server ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *greetings = "Hello, I am a statistical Chatbot. How can I assist you today?\n";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the the PORT 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding socket with address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening on created socket
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accepting incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Sending greetings message to the client
    send(new_socket , greetings , strlen(greetings) , 0);

    while(1) {
        // Reading message from the client
        printf("\nWaiting for client message...\n");
        valread = read(new_socket , buffer, 1024);
        printf("Client sent message: %s\n", buffer);

        if(strcmp(buffer, "bye\n") == 0) {
            // Ending the chat session
            char *bye = "Goodbye! Have a great day :) \n";
            send(new_socket, bye, strlen(bye), 0);
            break;
        }
        else {
            // Generating random numbers as a response to the client message
            int count = 0, sum = 0, max = -2147483647, min = 2147483647;

            char *token = strtok(buffer, " ");
            while(token != NULL) {
                int num = atoi(token);
                count++;
                sum += num;
                if(num > max)
                    max = num;
                if(num < min)
                    min = num;
                token = strtok(NULL, " ");
            }

            float mean = (float)sum/count;
            char response[500];
            sprintf(response, "Total numbers: %d\nSum of numbers: %d\nMean of numbers: %.2f\nMax of numbers: %d\nMin of numbers: %d\n", count, sum, mean, max, min);

            // Sending generated response to the client
            send(new_socket , response , strlen(response) , 0);
        }
        memset(buffer,0,sizeof(buffer));
    }

    // Closing the socket file descriptor
    close(new_socket);
    close(server_fd);
    return 0;
}