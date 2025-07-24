//FormAI DATASET v1.0 Category: Socket programming ; Style: modular
#include <stdio.h>
#include <stdlib.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
 
#define PORT 8080 
  
int createSocket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sock;
}

struct sockaddr_in getAddressStruct(char* ipAddress) {
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT); 
    
    if (inet_pton(AF_INET, ipAddress, &address.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }
    return address;
}

int connectToServer(int sock, struct sockaddr_in address) {
    if (connect(sock, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }
    return sock;
}

int sendMessageToServer(int sock, char* message) {
    int result = send(sock, message, strlen(message), 0);
    if (result == -1) {
        perror("Failed to send message to server");
        exit(EXIT_FAILURE);
    }
    return result;
}

char* receiveMessageFromServer(int sock) {
    char buffer[1024] = {0};
    int result = read(sock, buffer, 1024);
    if (result == -1) {
        perror("Failed to receive message from server");
        exit(EXIT_FAILURE);
    }
    char* message = malloc(strlen(buffer) + 1);
    strcpy(message, buffer);
    return message;
}

int closeConnection(int sock) {
    return close(sock);
}

int main(int argc, char const *argv[]) { 
    if (argc < 2) {
        printf("Please provide IP address of server\n");
        return -1;
    }

    char* ipAddress = argv[1];
    int sock = createSocket();
    struct sockaddr_in address = getAddressStruct(ipAddress);
    connectToServer(sock, address);

    printf("Please enter message to send to server: ");
    char message[1024];
    fgets(message, 1024, stdin);
    sendMessageToServer(sock, message);

    char* receivedMessage = receiveMessageFromServer(sock);
    printf("Message received from server:\n%s", receivedMessage);
    free(receivedMessage);

    closeConnection(sock);
    return 0; 
}