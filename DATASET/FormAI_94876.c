//FormAI DATASET v1.0 Category: Client Server Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8888
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main()
{
    printf("Welcome to the Happy Chat Server!\n");

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    char buffer[BUFFER_SIZE] = {0};
    char *happy_message = "Congrats! You joined the Happy Chat Server!";

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt error");
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

    if (listen(server_fd, MAX_CLIENTS) < 0)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Happy Chat Server is running and listening to port %d\n", PORT);

    while (1)
    {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            perror("accept error");
            exit(EXIT_FAILURE);
        }

        printf("New client connected with IP address: %s and port number: %d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        send(new_socket, happy_message, strlen(happy_message), 0);
        
        char happy_input[BUFFER_SIZE] = {0};
        while ((valread = read(new_socket, buffer, BUFFER_SIZE)) > 0)
        {
            if (strcmp(buffer, "exit\n") == 0)
                break;

            printf("Received message from client %s: %s\n", inet_ntoa(address.sin_addr), buffer);

            printf("Enter your happy message to client %s: ", inet_ntoa(address.sin_addr));

            fgets(happy_input, BUFFER_SIZE, stdin);

            send(new_socket, happy_input, strlen(happy_input), 0);
        }

        close(new_socket);
        printf("Client %s disconnected\n", inet_ntoa(address.sin_addr));
    }

    return 0;
}