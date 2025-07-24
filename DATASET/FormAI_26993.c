//FormAI DATASET v1.0 Category: Networking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void error_handling(char *message)
{
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int address_len = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        error_handling("socket failed");

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1)
        error_handling("setsockopt failed");

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Attaching socket to the address provided
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == -1)
        error_handling("bind failed");

    // Listening to incoming request
    if (listen(server_fd, 5) == -1)
        error_handling("listen failed");

    printf("Server is listening on port %d\n", PORT);

    // Accepting incoming request
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&address_len)) == -1)
        error_handling("accept failed");

    printf("Connected client IP: %s\n", inet_ntoa(address.sin_addr));

    while (1)
    {
        memset(buffer, 0, BUFFER_SIZE);

        int read_size = read(new_socket, buffer, BUFFER_SIZE);

        if (read_size == 0) // client disconnected
        {
            printf("Client disconnected\n");
            break;
        }
        else if (read_size == -1)
        {
            error_handling("read failed");
        }
        else
        {
            printf("Message received: %s\n", buffer);
            strcat(buffer, " OK");
            int write_size = write(new_socket, buffer, strlen(buffer));
            if (write_size == -1)
            {
                error_handling("write failed");
            }
            printf("Message sent: %s\n", buffer);
        }
    }

    close(new_socket);
    close(server_fd);

    return 0;
}