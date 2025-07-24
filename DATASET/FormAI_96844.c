//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: curious
#include <stdio.h>

// Function to check if the entered IP address is valid
int valid_ip(int ip[]) {
    for(int i=0; i<4; i++) {
        if(ip[i] > 255 || ip[i] < 0) {
            printf("\nInvalid IP address!");
            return 0; // return 0 if invalid
        }
    }
    return 1; // return 1 if valid
}

// Main function
int main() {
    int ip[4], subnet_mask;
    printf("\nEnter IP address in dotted decimal format: ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    if(valid_ip(ip)) {
        printf("\nEnter Subnet Mask in decimal format (0-32): ");
        scanf("%d", &subnet_mask);
        if(subnet_mask<0 || subnet_mask>32) {
            printf("\nInvalid Subnet Mask!");
            return 0;
        }
        int i=0, n=subnet_mask/8, bits=subnet_mask%8, mask[4]={0, 0, 0, 0};
        while(i<n) {
            mask[i] = 255;
            i++;
        }
        if(bits) {
            int temp = 1;
            for(int j=0; j<bits; j++) {
                temp *= 2;
            }
            temp--;
            mask[n] = temp;
        }
        printf("\nNetwork Address: %d.%d.%d.%d", ip[0]&mask[0], ip[1]&mask[1], ip[2]&mask[2], ip[3]&mask[3]);
        printf("\nBroadcast Address: %d.%d.%d.%d", ((ip[0]&mask[0])|(255-mask[0])), ((ip[1]&mask[1])|(255-mask[1])), ((ip[2]&mask[2])|(255-mask[2])), ((ip[3]&mask[3])|(255-mask[3])));
    }
    return 0; // Exit program
}