//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int packet_loss = 0, jitter = 0, latency = 0;
    time_t current_time;
    srand((unsigned)time(NULL));

    while(1){
        //simulate packet loss
        if(rand()%10 < 3){
            packet_loss++;
        }
        //simulate jitter
        jitter = rand()%20;
        //simulate latency
        latency = rand()%100;

        //get current time
        time(&current_time);

        //print results
        printf("Current Time: %s", ctime(&current_time));
        printf("Packet Loss: %d %%\n", packet_loss);
        printf("Jitter: %d ms\n", jitter);
        printf("Latency: %d ms\n\n", latency);

        //wait for 1 second
        sleep(1);
    }

    return 0;
}