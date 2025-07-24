//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int speed = 0;
    int latency = 0;
    int throughput = 0;

    printf("Welcome to the Internet Speed Test!\n");
    printf("Please wait while we calculate your internet speed.\n");

    srand(time(NULL));

    int random_num = (rand() % 20) + 1;
    
    if (random_num <= 10) {

        printf("Calculating latency...\n");
        latency = (rand() % 100) + 1;
        printf("Latency: %d ms\n", latency);

        printf("Calculating throughput...\n");
        throughput = (rand() % 10) + 1;
        printf("Throughput: %d Mbps\n", throughput);

        speed = latency * throughput * 1024;
        printf("Your internet speed is: %d kbps\n", speed);

    } else {

        printf("Calculating throughput...\n");
        throughput = (rand() % 10) + 1;
        printf("Throughput: %d Mbps\n", throughput);

        printf("Calculating latency...\n");
        latency = (rand() % 100) + 1;
        printf("Latency: %d ms\n", latency);
        
        speed = latency * throughput * 1024;
        printf("Your internet speed is: %d kbps\n", speed);
    }

    return 0;
}