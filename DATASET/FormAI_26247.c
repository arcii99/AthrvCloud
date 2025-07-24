//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <server_address> <server_port>\n", argv[0]);
        return 1;
    }

    int sockfd;
    struct sockaddr_in server_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create a socket");
        return 1;
    }

    // Set the server address and port number
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to the server");
        close(sockfd);
        return 1;
    }

    // Receive the welcome message from the server
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE - 1, 0) < 0) {
        perror("Failed to receive the welcome message from the server");
        close(sockfd);
        return 1;
    }
    printf("%s", buffer);

    // Send the user credentials to the server
    char user[100], pass[100];
    printf("User: ");
    fgets(user, 100, stdin);
    user[strcspn(user, "\n")] = 0;  // remove the newline
    printf("Password: ");
    fgets(pass, 100, stdin);
    pass[strcspn(pass, "\n")] = 0;  // remove the newline

    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "USER %s\r\n", user);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send the USER command to the server");
        close(sockfd);
        return 1;
    }

    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE - 1, 0) < 0) {
        perror("Failed to receive the response to the USER command from the server");
        close(sockfd);
        return 1;
    }
    printf("%s", buffer);

    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "PASS %s\r\n", pass);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send the PASS command to the server");
        close(sockfd);
        return 1;
    }

    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE - 1, 0) < 0) {
        perror("Failed to receive the response to the PASS command from the server");
        close(sockfd);
        return 1;
    }
    printf("%s", buffer);

    // List the messages
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "LIST\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send the LIST command to the server");
        close(sockfd);
        return 1;
    }

    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE - 1, 0) < 0) {
        perror("Failed to receive the response to the LIST command from the server");
        close(sockfd);
        return 1;
    }
    printf("%s", buffer);

    // Retrieve a message
    printf("Which message would you like to retrieve? ");
    int msgnum;
    scanf("%d", &msgnum);

    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "RETR %d\r\n", msgnum);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send the RETR command to the server");
        close(sockfd);
        return 1;
    }

    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE - 1, 0) < 0) {
        perror("Failed to receive the response to the RETR command from the server");
        close(sockfd);
        return 1;
    }
    printf("%s", buffer);

    // Delete a message
    printf("Would you like to delete the message? (y/n) ");
    char response;
    scanf(" %c", &response);

    if (response == 'y') {
        memset(buffer, 0, BUFFER_SIZE);
        sprintf(buffer, "DELE %d\r\n", msgnum);
        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            perror("Failed to send the DELE command to the server");
            close(sockfd);
            return 1;
        }

        memset(buffer, 0, BUFFER_SIZE);
        if (recv(sockfd, buffer, BUFFER_SIZE - 1, 0) < 0) {
            perror("Failed to receive the response to the DELE command from the server");
            close(sockfd);
            return 1;
        }
        printf("%s", buffer);
    }

    // Quit the session
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send the QUIT command to the server");
        close(sockfd);
        return 1;
    }

    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE - 1, 0) < 0) {
        perror("Failed to receive the response to the QUIT command from the server");
        close(sockfd);
        return 1;
    }
    printf("%s", buffer);

    // Close the connection
    close(sockfd);

    return 0;
}