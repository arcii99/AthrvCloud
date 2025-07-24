//FormAI DATASET v1.0 Category: Firewall ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Define the port number for the firewall
#define PORT 8080

int main()
{
    int sock_fd, client_fd, flag, rd_len;
    struct sockaddr_in server_addr, client_addr;
    char buff[BUFSIZ], *whitelist[] = {"www.google.com", "www.facebook.com", "www.youtube.com"};
    socklen_t client_len;

    // Create a socket using TCP protocol
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        printf("Error: Socket creation failed!\n");
        exit(EXIT_FAILURE);
    }

    // Initialize server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the given address and port number
    if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Error: Socket binding failed!\n");
        exit(EXIT_FAILURE);
    }

    // Listen to incoming connections
    if (listen(sock_fd, 5) < 0)
    {
        printf("Error: Listen failed!\n");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections and process them
    while (1)
    {
        client_len = sizeof(client_addr);
        client_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &client_len);

        if (client_fd < 0)
        {
            printf("Error: Accept failed!\n");
            exit(EXIT_FAILURE);
        }

        // Check if the client is in the whitelist
        flag = 0;
        for (int i = 0; i < sizeof(whitelist) / sizeof(whitelist[0]); ++i)
        {
            if (strstr(buff, whitelist[i]))
            {
                flag = 1;
                break;
            }
        }

        // If the client is not in the whitelist, deny connection
        if (!flag)
        {
            printf("Connection denied from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            close(client_fd);
            continue;
        }

        // Read the request from the client
        rd_len = read(client_fd, buff, BUFSIZ);

        if (rd_len < 0)
        {
            printf("Error: Read failed!\n");
            exit(EXIT_FAILURE);
        }

        // Log the request
        int fd = open("firewall.log", O_WRONLY | O_CREAT | O_APPEND, 0644);
        dprintf(fd, "%s %s\n", inet_ntoa(client_addr.sin_addr), buff);
        close(fd);

        // Send the response to the client
        char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Welcome to the Firewall!</h1></body></html>";
        write(client_fd, response, sizeof(response));

        // Close the client socket
        close(client_fd);
    }

    return 0;
}