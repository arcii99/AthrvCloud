//FormAI DATASET v1.0 Category: Client Server Application ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int client_sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    if((client_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("invalid address");
        return -1;
    }

    if(connect(client_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connection failed");
        return -1;
    }

    while(1) {
        char message[1024] = {0};
        printf("Enter message: ");
        fgets(message, 1024, stdin);

        if(strcmp(message, "exit\n") == 0) {
            send(client_sock, message, strlen(message), 0);
            break;
        }

        send(client_sock, message, strlen(message), 0);
        valread = read(client_sock, buffer, 1024);
        printf("Server response: %s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }

    close(client_sock);
    return 0;
}