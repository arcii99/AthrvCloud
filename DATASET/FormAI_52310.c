//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

/* Function to check the response code from the server */
int check_response(char* response) {
    char *token;
    
    token = strtok(response, " ");
    
    if (token == NULL) {
        return -1;
    }
    
    if (strcmp(token, "+OK") == 0) {
        return 0;
    } else {
        return -1;
    }
}

int main(int argc, char *argv[]) {
    // Check if enough arguments are passed
    if (argc != 4) {
        printf("Usage: %s <server ip> <username> <password>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Initialize server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(110);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Read response from the server
    char response[MAX_BUFFER_SIZE];
    bzero(response, MAX_BUFFER_SIZE);
    if (read(sockfd, response, MAX_BUFFER_SIZE) < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    // Check response code
    if (check_response(response) != 0) {
        printf("Authentication failed\n");
        exit(1);
    }

    // Send USER command
    char user[MAX_BUFFER_SIZE];
    bzero(user, MAX_BUFFER_SIZE);
    sprintf(user, "USER %s\r\n", argv[2]);
    if (send(sockfd, user, strlen(user), 0) < 0) {
        perror("Error sending message");
        exit(1);
    }

    // Read response
    bzero(response, MAX_BUFFER_SIZE);
    if (read(sockfd, response, MAX_BUFFER_SIZE) < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    // Check response code
    if (check_response(response) != 0) {
        printf("Authentication failed\n");
        exit(1);
    }

    // Send PASS command
    char pass[MAX_BUFFER_SIZE];
    bzero(pass, MAX_BUFFER_SIZE);
    sprintf(pass, "PASS %s\r\n", argv[3]);
    if (send(sockfd, pass, strlen(pass), 0) < 0) {
        perror("Error sending message");
        exit(1);
    }

    // Read response
    bzero(response, MAX_BUFFER_SIZE);
    if (read(sockfd, response, MAX_BUFFER_SIZE) < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    // Check response code
    if (check_response(response) != 0) {
        printf("Authentication failed\n");
        exit(1);
    }

    // Send STAT command to get number of emails
    char stat[MAX_BUFFER_SIZE];
    bzero(stat, MAX_BUFFER_SIZE);
    sprintf(stat, "STAT\r\n");
    if (send(sockfd, stat, strlen(stat), 0) < 0) {
        perror("Error sending message");
        exit(1);
    }

    // Read response
    bzero(response, MAX_BUFFER_SIZE);
    if (read(sockfd, response, MAX_BUFFER_SIZE) < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    // Parse response to get number of emails
    char *token;
    token = strtok(response, " ");
    token = strtok(NULL, " ");
    int num_emails = atoi(token);

    // Loop through emails and download them
    for (int i = 1; i <= num_emails; i++) {
        // Send RETR command to get email content
        char retr[MAX_BUFFER_SIZE];
        bzero(retr, MAX_BUFFER_SIZE);
        sprintf(retr, "RETR %d\r\n", i);
        if (send(sockfd, retr, strlen(retr), 0) < 0) {
            perror("Error sending message");
            continue;
        }

        // Read response
        bzero(response, MAX_BUFFER_SIZE);
        if (read(sockfd, response, MAX_BUFFER_SIZE) < 0) {
            perror("Error reading from socket");
            continue;
        }

        // Check response code
        if (check_response(response) != 0) {
            printf("Error retrieving email %d\n", i);
            continue;
        }

        // Print email content
        printf("Email %d:\n%s\n", i, response);
    }

    // Send QUIT command to logout
    char quit[MAX_BUFFER_SIZE];
    bzero(quit, MAX_BUFFER_SIZE);
    sprintf(quit, "QUIT\r\n");
    if (send(sockfd, quit, strlen(quit), 0) < 0) {
        perror("Error sending message");
        exit(1);
    }

    // Read response
    bzero(response, MAX_BUFFER_SIZE);
    if (read(sockfd, response, MAX_BUFFER_SIZE) < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    // Check response code
    if (check_response(response) != 0) {
        printf("Error logging out\n");
        exit(1);
    }

    printf("Logout successful\n");

    // Close socket
    close(sockfd);

    return 0;
}