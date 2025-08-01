//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: inquisitive
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int socket_desc;
    struct sockaddr_in server;
    char *message, server_reply[2000];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }

    // Set server address and port
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    // Connect to server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        puts("Connect error");
        return 1;
    }

    // Send GET request
    message = "GET / HTTP/1.1\r\n\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }
    puts("GET request sent");

    // Receive response
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        puts("Receive failed");
        return 1;
    }
    puts("Response received\n");
    printf("%s", server_reply);

    // Close socket
    close(socket_desc);

    return 0;
}