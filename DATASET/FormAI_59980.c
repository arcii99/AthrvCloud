//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <errno.h>
#include <sys/types.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <net/if.h>
#include <linux/sockios.h>
#include <linux/types.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFSIZE 1024
#define PORT 80                   // the port to listen on
#define MAX_CONNECTIONS 10        // maximum number of concurrent connections allowed
#define MAX_PENDING_DATA 102400   // maximum amount of data pending to be read/write
#define DELAY_THRESHOLD 100       // delay threshold in milliseconds for QoS monitoring

int num_connections = 0;          // number of active connections
int server_fd;                    // the server's socket FD

// structure to track connection information
struct connection {
    int fd;                       // socket FD for this connection
    struct timeval last_read;    // last time data was read from this connection
    unsigned long total_data_read; // total amount of data read from this connection
    unsigned long total_data_written; // total amount of data written to this connection
};

// forward declaration
void handle_new_connection();
void handle_incoming_data(struct connection *conn);
void handle_connection_closure(struct connection *conn);

// function to get current timestamp in milliseconds
unsigned long get_current_timestamp() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

int main(int argc, char *argv[]) {
    // create the server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    // bind to the port
    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(server_fd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding to port");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    // set the server socket to non-blocking mode
    int flags = fcntl(server_fd, F_GETFL, 0);
    if (flags == -1) {
        perror("Error getting socket flags");
        exit(EXIT_FAILURE);
    }
    if (fcntl(server_fd, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("Error setting socket flags");
        exit(EXIT_FAILURE);
    }

    // initialize the connections array
    struct connection connections[MAX_CONNECTIONS] = {{0}};
    fd_set read_fds;
    int max_fd = server_fd;

    // loop forever, handling incoming connections, data, and closures
    while (1) {
        // initialize the read file descriptor set
        FD_ZERO(&read_fds);
        FD_SET(server_fd, &read_fds);

        // add the active connection file descriptors to the read set
        for (int i = 0; i < MAX_CONNECTIONS; i++) {
            if (connections[i].fd != 0) {
                FD_SET(connections[i].fd, &read_fds);
                if (connections[i].fd > max_fd) {
                    max_fd = connections[i].fd;
                }
            }
        }

        // wait for incoming data or connections
        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) < 0) {
            if (errno == EINTR) {
                continue;
            }
            perror("Error in select");
            exit(EXIT_FAILURE);
        }

        // check for new connections
        if (FD_ISSET(server_fd, &read_fds)) {
            handle_new_connection(connections, &max_fd);
        }

        // handle incoming data for each active connection
        for (int i = 0; i < MAX_CONNECTIONS; i++) {
            if (connections[i].fd != 0 && FD_ISSET(connections[i].fd, &read_fds)) {
                handle_incoming_data(&connections[i]);
            }
        }

        // handle closure of any active connections
        for (int i = 0; i < MAX_CONNECTIONS; i++) {
            if (connections[i].fd != 0 && connections[i].total_data_read == connections[i].total_data_written) {
                handle_connection_closure(&connections[i]);
            }
        }

        // periodically check for QoS metrics and print them
        static unsigned long last_qos_check = 0;
        unsigned long cur_ts = get_current_timestamp();
        if (cur_ts - last_qos_check > DELAY_THRESHOLD) {
            printf("Current number of connections: %d\n", num_connections);
            unsigned long total_data_read = 0, total_data_written = 0;
            double avg_read_delay = 0, avg_write_delay = 0;
            for (int i = 0; i < MAX_CONNECTIONS; i++) {
                if (connections[i].fd != 0) {
                    total_data_read += connections[i].total_data_read;
                    total_data_written += connections[i].total_data_written;
                    unsigned long read_delay_ms = cur_ts - connections[i].last_read.tv_sec * 1000 - connections[i].last_read.tv_usec / 1000;
                    unsigned long write_delay_ms = cur_ts - connections[i].last_read.tv_sec * 1000 - connections[i].last_read.tv_usec / 1000;
                    if (read_delay_ms > DELAY_THRESHOLD) {
                        avg_read_delay += (double)read_delay_ms / num_connections;
                    }
                    if (write_delay_ms > DELAY_THRESHOLD) {
                        avg_write_delay += (double)write_delay_ms / num_connections;
                    }
                }
            }
            printf("Total data read: %lu\n", total_data_read);
            printf("Total data written: %lu\n", total_data_written);
            printf("Average read delay: %fms\n", avg_read_delay);
            printf("Average write delay: %fms\n", avg_write_delay);
            printf("--------------------------------\n");
            last_qos_check = cur_ts;
        }
    }

    return 0;
}

// function to handle a new incoming connection
void handle_new_connection(struct connection *connections, int *max_fd) {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_fd == -1) {
        if (errno == EWOULDBLOCK || errno == EAGAIN) {
            return;
        }
        perror("Error accepting incoming connection");
        exit(EXIT_FAILURE);
    }

    // check if maximum number of connections has been reached
    if (num_connections == MAX_CONNECTIONS) {
        printf("Maximum number of connections reached, closing incoming connection\n");
        close(client_fd);
        return;
    }

    // set the new client socket to non-blocking mode
    int flags = fcntl(client_fd, F_GETFL, 0);
    if (flags == -1) {
        perror("Error getting socket flags");
        exit(EXIT_FAILURE);
    }
    if (fcntl(client_fd, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("Error setting socket flags");
        exit(EXIT_FAILURE);
    }

    // add the new connection to the active connections array
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        if (connections[i].fd == 0) {
            connections[i].fd = client_fd;
            connections[i].last_read.tv_sec = 0;
            connections[i].last_read.tv_usec = 0;
            connections[i].total_data_read = 0;
            connections[i].total_data_written = 0;
            num_connections++;
            break;
        }
    }

    if (client_fd > *max_fd) {
        *max_fd = client_fd;
    }
}

// function to handle incoming data for an active connection
void handle_incoming_data(struct connection *conn) {
    char buf[BUFSIZE];
    ssize_t n = recv(conn->fd, buf, BUFSIZE, 0);
    if (n == -1) {
        if (errno == EWOULDBLOCK || errno == EAGAIN) {
            return;
        }
        perror("Error receiving data from client");
        exit(EXIT_FAILURE);
    }

    if (n == 0) {
        conn->total_data_read = conn->total_data_written;
        return;
    }

    conn->last_read = (struct timeval) {0};
    gettimeofday(&conn->last_read, NULL);
    conn->total_data_read += n;

    // process the incoming data here if needed
}

// function to handle closure of an active connection
void handle_connection_closure(struct connection *conn) {
    close(conn->fd);
    conn->fd = 0;
    num_connections--;
}