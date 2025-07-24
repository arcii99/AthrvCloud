//FormAI DATASET v1.0 Category: Socket programming ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Defined constants
#define PORT 8080
#define MAX_CONNECTIONS 3
#define MAX_BUFFER_SIZE 1024
#define SECRET_KEY "my_secret_key"

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully binding socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CONNECTIONS) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Start of paranoid logic
    if (getuid() != geteuid() || getgid() != getegid() || getuid() != 0)
    {
        fprintf(stderr, "ERROR: Don't run this program as root or with setuid/setgid bits set!\n");
        exit(EXIT_FAILURE);
    }

    char key_check_cmd[1024] = {0};
    sprintf(key_check_cmd, "grep \"%s\" /etc/shadow", SECRET_KEY);
    FILE *filePtr = popen(key_check_cmd, "r");
    if (filePtr == NULL)
    {
        perror("popen failed");
        exit(EXIT_FAILURE);
    }

    char fileOutput[1024] = {0};
    int i = 0;
    while (fgets(fileOutput, 1024, filePtr) != NULL)
    {
        i++;
        if (i > 1)
        {
            fprintf(stderr, "WARNING: Multiple users found with the secret key in their password hashes!\n");
            break;
        }
    }

    if (i == 0)
    {
        fprintf(stderr, "ERROR: No user found with the secret key in their password hash!\n");
        exit(EXIT_FAILURE);
    }

    pclose(filePtr);

    // If all checks passed, start accepting connections.
    while (1)
    {
        printf("Waiting for connections...\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New connection.\n");

        valread = read(new_socket, buffer, MAX_BUFFER_SIZE);
        printf("%s\n", buffer);
        send(new_socket, buffer, strlen(buffer), 0);
        printf("Message sent.\n");
        memset(buffer, 0, MAX_BUFFER_SIZE);
        close(new_socket);
    }

    return 0;
}