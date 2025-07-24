//FormAI DATASET v1.0 Category: System administration ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 8080

void handle_error(const char* error_message) {
    perror(error_message);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    int server_fd;
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        handle_error("Failed to create socket");
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*) &address, sizeof(address)) == -1) {
        handle_error("Failed to bind socket");
    }

    if (listen(server_fd, 10) == -1) {
        handle_error("Failed to listen on socket");
    }

    while (1) {
        struct sockaddr_in client_address;
        int addrlen = sizeof(client_address);
        int client_fd;
        if ((client_fd = accept(server_fd, (struct sockaddr*) &client_address, (socklen_t*) &addrlen)) == -1) {
            handle_error("Failed to accept incoming connection");
        }
        printf("Incoming connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        char buffer[BUFFER_SIZE] = {0};
        ssize_t num_bytes_received;

        if ((num_bytes_received = read(client_fd, buffer, BUFFER_SIZE)) == -1) {
            handle_error("Failed to read from socket");
        }

        if (num_bytes_received == 0) {
            printf("Client closed connection\n");
            continue;
        }

        buffer[num_bytes_received] = '\0';

        printf("Received command: %s", buffer);

        int stdout_fd[2];
        int stderr_fd[2];
        pid_t pid;

        if (pipe(stdout_fd) == -1 || pipe(stderr_fd) == -1) {
            handle_error("Failed to create pipe");
        }

        if ((pid = fork()) == -1) {
            handle_error("Failed to fork");
        }

        if (pid == 0) {
            dup2(stdout_fd[1], STDOUT_FILENO);
            dup2(stderr_fd[1], STDERR_FILENO);

            close(stdout_fd[0]);
            close(stdout_fd[1]);
            close(stderr_fd[0]);
            close(stderr_fd[1]);

            char* cmd_args[6];
            cmd_args[0] = "/bin/bash";
            cmd_args[1] = "-c";
            cmd_args[2] = buffer;
            cmd_args[3] = NULL;

            if (execvp(cmd_args[0], cmd_args) == -1) {
                handle_error("Failed to execute command");
            }
        } else {
            close(stdout_fd[1]);
            close(stderr_fd[1]);

            char stdout_buffer[BUFFER_SIZE] = {0};
            char stderr_buffer[BUFFER_SIZE] = {0};

            ssize_t num_bytes_read_stdout;
            ssize_t num_bytes_read_stderr;

            while ((num_bytes_read_stdout = read(stdout_fd[0], stdout_buffer, BUFFER_SIZE)) != 0) {
                if (num_bytes_read_stdout == -1 && errno != EAGAIN) {
                    handle_error("Failed to read from stdout");
                } else if (num_bytes_read_stdout > 0) {
                    if (write(client_fd, stdout_buffer, num_bytes_read_stdout) == -1) {
                        handle_error("Failed to write to socket");
                    }
                    printf("%s", stdout_buffer);
                    fflush(stdout);
                }
            }

            while ((num_bytes_read_stderr = read(stderr_fd[0], stderr_buffer, BUFFER_SIZE)) != 0) {
                if (num_bytes_read_stderr == -1 && errno != EAGAIN) {
                    handle_error("Failed to read from stderr");
                } else if (num_bytes_read_stderr > 0) {
                    if (write(client_fd, stderr_buffer, num_bytes_read_stderr) == -1) {
                        handle_error("Failed to write to socket");
                    }
                    fprintf(stderr, "%s", stderr_buffer);
                    fflush(stderr);
                }
            }

            close(stdout_fd[0]);
            close(stderr_fd[0]);
            close(client_fd);
        }
    }

    close(server_fd);

    return 0;
}