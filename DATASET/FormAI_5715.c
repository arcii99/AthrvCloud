//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

#define MAX_SIZE 1024

void receiveMessage(int socket, char messageBuffer[])
{
    int messageLength = read(socket, messageBuffer, MAX_SIZE);

    if (messageLength < 0) {
        printf("Error reading from socket");
    }

    messageBuffer[messageLength] = '\0';
}

int main()
{
    int clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (clientSocket < 0) {
        printf("Error creating socket");
        return 1;
    }

    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddress.sin_port = htons(110);

    int connectSuccess = connect(clientSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));

    if (connectSuccess < 0) {
        printf("Error connecting to server");
        return 1;
    }

    char userName[MAX_SIZE];
    char password[MAX_SIZE];
    char messageBuffer[MAX_SIZE];

    receiveMessage(clientSocket, messageBuffer);
    printf("%s", messageBuffer);

    printf("Enter user name: ");
    scanf("%s", userName);

    sprintf(messageBuffer, "USER %s\r\n", userName);
    write(clientSocket, messageBuffer, strlen(messageBuffer));

    receiveMessage(clientSocket, messageBuffer);
    printf("%s", messageBuffer);

    printf("Enter password: ");
    scanf("%s", password);

    sprintf(messageBuffer, "PASS %s\r\n", password);
    write(clientSocket, messageBuffer, strlen(messageBuffer));

    receiveMessage(clientSocket, messageBuffer);
    printf("%s", messageBuffer);

    sprintf(messageBuffer, "LIST\r\n");
    write(clientSocket, messageBuffer, strlen(messageBuffer));

    receiveMessage(clientSocket, messageBuffer);
    printf("%s", messageBuffer);

    close(clientSocket);

    return 0;
}