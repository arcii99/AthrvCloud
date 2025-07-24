//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    char ip[16];
    printf("Enter IP address: ");
    scanf("%s",ip);
    int ipaddr[4];
    int subnet;

    //Extracting IP address and subnet mask values
    sscanf(ip,"%d.%d.%d.%d/%d",&ipaddr[0],&ipaddr[1],&ipaddr[2],&ipaddr[3],&subnet);
    int subnet_bytes = subnet/8; //calculating number of full bytes in subnet mask
    int partial_bits = subnet%8; //calculating number of bits in partial byte of subnet mask

    //Converting subnet mask to binary
    char subnet_binary[33];
    for(int i=0;i<partial_bits;i++){
        subnet_binary[i] = '1';
    }
    for(int i=partial_bits;i<8;i++){
        subnet_binary[i] = '0';
    }
    for(int i=1;i<=subnet_bytes;i++){
        subnet_binary[8*i] = '.';
        for(int j=1;j<=8;j++){
            subnet_binary[8*i+j] = '1';
        }
    }
    subnet_binary[32] = '\0';

    //Calculating number of usable host addresses in the subnet
    int num_hosts;
    if(subnet==32){
        num_hosts = 0;
    } else {
        num_hosts = pow(2,32-subnet)-2;
    }

    //Printing results
    printf("\nIP Address: %s",ip);
    printf("\nSubnet Mask: %s",subnet_binary);
    printf("\nNumber of Usable Host Addresses: %d\n",num_hosts);

    return 0;
}