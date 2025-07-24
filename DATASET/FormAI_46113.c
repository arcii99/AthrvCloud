//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>
#include <signal.h>

#define TIMEOUT 5 // Timeout interval in seconds
#define PKTDATALEN 1024 // Maximum packet size
#define PKTNUM 10 // Number of packets to send
#define PORT 4444 // Destination port number
#define HOST "127.0.0.1" // Destination IP address

// Function to calculate the difference between two timeval structures
int timediff(struct timeval *t1, struct timeval *t2)
{
    return ((t1->tv_sec - t2->tv_sec) * 1000 +
            (t1->tv_usec - t2->tv_usec) / 1000);
}

// Signal handler for timeouts
void handle_timeout(int signum)
{
    printf("Timeout\n");
}

int main()
{
    int sockfd, bytes_recv, bytes_sent, i, pktloss, totaltime = 0, maxtime = 0, mintime = 1000, avetime;
    struct sockaddr_in servaddr;
    char sendbuf[PKTDATALEN], recvbuf[PKTDATALEN];
    struct timeval start, end, timeout;
    struct sigaction sigact;

    // Create socket
    sockfd  = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd < 0)
    {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    // Set destination IP address and port number
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(HOST);
    servaddr.sin_port = htons(PORT);

    // Set signal handler for timeouts
    sigemptyset(&sigact.sa_mask);
    sigact.sa_flags = 0;
    sigact.sa_handler = handle_timeout;
    if (sigaction(SIGALRM, &sigact, NULL) < 0)
    {
        perror("Unable to set signal handler");
        exit(EXIT_FAILURE);
    }

    // Initialize packet buffer with random data
    srand(time(NULL));
    for (i = 0; i < PKTDATALEN; i++)
    {
        sendbuf[i] = rand() % 256;
    }

    // Send packets and measure response time
    for (i = 0; i < PKTNUM; i++)
    {
        // Send packet
        bytes_sent = sendto(sockfd, sendbuf, sizeof(sendbuf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
        if (bytes_sent < 0)
        {
            perror("Unable to send packet");
            exit(EXIT_FAILURE);
        }

        // Set timeout for response
        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

        // Wait for response
        gettimeofday(&start, NULL);
        bytes_recv = recvfrom(sockfd, recvbuf, sizeof(recvbuf), 0, NULL, NULL);
        gettimeofday(&end, NULL);

        // Calculate response time, update min/max/avg times
        if (bytes_recv > 0)
        {
            totaltime += timediff(&end, &start);
            if (timediff(&end, &start) > maxtime)
            {
                maxtime = timediff(&end, &start);
            }
            if (timediff(&end, &start) < mintime)
            {
                mintime = timediff(&end, &start);
            }
            printf("Packet %d received in %d ms\n", i + 1, timediff(&end, &start));
        }
        else if (errno == EAGAIN || errno == EWOULDBLOCK)
        {
            printf("Packet %d dropped (timeout)\n", i + 1);
            pktloss++;
        }
        else
        {
            perror("Unable to receive packet");
            exit(EXIT_FAILURE);
        }
    }

    // Calculate packet loss and average response time
    pktloss = (pktloss * 100) / PKTNUM;
    avetime = totaltime / PKTNUM;

    // Print results
    printf("Packet loss: %d%%\n", pktloss);
    printf("Min response time: %d ms\n", mintime);
    printf("Max response time: %d ms\n", maxtime);
    printf("Avg response time: %d ms\n", avetime);

    // Close socket
    close(sockfd);

    return 0;
}