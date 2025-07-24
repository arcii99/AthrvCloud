//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: innovative
#include<stdio.h>
#include<math.h>

int main(){
    int subnet_mask;
    printf("Enter the subnet mask: ");
    scanf("%d", &subnet_mask);

    int n = 32 - subnet_mask;
    int hosts = pow(2, n) - 2;
    int first_octet, second_octet, third_octet, fourth_octet;
    printf("\nEnter the IP address: ");
    scanf("%d.%d.%d.%d", &first_octet, &second_octet, &third_octet, &fourth_octet);

    int octet_values[4] = {first_octet, second_octet, third_octet, fourth_octet};
    int network_values[4], broadcast_values[4];

    for(int i = 0; i < 4; i++){
        network_values[i] = octet_values[i] & (255 << (8 - n));
        broadcast_values[i] = network_values[i] | ~(255 << (8 - n));
    }

    printf("\nNetwork address: %d.%d.%d.%d", network_values[0], network_values[1], network_values[2], network_values[3]);
    printf("\nBroadcast address: %d.%d.%d.%d", broadcast_values[0], broadcast_values[1], broadcast_values[2], broadcast_values[3]);
    printf("\nNumber of usable hosts per subnet: %d", hosts);

    return 0;
}