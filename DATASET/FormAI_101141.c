//FormAI DATASET v1.0 Category: Chat server ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#define PORT 8080

// Function declarations
int create_socket();
void bind_socket(int server_fd, struct sockaddr_in address);
void listen_for_clients(int server_fd);
void handle_client(int client_fd);

int main()
{
    // Create socket
    int server_fd = create_socket();

    // Bind socket
    struct sockaddr_in address;
    bind_socket(server_fd, address);

    // Listen for clients
    listen_for_clients(server_fd);

    return 0;
}

int create_socket()
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd == -1) {
        printf("Error creating socket\n");
        exit(0);
    }

    printf("Socket created successfully\n");

    return server_fd;
}

void bind_socket(int server_fd, struct sockaddr_in address)
{
    memset(&address, 0, sizeof(address));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    int bind_result = bind(server_fd, (struct sockaddr*)&address, sizeof(address));

    if (bind_result < 0) {
        printf("Could not bind to port %d\n", PORT);
        exit(0);
    }

    printf("Bind successful\n");
}

void listen_for_clients(int server_fd)
{
    if (listen(server_fd, 5) < 0) {
        printf("Error listening for clients\n");
        exit(0);
    }

    printf("Server listening on port %d\n", PORT);

    // Accept clients
    int client_fd;
    struct sockaddr_in client_address;
    socklen_t client_size = sizeof(client_address);

    while ((client_fd = accept(server_fd, (struct sockaddr*)&client_address, &client_size))) {
        printf("New client connected\n");

        pid_t pid = fork();

        if (pid == 0) {
            // Child process
            handle_client(client_fd);
            exit(0);
        }
    }
}

void handle_client(int client_fd)
{
    char message[256];
    int read_result;

    while ((read_result = read(client_fd, message, sizeof(message))) > 0) {
        // Decrypt message
        for (int i = 0; i < strlen(message); i++) {
            message[i] = ~message[i];
        }

        // Echo message back to client
        write(client_fd, message, strlen(message));
    }

    if (read_result == 0) {
        printf("Client disconnected\n");
    }
    else {
        printf("Error reading from client\n");
    }

    close(client_fd);
}