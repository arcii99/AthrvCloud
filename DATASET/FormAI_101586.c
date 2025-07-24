//FormAI DATASET v1.0 Category: Chat server ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

bool running = true;
int server_fd, client_sockets[MAX_CLIENTS], max_clients = MAX_CLIENTS;

void handle_client(int client_socket)
{
    char buffer[BUFFER_SIZE];
    int read_size;
    
    while ((read_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0)
    {
        buffer[read_size] = '\0';
        printf("Message from client: %s", buffer);
        send(client_socket, buffer, strlen(buffer), 0);
        memset(buffer, 0, BUFFER_SIZE);
    }
    
    if (read_size == 0)
    {
        printf("Client disconnected\n");
        fflush(stdout);
    }
    else if (read_size == -1)
    {
        perror("recv error: ");
    }
}

void run_server()
{
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        perror("socket error: ");
        exit(EXIT_FAILURE);
    }
    
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1)
    {
        perror("setsockopt error: ");
        exit(EXIT_FAILURE);
    }
    
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == -1)
    {
        perror("bind error: ");
        exit(EXIT_FAILURE);
    }
    
    if (listen(server_fd, MAX_CLIENTS) == -1)
    {
        perror("listen error: ");
        exit(EXIT_FAILURE);
    }
    
    printf("Server running on port %d\n", PORT);
    fflush(stdout);
    
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(server_fd, &read_fds);
    
    while (running)
    {
        fd_set fds = read_fds;
        if (select(FD_SETSIZE, &fds, NULL, NULL, NULL) == -1)
        {
            perror("select error: ");
            break;
        }
        
        for (int i = 0; i < max_clients; i++)
        {
            if (FD_ISSET(client_sockets[i], &fds))
            {
                if (i == 0)
                {
                    struct sockaddr_in client_address;
                    socklen_t address_len = sizeof(client_address);
                    int client_socket = accept(server_fd, (struct sockaddr *)&client_address, &address_len);
                    if (client_socket == -1)
                    {
                        perror("accept error: ");
                        continue;
                    }
                    
                    printf("New client connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                    fflush(stdout);
                    
                    for (int j = 1; j < max_clients; j++)
                    {
                        if (client_sockets[j] == 0)
                        {
                            client_sockets[j] = client_socket;
                            break;
                        }
                    }
                }
                else
                {
                    handle_client(client_sockets[i]);
                }
            }
        }
    }
}

int main()
{
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        client_sockets[i] = 0;
    }
    
    run_server();
    
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        if (client_sockets[i] != 0)
        {
            close(client_sockets[i]);
        }
    }
    
    close(server_fd);
    
    printf("Server shut down successfully\n");
    fflush(stdout);
    
    return 0;
}