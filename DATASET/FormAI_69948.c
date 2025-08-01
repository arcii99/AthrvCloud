//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char message[1000], server_reply[2000];

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    // connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed. Error");
        return 1;
    }
    puts("Connected");

    // send HTTP request
    strcpy(message, "GET / HTTP/1.1\r\n\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }
    puts("Data Sent\n");

    // receive HTTP response
    if (recv(sock, server_reply, 2000, 0) < 0) {
        puts("receive failed");
    }
    puts("Reply received\n");
    puts(server_reply);

    close(sock);
    return 0;
}