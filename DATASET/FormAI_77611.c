//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_ADDR "smtp.gmail.com"
#define SERVER_PORT 587
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE], response[BUFFER_SIZE];
    int len, resp_len;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    server_addr.sin_port = htons(SERVER_PORT);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // read welcome message
    resp_len = read(sockfd, response, BUFFER_SIZE - 1);
    response[resp_len] = '\0';
    printf("%s\n", response);

    // send HELO command
    strcpy(buffer, "HELO localhost\r\n");
    len = strlen(buffer);
    write(sockfd, buffer, len);

    // read response
    resp_len = read(sockfd, response, BUFFER_SIZE - 1);
    response[resp_len] = '\0';
    printf("%s\n", response);

    // send STARTTLS command
    strcpy(buffer, "STARTTLS\r\n");
    len = strlen(buffer);
    write(sockfd, buffer, len);

    // read response
    resp_len = read(sockfd, response, BUFFER_SIZE - 1);
    response[resp_len] = '\0';
    printf("%s\n", response);

    // start encrypted communication
    if (strstr(response, "220 2.0.0 Ready to start TLS") != NULL) {
        if (system("openssl s_client -quiet -connect smtp.gmail.com:587 < /dev/null 2> /dev/null | grep 'Verify return code: 0'") == 0) {
            strcpy(buffer, "EHLO localhost\r\n");
            len = strlen(buffer);
            write(sockfd, buffer, len);

            // read response
            resp_len = read(sockfd, response, BUFFER_SIZE - 1);
            response[resp_len] = '\0';
            printf("%s\n", response);

            // send AUTH LOGIN command
            strcpy(buffer, "AUTH LOGIN\r\n");
            len = strlen(buffer);
            write(sockfd, buffer, len);

            // read response
            resp_len = read(sockfd, response, BUFFER_SIZE - 1);
            response[resp_len] = '\0';
            printf("%s\n", response);

            // send username
            strcpy(buffer, "<base64-encoded-username-goes-here>\r\n");
            len = strlen(buffer);
            write(sockfd, buffer, len);

            // read response
            resp_len = read(sockfd, response, BUFFER_SIZE - 1);
            response[resp_len] = '\0';
            printf("%s\n", response);

            // send password
            strcpy(buffer, "<base64-encoded-password-goes-here>\r\n");
            len = strlen(buffer);
            write(sockfd, buffer, len);

            // read response
            resp_len = read(sockfd, response, BUFFER_SIZE - 1);
            response[resp_len] = '\0';
            printf("%s\n", response);

            // send MAIL FROM command
            strcpy(buffer, "MAIL FROM:<sender-email-address-goes-here>\r\n");
            len = strlen(buffer);
            write(sockfd, buffer, len);

            // read response
            resp_len = read(sockfd, response, BUFFER_SIZE - 1);
            response[resp_len] = '\0';
            printf("%s\n", response);

            // send RCPT TO command
            strcpy(buffer, "RCPT TO:<recipient-email-address-goes-here>\r\n");
            len = strlen(buffer);
            write(sockfd, buffer, len);

            // read response
            resp_len = read(sockfd, response, BUFFER_SIZE - 1);
            response[resp_len] = '\0';
            printf("%s\n", response);

            // send DATA command
            strcpy(buffer, "DATA\r\n");
            len = strlen(buffer);
            write(sockfd, buffer, len);

            // read response
            resp_len = read(sockfd, response, BUFFER_SIZE - 1);
            response[resp_len] = '\0';
            printf("%s\n", response);

            // send message
            strcpy(buffer, "Subject: SMTP Client Example Program\r\n\r\n");
            strcat(buffer, "This is a test message sent using my SMTP client example program.\r\n");
            strcat(buffer, ".\r\n");
            len = strlen(buffer);
            write(sockfd, buffer, len);

            // read response
            resp_len = read(sockfd, response, BUFFER_SIZE - 1);
            response[resp_len] = '\0';
            printf("%s\n", response);

            // send QUIT command
            strcpy(buffer, "QUIT\r\n");
            len = strlen(buffer);
            write(sockfd, buffer, len);

            // read response
            resp_len = read(sockfd, response, BUFFER_SIZE - 1);
            response[resp_len] = '\0';
            printf("%s\n", response);
        }
        else {
            printf("Could not establish secure connection.\n");
        }
    }

    // close socket
    close(sockfd);

    return 0;
}