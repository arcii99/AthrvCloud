//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LEN 1024
#define PORT 8080

int main()
{
    // Greetings, fair traveller!
    printf("Hail and well met! I am a Simple HTTP Proxy, ready to serve thee.\n");

    // Prepare thy sockets and variables
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[MAX_LEN] = {0};

    // Create thy server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set thy server port, oh valorous knight!
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind thy socket to thine port, brave sir!
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // Listen to thy socket, noble lord!
    if (listen(server_fd, 3) < 0)
    {
        perror("Failed to listen on socket");
        exit(EXIT_FAILURE);
    }

    // Await requests and serve, fair maiden!
    while (1)
    {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            perror("Error accepting request");
            exit(EXIT_FAILURE);
        }

        // Fetch the request message, oh thy fair lady!
        valread = read(new_socket, buffer, MAX_LEN);
        printf("Received Request: %s", buffer);

        // Parse the request message and extract the host, gentle sir!
        char *host = strtok(buffer, " ");
        host = strtok(NULL, " \r\n");
        if (host == NULL)
        {
            fprintf(stderr, "Could not extract host from request\n");
            close(new_socket);
            continue;
        }

        // Fetch the IP address of the host, oh thou valiant knave!
        struct hostent *server = gethostbyname(host);
        if (server == NULL)
        {
            fprintf(stderr, "Could not get IP address for host: %s\n", host);
            close(new_socket);
            continue;
        }
        struct in_addr **addr_list = (struct in_addr **)server->h_addr_list;

        // Connect to the remote server, oh most esteemed lord!
        int remote_socket = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in remote_address;
        remote_address.sin_family = AF_INET;
        remote_address.sin_addr.s_addr = inet_addr(inet_ntoa(*addr_list[0]));
        remote_address.sin_port = htons(80);
        if (connect(remote_socket, (struct sockaddr *)&remote_address, sizeof(remote_address)) < 0)
        {
            perror("Could not connect to remote server");
            close(new_socket);
            close(remote_socket);
            continue;
        }

        // Forward the request to the remote server, brave knight!
        if (write(remote_socket, buffer, strlen(buffer)) < 0)
        {
            perror("Failed to send request to remote server");
            close(new_socket);
            close(remote_socket);
            continue;
        }

        // Receive the response from the remote server, oh wise sage!
        memset(buffer, 0, MAX_LEN);
        while (read(remote_socket, buffer, MAX_LEN) > 0)
        {
            // Forward the response to the client, oh victorious warrior!
            if (write(new_socket, buffer, strlen(buffer)) < 0)
            {
                perror("Failed to send response to client");
                close(new_socket);
                close(remote_socket);
                break;
            }
            memset(buffer, 0, MAX_LEN);
        }

        // Close the sockets, all ye gentlefolk!
        close(new_socket);
        close(remote_socket);
    }
    // Fare thee well, oh noble adventurer!
    return 0;
}