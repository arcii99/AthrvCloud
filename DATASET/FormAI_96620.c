//FormAI DATASET v1.0 Category: Client Server Application ; Style: Romeo and Juliet
// Romeo and Juliet Chat Application
// Server Side

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8888

int create_socket()
{
    int server_fd;
    struct sockaddr_in address;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket failed.");
        exit(EXIT_FAILURE);
    }

    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
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

    if (listen(server_fd, 5) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);
    return server_fd;
}

int main(int argc, char const *argv[])
{
    int server_fd = create_socket();

    int client_fd;
    struct sockaddr_in client_address;
    int client_address_len = sizeof(client_address);
    char buffer[1024] = "";

    if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t *)&client_address_len)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("A client has connected!\n");

    // Conversation starts
    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        int val_read = read(client_fd, buffer, 1024);

        // When client exits the program
        if (val_read == 0)
        {
            printf("Client has disconnected.\n");
            break;
        }

        printf("ROMEO: %s\n", buffer);

        // When Romeo accidentally types "I am sorry"
        if (strcmp(buffer, "I am sorry") == 0)
        {
            write(client_fd, "ROMEO: Oh my Juliet, please forgive me.\n", strlen("ROMEO: Oh my Juliet, please forgive me.\n"));
        }
        else
        {
            printf("Enter your message, my Juliet: ");
            fgets(buffer, 1024, stdin);
            printf("Sending [%s] to the client...\n", buffer);
            write(client_fd, buffer, strlen(buffer));
        }
    }

    close(server_fd);
    return EXIT_SUCCESS;
}