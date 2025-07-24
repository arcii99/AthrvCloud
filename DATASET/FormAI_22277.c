//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>

#define DEFAULT_TIMEOUT  5000   /* In ms */
#define DEFAULT_INTERVAL 5000   /* In ms */
#define DEFAULT_COUNT    -1     /* Infinite count */

volatile sig_atomic_t done = 0;

void handler(int signal) {
    done = 1;
}

void usage(char *progname) {
    printf("Usage:\n");
    printf("%s hostname [-p port] [-i interval] [-t timeout] [-c count]\n", progname);
    exit(1);
}

int main(int argc, char *argv[]) {
    int opt, sock, port, i, count;
    unsigned long addr;
    char *hostname;
    struct hostent *host;
    struct sockaddr_in server;
    long int elapsed;
    int timeout, interval, status;
    struct timeval tv;
    fd_set readfds;
    
    /* set defaults */
    port = 80;
    interval = DEFAULT_INTERVAL;
    timeout = DEFAULT_TIMEOUT;
    count = DEFAULT_COUNT;

    /* parse command-line options */
    opterr = 0;
    while ((opt = getopt(argc, argv, "p:i:t:c:")) != -1) {
        switch(opt) {
            case 'p':
                port = atoi(optarg);
                break;
            case 'i':
                interval = atoi(optarg);
                break;
            case 't':
                timeout = atoi(optarg);
                break;
            case 'c':
                count = atoi(optarg);
                break;
            default:
                usage(argv[0]);
        }
    }
    argc -= optind;
    argv += optind;

    /* ensure hostname is provided */
    if (argc != 1)
        usage(argv[0]);
    hostname = argv[0];

    /* resolve hostname to IP address */
    if (inet_aton(hostname, (struct in_addr *)&addr) == 0) {
        host = gethostbyname(hostname);
        if (host == NULL) {
            fprintf(stderr, "Cannot resolve address %s: %s\n", hostname, hstrerror(h_errno));
            exit(1);
        }
        addr = *((unsigned long *) host->h_addr_list[0]);
        hostname = host->h_name;
        printf("Found %s at %s\n", hostname, inet_ntoa(*(struct in_addr *)&addr));
    }

    /* set up socket */
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        fprintf(stderr, "Cannot create socket: %s\n", strerror(errno));
        exit(1);
    }
    bzero((char *) &server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = addr;
    server.sin_port = htons(port);

    /* install signal handler */
    signal(SIGINT, handler);

    /* start monitoring */
    for (i = 1; count == DEFAULT_COUNT || i <= count; i++) {
        printf("Pinging %s with %d bytes of data:\n", hostname, sizeof(elapsed));
        status = 0;
        tv.tv_sec = timeout / 1000;
        tv.tv_usec = (timeout % 1000) * 1000;
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            FD_ZERO(&readfds);
            FD_SET(sock, &readfds);
            if (write(sock, (char *)&elapsed, sizeof(elapsed)) == sizeof(elapsed)) {
                if (select(sock + 1, &readfds, NULL, NULL, &tv) > 0) {
                    if (read(sock, (char *)&elapsed, sizeof(elapsed)) == sizeof(elapsed)) {
                        elapsed = htonl(elapsed);
                        printf("Reply from %s: time=%ldms\n", inet_ntoa(*(struct in_addr *)&addr), elapsed);
                        status = 1;
                    }
                }
            }
            close(sock);
        }
        if (!status)
            printf("Request timed out.\n");
        
        if (count != DEFAULT_COUNT && i == count)
            break;
        usleep(interval * 1000);
        if (done)
            break;
    }

    printf("Ping statistics for %s:\n", hostname);
    printf("\tPackets: Sent = %d, Received = %d, Lost = %d (%d%% loss)\n",
           i - 1, i - 1 - (status ? 0 : 1), status ? 0 : 1, (status ? 0 : 1) * 100 / (i - 1));

    return 0;
}