//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <sys/time.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

#define DEFAULT_PORT 5000
#define DEFAULT_PACKET_SIZE 1024
#define DEFAULT_NUM_PACKETS 1000
#define DEFAULT_DELAY 1000000

struct sockaddr_in _sin;
struct sockaddr_in _bind_address;
struct sockaddr_in _dest_address;
int valid;
int running;
int _socket_fd;
int _num_packets;
int _packet_size;
int _delay;
long _total_bytes_sent;
long _total_bytes_received;
int _verbose;

void print_usage() {
    printf("Usage: qosmonitor [-h] [-v] [-s packet_size] [-n num_packets] [-d delay] [-p port] [-b bind_address] dest_address\n");
    printf("-h \t\t\t: Show this help message and exit\n");
    printf("-v \t\t\t: Verbose mode\n");
    printf("-s packet_size \t\t: Packet size in bytes (default: %d)\n", DEFAULT_PACKET_SIZE);
    printf("-n num_packets \t\t: Number of packets to send (default: %d)\n", DEFAULT_NUM_PACKETS);
    printf("-d delay \t\t: Delay between packets in microseconds (default: %d)\n", DEFAULT_DELAY);
    printf("-p port \t\t: Local port to bind to (default: %d)\n", DEFAULT_PORT);
    printf("-b bind_address \t: Local IP address to bind to (default: any)\n");
}

void set_defaults() {
    memset(&_sin, 0, sizeof(_sin));
    _sin.sin_family = AF_INET;
    memset(&_bind_address, 0, sizeof(_bind_address));
    _bind_address.sin_family = AF_INET;
    _bind_address.sin_addr.s_addr = htonl(INADDR_ANY);
    memset(&_dest_address, 0, sizeof(_dest_address));
    _dest_address.sin_family = AF_INET;
    _verbose = 0;
    _socket_fd = -1;
    _num_packets = DEFAULT_NUM_PACKETS;
    _packet_size = DEFAULT_PACKET_SIZE;
    _delay = DEFAULT_DELAY;
    _total_bytes_sent = 0;
    _total_bytes_received = 0;
    valid = 1;
    running = 0;
}

void set_dest_address(char *addr) {
    struct hostent *he;
    if ((he = gethostbyname(addr)) == NULL) {
        printf("Error: invalid destination address %s\n", addr);
        valid = 0;
        return;
    }
    memcpy(&(_dest_address.sin_addr), he->h_addr_list[0], he->h_length);
}

void set_bind_address(char *addr) {
    struct in_addr tmp;
    if (inet_aton(addr, &tmp) == 0) {
        printf("Error: invalid bind address %s\n", addr);
        valid = 0;
        return;
    }
    _bind_address.sin_addr = tmp;
}

void set_port(char *port) {
    int p = atoi(port);
    if (p < 1 || p > 65535) {
        printf("Error: invalid port number %s\n", port);
        valid = 0;
        return;
    }
    _sin.sin_port = htons(p);
}

void set_packet_size(char *size) {
    int s = atoi(size);
    if (s < 1 || s > 65535) {
        printf("Error: invalid packet size %s\n", size);
        valid = 0;
        return;
    }
    _packet_size = s;
}

void set_num_packets(char *num_packets) {
    int n = atoi(num_packets);
    if (n < 1) {
        printf("Error: invalid number of packets %s\n", num_packets);
        valid = 0;
        return;
    }
    _num_packets = n;
}

void set_delay(char *delay) {
    int d = atoi(delay);
    if (d < 0) {
        printf("Error: invalid delay %s\n", delay);
        valid = 0;
        return;
    }
    _delay = d;
}

void parse_args(int argc, char *argv[]) {
    int opt;
    while ((opt = getopt(argc, argv, "hvs:n:d:p:b:")) != -1) {
        switch (opt) {
            case 'h':
                print_usage();
                exit(0);
                break;
            case 'v':
                _verbose = 1;
                break;
            case 's':
                set_packet_size(optarg);
                break;
            case 'n':
                set_num_packets(optarg);
                break;
            case 'd':
                set_delay(optarg);
                break;
            case 'p':
                set_port(optarg);
                break;
            case 'b':
                set_bind_address(optarg);
                break;
            default: /* '?' */
                print_usage();
                exit(-1);
                break;
        }
    }
    if (optind >= argc) {
        printf("Error: destination address required\n");
        valid = 0;
        return;
    }
    set_dest_address(argv[optind]);
}

