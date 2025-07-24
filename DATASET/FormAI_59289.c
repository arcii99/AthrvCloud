//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>

#define DEFAULT_QOS "BEST_EFFORT"
#define MAX_QOS_OPTIONS 3

char* qos_options[MAX_QOS_OPTIONS] = {"BEST_EFFORT", "LOW_LATENCY", "HIGH_THROUGHPUT"};

void print_qos_options() {
    int i;
    printf("Available QoS options:\n");
    for(i=0; i<MAX_QOS_OPTIONS; i++) {
        printf("%s\n", qos_options[i]);
    }
}

void monitor_network_qos(int socket_fd, char* qos) {
    int rc = setsockopt(socket_fd, IPPROTO_IP, IP_TOS, qos, sizeof(qos));
    if (rc < 0) {
        printf("Error setting socket option %s: %s\n", qos, strerror(errno));
        exit(1);
    }

    //TODO: Ping a remote server and measure response time, jitter and packet loss

    //TODO: Gather other network statistics here

    printf("Network QoS set to %s\n", qos);
}

int main(int argc, char *argv[]) {
    //parse command line arguments
    char* qos = DEFAULT_QOS; //default value
    int c;
    while ((c = getopt (argc, argv, "q:")) != -1) {
        switch (c) {
            case 'q':
                qos = optarg;
                break;
            default:
                printf("Invalid argument %c. Valid arguments are -q [QOS_OPTION]\n", c);
                print_qos_options();
                return 1;
        }
    }

    //check if the selected QoS option is valid
    int valid_qos = 0;
    int i;
    for(i=0; i<MAX_QOS_OPTIONS; i++) {
        if(strcmp(qos, qos_options[i])==0) {
            valid_qos = 1;
            break;
        }
    }
    if(!valid_qos) {
        printf("Invalid QoS option %s. Valid options are:\n", qos);
        print_qos_options();
        return 1;
    }

    //create a socket
    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd < 0) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    //set up the server address
    struct sockaddr_in server_addr;
    socklen_t server_len = sizeof(server_addr);
    memset(&server_addr, 0, server_len);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(9000);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    //monitor the network QoS
    monitor_network_qos(socket_fd, qos);

    //clean up
    close(socket_fd);
    return 0;
}