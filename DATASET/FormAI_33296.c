//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888
#define MAXCLIENTS 10

int main(int argc, char *argv[])
{
    int server_fd, new_socket, valread, opt = 1;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *message = "Wireless network devices found: Router1, Router2, Printer1, Printer2, Computer1, Computer2";
    int clients[MAXCLIENTS] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8888
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8888
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

    while (1)
    {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        //display new client's IP address
        printf("New client connected with IP address: %s \n", inet_ntoa(address.sin_addr));

        send(new_socket, message, strlen(message), 0); //send message to client

        //add new connection to array of clients
        for (int i = 0; i < MAXCLIENTS; i++)
        {
            if (clients[i] == 0)
            {
                clients[i] = new_socket;
                break;
            }
        }

        //broadcast message to all connected clients
        for (int i = 0; i < MAXCLIENTS; i++)
        {
            if (clients[i] > 0 && clients[i] != new_socket)
            {
                if (send(clients[i], message, strlen(message), 0) == -1)
                {
                    perror("send failed");
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
    return 0;
}