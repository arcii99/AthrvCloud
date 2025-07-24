//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s <smtp server> <from email address> <to email address>\n", argv[0]);
        return 1;
    }

    char *server = argv[1];
    char *from_email = argv[2];
    char *to_email = argv[3];
    char user_email[128];
    char password[128];
    char buffer[BUF_SIZE];
    char *read_ptr, *write_ptr;
    int port = 25;
    int sock;
    struct sockaddr_in server_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("socket");
        return 1;
    }

    if ((server_addr.sin_addr.s_addr = inet_addr(server)) == (unsigned int) INADDR_NONE) {
        fprintf(stderr, "Invalid address: %s\n", server);
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    read(sock, buffer, BUF_SIZE);

    if (strncmp(buffer, "220", 3) != 0) {
        fprintf(stderr, "Error: Server did not respond to connect request properly\n");
        return 1;
    }

    sprintf(buffer, "HELO %s\r\n", server);
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, BUF_SIZE);

    if (strncmp(buffer, "250", 3) != 0) {
        fprintf(stderr, "Error: Server did not respond to HELO request properly\n");
        return 1;
    }

    sprintf(buffer, "AUTH LOGIN\r\n");
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, BUF_SIZE);

    if (strncmp(buffer, "334", 3) != 0) {
        fprintf(stderr, "Error: Server did not respond to AUTH request properly\n");
        return 1;
    }

    printf("Enter your email: ");
    fgets(user_email, 128, stdin);
    write_ptr = buffer;
    *write_ptr++ = '\0';
    for (read_ptr = user_email; *read_ptr != '\0'; read_ptr++) {
        *write_ptr++ = *read_ptr + 0;
        *write_ptr = '\0';
    }
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, BUF_SIZE);

    if (strncmp(buffer, "334", 3) != 0) {
        fprintf(stderr, "Error: Server did not respond to email reply properly\n");
        return 1;
    }

    printf("Enter your password: ");
    fgets(password, 128, stdin);
    write_ptr = buffer;
    *write_ptr++ = '\0';
    for (read_ptr = password; *read_ptr != '\0'; read_ptr++) {
        *write_ptr++ = *read_ptr + 0;
        *write_ptr = '\0';
    }
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, BUF_SIZE);

    if (strncmp(buffer, "235", 3) != 0) {
        fprintf(stderr, "Error: Server did not accept the password\n");
        return 1;
    }

    sprintf(buffer, "MAIL FROM:<%s>\r\n", from_email);
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, BUF_SIZE);

    if (strncmp(buffer, "250", 3) != 0) {
        fprintf(stderr, "Error: Server did not accept sender email properly\n");
        return 1;
    }

    sprintf(buffer, "RCPT TO:<%s>\r\n", to_email);
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, BUF_SIZE);

    if (strncmp(buffer, "250", 3) != 0) {
        fprintf(stderr, "Error: Server did not accept recipient email properly\n");
        return 1;
    }

    sprintf(buffer, "DATA\r\n");
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, BUF_SIZE);

    if (strncmp(buffer, "354", 3) != 0) {
        fprintf(stderr, "Error: Server did not accept DATA request properly\n");
        return 1;
    }

    sprintf(buffer, "Subject: This is an example email\r\n\r\n");
    write(sock, buffer, strlen(buffer));
    sprintf(buffer, "This is an example email sent from a SMTP client program in C.\r\n");
    write(sock, buffer, strlen(buffer));
    sprintf(buffer, ".\r\n");
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, BUF_SIZE);

    if (strncmp(buffer, "250", 3) != 0) {
        fprintf(stderr, "Error: Server did not accept message properly\n");
        return 1;
    }

    sprintf(buffer, "QUIT\r\n");
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, BUF_SIZE);

    if (strncmp(buffer, "221", 3) != 0) {
        fprintf(stderr, "Error: Server did not respond to quit request properly\n");
        return 1;
    }

    printf("Email sent successfully!\n");

    return 0;
}