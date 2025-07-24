//FormAI DATASET v1.0 Category: Networking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888

int main(int argc, char *argv[]) 
{

    int sock = socket(AF_INET, SOCK_STREAM, 0); // Create socket

    if (sock == -1) {
        printf("Could not create socket");
    }

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    // Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        return 1;
    }
    printf("Connected to server.\n");

    char message[1000];
    char server_reply[2000];  
    while(1) { // Loop until user types "quit"

        memset(message, 0, sizeof(message));
        printf("\nType a message: ");
        fgets(message, 1000, stdin);

        if (strcmp(message, "quit\n") == 0) {
            break;
        }

        // Send message to server
        if (send(sock, message, strlen(message), 0) < 0) {
            puts("Send failed");
            return 1;
        }

        // Receive reply from server
        if (recv(sock, server_reply, 2000, 0) < 0) {
            puts("Receive failed");
            break;
        }

        printf("Server reply: %s\n", server_reply);
        memset(server_reply, 0, sizeof(server_reply));
    }

    close(sock);
    printf("Connection closed.\n");
    return 0;
}