//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024
#define SMTP_PORT 25

int main(int argc, char const *argv[]) {
    // Check if the user provided the email information
    if (argc < 3) {
        printf("Usage: %s <receiver_email_address> <subject>\n", argv[0]);
        exit(0);
    }

    // Get the email information
    char *receiver_email_address = argv[1];
    char *subject = argv[2];
    char body[MAX_BUFFER_SIZE];
    printf("Enter the email body:\n");
    fgets(body, MAX_BUFFER_SIZE, stdin);

    // Create socket endpoint for communication
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Error opening client socket");
        exit(1);
    }

    // Connect to the SMTP server
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SMTP_PORT);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change this to the SMTP server IP address
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to SMTP server");
        exit(1);
    }

    char recv_buffer[MAX_BUFFER_SIZE];
    char send_buffer[MAX_BUFFER_SIZE];

    // Receive the server greeting message
    if(recv(client_socket, recv_buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Error receiving from server");
        exit(1);
    }
    printf("%s", recv_buffer);

    // Send HELO message to the server
    sprintf(send_buffer, "HELO localhost\r\n");
    if (send(client_socket, send_buffer, strlen(send_buffer), 0) < 0) {
        perror("Error sending to server");
        exit(1);
    }

    if(recv(client_socket, recv_buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Error receiving from server");
        exit(1);
    }
    printf("%s", recv_buffer);

    // Send MAIL FROM message to the server
    sprintf(send_buffer, "MAIL FROM:<sender@domain.com>\r\n");
    if (send(client_socket, send_buffer, strlen(send_buffer), 0) < 0) {
        perror("Error sending to server");
        exit(1);
    }
    if(recv(client_socket, recv_buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Error receiving from server");
        exit(1);
    }
    printf("%s", recv_buffer);

    // Send RCPT TO message to the server
    sprintf(send_buffer, "RCPT TO:<%s>\r\n", receiver_email_address);
    if (send(client_socket, send_buffer, strlen(send_buffer), 0) < 0) {
        perror("Error sending to server");
        exit(1);
    }
    if(recv(client_socket, recv_buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Error receiving from server");
        exit(1);
    }
    printf("%s", recv_buffer);

    // Send DATA message to the server
    sprintf(send_buffer, "DATA\r\n");
    if (send(client_socket, send_buffer, strlen(send_buffer), 0) < 0) {
        perror("Error sending to server");
        exit(1);
    }
    if(recv(client_socket, recv_buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Error receiving from server");
        exit(1);
    }
    printf("%s", recv_buffer);

    // Send email headers and body to the server
    sprintf(send_buffer, "From: <sender@domain.com>\r\nTo: <%s>\r\nSubject: %s\r\n\r\n%s", receiver_email_address, subject, body);
    if (send(client_socket, send_buffer, strlen(send_buffer), 0) < 0) {
        perror("Error sending to server");
        exit(1);
    }
    if(recv(client_socket, recv_buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Error receiving from server");
        exit(1);
    }
    printf("%s", recv_buffer);

    // Send QUIT message to the server
    sprintf(send_buffer, "QUIT\r\n");
    if (send(client_socket, send_buffer, strlen(send_buffer), 0) < 0) {
        perror("Error sending to server");
        exit(1);
    }
    if(recv(client_socket, recv_buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Error receiving from server");
        exit(1);
    }
    printf("%s", recv_buffer);

    // Close the client socket
    close(client_socket);

    return 0;
}