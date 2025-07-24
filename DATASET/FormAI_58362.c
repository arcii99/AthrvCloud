//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 21
#define USERNAME "username"
#define PASSWORD "password"

int sock_fd;

void readResponse(char* buffer, int size) {
    memset(buffer, 0, size);
    int len = recv(sock_fd, buffer, size, 0);
    if(len < 0) {
        perror("Error occurred while reading response!");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);
}

int sendCommand(char* command) {
    if(send(sock_fd, command, strlen(command), 0) < 0) {
        perror("Error occurred while sending command!");
        exit(EXIT_FAILURE);
    }
    printf("%s", command);
    char buffer[512];
    readResponse(buffer, sizeof(buffer));
    return buffer[0] == '2' ? 0 : -1;
}

void connectToServer() {
    struct sockaddr_in server_addr;
    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error occurred while creating socket!");
        exit(EXIT_FAILURE);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if(inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Error occurred while setting server address!");
        exit(EXIT_FAILURE);
    }
    if(connect(sock_fd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error occurred while connecting to server!");
        exit(EXIT_FAILURE);
    }
    char buffer[512];
    readResponse(buffer, sizeof(buffer));
}

void login() {
    char buffer[512];
    if(sendCommand("USER " USERNAME "\r\n") < 0) exit(EXIT_FAILURE);
    if(sendCommand("PASS " PASSWORD "\r\n") < 0) exit(EXIT_FAILURE);
    printf("Login successful!\n");
}

void startFTP() {
    char buffer[512];
    if(sendCommand("PASV\r\n") < 0) exit(EXIT_FAILURE);

    char* response = strdup(buffer);
    int a, b, c, d, p, p1, p2, p3, p4;
    sscanf(response, "%d.%d.%d.%d,%d,%d", &a, &b, &c, &d, &p1, &p2);
    p = p1 * 256 + p2;
    printf("Trying to connect to data channel on %d\n", p);

    struct sockaddr_in data_addr;
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(p);
    data_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    int data_sock_fd;
    if((data_sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error occurred while creating data socket!");
        exit(EXIT_FAILURE);
    }
    if(connect(data_sock_fd, (const struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        perror("Error occurred while connecting to data channel!");
        exit(EXIT_FAILURE);
    }
    readResponse(buffer, sizeof(buffer));
    printf("\nResponse from data channel:%s\n", buffer);
    printf("FTP session started!\n");
}

int main() {
    connectToServer();
    login();
    startFTP();
    return 0;
}