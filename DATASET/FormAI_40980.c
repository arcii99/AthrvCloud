//FormAI DATASET v1.0 Category: Socket programming ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888

int main(int argc, char **argv) {

    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char message[1024];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    // Configuring server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to address/port
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind error");
        exit(EXIT_FAILURE);
    }

    // Start listening for client connections
    if (listen(sockfd, 3) < 0) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    printf("Genius chatbot is listening on port %d \n", PORT);

    while (1) {

        socklen_t client_size = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_size);

        printf("Connection accepted from %s:%d \n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Send welcome message to client
        sprintf(message, "Welcome to the Genius chatbot. Type 'exit' to quit.\n");
        write(client_sockfd, message, strlen(message));

        while (1) {

            // Receive message from client
            memset(message, 0, sizeof(message));
            read(client_sockfd, message, sizeof(message));

            // If message is "exit", close connection
            if (strcmp(message, "exit\n") == 0) {
                printf("Connection closed from %s:%d \n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                close(client_sockfd);
                break;
            }

            // Genius chatbot response
            char response[1024] = {0};
            srand(time(NULL));
            int genius_num = rand() % 3;
            if (genius_num == 0) {
                sprintf(response, "I'm sorry, I cannot answer that question. Please try again.\n");
            } else if (genius_num == 1) {
                sprintf(response, "Interesting question. Let me think about it for a moment...\n");
            } else {
                sprintf(response, "Ah yes, I know the answer to that question. It's...\n");
            }

            write(client_sockfd, response, strlen(response));
        }
    }

    return 0;  
}