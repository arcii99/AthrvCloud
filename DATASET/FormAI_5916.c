//FormAI DATASET v1.0 Category: Modern Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/sendfile.h>
#include <sys/wait.h>
#include <signal.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void encryption(char *filename);
void decryption(char *filename);

int main(int argc, char *argv[])
{
    int sockfd, new_sockfd;
    struct sockaddr_in server_addr;
    struct sockaddr_storage server_storage;
    socklen_t addr_size;
    char buffer[BUFFER_SIZE];
    pid_t pid;

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    // address structure
    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // bind socket
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Unable to bind socket");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(sockfd, 5) == 0)
        printf("Server is listening at port %d\n", PORT);
    else
    {
        perror("Unable to listen");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        // accept incoming connection
        addr_size = sizeof(server_storage);
        new_sockfd = accept(sockfd, (struct sockaddr*)&server_storage, &addr_size);

        if ((pid = fork()) == 0)
        {
            close(sockfd);

            while (1)
            {
                memset(buffer, '\0', BUFFER_SIZE);

                // receive request from client
                if (recv(new_sockfd, buffer, BUFFER_SIZE, 0) == 0)
                    break;

                printf("Received request: %s\n", buffer);

                // process request
                if (strcmp(buffer, "encrypt") == 0)
                    encryption(argv[1]);
                else if (strcmp(buffer, "decrypt") == 0)
                    decryption(argv[1]);
                else if (strcmp(buffer, "exit") == 0)
                    break;
                else
                    printf("Invalid request\n");

                // send response to client
                if (send(new_sockfd, buffer, strlen(buffer), 0) == -1)
                {
                    perror("Unable to send response");
                    exit(EXIT_FAILURE);
                }
            }

            close(new_sockfd);
            exit(EXIT_SUCCESS);
        }

        close(new_sockfd);
        signal(SIGCHLD, SIG_IGN);
    }

    close(sockfd);

    return 0;
}

void encryption(char *filename)
{
    int input_fd, output_fd, key_fd;
    char *key_filename = "key.txt";
    unsigned char key[BUFFER_SIZE], buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written, key_size;
    struct stat st;

    // open input file
    if ((input_fd = open(filename, O_RDONLY)) == -1)
    {
        perror("Unable to open input file");
        exit(EXIT_FAILURE);
    }

    // create output file
    if ((output_fd = open("encrypted.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
    {
        perror("Unable to create output file");
        exit(EXIT_FAILURE);
    }

    // open key file
    if ((key_fd = open(key_filename, O_RDONLY)) == -1)
    {
        perror("Unable to open key file");
        exit(EXIT_FAILURE);
    }

    // read key
    if ((key_size = read(key_fd, key, BUFFER_SIZE)) == -1)
    {
        perror("Unable to read key file");
        exit(EXIT_FAILURE);
    }

    // encrypt file
    while ((bytes_read = read(input_fd, buffer, BUFFER_SIZE)) > 0)
    {
        for (ssize_t i = 0; i < bytes_read; i++)
        {
            buffer[i] ^= key[i % key_size];
        }

        if ((bytes_written = write(output_fd, buffer, bytes_read)) == -1)
        {
            perror("Unable to write to output file");
            exit(EXIT_FAILURE);
        }
    }

    // close files
    close(input_fd);
    close(output_fd);
    close(key_fd);

    printf("File encrypted successfully\n");
}

void decryption(char *filename)
{
    int input_fd, output_fd, key_fd;
    char *key_filename = "key.txt";
    unsigned char key[BUFFER_SIZE], buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written, key_size;
    struct stat st;

    // open input file
    if ((input_fd = open(filename, O_RDONLY)) == -1)
    {
        perror("Unable to open input file");
        exit(EXIT_FAILURE);
    }

    // create output file
    if ((output_fd = open("decrypted.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
    {
        perror("Unable to create output file");
        exit(EXIT_FAILURE);
    }

    // open key file
    if ((key_fd = open(key_filename, O_RDONLY)) == -1)
    {
        perror("Unable to open key file");
        exit(EXIT_FAILURE);
    }

    // read key
    if ((key_size = read(key_fd, key, BUFFER_SIZE)) == -1)
    {
        perror("Unable to read key file");
        exit(EXIT_FAILURE);
    }

    // decrypt file
    while ((bytes_read = read(input_fd, buffer, BUFFER_SIZE)) > 0)
    {
        for (ssize_t i = 0; i < bytes_read; i++)
        {
            buffer[i] ^= key[i % key_size];
        }

        if ((bytes_written = write(output_fd, buffer, bytes_read)) == -1)
        {
            perror("Unable to write to output file");
            exit(EXIT_FAILURE);
        }
    }

    // close files
    close(input_fd);
    close(output_fd);
    close(key_fd);

    printf("File decrypted successfully\n");
}