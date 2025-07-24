//FormAI DATASET v1.0 Category: Firewall ; Style: creative
#include<stdio.h>
#include<string.h>

int main(){
    char packet[20];
    int accept = 0;

    //getting packet from user
    printf("Enter packet details: ");
    scanf("%s", packet);

    //checking if packet is safe
    if (strstr(packet, "hack") != NULL || strstr(packet, "attack") != NULL){
        printf("Access denied! Firewall blocked this packet. \n");
    }
    else{
        accept = 1;
    }

    //allowing safe packets
    if (accept){
        printf("Packet accepted and forwarded to destination. \n");
    }

    return 0;
}