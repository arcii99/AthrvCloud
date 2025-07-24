//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    int sock;
    struct sockaddr_in server;
    char message[1000], server_reply[2000];
    
    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");
    
    // Set server information
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    
    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed");
        return 1;
    }
    
    puts("Connected to server");

    // Send data to server
    strcpy(message, "GET / HTTP/1.1\r\n\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }
    puts("Data sent\n");
    
    // Receive data from server
    if (recv(sock, server_reply, 2000, 0) < 0) {
        puts("recv failed");
        return 1;
    }
    puts("Reply received\n");
    printf("%s\n", server_reply);

    // Close socket
    close(sock);
    return 0;
}