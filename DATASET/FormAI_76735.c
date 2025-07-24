//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 80

int main()
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    // Creating socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\nSocket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    // Server information
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "192.168.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connect the socket to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    // Send request
    char *message = "GET / HTTP/1.1\r\nHost: 192.168.0.1\r\nConnection: close\r\n\r\n";
    send(sock, message, strlen(message), 0);

    // Receive response
    printf("Scanning network...\n");
    while ((valread = read(sock, buffer, 1024)) > 0)
    {
        printf("%s", buffer);
    }

    printf("\nScan complete!");

    return 0;
}