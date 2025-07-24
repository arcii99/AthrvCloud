//FormAI DATASET v1.0 Category: Networking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1)
    {
        printf("Error creating socket.\n");
        return 1;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    int connection_status = connect(sock, (struct sockaddr *)&server_address, sizeof(server_address));

    if (connection_status == -1)
    {
        printf("Error connecting to server.\n");
        close(sock);
        return 1;
    }

    char server_response[256];
    recv(sock, &server_response, sizeof(server_response), 0);

    printf("Server Response: %s\n", server_response);

    char message[256];
    printf("Enter a message to send to the server: ");
    fgets(message, 256, stdin);

    send(sock, message, sizeof(message), 0);

    char server_reply[256];
    recv(sock, &server_reply, sizeof(server_reply), 0);

    printf("Server Reply: %s\n", server_reply);

    close(sock);
    return 0;
}