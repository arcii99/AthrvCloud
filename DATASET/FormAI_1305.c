//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define PACKET_SIZE 1024
#define INTERVAL 5

int main(int argc, char **argv)
{
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(8080);

    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");
    printf("Monitoring network QoS...\n");

    for (;;)
    {
        char buffer[PACKET_SIZE] = "Hello, world!";
        ssize_t write_size = write(sock_fd, buffer, sizeof(buffer));
        if (write_size < 0)
        {
            perror("write failed");
            exit(EXIT_FAILURE);
        }
        printf("Sent packet of size %zd\n", write_size);
        sleep(INTERVAL);
    }

    close(sock_fd);
    return 0;
}