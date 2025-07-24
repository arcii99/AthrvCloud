//FormAI DATASET v1.0 Category: Chat server ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080

int main()
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,(socklen_t*)&addrlen)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("Welcome to my chat server!\n");
    printf("Type 'help' for commands and 'exit' to leave the chat.\n\n");

    while (1)
    {
        valread = read(new_socket, buffer, 1024);
        buffer[valread] = '\0';

        if (strcmp(buffer, "help\n") == 0)
        {
            printf("Commands:\n");
            printf("1. help : Display all commands\n");
            printf("2. clear : Clear the chat screen\n");
            printf("3. exit : Leave the chat\n");
        }
        else if (strcmp(buffer, "clear\n") == 0)
        {
            printf("\033[2J\033[1;1H"); // Clear screen
        }
        else if (strcmp(buffer, "exit\n") == 0)
        {
            printf("Goodbye!\n");
            send(new_socket, "Goodbye!\n", strlen("Goodbye!\n"), 0);
            break;
        }
        else
        {
            printf("Client: %s", buffer);
            printf("You: ");

            fgets(buffer, 1024, stdin);
            buffer[strcspn(buffer, "\n")] = '\0'; // Remove new line character

            send(new_socket, buffer, strlen(buffer), 0);
        }
    }
    return 0;
}