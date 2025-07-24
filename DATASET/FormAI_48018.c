//FormAI DATASET v1.0 Category: Firewall ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to check if the IP address is in the blocked list
int isBlocked(char* ip_address, char** blocked_list, int blocked_list_size) {
    for (int i = 0; i < blocked_list_size; i++) {
        if (strcmp(ip_address, blocked_list[i]) == 0) {
            return 1; // IP address is in the blocked list
        }
    }
    return 0; // IP address is not in the blocked list
}

int main() {
    int sockfd, newsockfd, portno;
    socklen_t cli_len;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // List of IP addresses to block
    char* blocked_list[] = {"192.168.1.10", "10.0.2.5", "172.16.0.1"};
    int blocked_list_size = sizeof(blocked_list) / sizeof(char*);

    // Create a new socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Initialize server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 5001; // Port number on which the server will listen
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket to server address");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    // Accept incoming connections
    cli_len = sizeof(cli_addr);
    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &cli_len);
        if (newsockfd < 0) {
            perror("Error accepting connection");
            exit(1);
        }

        // Convert client IP address to string
        char ip_address[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(cli_addr.sin_addr), ip_address, INET_ADDRSTRLEN);

        // Check if client IP address is in the blocked list
        if (isBlocked(ip_address, blocked_list, blocked_list_size)) {
            printf("Connection from %s blocked\n", ip_address);

            // Send a message to the client and close the connection
            char block_message[] = "Access Denied. Your IP address is blocked by the Firewall.\n";
            write(newsockfd, block_message, strlen(block_message));
            close(newsockfd);
        } else {
            printf("Connection from %s allowed\n", ip_address);

            // Receive data from the client
            bzero(buffer, BUFFER_SIZE);
            n = read(newsockfd, buffer, BUFFER_SIZE - 1);
            if (n < 0) {
                perror("Error reading from socket");
                exit(1);
            }

            // Print the received message
            printf("Message from %s: %s", ip_address, buffer);

            // Send a response to the client
            char response[] = "Message received.\n";
            write(newsockfd, response, strlen(response));
            close(newsockfd);
        }
    }

    close(sockfd);
    return 0;
}