//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[])
{
    int sock_fd, bytes_read;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER] = {0};
    char username[MAX_BUFFER], password[MAX_BUFFER];
    const char *hostname = "mail.example.com"; // replace with your own POP3 server's hostname or IP address
    const int port = 110; // default port for POP3 protocol

    // create a socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if(inet_pton(AF_INET, hostname, &server_addr.sin_addr)<=0) {
        perror("Invalid hostname or IP address");
        exit(EXIT_FAILURE);
    }

    // connect to server
    if (connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // read welcome message from server
    memset(buffer, 0, MAX_BUFFER);
    bytes_read = read(sock_fd, buffer, MAX_BUFFER);
    if (bytes_read < 0) {
        perror("Error reading response from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // send authentication credentials
    printf("Enter your username: ");
    fgets(username, MAX_BUFFER, stdin);
    printf("Enter your password: ");
    fgets(password, MAX_BUFFER, stdin);

    snprintf(buffer, MAX_BUFFER, "USER %s", username);
    write(sock_fd, buffer, strlen(buffer));
    memset(buffer, 0, MAX_BUFFER);
    bytes_read = read(sock_fd, buffer, MAX_BUFFER);
    printf("%s", buffer);

    snprintf(buffer, MAX_BUFFER, "PASS %s", password);
    write(sock_fd, buffer, strlen(buffer));
    memset(buffer, 0, MAX_BUFFER);
    bytes_read = read(sock_fd, buffer, MAX_BUFFER);
    printf("%s", buffer);

    // list all messages
    snprintf(buffer, MAX_BUFFER, "LIST");
    write(sock_fd, buffer, strlen(buffer));
    memset(buffer, 0, MAX_BUFFER);
    bytes_read = read(sock_fd, buffer, MAX_BUFFER);
    printf("%s", buffer);

    // quit session
    snprintf(buffer, MAX_BUFFER, "QUIT");
    write(sock_fd, buffer, strlen(buffer));
    memset(buffer, 0, MAX_BUFFER);
    bytes_read = read(sock_fd, buffer, MAX_BUFFER);
    printf("%s", buffer);

    // close socket
    close(sock_fd);

    return 0;
}