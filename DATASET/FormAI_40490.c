//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: artistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

// Function to send data to server
void send_data(int socket, char *data) {
    printf("Sending data: %s\n", data);
    send(socket, data, strlen(data), 0);
}

// Function to receive data from server
void receive_data(int socket) {
    char buffer[1024];
    memset(buffer, 0, 1024);
    recv(socket, buffer, 1024, 0);
    printf("Received data: %s\n", buffer);
}

// Main function
int main() {
    // Initialize socket
    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket\n");
        return -1;
    }

    // Initialize server address
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(25);

    // Connect to server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Could not connect to server\n");
        return -1;
    }

    // Receive banner from server
    receive_data(socket_desc);

    // Send HELO command to server
    send_data(socket_desc, "HELO localhost\r\n");
    receive_data(socket_desc);

    // Send MAIL FROM command to server
    send_data(socket_desc, "MAIL FROM: <example@example.com>\r\n");
    receive_data(socket_desc);

    // Send RCPT TO command to server
    send_data(socket_desc, "RCPT TO: <recipient@example.com>\r\n");
    receive_data(socket_desc);

    // Send DATA command to server
    send_data(socket_desc, "DATA\r\n");
    receive_data(socket_desc);

    // Send email body to server
    send_data(socket_desc, "From: example@example.com\r\nTo: recipient@example.com\r\nSubject: Test Email\r\n\r\nHello, world!\r\n.\r\n");

    // Exit program with success
    close(socket_desc);
    return 0;
}