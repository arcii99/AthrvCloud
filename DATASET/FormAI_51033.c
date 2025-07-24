//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080

int main()
{
    int sockfd = 0, valread;
    struct sockaddr_in serv_addr;
    char greeting[] = "Hello, World!";
    char buffer[1024] = {0};
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }

    int len = strlen(greeting) + 1;
    send(sockfd, &len, sizeof(len), 0);
    send(sockfd, greeting, len, 0);
    printf("Greetings message sent\n");

    valread = read(sockfd, buffer, 1024);
    printf("%s\n", buffer);
    close(sockfd);
    return 0;
}