//FormAI DATASET v1.0 Category: Networking ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "127.0.0.1" // Replace with your server IP address
#define PORT 8080 // Port number

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char message[1024] = {0};
    
    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }
    
    memset(&serv_addr, '0', sizeof(serv_addr));
    
    // Set server address and port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    if (inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return -1;
    }
    
    //Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        return -1;
    }
    
    // Send and receive message from server
    while (1) {
        printf("\nEnter message: ");
        fgets(message, 1024, stdin);
        send(sock, message, strlen(message), 0);
        memset(message, 0, sizeof(message));
        recv(sock, message, 1024, 0);
        printf("Received from server: %s\n", message);
    }
    
    close(sock);
    return 0;
}