//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define MAXSIZE 1024

void connectFTPClient(int *client_socket);
void sendFTPCommand(int client_socket, char *command);
void receiveFTPResponse(int client_socket, char *buffer);
void loginFTP(int client_socket);
void changeDirectoryFTP(int client_socket);
void listDirectoryFTP(int client_socket, char *path);
void downloadFTPFile(int client_socket, char *filepath);

int main()
{
    int client_socket;
    char buffer[MAXSIZE];

    connectFTPClient(&client_socket);
    receiveFTPResponse(client_socket, buffer);
    loginFTP(client_socket);
    changeDirectoryFTP(client_socket);
    listDirectoryFTP(client_socket, ".");
    downloadFTPFile(client_socket, "/example.txt");

    close(client_socket);
    return 0;
}

void connectFTPClient(int *client_socket)
{
    struct sockaddr_in server;

    // Creating socket
    *client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (*client_socket == -1)
    {
        perror("ERROR: Could not create socket");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connecting to server
    if (connect(*client_socket, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        close(*client_socket);
        perror("ERROR: Could not connect to server");
        exit(EXIT_FAILURE);
    }
}

void sendFTPCommand(int client_socket, char *command)
{
    if (send(client_socket, command, strlen(command), 0) == -1)
    {
        perror("ERROR: Could not send command");
        exit(EXIT_FAILURE);
    }
}

void receiveFTPResponse(int client_socket, char *buffer)
{
    int len = read(client_socket, buffer, MAXSIZE - 1);
    if (len == -1)
    {
        perror("ERROR: Could not receive response");
        exit(EXIT_FAILURE);
    }
    buffer[len] = '\0';
}

void loginFTP(int client_socket)
{
    char buffer[MAXSIZE];

    sendFTPCommand(client_socket, "USER anonymous\r\n");
    receiveFTPResponse(client_socket, buffer);

    sendFTPCommand(client_socket, "PASS \r\n");
    receiveFTPResponse(client_socket, buffer);
}

void changeDirectoryFTP(int client_socket)
{
    char buffer[MAXSIZE];

    sendFTPCommand(client_socket, "CWD /pub/\r\n");
    receiveFTPResponse(client_socket, buffer);
}

void listDirectoryFTP(int client_socket, char *path)
{
    char buffer[MAXSIZE];

    sendFTPCommand(client_socket, "PASV\r\n");
    receiveFTPResponse(client_socket, buffer);

    int port, p1, p2;
    sscanf(buffer, "227 Entering Passive Mode (%*d,%*d,%*d,%*d,%d,%d)", &p1, &p2);
    port = (p1 << 8) + p2;

    struct sockaddr_in data_server;
    bzero(&data_server, sizeof(data_server));
    data_server.sin_family = AF_INET;
    data_server.sin_addr.s_addr = inet_addr("127.0.0.1");
    data_server.sin_port = htons(port);

    int data_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (data_socket == -1)
    {
        perror("ERROR: Could not create data socket");
        exit(EXIT_FAILURE);
    }

    if (connect(data_socket, (struct sockaddr *)&data_server, sizeof(data_server)) == -1)
    {
        close(data_socket);
        perror("ERROR: Could not connect to data server");
        exit(EXIT_FAILURE);
    }

    char list_command[MAXSIZE];
    sprintf(list_command, "LIST %s\r\n", path);
    sendFTPCommand(client_socket, list_command);
    receiveFTPResponse(client_socket, buffer);

    while ((recv(data_socket, buffer, MAXSIZE - 1, 0)) > 0)
    {
        printf("%s", buffer);
    }
    close(data_socket);
}

void downloadFTPFile(int client_socket, char *filepath)
{
    char buffer[MAXSIZE];

    sendFTPCommand(client_socket, "PASV\r\n");
    receiveFTPResponse(client_socket, buffer);

    int port, p1, p2;
    sscanf(buffer, "227 Entering Passive Mode (%*d,%*d,%*d,%*d,%d,%d)", &p1, &p2);
    port = (p1 << 8) + p2;

    struct sockaddr_in data_server;
    bzero(&data_server, sizeof(data_server));
    data_server.sin_family = AF_INET;
    data_server.sin_addr.s_addr = inet_addr("127.0.0.1");
    data_server.sin_port = htons(port);

    int data_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (data_socket == -1)
    {
        perror("ERROR: Could not create data socket");
        exit(EXIT_FAILURE);
    }

    if (connect(data_socket, (struct sockaddr *)&data_server, sizeof(data_server)) == -1)
    {
        close(data_socket);
        perror("ERROR: Could not connect to data server");
        exit(EXIT_FAILURE);
    }

    char retr_command[MAXSIZE];
    sprintf(retr_command, "RETR %s\r\n", filepath);
    sendFTPCommand(client_socket, retr_command);
    receiveFTPResponse(client_socket, buffer);

    FILE *file = fopen(filepath, "w");
    while ((recv(data_socket, buffer, MAXSIZE - 1, 0)) > 0)
    {
        fwrite(buffer, sizeof(char), strlen(buffer), file);
    }
    fclose(file);
    close(data_socket);
}