//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: romantic
#include<stdio.h>

int main() {
    printf("My love, let me monitor your network quality of service,\n");
    printf("With my program, I will ensure that there are no errors.\n\n");

    int packet_loss, latency, throughput;

    printf("Please enter the packet loss: ");
    scanf("%d", &packet_loss);

    printf("Please enter the latency: ");
    scanf("%d", &latency);

    printf("Please enter the throughput: ");
    scanf("%d", &throughput);

    if(packet_loss < 5) {
        printf("Your network quality of service is perfect,\n");
        printf("With a packet loss of only %d percent.\n", packet_loss);
        printf("My love, you are the best!\n");
    }
    else if(packet_loss >= 5 && packet_loss < 10) {
        printf("Your network quality of service is good,\n");
        printf("With a packet loss of %d percent.\n", packet_loss);
        printf("But my love, we need to work on it,\n");
        printf("To make it perfect like us.\n");
    }
    else {
        printf("Oh no, your network quality of service is red,\n");
        printf("With a packet loss of %d percent.\n", packet_loss);
        printf("But worry not, my love,\n");
        printf("I will always be here to fix it.\n");
    }

    printf("\nThank you for using my program, my love!\n");
    return 0;
}