//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Constants for IP and PORT
#define IP_ADDRESS "127.0.0.1"
#define PORT 8080

int main() {

    // Creating socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
      perror("Socket creation failed");
      exit(EXIT_FAILURE);
    }

    // Initializing server address and setting socket options
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
    serverAddr.sin_port = htons(PORT);

    // Binding socket to address and port
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
      perror("Socket bind failed");
      exit(EXIT_FAILURE);
    }

    // Listening to incoming connections
    if (listen(serverSocket, 10) == -1) {
      perror("Socket listen failed");
      exit(EXIT_FAILURE);
    }
  
    printf("Server is listening for incoming connections......\n");

    while(1) {
        // Accepting incoming connection request
        int clientSocket = accept(serverSocket, NULL, NULL);
        if (clientSocket == -1) {
          perror("Socket accept failed");
          exit(EXIT_FAILURE);
        }
    
        // Reading data from client
        char buffer[1024] = {0};
        ssize_t valread = read(clientSocket, buffer, 1024);
        printf("Message received from client: %s\n", buffer);

        // Modifying data and sending back to client
        char response[] = "Server received your message!";
        if (send(clientSocket, response, strlen(response), 0) == -1) {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }
        printf("Response sent back to client\n");

        // Closing client socket
        close(clientSocket);
    }

    // Closing server socket
    close(serverSocket);

    return 0;
}