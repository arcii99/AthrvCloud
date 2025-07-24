//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    // Initialize variables
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }

    // Set server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(143); // IMAP port
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection Failed\n");
        return -1;
    }

    // Send LOGIN command
    char* login_cmd = "a001 LOGIN johnsmith password\n";
    send(sock, login_cmd, strlen(login_cmd), 0);
    valread = read(sock, buffer, 1024);
    printf("%s", buffer);

    // Send SELECT command
    char* select_cmd = "a002 SELECT INBOX\n";
    send(sock, select_cmd, strlen(select_cmd), 0);
    valread = read(sock, buffer, 1024);
    printf("%s", buffer);

    // Send FETCH command
    char* fetch_cmd = "a003 FETCH 1 BODY[TEXT]\n";
    send(sock, fetch_cmd, strlen(fetch_cmd), 0);
    valread = read(sock, buffer, 1024);
    printf("%s", buffer);

    // Close socket
    close(sock);

    return 0;
}