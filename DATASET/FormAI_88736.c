//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF 1024
#define PORT 21

void send_command(int sock, char *cmd) {
    char buf[MAX_BUF];
    memset(buf, 0, MAX_BUF);
    sprintf(buf, "%s\r\n", cmd);
    send(sock, buf, strlen(buf), 0);
}

int main(int argc, char *argv[]) {
    struct sockaddr_in server;
    int sock;
    char buf[MAX_BUF];
    int recv_len;
    char *host = "ftp.example.com";
    char *username = "username";
    char *password = "password";
    char *filename = "example.txt";

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 1;
    }

    // Connect to server
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(host);
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("connect");
        return 1;
    }

    // Read welcome message
    memset(buf, 0, MAX_BUF);
    recv_len = recv(sock, buf, MAX_BUF, 0);
    printf("%s", buf);

    // Send username
    send_command(sock, "USER");
    memset(buf, 0, MAX_BUF);
    recv_len = recv(sock, buf, MAX_BUF, 0);
    printf("%s", buf);
    memset(buf, 0, MAX_BUF);
    sprintf(buf, "%s\r\n", username);
    send(sock, buf, strlen(buf), 0);
    recv_len = recv(sock, buf, MAX_BUF, 0);
    printf("%s", buf);

    // Send password
    send_command(sock, "PASS");
    memset(buf, 0, MAX_BUF);
    recv_len = recv(sock, buf, MAX_BUF, 0);
    printf("%s", buf);
    memset(buf, 0, MAX_BUF);
    sprintf(buf, "%s\r\n", password);
    send(sock, buf, strlen(buf), 0);
    recv_len = recv(sock, buf, MAX_BUF, 0);
    printf("%s", buf);

    // Switch to binary mode
    send_command(sock, "TYPE I");
    memset(buf, 0, MAX_BUF);
    recv_len = recv(sock, buf, MAX_BUF, 0);
    printf("%s", buf);

    // Send PASV command
    send_command(sock, "PASV");
    memset(buf, 0, MAX_BUF);
    recv_len = recv(sock, buf, MAX_BUF, 0);
    printf("%s", buf);

    // Parse IP and port from response
    char *ip_str = strtok(buf, "(");
    ip_str = strtok(NULL, ",");
    ip_str = strtok(NULL, ",");
    ip_str = strtok(NULL, ",");
    char *port_str = strtok(NULL, ",");
    port_str[strlen(port_str)-1] = '\0';
    unsigned char ip[4];
    sscanf(ip_str, "%hhu,%hhu,%hhu,%hhu", &ip[0], &ip[1], &ip[2], &ip[3]);
    int port = atoi(port_str) * 256 + atoi(port_str+strlen(port_str)+1);

    // Connect to data socket
    int data_sock;
    struct sockaddr_in data_server;
    if ((data_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 1;
    }
    data_server.sin_family = AF_INET;
    data_server.sin_port = htons(port);
    data_server.sin_addr.s_addr = inet_addr(host);
    if (connect(data_sock, (struct sockaddr*)&data_server, sizeof(data_server)) < 0) {
        perror("connect");
        return 1;
    }

    // Send RETR command
    send_command(sock, "RETR");
    memset(buf, 0, MAX_BUF);
    sprintf(buf, "%s\r\n", filename);
    send(sock, buf, strlen(buf), 0);
    memset(buf, 0, MAX_BUF);
    recv_len = recv(sock, buf, MAX_BUF, 0);
    printf("%s", buf);

    // Receive file
    FILE *fp = fopen(filename, "wb");
    while ((recv_len = recv(data_sock, buf, MAX_BUF, 0)) > 0) {
        fwrite(buf, 1, recv_len, fp);
    }
    fclose(fp);
    printf("File transfer complete.\n");

    // Close sockets and exit
    close(data_sock);
    close(sock);
    return 0;
}