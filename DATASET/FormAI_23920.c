//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>

void checkHostName(int hostName);
void checkIPbuffer(char *IPbuffer);

int main(){

    int clientSocket, portNum, nBytes;
    char buffer[1024];
    struct hostent *server;
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    server = gethostbyname("www.example.com");

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5999);
    serverAddr.sin_addr.s_addr = inet_addr("192.0.2.0");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    addr_size = sizeof serverAddr;
    connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

    printf("Enter your message:");
    fgets(buffer, 1024, stdin);

    nBytes = strlen(buffer) + 1;

    send(clientSocket,buffer,nBytes,0);

    recv(clientSocket, buffer, 1024, 0);

    printf("Received from server: %s\n", buffer);

    return 0;
}

void checkHostName(int hostName){
    if(hostName == -1){
        perror("gethostname");
        exit(1);
    }
}

void checkIPbuffer(char *IPbuffer){
    if(strcmp(IPbuffer, "") == 0){
        perror("gethostbyname");
        exit(1);
    }
}