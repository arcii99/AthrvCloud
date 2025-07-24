//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Sherlock Holmes
//The Case Of The Mysterious Network Fluctuations
//By Sherlock Holmes (Code Investigator Extraordinaire)


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 8080

void* monitor(void* arg)
{
    int sock = *((int*)arg);

    int total_packets = 0;
    int dropped_packets = 0;

    while(1)
    {
        char buffer[1024] = {0};
        int valread = read( sock , buffer, 1024);
        total_packets++;
        if (valread == -1)
        {
            dropped_packets++;
        }
        float percentage_dropped = ((float)dropped_packets / total_packets) * 100;
        printf("Total Packets: %d, Dropped Packets: %d, Percentage Dropped: %.2f%% \n", total_packets, dropped_packets, percentage_dropped);
    }
}

int main(int argc, char const *argv[])
{
    printf("Welcome to The Case Of The Mysterious Network Fluctuations\n");

    //Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Could not create socket\n");
        return -1;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = inet_addr("127.0.0.1");

    //Connect to server
    if (connect(sock, (struct sockaddr *)&address, sizeof(address)) != 0)
    {
        printf("Connection Failed\n");
        return -1;
    }

    //Monitor the network
    pthread_t tid;
    pthread_create(&tid, NULL, monitor, (void*)&sock);

    //Send test packets
    for(int i = 0; i < 100; i++)
    {
        char packet[1024];
        sprintf(packet, "Packet %d", i);
        send(sock, packet, strlen(packet), 0);
    }

    close(sock);

    return 0;
}