//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#define MAX_LOAD 80

static int counter = 0;
static int pkt_loss_counter = 0;
static int pkt_total_counter = 0;
static int pkt_loss_rate = 0;

void sig_handler(int sig)
{
    if (sig == SIGINT) {
        printf("\n");
        printf("Total Packets: %d \n", pkt_total_counter);
        printf("Packet Loss: %d \n", pkt_loss_counter);
        printf("Packet Loss Rate: %d%%\n", pkt_loss_rate);
        exit(0);
    }
}

void monitor_network_qos()
{
    int load_percent = 0;
    
    printf("Monitoring network QoS...\n");
    while(1) {
        load_percent = rand() % 100;
        if(load_percent > MAX_LOAD) {
            pkt_loss_counter++;
        }
        pkt_total_counter++;

        pkt_loss_rate = (pkt_loss_counter * 100) / pkt_total_counter;
        
        printf("Total Packets: %d \n", pkt_total_counter);
        printf("Packet Loss: %d \n", pkt_loss_counter);
        printf("Packet Loss Rate: %d%%\n", pkt_loss_rate);
        
        counter++;
        if (counter == 5) {
            counter = 0;
            printf("Sending Heartbeat...\n");
        }
        sleep(1);
    }
}

int main()
{
    signal(SIGINT, sig_handler);

    monitor_network_qos();

    return 0;
}