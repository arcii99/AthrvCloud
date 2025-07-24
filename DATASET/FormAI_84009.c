//FormAI DATASET v1.0 Category: Simple Web Server ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

// Define a constant to represent the maximum number of bytes to be read.
#define MAX_READ_BYTES 1024

// Define a function to display an error message and exit the program.
void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {

    // Make sure user has specified the correct port number.
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port_number>\n", argv[0]);
        exit(1);
    }

    // Convert the port number argument from string to integer.
    int port_no = atoi(argv[1]);

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Define the server address struct.
    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr)); // Clear the address struct.
    serv_addr.sin_family = AF_INET; // Set the address family to IPv4.
    serv_addr.sin_addr.s_addr = INADDR_ANY; // Bind the socket to all interfaces.
    serv_addr.sin_port = htons(port_no); // Set the port number.

    // Bind the socket to the server address.
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }

    // Listen for incoming connections.
    listen(sockfd, 5);

    // Accept incoming connections.
    struct sockaddr_in cli_addr;
    socklen_t clilen = sizeof(cli_addr);
    int newsockfd = accept(sockfd,  (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        error("ERROR on accept");
    }

    // Read the request message sent by the client.
    char buffer[MAX_READ_BYTES];
    bzero(buffer, MAX_READ_BYTES);
    int n = read(newsockfd, buffer, MAX_READ_BYTES);
    if (n < 0) {
        error("ERROR reading from socket");
    }

    // Display the request message received from the client.
    printf("Here is the message: %s\n", buffer);

    // Write a response message to send back to the client.
    char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: 12\r\n\r\nHello world!";
    n = write(newsockfd, response, strlen(response));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Close the socket.
    close(newsockfd);
    close(sockfd);
    return 0;
}