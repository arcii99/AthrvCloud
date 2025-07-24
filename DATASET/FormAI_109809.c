//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>

#define PORT 12345

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sock_fd, conn_fd, client_len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[256];

    // create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0)
        error("Error: Opening socket\n");

    // set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // bind the socket to the server address
    if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("Error: Binding\n");

    // listen for incoming connections
    listen(sock_fd, 5);

    printf("Server is listening on port %d...\n", PORT);

    while (true)
    {
        // accept connection
        client_len = sizeof(client_addr);
        conn_fd = accept(sock_fd, (struct sockaddr *)&client_addr, (socklen_t *)&client_len);
        if (conn_fd < 0)
            error("Error: Accepting connection\n");

        // print client's address
        printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));

        int pid = fork();

        if (pid < 0)
        {
            error("Error: Forking\n");
        }
        else if (pid == 0) // child process
        {
            close(sock_fd); // child process does not need the listening socket

            while (true)
            {
                memset(buffer, 0, sizeof(buffer));
                int bytes_read = read(conn_fd, buffer, sizeof(buffer)-1);
                if (bytes_read < 0)
                    error("Error: Reading from socket\n");
                else if (bytes_read == 0) // client disconnected
                    break;

                buffer[bytes_read] = '\0';
                printf("Message from client: %s\n", buffer);

                // echo message back to client
                int bytes_sent = write(conn_fd, buffer, bytes_read);
                if (bytes_sent < 0)
                    error("Error: Writing to socket\n");
            }

            close(conn_fd); // child process should close connection before terminating
            exit(0);
        }
        else // parent process
        {
            close(conn_fd); // parent process does not need the connection socket
        }
    }

    return 0;
}