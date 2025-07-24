//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char *message, server_reply[2000];
    int message_length;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Socket creation failed\n");
        return 1;
    }
    printf("Socket created successfully!\n");

    // Prepare server address structure
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 80 );

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection failed\n");
        return 1;
    }
    printf("Connected to server successfully!\n");

    // Send message to server
    message = "GET / HTTP/1.1\r\n\r\n";
    message_length = strlen(message);
    if (send(sock, message, message_length, 0) < 0) {
        printf("Send failed\n");
        return 1;
    }
    printf("Message sent successfully!\n");

    // Receive reply from server
    if (recv(sock, server_reply, 2000, 0) < 0) {
        printf("Receive failed\n");
        return 1;
    }
    printf("Server replied: %s\n", server_reply);

    // Close the socket
    close(sock);
    printf("Socket closed\n");

    return 0;
}