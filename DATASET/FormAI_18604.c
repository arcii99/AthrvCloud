//FormAI DATASET v1.0 Category: Client Server Application ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[]) 
{
    int sock;
    struct sockaddr_in serv_addr;
    char message[BUF_SIZE];
    int str_len;
    int i = 0;

    if (argc != 3) 
    {
        printf("Usage: %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        error_handling("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("connect() error");

    printf("Enter a message: ");
    fgets(message, BUF_SIZE, stdin);

    if (write(sock, message, strlen(message)) == -1)
        error_handling("write() error");

    while ((str_len = read(sock, message, BUF_SIZE - 1)) > 0) 
    {
        message[str_len] = 0;
        printf("Message from server: %s", message);
        if(strcmp(message, "quit\n") == 0)
            break;

        printf("Enter a message: ");
        fgets(message, BUF_SIZE, stdin);

        if (write(sock, message, strlen(message)) == -1)
            error_handling("write() error");
    }

    close(sock);
    return 0;
}

void error_handling(char *message) 
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}