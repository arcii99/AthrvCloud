//FormAI DATASET v1.0 Category: Client Server Application ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Function to create socket and establish connection with server
int createSocketAndConnect(struct sockaddr_in *serv_addr) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }
  
    if (connect(sock, (struct sockaddr *)serv_addr, sizeof(*serv_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    return sock;
}

// Function to send message to server
void sendMessage(int sock, char *message) {
    send(sock, message, strlen(message), 0);
    printf("Message sent\n");
}

// Function to receive message from server
void receiveMessage(int sock) {
    char buffer[1024] = {0};
    if (read(sock, buffer, 1024) < 0) {
        perror("Read error");
        exit(EXIT_FAILURE);
    }

    printf("Server message: %s\n", buffer);
}

int main(int argc, char const *argv[]) {
    int sock;
    struct sockaddr_in serv_addr;
  
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
      
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        perror("Invalid address/ Address not supported");
        return -1;
    }
  
    sock = createSocketAndConnect(&serv_addr);

    // Communication with server
    char message[1024];
    while (1) {
        printf("Enter message to send to server: ");
        fgets(message, 1024, stdin);
        sendMessage(sock, message);
        receiveMessage(sock);
        // Exit if user enters "exit"
        if (strcmp(message, "exit\n") == 0) {
            break;
        }
    }

    close(sock);
    return 0;
}