//FormAI DATASET v1.0 Category: Simple Web Server ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main(int argc, char const *argv[])
{
    int sock_fd, new_sock_fd, opt = 1;
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    char buffer[BUFFER_SIZE] = {0};

    // Create socket file descriptor
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port 8080 using setsockopt
    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    // Attach socket to the port 8080 using bind
    if (bind(sock_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections using listen
    if (listen(sock_fd, 5) < 0)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        // Accept incoming connections using accept
        if ((new_sock_fd = accept(sock_fd, (struct sockaddr *)&addr, (socklen_t *)&addr_len)) < 0)
        {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Read the request from the client
        read(new_sock_fd, buffer, BUFFER_SIZE);

        // Send the response to the client
        char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nHello, World!";
        write(new_sock_fd, response, strlen(response));

        // Close the socket
        close(new_sock_fd);
    }
    return 0;
}