//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: lively
#include <stdio.h>

int main() {
    int IP[4]; // array to store the IP address
    int subnet_mask; // variable to store the subnet mask
    int network_class; // variable to store the network class
    
    printf("Enter IP address in dotted decimal format (e.g., 192.168.0.1):\n");
    scanf("%d.%d.%d.%d",&IP[0],&IP[1],&IP[2],&IP[3]);
    
    printf("Enter subnet mask in CIDR notation (e.g., 24):\n");
    scanf("%d",&subnet_mask);
    
    // determine the class of network based on the first octet of the IP address
    if (IP[0] >= 1 && IP[0] <= 126) {
        network_class = 'A';
    } else if (IP[0] >= 128 && IP[0] <= 191) {
        network_class = 'B';
    } else if (IP[0] >= 192 && IP[0] <= 223) {
        network_class = 'C';
    } else if (IP[0] >= 224 && IP[0] <= 239) {
        network_class = 'D';
    } else {
        network_class = 'E';
    }
    
    // calculate the subnet mask in binary format
    int num_bits = 32 - subnet_mask;
    int subnet_mask_binary[32];
    for (int i=0; i<subnet_mask; i++) {
        subnet_mask_binary[i] = 1;
    }
    for (int i=subnet_mask; i<32; i++) {
        subnet_mask_binary[i] = 0;
    }
    
    // print the results
    printf("IP address: %d.%d.%d.%d\n",IP[0],IP[1],IP[2],IP[3]);
    printf("Subnet mask: %d.%d.%d.%d\n",subnet_mask_binary[0]*255+subnet_mask_binary[1]*128+subnet_mask_binary[2]*64+subnet_mask_binary[3]*32+subnet_mask_binary[4]*16+subnet_mask_binary[5]*8+subnet_mask_binary[6]*4+subnet_mask_binary[7]*2+subnet_mask_binary[8], subnet_mask_binary[9]*128+subnet_mask_binary[10]*64+subnet_mask_binary[11]*32+subnet_mask_binary[12]*16+subnet_mask_binary[13]*8+subnet_mask_binary[14]*4+subnet_mask_binary[15]*2+subnet_mask_binary[16], subnet_mask_binary[17]*128+subnet_mask_binary[18]*64+subnet_mask_binary[19]*32+subnet_mask_binary[20]*16+subnet_mask_binary[21]*8+subnet_mask_binary[22]*4+subnet_mask_binary[23]*2+subnet_mask_binary[24], subnet_mask_binary[25]*128+subnet_mask_binary[26]*64+subnet_mask_binary[27]*32+subnet_mask_binary[28]*16+subnet_mask_binary[29]*8+subnet_mask_binary[30]*4+subnet_mask_binary[31]*2);
    printf("Number of subnets: %d\n",(1 << num_bits));
    printf("Number of hosts per subnet: %d\n",(1 << (32-subnet_mask))-2);
    printf("Network class: %c\n",network_class);
    
    return 0;
}