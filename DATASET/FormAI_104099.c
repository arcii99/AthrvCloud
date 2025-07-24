//FormAI DATASET v1.0 Category: Networking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main()
{
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    // Creating a socket for client
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Socket creation failed\n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    // IP Address and Port to connect to
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf("Invalid address/ Address not supported\n");
        return -1;
    }

    // Establishing a connection to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Connection Failed\n");
        return -1;
    }

    printf("Connected to server on port %d\n", PORT);
    printf("Enter message to send to server: ");
    fgets(buffer, 1024, stdin);

    // Sending data to the server
    if (send(sock, buffer, strlen(buffer), 0) < 0)
    {
        printf("Send failed\n");
        return -1;
    }

    printf("Message sent to server\n");

    memset(buffer, 0, sizeof(buffer));

    // Receiving data from the server
    if (read(sock, buffer, 1024) < 0)
    {
        printf("Read failed\n");
        return -1;
    }

    printf("Message from server: %s\n", buffer);

    close(sock);
    return 0;
}