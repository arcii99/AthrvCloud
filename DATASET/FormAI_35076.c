//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>         // For socket()
#include <netinet/in.h>         // For sockaddr_in

#define PORT 8000
#define BUFSIZE 1024

int main() {
    int sockfd, newsockfd, bind_result, listen_result, on = 1;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char buffer[BUFSIZE];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error creating socket!\n");
        exit(1);
    }

    // Set socket options
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    // Clear server struct
    memset(&serv_addr, 0, sizeof(serv_addr));

    // Set server options
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind socket to port
    if ((bind_result = bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))) < 0) {
        printf("Error binding socket to port!\n");
        exit(1);
    }

    // Listen for connections
    if ((listen_result = listen(sockfd, 5)) < 0) {
        printf("Error listening for connections!\n");
        exit(1);
    }

    printf("Server listening at port %d\n", PORT);

    // Accept incoming connections
    clilen = sizeof(cli_addr);
    if ((newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen)) < 0) {
        printf("Error accepting connection!\n");
        exit(1);
    }

    printf("Client connected!\n");

    // Receive data from client
    memset(buffer, 0, BUFSIZE);
    int n = recv(newsockfd, buffer, BUFSIZE, 0);
    if (n < 0) {
        printf("Error receiving data from client!\n");
        exit(1);
    }

    // Print received data
    printf("Received message: %s\n", buffer);

    // Send response to client
    char response[BUFSIZE] = "Message received!";
    n = send(newsockfd, response, strlen(response), 0);
    if (n < 0) {
        printf("Error sending response to client!\n");
        exit(1);
    }

    printf("Message sent: %s\n", response);

    // Close sockets and exit
    close(newsockfd);
    close(sockfd);
    return 0;
}