//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXSIZE 4096

// Function to read a response from the IMAP server
void read_response(int sockfd) {
    char buffer[MAXSIZE];
    int bytes_received = recv(sockfd, buffer, MAXSIZE, 0);
    // Print out the response
    printf("%s", buffer);
}

int main(int argc, char **argv) {
    int sockfd;
    char buffer[MAXSIZE];
    struct sockaddr_in servaddr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Set up the address of the server
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(993); // IMAP default port
    inet_pton(AF_INET, "mail.example.com", &servaddr.sin_addr);

    // Connect to the server
    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    read_response(sockfd); // Should receive a greeting response

    // Send the login command
    sprintf(buffer, "LOGIN username password\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    read_response(sockfd); // Should receive a success response

    // Send the select command to select the inbox
    sprintf(buffer, "SELECT INBOX\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    read_response(sockfd); // Should receive a success response

    // Send the search command to retrieve all emails
    sprintf(buffer, "SEARCH ALL\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    read_response(sockfd); // Should receive a list of email IDs

    // Send the fetch command to retrieve the first email
    sprintf(buffer, "FETCH 1 BODY[]\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    read_response(sockfd); // Should receive the email data

    // Logout and close the socket
    sprintf(buffer, "LOGOUT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    read_response(sockfd); // Should receive a success response
    close(sockfd); // Close the socket

    return 0;
}