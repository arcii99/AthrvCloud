//FormAI DATASET v1.0 Category: Networking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    printf("Are you ready to connect to the World Wide Web?!\n\n");

    int socket_desc;

    // Creating a socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Failed to create socket\n");
        return 1;
    }
    printf("Socket created\n");

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("192.168.0.1");
    server.sin_port = htons(8888);

    // Connecting to the server
    if (connect(socket_desc, (struct sockaddr*)&server, sizeof(server)) < 0) {
        printf("Connection failed\n");
        return 1;
    }

    printf("Connected to the server! Say hello to the internet for me!\n\n");

    char message[2000] = "Hey internet, it's good to finally meet you!";

    // Sending data to the server
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Send failed\n");
        return 1;
    }

    printf("Data sent to the server. Let's see what the internet has to say!\n\n");

    char server_response[2000];

    // Receiving data from the server
    if (recv(socket_desc, server_response, 2000, 0) < 0) {
        printf("Receive failed\n");
        return 1;
    }

    printf("The internet says: %s\n\n", server_response);

    printf("Closing the socket. May our connection never drop!\n");

    close(socket_desc);

    return 0;
}