//FormAI DATASET v1.0 Category: Port Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>

#define MAX_SOCKETS 65535      // Maximum number of sockets to be opened
#define TIMEOUT 200            // Timeout in microseconds
#define BUFFER 2048            // Size of buffer to receive data

// Function to set a socket to non-blocking mode
void set_nonblock(int sockfd) {
    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <host> <start_port> <end_port(optional)>\n", argv[0]);
        return 0;
    }

    char *host = argv[1];          // Hostname or IP address
    int start_port = atoi(argv[2]);  // Starting port
    int end_port;
    if (argc >= 4) {
        end_port = atoi(argv[3]);  // Ending port
    } else {
        end_port = start_port;
    }

    int open_sockets[MAX_SOCKETS];  // Array to store the file descriptors of open sockets
    int found_ports[MAX_SOCKETS];   // Array to store the open ports
    memset(open_sockets, 0, sizeof(open_sockets));   // Filling the array with 0 values
    memset(found_ports, 0, sizeof(found_ports));     // Filling the array with 0 values

    struct addrinfo hints, *res, *p;   // Struct to hold the address information
    char port_string[6];               // String to hold the port number

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;         // IPv4
    hints.ai_socktype = SOCK_STREAM;   // TCP

    int status;
    for (int port = start_port; port <= end_port; ++port) {
        snprintf(port_string, sizeof(port_string), "%d", port);

        if ((status = getaddrinfo(host, port_string, &hints, &res)) != 0) {
            fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
            continue;
        }

        for (p = res; p != NULL; p = p->ai_next) {
            int sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
            if (sockfd == -1) {
                perror("socket");
                continue;
            }

            set_nonblock(sockfd);   // Setting the socket to non-blocking mode

            int error = connect(sockfd, p->ai_addr, p->ai_addrlen);
            if (error == -1 && errno != EINPROGRESS) {    // If error occurred and it is not EINPROGRESS
                perror("connect");
                close(sockfd);
                continue;
            }

            fd_set rset, wset;
            FD_ZERO(&rset);
            FD_SET(sockfd, &rset);
            wset = rset;

            struct timeval tv;
            tv.tv_sec = 0;
            tv.tv_usec = TIMEOUT;

            int ret;
            if ((ret = select(sockfd + 1, &rset, &wset, NULL, &tv)) <= 0) {
                if (ret == 0) {             // If timeout occurred
                    close(sockfd);
                    continue;
                } else if (errno == EINTR) {     // If an interrupt occurred
                    close(sockfd);
                    perror("select");
                    exit(EXIT_FAILURE);
                } else {        // If some other error occurred
                    close(sockfd);
                    perror("select");
                    exit(EXIT_FAILURE);
                }
            }

            int valopt;
            socklen_t lon = sizeof(valopt);

            if (getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &valopt, &lon) < 0) {     // Checking if connection was successful
                perror("getsockopt");
                close(sockfd);
                continue;
            }

            if (valopt) {   // If an error occurred
                close(sockfd);
                continue;
            }

            open_sockets[port] = sockfd;   // Storing the socket in the array
            found_ports[port] = 1;         // Updating the open port array
        }

        freeaddrinfo(res);
    }

    printf("Results:\n");
    for (int i = start_port; i <= end_port; ++i) {
        if (found_ports[i]) {
            printf("%d : open\n", i);
        } else {
            printf("%d : closed\n", i);
        }
        if (open_sockets[i]) {
            close(open_sockets[i]);
        }
    }

    return 0;
}