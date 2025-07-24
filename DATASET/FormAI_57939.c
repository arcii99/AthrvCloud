//FormAI DATASET v1.0 Category: Client Server Application ; Style: protected
/* This is a simple client-server program using sockets in C.
 * Communication occurs over the local loopback address.
 * The server receives messages from the client, capitalizes them, and sends them back.
 * The client and server communicate until the client types "exit".
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for close()
#include <string.h>
#include <ctype.h> // for toupper()
#include <arpa/inet.h> // for socket(), bind(), and connect()

#define MAX_MESSAGE_SIZE 100
#define PORT 5000

void capitalize_message(char* message);

int main() {
    int sockfd, client_sockfd;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);
    char message[MAX_MESSAGE_SIZE];

    /* Create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(1);
    }

    /* Bind to address and port */
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket to address and port");
        exit(1);
    }

    /* Listen for incoming connections */
    if (listen(sockfd, 1) == -1) {
        perror("Error listening for incoming connections");
        exit(1);
    }
    printf("Server is listening on port %d ...\n", PORT);

    /* Accept incoming connections */
    client_sockfd = accept(sockfd, (struct sockaddr *) &client_address, &client_address_len);
    if (client_sockfd == -1) {
        perror("Error accepting incoming connections");
        exit(1);
    }
    printf("Accepted incoming connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    /* Receive messages and send back capitalized versions until client types "exit" */
    do {
        bzero(message, MAX_MESSAGE_SIZE); // clear buffer
        if (read(client_sockfd, message, MAX_MESSAGE_SIZE) == -1) {
            perror("Error reading message from client");
            exit(1);
        }
        capitalize_message(message);
        if (write(client_sockfd, message, strlen(message)) == -1) {
            perror("Error sending message to client");
            exit(1);
        }
    } while (strcmp(message, "exit\n") != 0);

    /* Close sockets */
    close(client_sockfd);
    close(sockfd);

    return 0;
}

/* Turn all characters in message to uppercase */
void capitalize_message(char* message) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        message[i] = toupper(message[i]);
    }
}