//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int client_socket, portno, n = 0, len = 0;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE];
    char *from = "sender@example.com";
    char *to = "receiver@example.com";
    char *server = "mail.example.com";

    // construct message
    memset(message, 0, BUFFER_SIZE);
    strcat(message, "From: ");
    strcat(message, from);
    strcat(message, "\r\nTo: ");
    strcat(message, to);
    strcat(message, "\r\nSubject: Test SMTP Client\r\n\r\n");
    strcat(message, "Hello, this is a test email.\r\n");

    // create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // set server address and port
    memset(&server_address, 0, sizeof(server_address));
    portno = 25;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server);
    server_address.sin_port = htons(portno);

    // connect to server
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // receive welcome message from server
    memset(buffer, 0, BUFFER_SIZE);
    n = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("ERROR receiving message");
        exit(1);
    }
    printf("%s", buffer);

    // send HELO message to server
    memset(message, 0, BUFFER_SIZE);
    sprintf(message, "HELO %s\r\n", from);
    len = strlen(message);
    n = send(client_socket, message, len, 0);
    if (n < 0) {
        perror("ERROR sending message");
        exit(1);
    }
    printf("%s", message);

    // receive response from server
    memset(buffer, 0, BUFFER_SIZE);
    n = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("ERROR receiving message");
        exit(1);
    }
    printf("%s", buffer);

    // send MAIL FROM message to server
    memset(message, 0, BUFFER_SIZE);
    sprintf(message, "MAIL FROM:<%s>\r\n", from);
    len = strlen(message);
    n = send(client_socket, message, len, 0);
    if (n < 0) {
        perror("ERROR sending message");
        exit(1);
    }
    printf("%s", message);

    // receive response from server
    memset(buffer, 0, BUFFER_SIZE);
    n = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("ERROR receiving message");
        exit(1);
    }
    printf("%s", buffer);

    // send RCPT TO message to server
    memset(message, 0, BUFFER_SIZE);
    sprintf(message, "RCPT TO:<%s>\r\n", to);
    len = strlen(message);
    n = send(client_socket, message, len, 0);
    if (n < 0) {
        perror("ERROR sending message");
        exit(1);
    }
    printf("%s", message);

    // receive response from server
    memset(buffer, 0, BUFFER_SIZE);
    n = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("ERROR receiving message");
        exit(1);
    }
    printf("%s", buffer);

    // send DATA message to server
    memset(message, 0, BUFFER_SIZE);
    sprintf(message, "DATA\r\n");
    len = strlen(message);
    n = send(client_socket, message, len, 0);
    if (n < 0) {
        perror("ERROR sending message");
        exit(1);
    }
    printf("%s", message);

    // receive response from server
    memset(buffer, 0, BUFFER_SIZE);
    n = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("ERROR receiving message");
        exit(1);
    }
    printf("%s", buffer);

    // send message body to server
    len = strlen(message);
    n = send(client_socket, message, len, 0);
    if (n < 0) {
        perror("ERROR sending message");
        exit(1);
    }
    printf("%s", message);

    // send QUIT message to server
    memset(message, 0, BUFFER_SIZE);
    sprintf(message, "QUIT\r\n");
    len = strlen(message);
    n = send(client_socket, message, len, 0);
    if (n < 0) {
        perror("ERROR sending message");
        exit(1);
    }
    printf("%s", message);

    // receive response from server
    memset(buffer, 0, BUFFER_SIZE);
    n = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("ERROR receiving message");
        exit(1);
    }
    printf("%s", buffer);

    // close socket
    close(client_socket);

    return 0;
}