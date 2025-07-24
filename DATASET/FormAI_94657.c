//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: excited
// FTP Client example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 512
#define COMMAND_SIZE 100

char buffer[BUFFER_SIZE];

int main(int argc, char *argv[]) {
    int sock = 0;
    struct sockaddr_in serv_addr;

    // create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error.");
        return -1;
    }

    // set server address
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported");
        return -1;
    }

    // connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
      printf("Connection failed.");
      return -1;
    }

    // receive welcome message
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // send username
    char user[COMMAND_SIZE];
    printf("Enter username: ");
    fgets(user, COMMAND_SIZE, stdin);
    send(sock, user, strlen(user), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // send password
    char pass[COMMAND_SIZE];
    printf("Enter password: ");
    fgets(pass, COMMAND_SIZE, stdin);
    send(sock, pass, strlen(pass), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // send passive mode command
    char pasv[] = "PASV\r\n";
    send(sock, pasv, strlen(pasv), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // close connection
    close(sock);
    return 0;
}