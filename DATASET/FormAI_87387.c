//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main() {
    printf("Welcome to the surrealist SMTP Client program!\n");
    printf("Please enter the hostname/IP Address: ");
    char host[100];
    fgets(host, sizeof(host), stdin);

    printf("Please enter the port number: ");
    char port_number[10];
    fgets(port_number, sizeof(port_number), stdin);

    printf("Please enter the sender email address: ");
    char sender_email[100];
    fgets(sender_email, sizeof(sender_email), stdin);

    printf("Please enter the recipient email address: ");
    char recipient_email[100];
    fgets(recipient_email, sizeof(recipient_email), stdin);

    printf("Please enter the email subject: ");
    char subject[100];
    fgets(subject, sizeof(subject), stdin);

    printf("Please enter the email body: ");
    char body[1000];
    fgets(body, sizeof(body), stdin);

    // create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // set up server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(port_number));
    inet_aton(host, &server_address.sin_addr);

    // connect to server
    connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    printf("Connected to server!\n");

    char server_response[100];
    recv(client_socket, &server_response, sizeof(server_response), 0);
    printf("Server response: %s", server_response);

    // send greeting
    char greeting[] = "HELLO";
    send(client_socket, greeting, sizeof(greeting), 0);

    char server_greeting[100];
    recv(client_socket, &server_greeting, sizeof(server_greeting), 0);
    printf("Server greeting: %s", server_greeting);

    // send sender email
    char sender_command[100];
    snprintf(sender_command, sizeof(sender_command), "MAIL FROM:<%s>\r\n", sender_email);
    send(client_socket, sender_command, sizeof(sender_command), 0);

    char sender_response[100];
    recv(client_socket, &sender_response, sizeof(sender_response), 0);
    printf("Sender response: %s", sender_response);

    // send recipient email
    char recipient_command[100];
    snprintf(recipient_command, sizeof(recipient_command), "RCPT TO:<%s>\r\n", recipient_email);
    send(client_socket, recipient_command, sizeof(recipient_command), 0);

    char recipient_response[100];
    recv(client_socket, &recipient_response, sizeof(recipient_response), 0);
    printf("Recipient response: %s", recipient_response);

    // send data command
    char data_command[] = "DATA\r\n";
    send(client_socket, data_command, sizeof(data_command), 0);

    char data_response[100];
    recv(client_socket, &data_response, sizeof(data_response), 0);
    printf("Data response: %s", data_response);

    // send email subject and body
    char email[1100];
    snprintf(email, sizeof(email), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send(client_socket, email, sizeof(email), 0);

    char email_response[100];
    recv(client_socket, &email_response, sizeof(email_response), 0);
    printf("Email response: %s", email_response);

    // end connection
    char quit_command[] = "QUIT\r\n";
    send(client_socket, quit_command, sizeof(quit_command), 0);

    char quit_response[100];
    recv(client_socket, &quit_response, sizeof(quit_response), 0);
    printf("Quit response: %s", quit_response);

    close(client_socket);

    printf("Email sent successfully!\n");

    return 0;
}