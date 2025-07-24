//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define BUFSIZE 2048

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buff[BUFSIZE];
    int n;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);

    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("inet_pton error");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect error");
        return 1;
    }

    if ((n = read(sock, buff, BUFSIZE)) < 0) {
        perror("read error");
        return 1;
    }
    buff[n] = '\0';
    printf("%s", buff);

    char user[50];
    printf("Username: ");
    scanf("%s", user);
    sprintf(buff, "USER %s\r\n", user);
    write(sock, buff, strlen(buff));

    if ((n = read(sock, buff, BUFSIZE)) < 0) {
        perror("read error");
        return 1;
    }
    buff[n] = '\0';
    printf("%s", buff);

    char password[50];
    printf("Password: ");
    scanf("%s", password);
    sprintf(buff, "PASS %s\r\n", password);
    write(sock, buff, strlen(buff));

    if ((n = read(sock, buff, BUFSIZE)) < 0) {
        perror("read error");
        return 1;
    }
    buff[n] = '\0';
    printf("%s", buff);

    sprintf(buff, "LIST\r\n");
    write(sock, buff, strlen(buff));

    if ((n = read(sock, buff, BUFSIZE)) < 0) {
        perror("read error");
        return 1;
    }
    buff[n] = '\0';
    printf("%s", buff);

    close(sock);

    return 0;
}