void sig_handler(int sig) {
    printf("\nInterrupted. Cleaning up and exiting.\n");
    running = 0;
}

int create_socket() {
    _socket_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (_socket_fd < 0) {
        perror("Error creating socket");
        return -1;
    }
    if (bind(_socket_fd, (struct sockaddr *) &_bind_address, sizeof(_bind_address)) < 0) {
        perror("Error binding socket");
        return -1;
    }
    return 0;
}

int send_packets() {
    char *buf = (char *) malloc(_packet_size);
    if (buf == NULL) {
        perror("Error allocating memory for packet buffer");
        return -1;
    }
    memset(buf, 'a', _packet_size);
    int num_sent = 0;
    struct timeval start, end;
    gettimeofday(&start, NULL);
    while (running && num_sent < _num_packets) {
        if (sendto(_socket_fd, buf, _packet_size, 0, (struct sockaddr *) &_dest_address, sizeof(_dest_address)) < 0) {
            perror("Error sending packet");
            free(buf);
            return -1;
        }
        if (_verbose) printf("Sent packet #%d\n", num_sent+1);
        _total_bytes_sent += _packet_size;
        num_sent++;
        usleep(_delay);
    }
    gettimeofday(&end, NULL);
    double time_elapsed = end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) / 1000000.0;
    double data_rate = (_total_bytes_sent / time_elapsed) / 1000000.0;
    printf("Sent %d packets (%ld bytes) in %lf seconds (%lf Mbps)\n", _num_packets, _total_bytes_sent, time_elapsed, data_rate);
    free(buf);
    return 0;
}

int receive_packets() {
    char *buf = (char *) malloc(_packet_size);
    if (buf == NULL) {
        perror("Error allocating memory for packet buffer");
        return -1;
    }
    int num_received = 0;
    struct timeval start, end;
    gettimeofday(&start, NULL);
    while (running && num_received < _num_packets) {
        struct sockaddr_in si_other;
        socklen_t slen = sizeof(si_other);
        int bytes_received = recvfrom(_socket_fd, buf, _packet_size, 0, (struct sockaddr *) &si_other, &slen);
        if (bytes_received < 0) {
            perror("Error receiving packet");
            free(buf);
            return -1;
        }
        if (_verbose) printf("Received packet #%d\n", num_received+1);
        _total_bytes_received += bytes_received;
        num_received++;
    }
    gettimeofday(&end, NULL);
    double time_elapsed = end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) / 1000000.0;
    double data_rate = (_total_bytes_received / time_elapsed) / 1000000.0;
    double packet_loss = 100.0 - ((num_received / (double) _num_packets) * 100.0);
    printf("Received %d packets (%ld bytes) in %lf seconds (%lf Mbps, %lf%% packet loss)\n", num_received, _total_bytes_received, time_elapsed, data_rate, packet_loss);
    free(buf);
    return 0;
}

void *qos_monitor_thread(void *ptr) {
    while (running) {
        int bytes_sent = _total_bytes_sent;
        int bytes_received = _total_bytes_received;
        usleep(1000000);
        int bytes_sent_diff = _total_bytes_sent - bytes_sent;
        int bytes_received_diff = _total_bytes_received - bytes_received;
        double data_rate = (bytes_sent_diff + bytes_received_diff) / 1000000.0;
        printf("QoS: %lf Mbps\n", data_rate);
    }
    pthread_exit(NULL);
}

int start_qos_monitor() {
    pthread_t thread_id;
    int ret = pthread_create(&thread_id, NULL, qos_monitor_thread, NULL);
    if (ret != 0) {
        printf("Error creating QoS monitor thread: %s", strerror(errno));
        return -1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    set_defaults();
    parse_args(argc, argv);
    if (!valid) {
        print_usage();
        exit(-1);
    }
    if (create_socket() < 0) {
        exit(-1);
    }
    running = 1;
    if (start_qos_monitor() < 0) {
        exit(-1);
    }
    signal(SIGINT, sig_handler);
    if (send_packets() < 0) {
        running = 0;
    }
    if (receive_packets() < 0) {
        running = 0;
    }
    close(_socket_fd);
    return 0;
}