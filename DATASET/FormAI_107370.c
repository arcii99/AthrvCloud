//FormAI DATASET v1.0 Category: Networking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG_LEN 1024

int main(int argc, char *argv[]) {
    int socket_desc;
    struct sockaddr_in server_addr;
    char *message, server_reply[MAX_MSG_LEN];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }

    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Replace with actual IP of server
    server_addr.sin_port = htons(8888); // Use port 8888

    // Connect to remote server
    if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection error");
        return 1;
    }

    // Send some data to the server
    message = "Greetings, my Lord! How are you this fine day?";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }

    // Receive a reply from the server
    if (recv(socket_desc, server_reply, MAX_MSG_LEN, 0) < 0) {
        puts("Receive failed");
    }
    printf("Server reply: %s\n", server_reply);

    close(socket_desc);
    return 0;
}