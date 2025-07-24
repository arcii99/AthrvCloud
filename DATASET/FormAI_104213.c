//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/time.h>

#define PORT 8080
#define TCP_PACKET_PAYLOAD_SIZE 1024  // in bytes
#define MAX_BUFFER_SIZE 1024  // in bytes
#define AVG_PACKET_LATENCY 1000  // in microseconds
#define MAX_PACKET_LOSS_LIMIT_PERCENTAGE 5  // in percentage
#define NUMBER_OF_PACKETS_TO_SEND 1000

double current_time_in_microseconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    double time_in_microseconds = (double)tv.tv_sec*1000000 + (double)tv.tv_usec;
    return time_in_microseconds;
}

double average_packet_delivery_ratio(double total_packets_sent, double total_packets_received) {
    return (total_packets_received/total_packets_sent)*100;
}

int main(int argc, char const *argv[]) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
    
    memset(&serv_addr, '0', sizeof(serv_addr));
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    
    char *msg = "Hello from client";
    char buffer[MAX_BUFFER_SIZE] = {0};

    double total_packets_sent = 0, total_packets_received = 0, time_diff_in_microseconds = 0;
    int packet_delivery_ratio = 0;

    for(int i = 0; i < NUMBER_OF_PACKETS_TO_SEND; i++) {
        // send a packet
        double send_time = current_time_in_microseconds();
        send(sock, msg, strlen(msg), 0);
        total_packets_sent++;

        // wait for a packet
        int valread;
        if ((valread = read(sock, buffer, MAX_BUFFER_SIZE)) <= 0) {
            printf("\nConnection closed by server\n");
            break;
        }
        total_packets_received++;

        // measure time difference between sent and received time
        double received_time = current_time_in_microseconds();
        time_diff_in_microseconds += (received_time - send_time) - AVG_PACKET_LATENCY;

        // calculate packet delivery ratio
        double current_packet_delivery_ratio = average_packet_delivery_ratio(total_packets_sent, total_packets_received);
        if(current_packet_delivery_ratio < packet_delivery_ratio - MAX_PACKET_LOSS_LIMIT_PERCENTAGE) {
            printf("\nPacket delivery ratio is below limit of %d percent. Current packet delivery ratio: %f percent\n", MAX_PACKET_LOSS_LIMIT_PERCENTAGE, current_packet_delivery_ratio);
            break;
        }
        packet_delivery_ratio = current_packet_delivery_ratio;
    }

    printf("\nTotal packets sent: %f\nTotal packets received: %f\nAverage latency per packet: %f microseconds\nPacket delivery ratio: %f percent\n", total_packets_sent, total_packets_received, time_diff_in_microseconds/total_packets_received, packet_delivery_ratio);
    return 0;
}