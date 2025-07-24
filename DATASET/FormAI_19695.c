//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER "pop.gmail.com"
#define PORT 995

char username[100];
char password[100];

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void receive(int sock) {
    char buffer[2048] = {0};
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
}

void send_command(int sock, char *cmd) {
    char buffer[2048] = {0};
    sprintf(buffer, "%s\r\n", cmd);
    send(sock, buffer, strlen(buffer), 0);
}

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;

    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    strtok(username, "\n");

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    strtok(password, "\n");

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation error");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, SERVER, &serv_addr.sin_addr) <= 0) {
        error("Invalid address/ Address not supported");
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Connection Failed");
    }

    receive(sock);

    send_command(sock, "USER");
    send_command(sock, username);

    receive(sock);

    send_command(sock, "PASS");
    send_command(sock, password);

    receive(sock);

    send_command(sock, "LIST");

    receive(sock);

    send_command(sock, "QUIT");

    receive(sock);

    close(sock);

    return 0;
}