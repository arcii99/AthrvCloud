//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 21
#define SERVER_ADDR "127.0.0.1"

int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0){
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, SERVER_ADDR, &serv_addr.sin_addr)<=0){
        perror("invalid address");
        exit(EXIT_FAILURE);
    }

    if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    send(sock, "USER anonymous\r\n", strlen("USER anonymous\r\n"), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    send(sock, "PASS guest\r\n", strlen("PASS guest\r\n"), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    send(sock, "SYST\r\n", strlen("SYST\r\n"), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    send(sock, "PWD\r\n", strlen("PWD\r\n"), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    send(sock, "PASV\r\n", strlen("PASV\r\n"), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // extract passive mode ip and port from response
    char *token = strtok(buffer, ",");
    int ip[4];
    for(int i = 0; i < 4; i++){
        ip[i] = atoi(token);
        token = strtok(NULL, ",");
    }
    int port = atoi(token) * 256;
    token = strtok(NULL, ",");
    port += atoi(token);

    // open new data socket for passive mode
    int data_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(data_sock < 0){
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in data_addr;
    memset(&data_addr, '0', sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(port);
    char data_addr_str[BUFFER_SIZE];
    sprintf(data_addr_str, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
    if(inet_pton(AF_INET, data_addr_str, &data_addr.sin_addr)<=0){
        perror("invalid address");
        exit(EXIT_FAILURE);
    }

    if(connect(data_sock, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0){
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    send(sock, "RETR file.txt\r\n", strlen("RETR file.txt\r\n"), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    FILE *fp = fopen("file.txt", "w");
    if(fp == NULL){
        perror("file creation failed");
        exit(EXIT_FAILURE);
    }

    // receive file content and write to file
    int len;
    while((len = recv(data_sock, buffer, BUFFER_SIZE, 0)) > 0){
        fwrite(buffer, sizeof(char), len, fp);
    }

    fclose(fp);
    close(data_sock);
    close(sock);

    return 0;
}