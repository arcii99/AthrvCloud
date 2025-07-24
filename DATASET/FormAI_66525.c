//FormAI DATASET v1.0 Category: Firewall ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int sockfd;
    struct sockaddr_in server_addr, client_addr;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Adding firewall rule to block incoming traffic from IP address 192.168.0.10
    system("iptables -A INPUT -s 192.168.0.10 -j DROP");

    memset(&server_addr, 0, sizeof(server_addr));

    // Filling server information
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Binding the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(sockfd, 5) == -1)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        socklen_t len = sizeof(client_addr);

        // Accepting incoming connection
        int connfd = accept(sockfd, (struct sockaddr *)&client_addr, &len);

        // Adding firewall rule to block incoming traffic from port 22
        system("iptables -A INPUT -p tcp --dport 22 -j DROP");

        if (connfd == -1)
        {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Handling incoming data
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));
        read(connfd, buffer, sizeof(buffer));

        // Printing incoming data
        printf("Data received: %s\n", buffer);

        // Adding firewall rule to block all incoming traffic to specific port
        system("iptables -A INPUT -p tcp --dport 8080 -j DROP");

        // Clearing buffer and closing connection
        memset(buffer, 0, sizeof(buffer));
        close(connfd);
    }

    return 0;
}