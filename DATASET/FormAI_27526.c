//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: scalable
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define SERVER_ADDRESS "smtp.example.com"
#define SERVER_PORT 25

int main(int argc, char *argv[]) {

    // Create TCP Socket
    int socket_id = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // Create Socket Address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &(server_address.sin_addr));

    // Connect to Server
    if (connect(socket_id, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connect Error");
        return -1;
    }

    // Receive Server Greeting
    char recv_buffer[1024];
    memset(recv_buffer, 0, sizeof(recv_buffer));
    recv(socket_id, recv_buffer, sizeof(recv_buffer), 0);
    printf("%s", recv_buffer);

    // Send HELO Command
    char message_buffer[1024] = {0};
    sprintf(message_buffer, "HELO example.com\r\n");
    send(socket_id, message_buffer, strlen(message_buffer), 0);

    // Receive Response
    memset(recv_buffer, 0, sizeof(recv_buffer));
    recv(socket_id, recv_buffer, sizeof(recv_buffer), 0);
    printf("%s", recv_buffer);

    // Send MAIL FROM Command
    memset(message_buffer, 0, sizeof(message_buffer));
    sprintf(message_buffer, "MAIL FROM:<sender@example.com>\r\n");
    send(socket_id, message_buffer, strlen(message_buffer), 0);

    // Receive Response
    memset(recv_buffer, 0, sizeof(recv_buffer));
    recv(socket_id, recv_buffer, sizeof(recv_buffer), 0);
    printf("%s", recv_buffer);

    // Send RCPT TO Command
    memset(message_buffer, 0, sizeof(message_buffer));
    sprintf(message_buffer, "RCPT TO:<receiver@example.com>\r\n");
    send(socket_id, message_buffer, strlen(message_buffer), 0);

    // Receive Response
    memset(recv_buffer, 0, sizeof(recv_buffer));
    recv(socket_id, recv_buffer, sizeof(recv_buffer), 0);
    printf("%s", recv_buffer);

    // Send DATA Command
    memset(message_buffer, 0, sizeof(message_buffer));
    sprintf(message_buffer, "DATA\r\n");
    send(socket_id, message_buffer, strlen(message_buffer), 0);

    // Receive Response
    memset(recv_buffer, 0, sizeof(recv_buffer));
    recv(socket_id, recv_buffer, sizeof(recv_buffer), 0);
    printf("%s", recv_buffer);

    // Send Message Body
    memset(message_buffer, 0, sizeof(message_buffer));
    sprintf(message_buffer, "Subject: Hello World!\r\n\r\nThis is a test message.\r\n.\r\n");
    send(socket_id, message_buffer, strlen(message_buffer), 0);

    // Receive Response
    memset(recv_buffer, 0, sizeof(recv_buffer));
    recv(socket_id, recv_buffer, sizeof(recv_buffer), 0);
    printf("%s", recv_buffer);

    // Send QUIT Command
    memset(message_buffer, 0, sizeof(message_buffer));
    sprintf(message_buffer, "QUIT\r\n");
    send(socket_id, message_buffer, strlen(message_buffer), 0);

    // Receive Response
    memset(recv_buffer, 0, sizeof(recv_buffer));
    recv(socket_id, recv_buffer, sizeof(recv_buffer), 0);
    printf("%s", recv_buffer);

    // Close Socket
    close(socket_id);

    return 0;
}