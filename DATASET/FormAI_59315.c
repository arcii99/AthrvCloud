//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSIZE 1024

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Can't create socket.\n");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(21);

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        printf("Error: Can't connect to server.\n");
        return 1;
    }

    char buffer[MAXSIZE];
    memset(buffer, 0, MAXSIZE);
    recv(sock, buffer, MAXSIZE, 0);
    printf("%s", buffer);

    strcpy(buffer, "USER ftpuser\r\n");
    send(sock, buffer, strlen(buffer), 0);
    memset(buffer, 0, MAXSIZE);
    recv(sock, buffer, MAXSIZE, 0);
    printf("%s", buffer);

    strcpy(buffer, "PASS S3cr3tP@ssw0rd\r\n");
    send(sock, buffer, strlen(buffer), 0);
    memset(buffer, 0, MAXSIZE);
    recv(sock, buffer, MAXSIZE, 0);
    printf("%s", buffer);

    strcpy(buffer, "PASV\r\n");
    send(sock, buffer, strlen(buffer), 0);
    memset(buffer, 0, MAXSIZE);
    recv(sock, buffer, MAXSIZE, 0);
    printf("%s", buffer);

    char *p1, *p2;
    p1 = strchr(buffer, '(');
    p2 = strchr(buffer, ')');
    char *token;
    token = strtok(p1 + 1, ",");
    unsigned int port = atoi(token) << 8;
    token = strtok(NULL, ",");
    port += atoi(token);
    printf("port is %d\n", port);

    struct sockaddr_in data_socket;
    int data_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sock == -1) {
        printf("ERROR: Can't create socket.\n");
        return 1;
    }

    memset(&data_socket, 0, sizeof(data_socket));
    data_socket.sin_family = AF_INET;
    data_socket.sin_addr.s_addr = inet_addr("127.0.0.1");
    data_socket.sin_port = htons(port);

    if (connect(data_sock, (struct sockaddr *) &data_socket, sizeof(data_socket)) < 0) {
        printf("Error: Can't connect to server.\n");
        return 1;
    }

    strcpy(buffer, "SIZE example.txt\r\n");
    send(sock, buffer, strlen(buffer), 0);
    memset(buffer, 0, MAXSIZE);
    recv(sock, buffer, MAXSIZE, 0);
    printf("%s", buffer);

    char size_buffer[MAXSIZE];
    strcpy(size_buffer, buffer + 4);
    char *p;
    p = strchr(size_buffer, '\r');
    *p = '\0';
    printf("The size of example.txt is %s bytes.\n", size_buffer);

    FILE *fp = fopen("example.txt", "wb");
    if (fp == NULL) {
        printf("ERROR: Can't open file.\n");
        return 1;
    }

    strcpy(buffer, "RETR example.txt\r\n");
    send(sock, buffer, strlen(buffer), 0);
    memset(buffer, 0, MAXSIZE);
    recv(sock, buffer, MAXSIZE, 0);
    printf("%s", buffer);

    while (1) {
        memset(buffer, 0, MAXSIZE);
        int bytes_recv = recv(data_sock, buffer, MAXSIZE, 0);
        if (bytes_recv == 0) {
            break;
        }
        fwrite(buffer, sizeof(char), bytes_recv, fp);
    }

    memset(buffer, 0, MAXSIZE);
    recv(sock, buffer, MAXSIZE, 0);
    printf("%s", buffer);

    fclose(fp);
    close(sock);
    close(data_sock);

    return 0;
}