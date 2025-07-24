//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {

    char* server_address = "mail.example.com"; // replace with your server's address
    int server_port = 25; // SMTP port is typically 25

    // create a socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // set up the server address and port
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_port = htons(server_port);

    // connect to the server
    if (connect(client_socket, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Error connecting to the server");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server at %s:%d\n", server_address, server_port);

    // receive the server's greeting message
    char server_message[BUFFER_SIZE];
    memset(server_message, 0, BUFFER_SIZE);
    if (recv(client_socket, server_message, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving server message");
        exit(EXIT_FAILURE);
    }
    printf("Server message: %s\n", server_message);

    // send the initial SMTP handshake
    char client_message[BUFFER_SIZE];
    memset(client_message, 0, BUFFER_SIZE);
    snprintf(client_message, BUFFER_SIZE, "HELO %s\r\n", server_address);
    if (send(client_socket, client_message, strlen(client_message), 0) < 0) {
        perror("Error sending client message");
        exit(EXIT_FAILURE);
    }
    printf("Sent client message: %s", client_message);

    // receive the server's response
    memset(server_message, 0, BUFFER_SIZE);
    if (recv(client_socket, server_message, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving server message");
        exit(EXIT_FAILURE);
    }
    printf("Server message: %s\n", server_message);

    // send the mail from command with a "from" address
    memset(client_message, 0, BUFFER_SIZE);
    snprintf(client_message, BUFFER_SIZE, "MAIL FROM:<myemail@example.com>\r\n");
    if (send(client_socket, client_message, strlen(client_message), 0) < 0) {
        perror("Error sending client message");
        exit(EXIT_FAILURE);
    }
    printf("Sent client message: %s", client_message);

    // receive the server's response
    memset(server_message, 0, BUFFER_SIZE);
    if (recv(client_socket, server_message, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving server message");
        exit(EXIT_FAILURE);
    }
    printf("Server message: %s\n", server_message);

    // send the mail to command with a "to" address
    memset(client_message, 0, BUFFER_SIZE);
    snprintf(client_message, BUFFER_SIZE, "RCPT TO:<recipient@example.com>\r\n");
    if (send(client_socket, client_message, strlen(client_message), 0) < 0) {
        perror("Error sending client message");
        exit(EXIT_FAILURE);
    }
    printf("Sent client message: %s", client_message);

    // receive the server's response
    memset(server_message, 0, BUFFER_SIZE);
    if (recv(client_socket, server_message, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving server message");
        exit(EXIT_FAILURE);
    }
    printf("Server message: %s\n", server_message);

    // send the data command to start the email message
    memset(client_message, 0, BUFFER_SIZE);
    snprintf(client_message, BUFFER_SIZE, "DATA\r\n");
    if (send(client_socket, client_message, strlen(client_message), 0) < 0) {
        perror("Error sending client message");
        exit(EXIT_FAILURE);
    }
    printf("Sent client message: %s", client_message);

    // receive the server's response
    memset(server_message, 0, BUFFER_SIZE);
    if (recv(client_socket, server_message, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving server message");
        exit(EXIT_FAILURE);
    }
    printf("Server message: %s\n", server_message);

    // send the email message body
    memset(client_message, 0, BUFFER_SIZE);
    snprintf(client_message, BUFFER_SIZE, "From: My Name <myemail@example.com>\r\nTo: Recipient <recipient@example.com>\r\nSubject: Testing SMTP\r\n\r\nHello, this is a test email.\r\n.\r\n");
    if (send(client_socket, client_message, strlen(client_message), 0) < 0) {
        perror("Error sending client message");
        exit(EXIT_FAILURE);
    }
    printf("Sent client message: %s", client_message);

    // receive the server's response to the email message
    memset(server_message, 0, BUFFER_SIZE);
    if (recv(client_socket, server_message, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving server message");
        exit(EXIT_FAILURE);
    }
    printf("Server message: %s\n", server_message);

    // send the quit command to end the SMTP session
    memset(client_message, 0, BUFFER_SIZE);
    snprintf(client_message, BUFFER_SIZE, "QUIT\r\n");
    if (send(client_socket, client_message, strlen(client_message), 0) < 0) {
        perror("Error sending client message");
        exit(EXIT_FAILURE);
    }
    printf("Sent client message: %s", client_message);

    // receive the server's confirmation of the quit command
    memset(server_message, 0, BUFFER_SIZE);
    if (recv(client_socket, server_message, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving server message");
        exit(EXIT_FAILURE);
    }
    printf("Server message: %s\n", server_message);

    // close the socket and exit
    close(client_socket);
    return EXIT_SUCCESS;
}