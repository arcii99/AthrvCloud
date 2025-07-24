//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: multivariable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 5001

int main() {
    int sock_fd, conn_fd;
    struct sockaddr_in cli_addr, serv_addr;
    char send_buf[1000], receive_buf[1000];
    int send_len, receive_len;

    // create socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error: create socket failed");
        exit(1);
    }
    printf("Socket created successfully!\n");

    // bind
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("Error: bind failed");
        exit(1);
    }
    printf("Bind successfully!\n");

    // listen
    if (listen(sock_fd, 10) == -1) {
        perror("Error: listen failed");
        exit(1);
    }
    printf("Listening...\n");

    // accept
    socklen_t cli_len = sizeof(cli_addr);
    if ((conn_fd = accept(sock_fd, (struct sockaddr *)&cli_addr, &cli_len)) == -1) {
        perror("Error: accept failed");
        exit(1);
    }
    printf("Connected successfully!\n");

    // receive message from client
    if ((receive_len = recv(conn_fd, receive_buf, 1000, 0)) == -1) {
        perror("Error: receive failed");
        exit(1);
    }
    printf("Message received successfully!\n");
    printf("Message from client: %s\n", receive_buf);

    // send message to client
    sprintf(send_buf, "Hello, client! Your message length is %d", receive_len);
    send_len = strlen(send_buf);
    if (send(conn_fd, send_buf, send_len, 0) == -1) {
        perror("Error: send failed");
        exit(1);
    }
    printf("Message sent successfully!\n");

    // close socket
    close(conn_fd);
    close(sock_fd);

    return 0;
}