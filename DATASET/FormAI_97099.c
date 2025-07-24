//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_DEVICES 10              // maximum number of devices on network
#define MAX_PACKET_SIZE 1500        // maximum size of packet on network
#define MAX_DELAY 1000              // maximum delay for network traffic
#define MIN_THROUGHPUT 10           // minimum throughput for network traffic
#define MAX_THROUGHPUT 100          // maximum throughput for network traffic

// structure for a network device
typedef struct {
    int id;                     // device ID
    int packets_sent;           // number of packets sent
    int packets_received;       // number of packets received
    int packet_loss;            // packet loss percentage
    int throughput;             // current throughput in mbps
} Device;

// function to simulate network traffic for a given device
void simulate_traffic(Device *dev) {
    int delay = rand() % MAX_DELAY;          // random delay for packet
    int packet_size = rand() % MAX_PACKET_SIZE;       // random packet size
    int throughput = (rand() % (MAX_THROUGHPUT - MIN_THROUGHPUT + 1)) + MIN_THROUGHPUT;    // random throughput
    int time_taken = (packet_size / throughput) * 1000000;     // time taken in microseconds
    usleep(delay);                  // wait for the delay
    dev->packets_sent++;             // increment packets sent
    if (rand() % 100 < dev->packet_loss) {     // check if packet is dropped
        printf("Packet dropped by device %d.\n", dev->id);
    } else {
        usleep(time_taken);         // wait for time taken for packet to be transmitted
        dev->packets_received++;      // increment packets received
    }
}

int main() {
    srand(time(NULL));            // seed for random number generation
    Device devices[MAX_DEVICES];    // array of devices
    int num_devices;              // number of devices
    // get number of devices from user
    do {
        printf("Enter number of devices (maximum %d): ", MAX_DEVICES);
        scanf("%d", &num_devices);
    } while (num_devices < 1 || num_devices > MAX_DEVICES);
    // get details of each device from user
    for (int i = 0; i < num_devices; i++) {
        devices[i].id = i + 1;
        printf("Enter packet loss percentage for device %d (0-100): ", i + 1);
        scanf("%d", &devices[i].packet_loss);
        devices[i].packets_sent = devices[i].packets_received = 0;
    }
    // start sending packets to each device continuously
    while (1) {
        for (int i = 0; i < num_devices; i++) {
            simulate_traffic(&devices[i]);
            printf("Device %d status: packets sent = %d, packets received = %d, packet loss = %d%%.\n",
                   devices[i].id, devices[i].packets_sent, devices[i].packets_received,
                   (devices[i].packets_sent - devices[i].packets_received) * 100 / devices[i].packets_sent);
        }
        printf("\n");
    }
    return 0;
}