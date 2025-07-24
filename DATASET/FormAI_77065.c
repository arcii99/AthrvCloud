//FormAI DATASET v1.0 Category: Client Server Application ; Style: modular
//Client.c

#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    struct sockaddr_in server_addr;
    int sock = 0, valread;
    char msg[1024];
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if(inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr)<=0) {
        printf("Invalid address/ Address not supported\n");
        return -1;
    }
    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection Failed\n");
        return -1;
    }
    while(1) {
        bzero(buffer,1024);
        printf("Send message: ");
        scanf("%[^\n]%*c", msg);
        send(sock, msg, strlen(msg), 0);
        if(strncmp(msg, "Exit", 4) == 0) {
            printf("Closing connection\n");
            close(sock);
            return 0;
        }
        valread = read(sock, buffer, 1024);
        printf("%s\n", buffer);
    }
    return 0;
}