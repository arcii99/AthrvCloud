//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define PORT_NUM 80

void usage(char *prog_name) {
    printf("Usage: %s [-h] <hostname>\n", prog_name);
    printf("  -h: print this help message\n");
    printf("  <hostname>: the hostname to check\n");
}

int connect_to_host(char *host_name) {
    int client_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (client_socket == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct hostent *host_info = gethostbyname(host_name);
    if (host_info == NULL) {
        fprintf(stderr, "Error getting hostname info: %s\n", strerror(h_errno));
        exit(1);
    }

    struct sockaddr_in target_addr;
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr = *(struct in_addr *) host_info->h_addr;
    target_addr.sin_port = htons(PORT_NUM);

    if (connect(client_socket, (struct sockaddr *) &target_addr, sizeof(target_addr)) == -1) {
        fprintf(stderr, "Error connecting to host: %s\n", strerror(errno));
        exit(1);
    }

    return client_socket;
}

int get_signal_strength(int client_socket) {
    int signal_strength = 0;

    char request[100];
    sprintf(request, "GET / HTTP/1.1\r\nHOST: example.com\r\n\r\n");
    send(client_socket, request, strlen(request), 0);

    char response[1000];
    if (recv(client_socket, response, 1000, 0) == -1) {
        fprintf(stderr, "Error receiving response from host: %s\n", strerror(errno));
        exit(1);
    }

    char *signal_strength_str = strstr(response, "signal_strength:");
    if (signal_strength_str != NULL) {
        signal_strength_str += strlen("signal_strength:");
        signal_strength = atoi(signal_strength_str);
    }

    return signal_strength;
}

int main(int argc, char *argv[]) {
    char *host_name = NULL;
    int opt;

    while ((opt = getopt(argc, argv, "h:")) != -1) {
        switch (opt) {
            case 'h':
                usage(argv[0]);
                return 0;
            default:
                usage(argv[0]);
                exit(1);
        }
    }

    if (optind < argc) {
        host_name = argv[optind++];
    } else {
        fprintf(stderr, "Error: host name not specified\n");
        usage(argv[0]);
        exit(1);
    }

    int client_socket = connect_to_host(host_name);
    int signal_strength = get_signal_strength(client_socket);

    printf("Signal strength for %s: %d\n", host_name, signal_strength);

    close(client_socket);

    return 0;
}