//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER 1024
#define SERVER_PORT 25
#define SERVER_ADDRESS "mail.example.com"
#define MESSAGE_SUBJECT "Hello From SMTP Client"
#define MESSAGE_BODY "This is an example email sent from a multi-threaded SMTP client.\n\nThank you,\nSMTP Client"

// Function to send email to server
void send_email(int client_socket, char *sender, char *recipient)
{
    char buffer[MAX_BUFFER];

    // Send Mail From Command
    sprintf(buffer, "MAIL FROM:<%s>\r\n", sender);
    send(client_socket, buffer, strlen(buffer), 0);
    recv(client_socket, buffer, MAX_BUFFER, 0);

    // Send Recipient Command
    sprintf(buffer, "RCPT TO:<%s>\r\n", recipient);
    send(client_socket, buffer, strlen(buffer), 0);
    recv(client_socket, buffer, MAX_BUFFER, 0);

    // Send Data Command
    sprintf(buffer, "DATA\r\n");
    send(client_socket, buffer, strlen(buffer), 0);
    recv(client_socket, buffer, MAX_BUFFER, 0);

    // Send Message Headers
    sprintf(buffer, "Subject:%s\r\n", MESSAGE_SUBJECT);
    send(client_socket, buffer, strlen(buffer), 0);
    sprintf(buffer, "From:%s\r\n", sender);
    send(client_socket, buffer, strlen(buffer), 0);
    sprintf(buffer, "To:%s\r\n", recipient);
    send(client_socket, buffer, strlen(buffer), 0);

    // Send Message Body
    sprintf(buffer, "\r\n%s\r\n", MESSAGE_BODY);
    send(client_socket, buffer, strlen(buffer), 0);

    // Send Quit Command
    sprintf(buffer, "QUIT\r\n");
    send(client_socket, buffer, strlen(buffer), 0);
    recv(client_socket, buffer, MAX_BUFFER, 0);
}

// Function to send email in separate thread
void *send_email_thread(void *args)
{
    char *sender = (char *)args;
    char *recipient = "user@example.com";

    int client_socket;
    struct sockaddr_in server_address;

    // Create Socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        perror("Socket Creation Error");
        exit(EXIT_FAILURE);
    }

    // Set Server Address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);

    if (inet_pton(AF_INET, SERVER_ADDRESS, &server_address.sin_addr) <= 0)
    {
        perror("Invalid Address Format");
        exit(EXIT_FAILURE);
    }

    // Connect to Server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }

    // Receive Welcome Message from Server
    char buffer[MAX_BUFFER];
    recv(client_socket, buffer, MAX_BUFFER, 0);

    // Send Email to Server
    send_email(client_socket, sender, recipient);

    // Close Connection
    close(client_socket);

    pthread_exit(NULL);
}

int main()
{
    pthread_t thread1, thread2;

    // Create Sender Threads
    char sender1[] = "user1@example.com";
    char sender2[] = "user2@example.com";

    pthread_create(&thread1, NULL, send_email_thread, (void *)sender1);
    pthread_create(&thread2, NULL, send_email_thread, (void *)sender2);

    // Join Threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}