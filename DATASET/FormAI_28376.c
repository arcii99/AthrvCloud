//FormAI DATASET v1.0 Category: Firewall ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

int main()
{
    // create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("Socket creation error");
        exit(1);
    }

    // set up the socket address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // allow multiple connections
    int optval = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int));

    // bind the socket
    if (bind(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Binding error");
        exit(1);
    }

    // listen for incoming connections
    if (listen(sock, SOMAXCONN) < 0)
    {
        perror("Listening error");
        exit(1);
    }

    printf("Server listening on port 8080...\n");

    while (1)
    {
        // accept an incoming connection
        struct sockaddr_in cli_addr;
        socklen_t cli_len = sizeof(cli_addr);
        int cli_sock = accept(sock, (struct sockaddr *)&cli_addr, &cli_len);
        if (cli_sock < 0)
        {
            perror("Accepting error");
            exit(1);
        }

        // get the client's IP address
        char cli_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(cli_addr.sin_addr), cli_ip, INET_ADDRSTRLEN);
        printf("Accepted connection from %s\n", cli_ip);

        // read a message from the client
        char recv_buf[1024];
        memset(&recv_buf, 0, sizeof(recv_buf));
        int bytes_read = read(cli_sock, recv_buf, sizeof(recv_buf));
        if (bytes_read < 0)
        {
            perror("Reading error");
            exit(1);
        }

        // check if the message is allowed
        char *msg = "Hello, World!";
        if (strncmp(recv_buf, "GET / HTTP/1.1", 14) == 0)
        {
            // inject a fake response
            msg = "HTTP/1.1 200 OK\r\nContent-Length: 12\r\n\r\nHello, World!";
        }

        // send a response to the client
        int msg_len = strlen(msg);
        int bytes_sent = send(cli_sock, msg, msg_len, 0);
        if (bytes_sent < 0)
        {
            perror("Sending error");
            exit(1);
        }

        printf("Sent message (%d bytes) to %s\n", msg_len, cli_ip);

        // close the client connection
        close(cli_sock);
    }

    // close the server socket
    close(sock);

    return 0;
}