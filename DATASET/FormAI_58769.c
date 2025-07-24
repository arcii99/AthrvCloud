//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

char *to_address = "example@gmail.com"; // Replace with your own email address
char *from_address = "your_email@example.com"; // Replace with your own email address

void send_email(char *to, char *from, char *subject, char *body) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return;
    }
    
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(25); // Port number for SMTP
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // Replace with SMTP server IP address

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connect");
        return;
    }
    
    char buffer[1024];
    int bytes_read = read(sock, buffer, 1024);
    if (bytes_read < 0) {
        perror("read");
        return;
    }
    printf("%s", buffer);

    char *helo_command = "HELO example.com\r\n";
    if (send(sock, helo_command, strlen(helo_command), 0) < 0) {
        perror("send");
        return;
    }
    bytes_read = read(sock, buffer, 1024);
    if (bytes_read < 0) {
        perror("read");
        return;
    }
    printf("%s", buffer);

    char *mail_from_command = malloc(strlen(from) + 16); // allocate enough memory for the command string
    sprintf(mail_from_command, "MAIL FROM: <%s>\r\n", from);
    if (send(sock, mail_from_command, strlen(mail_from_command), 0) < 0) {
        perror("send");
        return;
    }
    bytes_read = read(sock, buffer, 1024);
    if (bytes_read < 0) {
        perror("read");
        return;
    }
    printf("%s", buffer);

    char *rcpt_to_command = malloc(strlen(to) + 14);
    sprintf(rcpt_to_command, "RCPT TO: <%s>\r\n", to);
    if (send(sock, rcpt_to_command, strlen(rcpt_to_command), 0) < 0) {
        perror("send");
        return;
    }
    bytes_read = read(sock, buffer, 1024);
    if (bytes_read < 0) {
        perror("read");
        return;
    }
    printf("%s", buffer);

    char *data_command = "DATA\r\n";
    if (send(sock, data_command, strlen(data_command), 0) < 0) {
        perror("send");
        return;
    }
    bytes_read = read(sock, buffer, 1024);
    if (bytes_read < 0) {
        perror("read");
        return;
    }
    printf("%s", buffer);

    char *subject_header = malloc(strlen(subject) + 11);
    sprintf(subject_header, "Subject: %s\r\n", subject);

    char *message_headers = malloc(strlen(from) + strlen(to) + strlen(subject_header) + 40);
    sprintf(message_headers, "From: <%s>\r\nTo: <%s>\r\n%s\r\n", from, to, subject_header);
    char *message_body = strdup(body);
    char *message_footer = "\r\n.\r\n";

    char *message = malloc(strlen(message_headers) + strlen(message_body) + strlen(message_footer) + 1);
    sprintf(message, "%s%s%s", message_headers, message_body, message_footer);

    if (send(sock, message, strlen(message), 0) < 0) {
        perror("send");
        return;
    }
    bytes_read = read(sock, buffer, 1024);
    if (bytes_read < 0) {
        perror("read");
        return;
    }
    printf("%s", buffer);

    char *quit_command = "QUIT\r\n";
    if (send(sock, quit_command, strlen(quit_command), 0) < 0) {
        perror("send");
        return;
    }
    bytes_read = read(sock, buffer, 1024);
    if (bytes_read < 0) {
        perror("read");
        return;
    }
    printf("%s", buffer);

    close(sock);
    printf("Email sent successfully!\n");
}

int main(int argc, char *argv[]) {
    send_email(to_address, from_address, "Test Email", "This is a test email sent from my SMTP client program.");
    return 0;
}