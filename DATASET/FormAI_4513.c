//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void celebrate() {
    printf("Hurray! You did it!\n");
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char message[1000], server_reply[2000];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket :(\n");
        return 1;
    }
    printf("Socket created! :)\n");

    // Set connection details
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    // Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed. Error");
        return 1;
    }
    printf("Connected! :)\n");

    // Send some data
    strcpy(message, "Hello there! I'm sending you this message with love <3");
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Send failed :(\n");
        return 1;
    }
    printf("Data sent! :)\n");

    // Receive some data
    if (recv(sock, server_reply, 2000, 0) < 0) {
        printf("Receive failed :(\n");
        return 1;
    }
    printf("Data received! :)\n");

    // Celebrate!
    celebrate();

    close(sock);
    return 0;
}