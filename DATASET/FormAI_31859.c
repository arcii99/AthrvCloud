//FormAI DATASET v1.0 Category: Simple Web Server ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <stdbool.h>
#include <errno.h>
#include <signal.h>
#include <ctype.h>

#define BUF_SIZE 1024
#define SERVER_PORT 8080

volatile sig_atomic_t g_interrupted = 0;

typedef struct {
    int fd;
    bool closed;
    char* buffer;
    size_t buffer_size;
    size_t buffer_len;
    char* data;
    size_t data_size;
    size_t data_len;
    char* file_path;
} connection_t;

void interrupt_handler(int signo) {
    g_interrupted = signo;
}

void initialize_listen_socket(int* listen_socket, struct sockaddr_in* address) {
    *listen_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (*listen_socket < 0) {
        perror("Failed to create listen socket");
        exit(EXIT_FAILURE);
    }

    int opt_val = 1;
    if (setsockopt(*listen_socket, SOL_SOCKET, SO_REUSEADDR, &opt_val, sizeof(opt_val)) < 0) {
        perror("Failed to set socket options");
        exit(EXIT_FAILURE);
    }

    memset(address, 0, sizeof(*address));
    address->sin_family = AF_INET;
    address->sin_addr.s_addr = INADDR_ANY;
    address->sin_port = htons(SERVER_PORT);

    if (bind(*listen_socket, (struct sockaddr*)address, sizeof(*address)) < 0) {
        perror("Failed to bind listen socket");
        exit(EXIT_FAILURE);
    }

    if (listen(*listen_socket, SOMAXCONN) < 0) {
        perror("Failed to listen on listen socket");
        exit(EXIT_FAILURE);
    }
}

connection_t* create_connection(int fd) {
    connection_t* connection = malloc(sizeof(connection_t));
    connection->fd = fd;
    connection->closed = false;
    connection->buffer_size = BUF_SIZE;
    connection->buffer_len = 0;
    connection->buffer = malloc(connection->buffer_size);
    connection->data_size = 0;
    connection->data_len = 0;
    connection->data = NULL;
    connection->file_path = NULL;
    return connection;
}

void close_connection(connection_t* connection) {
    close(connection->fd);
    free(connection->buffer);
    free(connection->data);
    free(connection->file_path);
    connection->closed = true;
}

int handle_receive(connection_t* connection) {
    int read_count = read(connection->fd, connection->buffer + connection->buffer_len, connection->buffer_size - connection->buffer_len - 1);
    if (read_count < 0) {
        if (errno != EWOULDBLOCK && errno != EAGAIN) {
            perror("Failed to read from connection");
            close_connection(connection);
            return -1;
        }
    } else if (read_count == 0) {
        close_connection(connection);
        return -1;
    } else {
        connection->buffer_len += read_count;
        connection->buffer[connection->buffer_len] = '\0';

        char* end_of_header = strstr(connection->buffer, "\r\n\r\n");
        if (end_of_header) {
            size_t header_len = end_of_header - connection->buffer + 4;
            size_t data_len = connection->buffer_len - header_len;
            connection->data_size = data_len;
            connection->data = malloc(data_len);
            memmove(connection->data, connection->buffer + header_len, data_len);
            connection->data_len = data_len;
            connection->buffer_len = header_len;
            connection->buffer[connection->buffer_len] = '\0';

            char* end_of_path = strchr(connection->buffer, ' ');
            if (end_of_path) {
                end_of_path++;
                char* end_of_path2 = strchr(end_of_path, ' ');
                if (end_of_path2) {
                    *end_of_path2 = '\0';
                    connection->file_path = strdup(end_of_path);
                }
            }
        }
    }

    return 0;
}

int handle_send(connection_t* connection) {
    int write_count = write(connection->fd, connection->data + connection->data_len, connection->data_size - connection->data_len);
    if (write_count < 0) {
        if (errno != EWOULDBLOCK && errno != EAGAIN) {
            perror("Failed to write to connection");
            close_connection(connection);
            return -1;
        }
    } else {
        connection->data_len += write_count;
        if (connection->data_len == connection->data_size) {
            close_connection(connection);
            return 1;
        }
    }

    return 0;
}

int handle_request(connection_t* connection) {
    if (!connection->file_path) {
        connection->file_path = strdup("/index.html");
    }

    int fd = open(connection->file_path + 1, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open file");
        return -1;
    }

    char buf[BUF_SIZE];
    int data_len = 0;
    int read_count;

    while ((read_count = read(fd, buf, BUF_SIZE)) > 0) {
        if (handle_send(connection) < 0) {
            perror("Failed to send response");
            return -1;
        }
    }

    close(fd);

    return 0;
}

void run_server(int listen_socket) {
    struct sockaddr_in address;
    socklen_t address_len = sizeof(address);

    int flags = fcntl(listen_socket, F_GETFL, 0);
    fcntl(listen_socket, F_SETFL, flags | O_NONBLOCK);

    fd_set read_fds;
    fd_set write_fds;
    FD_ZERO(&read_fds);
    FD_ZERO(&write_fds);
    FD_SET(listen_socket, &read_fds);

    int max_fd = listen_socket;

    while (!g_interrupted) {
        fd_set read_fds_copy = read_fds;
        fd_set write_fds_copy = write_fds;

        int select_result = select(max_fd + 1, &read_fds_copy, &write_fds_copy, NULL, NULL);
        if (select_result < 0) {
            if (errno == EINTR) {
                continue;
            }
            perror("Failed to select");
            exit(EXIT_FAILURE);
        }

        for (int fd = 0; fd <= max_fd; ++fd) {
            if (FD_ISSET(fd, &read_fds_copy)) {
                if (fd == listen_socket) {
                    int client_socket = accept(listen_socket, (struct sockaddr*)&address, &address_len);
                    if (client_socket < 0) {
                        perror("Failed to accept connection");
                        continue;
                    }

                    connection_t* connection = create_connection(client_socket);
                    FD_SET(client_socket, &read_fds);
                    if (client_socket > max_fd) {
                        max_fd = client_socket;
                    }
                } else {
                    connection_t* connection = (connection_t*)fd;
                    if (handle_receive(connection) < 0) {
                        FD_CLR(fd, &read_fds);
                    }
                }
            }

            if (FD_ISSET(fd, &write_fds_copy)) {
                connection_t* connection = (connection_t*)fd;
                if (handle_request(connection) < 0) {
                    FD_CLR(fd, &write_fds);
                }
            }
        }

        for (int fd = 0; fd <= max_fd; ++fd) {
            connection_t* connection = (connection_t*)fd;
            if (!connection) {
                continue;
            }

            if (!connection->closed && connection->data_size && connection->data_len < connection->data_size) {
                FD_SET(fd, &write_fds);
            } else {
                FD_CLR(fd, &write_fds);
            }

            if (connection->closed || (connection->data_size && connection->data_len == connection->data_size)) {
                FD_CLR(fd, &read_fds);
                close_connection(connection);
                free(connection);
            }
        }
    }
}

int main() {
    struct sigaction sig_int_handler;
    sig_int_handler.sa_handler = interrupt_handler;
    sigemptyset(&sig_int_handler.sa_mask);
    sig_int_handler.sa_flags = 0;

    if (sigaction(SIGINT, &sig_int_handler, NULL) < 0) {
        perror("Failed to set up signal handler");
        return EXIT_FAILURE;
    }

    int listen_socket;
    struct sockaddr_in address;
    initialize_listen_socket(&listen_socket, &address);
    run_server(listen_socket);

    return EXIT_SUCCESS;
}