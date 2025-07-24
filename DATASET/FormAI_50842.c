//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    int sock_fd;
    struct sockaddr_in target;
    char *server_ip = "192.168.1.1";
    int port_no = 8080;
    char buffer[BUFSIZE];
    ssize_t bytes_recv, bytes_sent;
    int exit_status = 0;

    /* Create socket */
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        exit(1);
    }

    /* Configure socket parameters */
    bzero(&target, sizeof(struct sockaddr_in));
    target.sin_family = AF_INET;
    target.sin_port = htons(port_no);

    /* Convert server ip string to binary */
    if (inet_aton(server_ip, &target.sin_addr) == 0)
    {
        fprintf(stderr, "Invalid host address\n");
        exit(1);
    }

    /* Connect to server */
    if (connect(sock_fd, (struct sockaddr *)&target, sizeof(struct sockaddr_in)) == -1)
    {
        perror("connect");
        exit(1);
    }

    /* Send request to server */
    bytes_sent = send(sock_fd, "GET / HTTP/1.0\r\n\r\n", 18, 0);
    if (bytes_sent == -1)
    {
        perror("send");
        exit_status = 1;
        goto CLEANUP;
    }

    /* Receive response from server */
    memset(buffer, 0, BUFSIZE);
    bytes_recv = recv(sock_fd, buffer, BUFSIZE-1, 0);
    if (bytes_recv == -1)
    {
        perror("recv");
        exit_status = 1;
        goto CLEANUP;
    }

    printf("Server response:\n%s\n", buffer);

CLEANUP:
    close(sock_fd);
    return exit_status;
}