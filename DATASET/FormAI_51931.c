//FormAI DATASET v1.0 Category: Networking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    memset(server_addr.sin_zero, '\0', sizeof(server_addr.sin_zero));

    int connection_status = connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if (connection_status == -1)
    {
        printf("There was an error establishing a connection to the server.\n");
        exit(EXIT_FAILURE);
    }

    printf("Successfully connected to the server!\n");

    char message[128];
    printf("Please enter a message to send to the server: ");
    fgets(message, sizeof(message), stdin);

    send(client_socket, message, strlen(message), 0);

    char server_response[128];
    recv(client_socket, &server_response, sizeof(server_response), 0);

    printf("The server's response was: %s\n", server_response);

    close(client_socket);

    return 0;
}