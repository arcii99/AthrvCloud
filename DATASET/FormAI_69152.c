//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: enthusiastic
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

// function to handle client connections
void handle_client(int client_socket)
{
    printf("Handling client connection.\n");

    char message[256];
    ssize_t byte_count = recv(client_socket, message, sizeof(message), 0);

    if (byte_count > 0)
    {
        printf("Received message from client: %s\n", message);
        send(client_socket, "Message received by the server!", 32, 0);
    }

    // close the socket
    close(client_socket);
}

int main()
{
    // create TCP socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1)
    {
        printf("Error creating server socket.\n");
        return -1;
    }

    // bind socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1)
    {
        printf("Error binding server socket.\n");
        close(server_socket);
        return -1;
    }

    // listen for incoming connections
    if (listen(server_socket, 10) == -1)
    {
        printf("Error listening for incoming connections.\n");
        close(server_socket);
        return -1;
    }

    printf("Server is listening on port %d.\n", ntohs(server_address.sin_port));

    // loop indefinitely to handle incoming connections
    while (1)
    {
        // accept new connection
        struct sockaddr_in client_address;
        int client_socket = accept(server_socket, (struct sockaddr*)&client_address, (socklen_t*)&client_address);

        if (client_socket == -1)
        {
            printf("Error accepting incoming connection.\n");
            continue;
        }

        // handle client connection
        handle_client(client_socket);
    }

    // close the server socket
    close(server_socket);
    return 0;
}