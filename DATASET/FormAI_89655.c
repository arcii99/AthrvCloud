//FormAI DATASET v1.0 Category: Socket programming ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8765
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main()
{
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    // Creating server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Creating socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Setting server socket properties
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Binding server socket to specified port
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Binding to socket failed");
        exit(EXIT_FAILURE);
    }

    // Listening to incoming client connections
    listen(server_fd, MAX_CLIENTS);
    printf("The great medieval server is now listening on port %d...\n", SERVER_PORT);

    // Accepting incoming client connections and handling data
    while (1)
    {
        // Accepting client connection
        if ((client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len)) < 0)
        {
            perror("Accepting connection failed");
            exit(EXIT_FAILURE);
        }

        printf("Intruder alert! A new aspiring knight from %s has entered the great hall!\n",
                inet_ntoa(client_addr.sin_addr));

        // Reading incoming data from client
        while (1)
        {
            memset(buffer, 0, BUFFER_SIZE);
            if (recv(client_fd, buffer, BUFFER_SIZE, 0) < 0)
            {
                perror("Receiving data failed");
                exit(EXIT_FAILURE);
            }

            // Processing client's request
            if (strcmp(buffer, "HELLO") == 0)
            {
                printf("A new challenger has appeared! Who dares to defy me, the great medieval server!\n");
                send(client_fd, "Greetings! What brings you here?\n", BUFFER_SIZE, 0);
            }
            else if (strcmp(buffer, "ATTACK") == 0)
            {
                printf("Attack from %s! Summon the knights at once!\n", inet_ntoa(client_addr.sin_addr));
                send(client_fd, "You dare to attack me, the great medieval server? You shall pay for your insolence!\n", BUFFER_SIZE, 0);
            }
            else if (strcmp(buffer, "GOODBYE") == 0)
            {
                printf("Ha! Running away, are we? The great medieval server always prevails!\n");
                send(client_fd, "Farewell, weakling!\n", BUFFER_SIZE, 0);
                break;
            }
            else
            {
                printf("Unrecognized command: %s\n", buffer);
                send(client_fd, "I do not know what you mean. Please try again!\n", BUFFER_SIZE, 0);
            }
        }

        // Closing client connection
        close(client_fd);
        printf("The aspiring knight from %s has been dealt with accordingly!\n",
                inet_ntoa(client_addr.sin_addr));
    }

    // Closing server socket
    close(server_fd);

    return 0;
}