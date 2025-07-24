//FormAI DATASET v1.0 Category: Client Server Application ; Style: introspective
// This is a unique example of a Client-Server Application 
// It is designed to be a time-syncing server, which allows clients to sync up their time with the server's time
// This program is written in C and uses basic sockets to establish communication between the server and clients

// Server Side Program
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define PORT_NUM 8080
#define TIME_BUFF_SIZE 100

int main()
{
    int socket_fd, client_fd, n;
    char time_buff[TIME_BUFF_SIZE];
    struct sockaddr_in server_addr, client_addr;
    time_t current_time;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd < 0) 
    {
        perror("Error: Failed to create socket.");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT_NUM);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
    {
        perror("Error: Failed to bind socket.");
        exit(1);
    }

    listen(socket_fd, 5);

    printf("Server started. Waiting for clients...\n");

    memset(&client_addr, 0, sizeof(client_addr));
    socklen_t client_len = sizeof(client_addr);

    while (1) 
    {
        client_fd = accept(socket_fd, (struct sockaddr *)&client_addr, &client_len);

        if (client_fd < 0) 
        {
            perror("Error: Failed to accept client socket.");
            exit(1);
        }

        current_time = time(NULL);
        snprintf(time_buff, TIME_BUFF_SIZE, "%s", ctime(&current_time));

        n = write(client_fd, time_buff, strlen(time_buff));

        if (n < 0) 
        {
            perror("Error: Failed to write to client socket.");
            exit(1);
        }

        close(client_fd);
    }

    close(socket_fd);

    return 0;
}