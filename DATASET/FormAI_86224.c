//FormAI DATASET v1.0 Category: Chat server ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

void sendMessage(int client_socket, char message[])
{
    send(client_socket, message, strlen(message), 0);
}

int main()
{
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char message[1024], client_message[1024];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    listen(server_socket, 5);

    printf("\n**************************************************");
    printf("\n************** HAPPY CHAT SERVER *****************");
    printf("\n**************************************************");

    while (1)
    {
        printf("\n\nWaiting for a client to connect...");

        int client_address_size = sizeof(client_address);

        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);

        printf("\n\nA client connected successfully!");

        strcpy(message, "*** Welcome to Happy Chat Room! ***");
        sendMessage(client_socket, message);

        while (1)
        {
            memset(client_message, 0, sizeof(client_message));
            recv(client_socket, client_message, sizeof(client_message), 0);

            if (strcmp(client_message, "exit") == 0)
            {
                printf("\n\nA client disconnected successfully!");
                sendMessage(client_socket, "Good Bye :)");
                break;
            }

            printf("\n\nClient: %s", client_message);

            printf("\n\nYour message: ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = 0;

            if (strcmp(message, "exit") == 0)
            {
                sendMessage(client_socket, "Good Bye :)");
                close(client_socket);
                close(server_socket);
                return 0;
            }

            sendMessage(client_socket, message);
        }
    }

    return 0;
}