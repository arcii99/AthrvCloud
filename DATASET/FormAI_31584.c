//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: random
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define BUF_SIZE 256

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in serv_addr;
    char message[BUF_SIZE];
    int str_len, recv_len, recv_cnt;
    int port = 8888;

    // Create a TCP socket
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        perror("socket() error");
        return -1;
    }

    // Set the server address information
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(port);

    // Try to connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        perror("connect() error");
        return -1;
    }

    // Send a message to the server
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    str_len = write(sock, message, strlen(message));
    if (str_len == -1)
    {
        perror("write() error");
        return -1;
    }

    // Receive a message from the server
    recv_len = 0;
    while (recv_len < str_len)
    {
        recv_cnt = read(sock, &message[recv_len], BUF_SIZE-1);
        if (recv_cnt == -1)
        {
            perror("read() error");
            return -1;
        }
        recv_len += recv_cnt;
    }
    message[recv_len] = 0;

    printf("Received message from the server: %s\n", message);

    // Close the socket
    close(sock);

    return 0;
}