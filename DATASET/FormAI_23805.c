//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <string.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *hello = "Hello from server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the specific IP address and port number
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen to the clients
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept the incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Get the current time
    time_t now;
    char *timestamp;
    while (1)
    {
        now = time(NULL);
        timestamp = ctime(&now);
        memset(buffer, 0, BUFFER_SIZE);
        // Read data from the client
        valread = read(new_socket, buffer, BUFFER_SIZE);
        // Print the received message
        printf("Received message from client: %s\n", buffer);
        if (valread < 0)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }
        else if (valread == 0)
        {
            printf("Client disconnected\n");
            close(new_socket);
            // Accept new incoming connection
            if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
            {
                perror("accept");
                exit(EXIT_FAILURE);
            }
        }
        // Send current timestamp and number of bytes received back to client
        char msg[BUFFER_SIZE];
        sprintf(msg, "Timestamp: %sBytes received: %d", timestamp, valread);
        send(new_socket, msg, strlen(msg), 0);
        // Introduce delay of 1 second
        sleep(1);
    }
    return 0;
}