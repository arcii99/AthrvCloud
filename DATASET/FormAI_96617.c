//FormAI DATASET v1.0 Category: Chat server ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT_NUMBER 5500
#define BUFFER_SIZE 1024

int main()
{
    int sockfd, client_sockfd, opt = 1;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);
    char buffer[BUFFER_SIZE];

    // create socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // set socket options for reuse of port
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // initialize server addrress
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT_NUMBER);

    // bind socket to the specified port
    if (bind(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(sockfd, 5) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started listening on port %d\n", PORT_NUMBER);

    // accept client connections and handle data
    while(1)
    {
        if ((client_sockfd = accept(sockfd, (struct sockaddr*)&client_address, &client_address_length)) < 0)
        {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // handle client data
        while(1)
        {
            memset(buffer, 0, BUFFER_SIZE);

            // read client data
            if (read(client_sockfd, buffer, BUFFER_SIZE) < 0)
            {
                perror("Read failed");
                exit(EXIT_FAILURE);
            }

            printf("<%s:%d> %s", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), buffer);

            // write response data to client
            if (write(client_sockfd, buffer, strlen(buffer)) < 0)
            {
                perror("Write failed");
                exit(EXIT_FAILURE);
            }
        }

        close(client_sockfd);
    }

    close(sockfd);

    return 0;
}