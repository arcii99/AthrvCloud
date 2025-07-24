//FormAI DATASET v1.0 Category: Socket programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

int main()
{
    // initialize variables
    int server_socket, new_socket;
    struct sockaddr_in server_address, client_address;
    char buffer[256];
    time_t current_time;

    // create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    // bind socket to server address
    bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    // listen for incoming connections
    listen(server_socket, 5);

    printf("Server started on port 8080...\n");

    while(1)
    {
        // accept new connection
        socklen_t client_address_size = sizeof(client_address);
        new_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_size);

        // handle connection
        printf("Client connected: %s\n", inet_ntoa(client_address.sin_addr));
        current_time = time(NULL);
        snprintf(buffer, sizeof(buffer), "Server time: %s", ctime(&current_time));
        send(new_socket, buffer, sizeof(buffer), 0);

        // close connection
        close(new_socket);
        printf("Client disconnected.\n");
    }

    // close server socket
    close(server_socket);

    return 0;
}