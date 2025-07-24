//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *user, *pass, *command, *response;
    bool logged_in = false;

    if (argc != 3) {
        printf("Usage: %s <server> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    user = argv[2];
    pass = getpass("Password: ");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket");
        return EXIT_FAILURE;
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);

    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("Failed to convert address to binary");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return EXIT_FAILURE;
    }

    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Login
    command = "USER %s\r\n";
    snprintf(buffer, BUFFER_SIZE, command, user);
    write(sockfd, buffer, strlen(buffer));

    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    command = "PASS %s\r\n";
    snprintf(buffer, BUFFER_SIZE, command, pass);
    write(sockfd, buffer, strlen(buffer));

    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    logged_in = true;

    // List messages
    command = "LIST\r\n";
    write(sockfd, command, strlen(command));

    if (read(sockfd, buffer, BUFFER_SIZE) > 0) {
        if (buffer[0] == '+') {
            printf("%s", buffer);

            // Read response until "." is found
            while (true) {
                read(sockfd, buffer, BUFFER_SIZE);
                printf("%s", buffer);

                if (buffer[0] == '.') {
                    break;
                }
            }
        } else {
            printf("Failed to list messages\n");
        }
    }

    // Logout
    if (logged_in) {
        command = "QUIT\r\n";
        write(sockfd, command, strlen(command));

        read(sockfd, buffer, BUFFER_SIZE);
        printf("%s", buffer);
    }

    close(sockfd);

    return EXIT_SUCCESS;
}