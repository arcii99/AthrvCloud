//FormAI DATASET v1.0 Category: Socket programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int socket_desc;
    struct sockaddr_in server_addr;
    char* message = "Hello, world!";
    char server_reply[2000];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }

    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.1"); // Future IP address
    server_addr.sin_port = htons(8080); // Future port number

    // Connect to server
    if (connect(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connect error");
        return 1;
    }

    // Send data to server
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Send failed");
        return 1;
    }

    // Receive data from server
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
        return 1;
    }

    // Display server message
    printf("Server reply : ");
    puts(server_reply);

    // Close socket
    close(socket_desc);

    return 0;
}