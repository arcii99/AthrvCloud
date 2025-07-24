//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: genious
#include<stdio.h>
#include<math.h>

int main(){
    //header
    printf("\t\t\t******** C SUBNET CALCULATOR ********\n\n");
    
    int ctr=0,ip[4],mask[4],submask[4],subnetbits,subnets,hosts,power,rpower;
    //input section
    printf("Enter the IP address:\n");
    scanf("%d.%d.%d.%d",&ip[0],&ip[1],&ip[2],&ip[3]);
    printf("Enter the subnet mask:\n");
    scanf("%d.%d.%d.%d",&mask[0],&mask[1],&mask[2],&mask[3]);
    printf("Enter the number of subnet bits:\n");
    scanf("%d",&subnetbits);
    
    //subnet calculation
    for(int i=0;i<4;i++){
        submask[i]=mask[i];
        
        if(subnetbits>=8){
            submask[i]=255;
            subnetbits-=8;
        }
        else if(subnetbits<8&&subnetbits>0){
            power=7-rpower;
            subnets=pow(2,subnetbits);
            submask[i] |= (unsigned char)pow(2,power)-1; 
            submask[i] |= (subnets-1)<<(rpower); 
            subnetbits=0;
        }
        else{
            submask[i]=0;
        }
        
        rpower+=8;
    }
    
    //output section
    printf("\n");
    printf("IP Address\t\t: %d.%d.%d.%d\n",ip[0],ip[1],ip[2],ip[3]);
    printf("Subnet Mask\t\t: %d.%d.%d.%d\n",mask[0],mask[1],mask[2],mask[3]);
    printf("Number of Subnet Bits\t: %d\n",subnetbits);
    printf("Subnet Mask for Given IP\t: %d.%d.%d.%d\n",submask[0],submask[1],submask[2],submask[3]);
    
    return 0;
}