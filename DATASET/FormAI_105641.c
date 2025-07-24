//FormAI DATASET v1.0 Category: Socket programming ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sock;
    struct sockaddr_in server_address;
    char message[1000], server_reply[2000];
    
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
    }
    
    // Set server address and port number
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8888);
    
    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Connection failed");
        return 1;
    }
    
    printf("Connected to server\n");
    
    // Send message to server
    while (1) {
        printf("Enter message: ");
        fgets(message, 1000, stdin);
        message[strcspn(message, "\n")] = 0;
        
        if (send(sock, message, strlen(message), 0) < 0) {
            printf("Send failed");
            return 1;
        }
        
        // Receive message from server
        if (recv(sock, server_reply, 2000, 0) < 0) {
            printf("Receive failed");
            break;
        }
        
        printf("Server reply: %s\n", server_reply);
        
        if (strcmp(server_reply, "exit") == 0) {
            break;
        }
    }
    
    close(sock);
    return 0;
}