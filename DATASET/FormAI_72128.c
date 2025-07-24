//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define MAX_RECV_BUF 1024
#define MAX_SEND_BUF 1024

// Function to create a socket and connect to the SMTP server's IP address and port
int connect_to_server(char* server_ip, int server_port) {
    int client_socket;
    struct sockaddr_in server_addr;

    // Create a socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }
    printf("Socket created successfully\n");

    // Initialize the server address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(-1);
    }
    printf("Connected to SMTP server successfully\n");

    return client_socket;
}

int main() {
    int client_socket;
    char recv_buffer[MAX_RECV_BUF];
    char send_buffer[MAX_SEND_BUF];

    printf("Welcome to the Happy SMTP Client!\n");
    printf("Let's send some happy emails! :)\n\n");

    // Connect to the SMTP server
    char* server_ip = "192.168.1.10"; // replace with your SMTP server's IP address
    int server_port = 587; // replace with your SMTP server's port
    client_socket = connect_to_server(server_ip, server_port);

    // Wait for server greeting
    int recv_size = recv(client_socket, recv_buffer, MAX_RECV_BUF, 0);
    if (recv_size == -1) {
        printf("Error receiving from server\n");
        exit(-1);
    }
    printf("Server: %.*s", recv_size, recv_buffer);

    // Say hello to the server
    sprintf(send_buffer, "EHLO happy_client.com\r\n");
    if (send(client_socket, send_buffer, strlen(send_buffer), 0) == -1) {
        printf("Error sending to server\n");
        exit(-1);
    }
    printf("You: %s", send_buffer);

    // Wait for server response
    recv_size = recv(client_socket, recv_buffer, MAX_RECV_BUF, 0);
    if (recv_size == -1) {
        printf("Error receiving from server\n");
        exit(-1);
    }
    printf("Server: %.*s", recv_size, recv_buffer);

    // Start sending the email
    sprintf(send_buffer, "MAIL FROM: <happy_client@happy.com>\r\n");
    if (send(client_socket, send_buffer, strlen(send_buffer), 0) == -1) {
        printf("Error sending to server\n");
        exit(-1);
    }
    printf("You: %s", send_buffer);

    // Wait for server response
    recv_size = recv(client_socket, recv_buffer, MAX_RECV_BUF, 0);
    if (recv_size == -1) {
        printf("Error receiving from server\n");
        exit(-1);
    }
    printf("Server: %.*s", recv_size, recv_buffer);

    // Specify the recipient
    sprintf(send_buffer, "RCPT TO: <happy_recipient@happy.com>\r\n");
    if (send(client_socket, send_buffer, strlen(send_buffer), 0) == -1) {
        printf("Error sending to server\n");
        exit(-1);
    }
    printf("You: %s", send_buffer);

    // Wait for server response
    recv_size = recv(client_socket, recv_buffer, MAX_RECV_BUF, 0);
    if (recv_size == -1) {
        printf("Error receiving from server\n");
        exit(-1);
    }
    printf("Server: %.*s", recv_size, recv_buffer);

    // Start the email body
    sprintf(send_buffer, "DATA\r\n");
    if (send(client_socket, send_buffer, strlen(send_buffer), 0) == -1) {
        printf("Error sending to server\n");
        exit(-1);
    }
    printf("You: %s", send_buffer);

    // Wait for server response
    recv_size = recv(client_socket, recv_buffer, MAX_RECV_BUF, 0);
    if (recv_size == -1) {
        printf("Error receiving from server\n");
        exit(-1);
    }
    printf("Server: %.*s", recv_size, recv_buffer);

    // Write the email body
    sprintf(send_buffer, "Subject: A Happy Email :)\r\n\r\nHello, happy recipient! This is a happy email from your happy friend, the happy client! :)\r\n.\r\n");
    if (send(client_socket, send_buffer, strlen(send_buffer), 0) == -1) {
        printf("Error sending to server\n");
        exit(-1);
    }
    printf("You: %s", send_buffer);

    // Wait for server response
    recv_size = recv(client_socket, recv_buffer, MAX_RECV_BUF, 0);
    if (recv_size == -1) {
        printf("Error receiving from server\n");
        exit(-1);
    }
    printf("Server: %.*s", recv_size, recv_buffer);

    // Say goodbye to the server
    sprintf(send_buffer, "QUIT\r\n");
    if (send(client_socket, send_buffer, strlen(send_buffer), 0) == -1) {
        printf("Error sending to server\n");
        exit(-1);
    }
    printf("You: %s", send_buffer);

    // Wait for server response
    recv_size = recv(client_socket, recv_buffer, MAX_RECV_BUF, 0);
    if (recv_size == -1) {
        printf("Error receiving from server\n");
        exit(-1);
    }
    printf("Server: %.*s", recv_size, recv_buffer);

    // Close the socket
    close(client_socket);

    printf("\nEmail sent successfully! Enjoy spreading happiness! :D\n");

    return 0;
}