//FormAI DATASET v1.0 Category: Socket programming ; Style: scientific
/* 

Title: Socket Programming Example - Scientific Calculator

Description: This program implements a simple client-server architecture using sockets, where the client can send mathematical expressions to the server, and the server responds with the calculated result.

Author: Jane Doe

Date: 2022-09-01

*/

// Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <math.h>

// Port number of server
#define SERVER_PORT 8080

// Function to evaluate mathematical expressions
double evaluate(char *exp, int len) {
    char buffer[len + 1];
    strncpy(buffer, exp, len);
    buffer[len] = '\0';
    return atof(buffer);
}

// Main function
int main(int argc, char const *argv[]) {

    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    char *message = "Connected to the server!\n";
    double result;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    // Set server addresses and port number
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return -1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        return -1;
    }

    // Send connection message to server
    send(sock, message, strlen(message), 0);

    // Receive messages from server
    while(1) {
        valread = read(sock, buffer, 1024);

        // Check for termination message from server
        if (strcmp(buffer, "terminate") == 0) {
            printf("Terminating connection.\n");
            break;
        }

        // Evaluate mathematical expression
        result = evaluate(buffer, valread);
        printf("Received expression: %s\n", buffer);
        printf("Calculated result: %f\n", result);

        // Send result to server
        char resp[50];
        sprintf(resp, "%.2f", result);
        send(sock, resp, strlen(resp), 0);

        memset(buffer, 0, sizeof(buffer));
        memset(resp, 0, sizeof(resp));
    }

    // Close socket connection
    close(sock);

    return 0;
}