//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: scientific
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char ip[20],mask[20],subnet[20];
    int bits,nsubnet,nmask,host,bits_left;
    printf("Enter IP address in dotted decimal format: ");
    scanf("%s",ip);
    printf("Enter subnet mask in dotted decimal format: ");
    scanf("%s",mask);
    printf("Enter the number of subnets required: ");
    scanf("%d",&nsubnet);
    printf("Enter the number of hosts per subnet required: ");
    scanf("%d",&host);

    //Converting mask to bits
    nmask=0;
    sscanf(mask,"%d.%d.%d.%d",&bits_left,&bits_left,&bits_left,&bits_left);
    while(bits_left)
    {
        nmask+=bits_left%2;
        bits_left/=2;
    }
    sscanf(mask,"%d.%d.%d.%d",&bits_left,&bits_left,&bits_left,&bits_left);
    while(bits_left)
    {
        nmask+=bits_left%2;
        bits_left/=2;
    }
    sscanf(mask,"%d.%d.%d.%d",&bits_left,&bits_left,&bits_left,&bits_left);
    while(bits_left)
    {
        nmask+=bits_left%2;
        bits_left/=2;
    }
    sscanf(mask,"%d.%d.%d.%d",&bits_left,&bits_left,&bits_left,&bits_left);
    while(bits_left)
    {
        nmask+=bits_left%2;
        bits_left/=2;
    }

    bits=log2(nsubnet);
    memset(subnet,0,sizeof(subnet));
    sprintf(subnet,"%d.%d.%d.%d",255,255,255,255<<(8-bits));

    //Displaying Subnet Mask & Network ID
    printf("\nSubnet mask for the given requirement: %s\n",subnet);
    printf("\nThe network ID for the given IP address and subnet mask: %s\n\n",ip);

    //Calculating subnets
    printf("List of subnets for the given requirement:\n");
    bits_left=32-nmask;
    bits=log2(host+2);
    for(int i=0;i<host+2;i++)
    {
        if(i%(int)pow(2,bits)==0 && i!=0)
        {
            printf("\n");
            sprintf(ip,"%d.%d.%d.%d",ip[0],ip[1],ip[2],i/pow(2,bits));
        }
        printf("%d.%d.%d.%d  ",ip[0],ip[1],ip[2],i%(int)pow(2,bits));
    }
    printf("\n");
    return 0;
}