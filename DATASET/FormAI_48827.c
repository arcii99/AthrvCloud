//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

/* This code snippet is a paranoid SMTP client program that ensures secure email communication */

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide an email address to send to.\n");
        exit(0);
    }

    // Create a socket for the client
    int client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock == -1) {
        printf("Could not create socket.\n");
        exit(0);
    }

    // Set up the destination address for the email server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    int conn_res = connect(client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (conn_res == -1) {
        printf("Could not connect to email server.\n");
        close(client_sock);
        exit(0);
    }

    // Get the server's welcome message
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    recv(client_sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send the HELO command to the server
    char* helo_command = "HELO paranoid-client.com\r\n";
    send(client_sock, helo_command, strlen(helo_command), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(client_sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send the MAIL FROM command to the server
    char* mail_from_command = "MAIL FROM: <paranoid-client@paranoid.com>\r\n";
    send(client_sock, mail_from_command, strlen(mail_from_command), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(client_sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send the RCPT TO command to the server
    char recipient[BUFFER_SIZE];
    snprintf(recipient, BUFFER_SIZE, "RCPT TO: <%s>\r\n", argv[1]);
    send(client_sock, recipient, strlen(recipient), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(client_sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send the DATA command to the server
    char* data_command = "DATA\r\n";
    send(client_sock, data_command, strlen(data_command), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(client_sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send the email message
    char msg[BUFFER_SIZE];
    printf("Enter your email message and end with a dot on a separate line :\n");
    while (fgets(msg, BUFFER_SIZE, stdin) && msg[0] != '.' && strlen(msg) > 1) {
        send(client_sock, msg, strlen(msg), 0);
    }
    send(client_sock, ".\r\n", 3, 0);

    memset(buffer, 0, sizeof(buffer));
    recv(client_sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send the QUIT command to the server
    char* quit_command = "QUIT\r\n";
    send(client_sock, quit_command, strlen(quit_command), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(client_sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    close(client_sock);
    return 0;
}