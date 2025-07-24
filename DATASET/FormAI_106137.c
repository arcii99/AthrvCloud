//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024
#define POP3_PORT 110

// Connects to a POP3 Server
int connectToServer(char* server, char* user, char* password, int* clientSocket){
    // Create a Socket
    *clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    if(*clientSocket < 0){
        printf("Error creating Socket\n");
        return -1;
    }

    // Server Information
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(POP3_PORT);
    serverAddr.sin_addr.s_addr = inet_addr(server);

    // Connect to Server
    if(connect(*clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0){
        printf("Error connecting to Server\n");
        return -1;
    }

    // Receive Server Response
    char response[BUFSIZE];
    recv(*clientSocket, response, BUFSIZE, 0);
    printf("%s", response);

    // Send User Information
    char userString[BUFSIZE];
    sprintf(userString, "USER %s\r\n", user);
    send(*clientSocket, userString, strlen(userString), 0);
    recv(*clientSocket, response, BUFSIZE, 0);
    printf("%s", response);

    // Send Password Information
    char passString[BUFSIZE];
    sprintf(passString, "PASS %s\r\n", password);
    send(*clientSocket, passString, strlen(passString), 0);
    recv(*clientSocket, response, BUFSIZE, 0);
    printf("%s", response);

    return 0;
}

// Main Function
int main(){
    // Server Information
    char* server = "pop.gmail.com";
    char* user = "myemail@gmail.com";
    char* password = "mypassword";

    // Connect to Server
    int clientSocket;
    if(connectToServer(server, user, password, &clientSocket) < 0){
        return -1;  
    }

    // Send List Command to Server
    char listCommand[BUFSIZE] = "LIST\r\n";
    char response[BUFSIZE];
    send(clientSocket, listCommand, strlen(listCommand), 0);
    recv(clientSocket, response, BUFSIZE, 0);
    printf("%s", response);

    // Close Connection
    close(clientSocket);
    return 0;
}