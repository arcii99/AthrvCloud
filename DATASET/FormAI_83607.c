//FormAI DATASET v1.0 Category: Client Server Application ; Style: Romeo and Juliet
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>

#define PORT 8080

int main() {
    // create socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    // connect to server
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
    connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    // send messages to server
    char msg[100];
    strcpy(msg, "O Romeo, Romeo! Wherefore art thou Romeo?\n");
    send(clientSocket, msg, strlen(msg), 0);
    printf("Client: %s", msg);

    // receive messages from server
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    recv(clientSocket, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);

    // send more messages and receive responses
    // ...

    // close socket
    close(clientSocket);

    return 0;
}