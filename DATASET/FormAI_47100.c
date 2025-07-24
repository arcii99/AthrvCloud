//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: rigorous
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *server_ip = "smtp.gmail.com";
    int server_port = 587;

    // Create a socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Configure server address
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &serverAddr.sin_addr);

    // Connect to the server
    if (connect(clientSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
        perror("Failed to connect to server");
        return 1;
    }
    printf("Connected to server\n");

    char buffer[BUFFER_SIZE] = {0};

    // Receive the server greeting
    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Send HELO message
    char helo_message[] = "HELO smtp.gmail.com\r\n";
    send(clientSocket, helo_message, strlen(helo_message), 0);

    // Receive the server response to HELO message
    memset(buffer, 0, BUFFER_SIZE);
    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Send authentication command
    char auth_message[] = "AUTH LOGIN\r\n";
    send(clientSocket, auth_message, strlen(auth_message), 0);

    // Receive the server challenge for username
    memset(buffer, 0, BUFFER_SIZE);
    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Send username
    char base64_username[] = "base64_encoded_username";
    send(clientSocket, base64_username, strlen(base64_username), 0);
    char crlf[] = "\r\n";
    send(clientSocket, crlf, strlen(crlf), 0);

    // Receive the server challenge for password
    memset(buffer, 0, BUFFER_SIZE);
    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Send password
    char base64_password[] = "base64_encoded_password";
    send(clientSocket, base64_password, strlen(base64_password), 0);
    send(clientSocket, crlf, strlen(crlf), 0);

    // Send MAIL FROM command
    char mail_from[] = "MAIL FROM:<sender@gmail.com>\r\n";
    send(clientSocket, mail_from, strlen(mail_from), 0);

    memset(buffer, 0, BUFFER_SIZE);
    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Send RCPT TO command
    char rcpt_to[] = "RCPT TO:<recipient@gmail.com>\r\n";
    send(clientSocket, rcpt_to, strlen(rcpt_to), 0);

    memset(buffer, 0, BUFFER_SIZE);
    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Send DATA command
    char data[] = "DATA\r\n";
    send(clientSocket, data, strlen(data), 0);

    memset(buffer, 0, BUFFER_SIZE);
    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Send email content
    char subject[] = "Subject: Test email\r\n";
    send(clientSocket, subject, strlen(subject), 0);

    char body[] = "Hello recipient,\n\nThis is a test email sent from a SMTP client.\n\nBest regards,\nSender";
    send(clientSocket, body, strlen(body), 0);

    // Send end-of-email command
    char end_of_email[] = "\r\n.\r\n";
    send(clientSocket, end_of_email, strlen(end_of_email), 0);

    memset(buffer, 0, BUFFER_SIZE);
    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Send QUIT command
    char quit[] = "QUIT\r\n";
    send(clientSocket, quit, strlen(quit), 0);

    memset(buffer, 0, BUFFER_SIZE);
    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Close the connection
    close(clientSocket);

    return 0;
}