//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5000

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        printf("Error creating socket\n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error binding socket\n");
        return -1;
    }

    if (listen(server_fd, 3) < 0)
    {
        printf("Error listening\n");
        return -1;
    }

    printf("Server started...\n");

    while (1)
    {
        if ((new_socket = accept(server_fd, (struct sockaddr *)NULL, NULL)) < 0)
        {
            printf("Error accepting client\n");
            return -1;
        }

        printf("New client connected\n");

        send(new_socket, "Welcome to my chat room!\n", strlen("Welcome to my chat room!\n"), 0);

        while (1)
        {
            memset(buffer, 0, sizeof(buffer));

            valread = read(new_socket, buffer, sizeof(buffer));

            if (valread <= 0)
            {
                printf("Client disconnected\n");
                break;
            }

            printf("Client: %s", buffer);

            if (strcmp(buffer, "bye\n") == 0)
            {
                send(new_socket, "See you later!\n", strlen("See you later!\n"), 0);
                break;
            }

            printf("Server: ");

            fgets(buffer, sizeof(buffer), stdin);

            send(new_socket, buffer, strlen(buffer), 0);
        }

        close(new_socket);
    }

    close(server_fd);

    return 0;
}