//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char input[20], ipaddress[20];
    int cidr, subnetmask[4], nmask[4], i, j=0, temp, n;
    printf("Enter IP address in dotted decimal notation (XXX.XXX.XXX.XXX): ");
    fgets(input,20,stdin);
    sscanf(input,"%s",ipaddress);
    printf("Enter CIDR notation (0-32): ");
    fgets(input,20,stdin);
    sscanf(input,"%d",&cidr);

    //Calculating subnet mask
    for (i=0; i<4; i++){
        if (cidr>=8){
            subnetmask[i]=255;
            cidr-=8;
        }
        else{
            n=8-cidr;
            temp=256-(1<<n);
            subnetmask[i]=temp;
            cidr=0;
        }
    }

    //Calculating network mask
    for (i=0;i<4;i++){
        nmask[i]=subnetmask[i]^255;
    }
    
    printf("\nIP Address: %s\n",ipaddress);
    printf("CIDR Notation: /%d\n",cidr);
    printf("Subnet Mask: %d.%d.%d.%d\n",subnetmask[0],subnetmask[1],subnetmask[2],subnetmask[3]);
    printf("Network Mask: %d.%d.%d.%d\n",nmask[0],nmask[1],nmask[2],nmask[3]);

    return 0;
}