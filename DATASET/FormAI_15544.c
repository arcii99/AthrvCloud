//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

// FTP PORT
#define FTP_PORT 21
// BUFFER SIZE
#define BUFFER_SIZE 1024

// Function to connect to FTP server
int openSocket(char* ipAddress){
    int socketFD = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in ftpServer;

    if(socketFD == -1){
        perror("Socket Failed");
        exit(EXIT_FAILURE);
    }

    ftpServer.sin_addr.s_addr = inet_addr(ipAddress);
    ftpServer.sin_family = AF_INET;
    ftpServer.sin_port = htons(FTP_PORT);

    if(connect(socketFD, (struct sockaddr *)&ftpServer, sizeof(ftpServer)) < 0){
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }

    return socketFD;
}

// Function to receive response from FTP server
void recvResponse(int socketFD){
    char buffer[BUFFER_SIZE] = {0};
    int n;
    while((n = recv(socketFD, buffer, BUFFER_SIZE, 0))){
        printf("%s", buffer);
        if(strstr(buffer, "\n")) break;
        memset(buffer, 0, BUFFER_SIZE);
    }
}

// Function to send command to FTP server
void sendCommand(int socketFD, char* command){
    if(send(socketFD, command, strlen(command), 0) == -1){
        perror("Send Failed");
        exit(EXIT_FAILURE);
    }
}

// Function to create new client file and write the data in it
void downloadFile(int socketFD, char* fileName){
    FILE* fp = fopen(fileName, "w");
    char buffer[BUFFER_SIZE];
    int n;
    while((n = recv(socketFD, buffer, BUFFER_SIZE, 0))){
        fwrite(buffer, sizeof(char), n, fp);
        if(n < BUFFER_SIZE) break;
    }
    fclose(fp);
}

int main(int argc, char** argv){
    if(argc != 4){
        printf("Usage: %s <IP Address> <Username> <Password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* ipAddress = argv[1];
    char* username = argv[2];
    char* password = argv[3];

    int socketFD = openSocket(ipAddress);

    recvResponse(socketFD);

    char loginCommand[100];
    sprintf(loginCommand, "USER %s\r\n", username);
    sendCommand(socketFD, loginCommand);
    recvResponse(socketFD);

    sprintf(loginCommand, "PASS %s\r\n", password);
    sendCommand(socketFD, loginCommand);
    recvResponse(socketFD);

    printf("Connection Successful!\n");

    char fileCommand[100];
    sprintf(fileCommand, "RETR %s\r\n", "hello.txt");
    sendCommand(socketFD, fileCommand);
    recvResponse(socketFD);

    if(strstr(fileCommand, "150")){
        downloadFile(socketFD, "hello-download.txt");
        printf("File Downloaded Successfully!\n");
    }

    close(socketFD);

    return 0;
}