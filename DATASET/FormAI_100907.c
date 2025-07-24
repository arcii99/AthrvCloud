//FormAI DATASET v1.0 Category: Port Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>

#define PORT_LOWER_LIMIT 1
#define PORT_UPPER_LIMIT 65535

#define MAX_TIMEOUTS 3
#define TIMEOUT_INTERVAL 1

typedef struct {
    unsigned short int port_number;
    bool is_open;
} port_info;

void print_usage(char* program_name) {
    printf("Usage: %s IP_ADDRESS\n", program_name);
    printf("  IP_ADDRESS: the IP address to scan for open ports\n");
}

int create_socket() {
    int sd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sd == -1) {
        fprintf(stderr, "Failed to create socket. Error: %s\n", strerror(errno));
    }

    return sd;
}

void set_socket_non_blocking(int sd) {
    int flags = fcntl(sd, F_GETFL, 0);
    fcntl(sd, F_SETFL, flags | O_NONBLOCK);
}

bool connect_socket(int sd, struct sockaddr_in* addr) {
    int status = connect(sd, (struct sockaddr*) addr, sizeof(*addr));
    if (status == 0) {
        return true;
    } else if (errno == EINPROGRESS || errno == EAGAIN) {
        fd_set fdset;
        struct timeval timeout;
        FD_ZERO(&fdset);
        FD_SET(sd, &fdset);
        timeout.tv_sec = TIMEOUT_INTERVAL;
        timeout.tv_usec = 0;
        int result = select(sd+1, NULL, &fdset, NULL, &timeout);
        if (result > 0) {
            int error;
            socklen_t error_len = sizeof(error);
            getsockopt(sd, SOL_SOCKET, SO_ERROR, &error, &error_len);
            if (error == 0) {
                return true;
            }
        }
    }

    return false;
}

void scan_ports(const char* ip_address, port_info* ports, int num_ports) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);

    for (int i = 0; i < num_ports; i++) {
        int sd = create_socket();
        set_socket_non_blocking(sd);
        addr.sin_port = htons(ports[i].port_number);

        bool result = connect_socket(sd, &addr);
        if (result) {
            ports[i].is_open = true;
        }

        close(sd);
    }
}

void print_open_ports(port_info* ports, int num_ports) {
    printf("Open ports: ");
    bool first = true;
    for (int i = 0; i < num_ports; i++) {
        if (ports[i].is_open) {
            if (!first) {
                printf(", ");
            }

            printf("%d", ports[i].port_number);
            first = false;
        }
    }

    printf("\n");
}

bool is_valid_port(unsigned short int port) {
    return port >= PORT_LOWER_LIMIT && port <= PORT_UPPER_LIMIT;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 0;
    }

    char* ip_address = argv[1];
    if (inet_addr(ip_address) == INADDR_NONE) {
        printf("Invalid IP address: %s\n", ip_address);
        return 0;
    }

    int num_ports = PORT_UPPER_LIMIT - PORT_LOWER_LIMIT + 1;
    port_info* ports = calloc(num_ports, sizeof(port_info));
    if (ports == NULL) {
        fprintf(stderr, "Failed to allocate memory for port_info array.");
        return 1;
    }

    int index = 0;
    for (unsigned short int i = PORT_LOWER_LIMIT; i <= PORT_UPPER_LIMIT; i++) {
        ports[index].port_number = i;
        ports[index].is_open = false;
        index++;
    }

    scan_ports(ip_address, ports, num_ports);

    print_open_ports(ports, num_ports);

    free(ports);

    return 0;
}