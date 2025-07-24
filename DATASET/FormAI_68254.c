//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG_LEN 1024

// Function to remove newline character from string
void removeNewLineChar(char* str) {
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    // Initialize socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Failed to create socket\n");
        exit(1);
    }

    // Connect to mail server (POP3 server)
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Replace with your mail server IP address
    server.sin_port = htons(110); // POP3 server port number
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        printf("Failed to connect to server\n");
        exit(1);
    }

    // Receive reply from POP3 server after successful connection
    char reply[MAX_MSG_LEN];
    memset(reply, 0, sizeof(reply));
    if (recv(sock, reply, sizeof(reply), 0) < 0) {
        printf("Failed to receive reply from server\n");
        exit(1);
    }

    // Print server reply
    printf("%s\n", reply);

    // Send USER command
    char userMsg[MAX_MSG_LEN] = "USER johnsmith\n"; // Replace with your username
    removeNewLineChar(userMsg);
    if (send(sock, userMsg, strlen(userMsg), 0) < 0) {
        printf("Failed to send USER command\n");
        exit(1);
    }

    // Receive reply from POP3 server after sending USER command
    memset(reply, 0, sizeof(reply));
    if (recv(sock, reply, sizeof(reply), 0) < 0) {
        printf("Failed to receive reply from server\n");
        exit(1);
    }

    // Print server reply
    printf("%s\n", reply);

    // Send PASS command
    char passMsg[MAX_MSG_LEN] = "PASS password\n"; // Replace with your password
    removeNewLineChar(passMsg);
    if (send(sock, passMsg, strlen(passMsg), 0) < 0) {
        printf("Failed to send PASS command\n");
        exit(1);
    }

    // Receive reply from POP3 server after sending PASS command
    memset(reply, 0, sizeof(reply));
    if (recv(sock, reply, sizeof(reply), 0) < 0) {
        printf("Failed to receive reply from server\n");
        exit(1);
    }

    // Print server reply
    printf("%s\n", reply);

    // Send LIST command to retrieve list of emails
    char listMsg[MAX_MSG_LEN] = "LIST\n";
    removeNewLineChar(listMsg);
    if (send(sock, listMsg, strlen(listMsg), 0) < 0) {
        printf("Failed to send LIST command\n");
        exit(1);
    }

    // Receive reply from POP3 server after sending LIST command
    memset(reply, 0, sizeof(reply));
    if (recv(sock, reply, sizeof(reply), 0) < 0) {
        printf("Failed to receive reply from server\n");
        exit(1);
    }

    // Print server reply
    printf("%s\n", reply);

    // Send RETR command to retrieve email content
    char retrMsg[MAX_MSG_LEN] = "RETR 1\n"; // Replace 1 with desired email number from list
    removeNewLineChar(retrMsg);
    if (send(sock, retrMsg, strlen(retrMsg), 0) < 0) {
        printf("Failed to send RETR command\n");
        exit(1);
    }

    // Receive reply from POP3 server after sending RETR command
    memset(reply, 0, sizeof(reply));
    if (recv(sock, reply, sizeof(reply), 0) < 0) {
        printf("Failed to receive reply from server\n");
        exit(1);
    }

    // Print server reply
    printf("%s\n", reply);

    // Close socket and exit program
    close(sock);
    return 0;
}