//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Ken Thompson
/* 
 * QoS Monitor - A C Program to monitor network quality of service (QoS)
 * 
 * Written by: [Your Name]
 * 
 * This program uses sockets to send and receive data packets between a client and server
 * to monitor network QoS. It calculates the average latency and packet loss rate
 * between the client and server and reports the results to the user.
 * 
 * The program can be customized by changing the bufferSize, maxPackets and sleepTime values. 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>

#define PORT 8080
#define bufferSize 1024
#define maxPackets 100
#define sleepTime 1

struct packet {
    int seqno;
    struct timeval sendTime;
};

int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[bufferSize] = {0};
    char *hello = "Hello from client";
    struct timeval startTime, endTime;
    struct packet packets[maxPackets];
    int i = 0, packetLossCount = 0, totalPackets = 0;
    float avgLatency = 0.0, packetLossRate = 0.0;

    // create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    // initialize server address structure
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // send and receive data packets
    while (i < maxPackets) {
        struct packet p;
        memset(&p, 0, sizeof(p));
        p.seqno = i + 1;
        gettimeofday(&p.sendTime, NULL);
        send(sock, &p, sizeof(p), 0);
        valread = read(sock, buffer, bufferSize);
        gettimeofday(&endTime, NULL);

        if (valread > 0) {
            printf("Packet with seqno %d received\n", i + 1);
            packets[i] = p;
            i++;
        } else {
            printf("Packet loss with seqno %d\n", i + 1);
            packetLossCount++;
        }

        totalPackets++;
        usleep(sleepTime * 1000);
    }

    // calculate QoS metrics
    for (i = 0; i < maxPackets; i++) {
        if (packets[i].sendTime.tv_sec != 0) {
            float latency = ((endTime.tv_sec - packets[i].sendTime.tv_sec) * 1000.0) +
                            ((endTime.tv_usec - packets[i].sendTime.tv_usec) / 1000.0);
            avgLatency += latency;
            printf("Latency for packet %d: %.2fms\n", i + 1, latency);
        }
    }

    avgLatency /= maxPackets;
    packetLossRate = (packetLossCount / (float)totalPackets) * 100.0;
    printf("\nQoS Metrics:\n");
    printf("Average Latency: %.2fms\n", avgLatency);
    printf("Packet Loss Rate: %.2f%%\n", packetLossRate);

    return 0;
}