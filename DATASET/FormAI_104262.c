//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>

#define MAX_PACKET_SIZE 8192 // Maximum size of the packet
#define MAX_THREADS 256      // Maximum number of threads
#define MAX_PORTS_ALLOWED 16 // Maximum number of ports allowed
#define MAX_IP_LEN 15        // Maximum length of the IP address

// Struct to hold each host information
typedef struct host_t
{
    char ip[MAX_IP_LEN];    // IP address
    char name[NI_MAXHOST];  // Hostname
    int open_ports[MAX_PORTS_ALLOWED]; // Array to hold open ports of the host
    int num_ports;          // Number of open ports of the host
} host_t;

// Struct to hold port scan thread arguments
typedef struct thread_args_t
{
    char ip[MAX_IP_LEN];    // Target IP address
    int start;              // Start port
    int end;                // End port
    int *open_ports;        // Array to track open ports
    int scan_type;          // Scan type (0 = TCP, 1 = UDP)
} thread_args_t;

// TCP scan function
void tcp_scan(char *ip, int start, int end, int *open_ports)
{
    int sockfd;
    struct sockaddr_in target_addr;
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    // Loop through all the ports to be scanned
    for (int port = start; port <= end; port++)
    {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
        setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));

        // Set target address
        memset(&target_addr, 0, sizeof(target_addr));
        target_addr.sin_family = AF_INET;
        target_addr.sin_addr.s_addr = inet_addr(ip);
        target_addr.sin_port = htons(port);

        // Try to connect to the target port
        if (connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0)
        {
            open_ports[port - start] = 1;
            close(sockfd);
        }
        else
        {
            close(sockfd);
        }
    }
}

// UDP scan function
void udp_scan(char *ip, int start, int end, int *open_ports)
{
    int sockfd;
    struct sockaddr_in target_addr;
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    // Loop through all the ports to be scanned
    for (int port = start; port <= end; port++)
    {
        sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
        setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));

        // Set target address
        memset(&target_addr, 0, sizeof(target_addr));
        target_addr.sin_family = AF_INET;
        target_addr.sin_addr.s_addr = inet_addr(ip);
        target_addr.sin_port = htons(port);

        // Send UDP packet to the target port
        if (sendto(sockfd, NULL, 0, 0, (struct sockaddr *)&target_addr, sizeof(target_addr)) >= 0)
        {
            int length = sizeof(target_addr);
            char response[MAX_PACKET_SIZE];
            memset(response, 0, MAX_PACKET_SIZE);

            // Try to receive the response from the target port
            if (recvfrom(sockfd, response, MAX_PACKET_SIZE, 0, (struct sockaddr *)&target_addr, &length) >= 0)
            {
                open_ports[port - start] = 1;
            }
        }
        close(sockfd);
    }
}

// Thread function
void *scan_thread(void *arg)
{
    // Convert thread argument to thread_args_t
    thread_args_t *args = (thread_args_t *)arg;

    // Call the scan function based on scan_type
    if (args->scan_type == 0)
    {
        tcp_scan(args->ip, args->start, args->end, args->open_ports);
    }
    else
    {
        udp_scan(args->ip, args->start, args->end, args->open_ports);
    }

    pthread_exit(NULL);
}

// Function to print usage instructions
void usage(char *program_name)
{
    printf("Usage: %s [-t | -u] [-p port_range] [ip_range]\n", program_name);
    printf("  -t : TCP scan\n");
    printf("  -u : UDP scan\n");
    printf("  -p : Port range (default 1-1024)\n");
    printf("  ip_range : IP range to scan (e.g. 192.168.1.1-192.168.1.10)\n");
    printf("  Example: %s -t -p 80-100 192.168.1.1-192.168.1.10\n", program_name);
}

int main(int argc, char *argv[])
{
    // Set default values for options
    int tcp_scan_flag = 1;
    int udp_scan_flag = 0;
    int start_port = 1;
    int end_port = 1024;
    char *ip_range = NULL;

    // Parse command line arguments
    int opt;
    while ((opt = getopt(argc, argv, "tup:")) != -1)
    {
        switch (opt)
        {
        case 't':
            tcp_scan_flag = 1;
            udp_scan_flag = 0;
            break;
        case 'u':
            tcp_scan_flag = 0;
            udp_scan_flag = 1;
            break;
        case 'p':
            sscanf(optarg, "%d-%d", &start_port, &end_port);
            break;
        default:
            usage(argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    if (optind < argc)
    {
        ip_range = argv[optind];
    }
    else
    {
        usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    // Split IP range into start and end IP addresses
    char start_ip[MAX_IP_LEN], end_ip[MAX_IP_LEN];
    sscanf(ip_range, "%15[^-]-%15s", start_ip, end_ip);

    // Convert start and end IP addresses to uint32_t integers
    uint32_t start_ip_int = ntohl(inet_addr(start_ip));
    uint32_t end_ip_int = ntohl(inet_addr(end_ip));

    // Create array to hold all the hosts and initialize them with empty values
    host_t hosts[(end_ip_int - start_ip_int) + 1];
    for (int i = 0; i < (end_ip_int - start_ip_int) + 1; i++)
    {
        sprintf(hosts[i].ip, "%u", htonl(start_ip_int + i));
        strncpy(hosts[i].name, "", NI_MAXHOST);
        hosts[i].num_ports = 0;
        memset(hosts[i].open_ports, 0, sizeof(int) * MAX_PORTS_ALLOWED);
    }

    // Create threads to scan each host for open ports
    pthread_t threads[MAX_THREADS];
    int thread_args[MAX_THREADS];
    int num_threads = 0;
    for (uint32_t i = start_ip_int; i <= end_ip_int; i++)
    {
        thread_args_t *args = (thread_args_t *)malloc(sizeof(thread_args_t));
        args->scan_type = tcp_scan_flag;
        args->start = start_port;
        args->end = end_port;

        // Convert IP address to string
        sprintf(args->ip, "%u", htonl(i));

        args->open_ports = hosts[i - start_ip_int].open_ports;

        // Create thread for each host
        if (pthread_create(&threads[num_threads], NULL, scan_thread, (void *)args) != 0)
        {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }

        num_threads++;
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            perror("Failed to join thread");
        }
    }

    // Resolve hostnames and print the results
    for (int i = 0; i < (end_ip_int - start_ip_int) + 1; i++)
    {
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(struct sockaddr_in));
        addr.sin_family = AF_INET;
        inet_aton(hosts[i].ip, &addr.sin_addr);

        // Try to resolve hostname
        if (getnameinfo((struct sockaddr *)&addr, sizeof(struct sockaddr_in), hosts[i].name, NI_MAXHOST, NULL, 0, 0) == 0)
        {
            printf("%-15s (%-30s) : ", hosts[i].ip, hosts[i].name);
        }
        else
        {
            printf("%-15s (%-30s) : ", hosts[i].ip, "Unknown host");
        }

        int num_open_ports = 0;
        for (int j = 0; j < MAX_PORTS_ALLOWED; j++)
        {
            if (hosts[i].open_ports[j] == 1)
            {
                printf("%d ", j + start_port);
                num_open_ports++;
            }
        }
        if (num_open_ports == 0)
        {
            printf("No open ports");
        }
        printf("\n");
    }

    return 0;
}