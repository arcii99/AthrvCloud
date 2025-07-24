//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: active
#include <stdio.h>      //Header files to include
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
 
#define SERVER_ADDR "127.0.0.1"    //IP address to connect to
#define SERVER_PORT 21              //FTP port
#define BUFFER_SIZE 1024            //Buffer size for sending/receiving data

int main()
{
    int sd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    //Creating socket
    if((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    //Server address structure
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDR, &(server_addr.sin_addr));
 
    //Connecting to the FTP server 
    if (connect(sd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("connect error");
        exit(EXIT_FAILURE);
    }

    //Receiving welcome message from server
    bzero(buffer, BUFFER_SIZE);
    if (recv(sd, buffer, BUFFER_SIZE, 0) < 0)
    {
        perror("receive error");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);
 
    //Sending username
    char username[] = "USER anonymous\r\n";
    if (send(sd, username, strlen(username), 0) < 0)
    {
        perror("send error");
        exit(EXIT_FAILURE);
    }
 
    //Receiving response from server
    bzero(buffer, BUFFER_SIZE);
    if (recv(sd, buffer, BUFFER_SIZE, 0) < 0)
    {
        perror("receive error");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);
 
    //Sending password
    char password[] = "PASS \r\n";
    if (send(sd, password, strlen(password), 0) < 0)
    {
        perror("send error");
        exit(EXIT_FAILURE);
    }
 
    //Receiving response from server
    bzero(buffer, BUFFER_SIZE);
    if (recv(sd, buffer, BUFFER_SIZE, 0) < 0)
    {
        perror("receive error");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    //Entering passive mode
    char pasv[] = "PASV\r\n";
    if (send(sd, pasv, strlen(pasv), 0) < 0)
    {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    //Receiving response from server
    bzero(buffer, BUFFER_SIZE);
    if (recv(sd, buffer, BUFFER_SIZE, 0) < 0)
    {
        perror("receive error");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    //Parsing passive mode response to get port number
    char *p1 = strchr(buffer, '(') + 1;
    char *p2 = strchr(buffer, ')');
    char *temp = calloc((p2 - p1), sizeof(char));
    strncpy(temp, p1, (p2 - p1));
    char *token;
    token = strtok(temp, ",");
    int port[6];
    int i = 0;
    while (token != NULL)
    {
        port[i] = atoi(token);
        token = strtok(NULL, ",");
        i++;
    }
    int data_port = port[4]*256 + port[5];

    //Creating data socket
    int data_sd;
    struct sockaddr_in data_addr;
    bzero(&data_addr, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER_ADDR, &(data_addr.sin_addr));
    data_addr.sin_port = htons(data_port);
    if((data_sd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    //Connecting to the data socket
    if (connect(data_sd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0)
    {
        perror("connect error");
        exit(EXIT_FAILURE);
    }

    //Sending command to list files
    char list[] = "LIST\r\n";
    if (send(sd, list, strlen(list), 0) < 0)
    {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    //Receiving file list
    bzero(buffer, BUFFER_SIZE);
    if (recv(data_sd, buffer, BUFFER_SIZE, 0) < 0)
    {
        perror("receive error");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    //Closing data socket
    close(data_sd);

    //Exiting from FTP server
    char quit[] = "QUIT\r\n";
    if (send(sd, quit, strlen(quit), 0) < 0)
    {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    //Receiving response from server
    bzero(buffer, BUFFER_SIZE);
    if (recv(sd, buffer, BUFFER_SIZE, 0) < 0)
    {
        perror("receive error");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);
 
    //Closing control socket
    close(sd);

    return 0;
}