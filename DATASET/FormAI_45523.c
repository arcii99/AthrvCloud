//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 1024

void sendCommand(int fd, char* msg);
void sendUser(int fd, char* user);
void sendPass(int fd, char* pass);
void receive(int fd, char* buffer);

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <Server Address> <Username> <Password>\n", argv[0]);
        return 0;
    }

    int fd;
    struct sockaddr_in serverAddr;

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0)
    {
        printf("Failed to create socket\n");
        return -1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(110);
    inet_pton(AF_INET, argv[1], &serverAddr.sin_addr);

    if (connect(fd, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) < 0)
    {
        printf("Failed to connect to server\n");
        return -1;
    }

    char buffer[MAX_SIZE];
    receive(fd, buffer);

    sendUser(fd, argv[2]);
    receive(fd, buffer);

    sendPass(fd, argv[3]);
    receive(fd, buffer);

    sendCommand(fd, "LIST\n");
    receive(fd, buffer);

    printf("List of messages:\n%s\n", buffer);

    close(fd);

    return 0;
}

void sendCommand(int fd, char* msg)
{
    send(fd, msg, strlen(msg), 0);
}

void sendUser(int fd, char* user)
{
    char buffer[MAX_SIZE];

    sprintf(buffer, "USER %s\n", user);
    sendCommand(fd, buffer);
}

void sendPass(int fd, char* pass)
{
    char buffer[MAX_SIZE];

    sprintf(buffer, "PASS %s\n", pass);
    sendCommand(fd, buffer);
}

void receive(int fd, char* buffer)
{
    memset(buffer, 0, MAX_SIZE);
    recv(fd, buffer, MAX_SIZE, 0);
}