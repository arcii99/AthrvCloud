//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include<stdio.h>
#include<math.h>
int main(){
    int octet[4],CIDR,layers;
    printf("Enter the IP address in dotted decimal notation(i.e. xxx.xxx.xxx.xxx): ");
    scanf("%d.%d.%d.%d",&octet[0],&octet[1],&octet[2],&octet[3]);
    printf("Enter the CIDR notation: ");
    scanf("%d",&CIDR);
    layers=32-CIDR;
    int mask;
    for(int i=0;i<4;i++){
        mask=0;
        for(int j=7;j>=0;j--){
            mask+=pow(2,j);
            if(layers--==0)
                break;
        }
        octet[i]=octet[i]&mask;
    }
    printf("\nNetwork Address (in binary): ");
    for(int i=0;i<4;i++){
        for(int j=7;j>=0;j--){
            printf("%d",(octet[i]>>j)&1);
        }
        printf(".");
    }
    printf("\n\nNetwork Address (in dotted decimal notation): %d.%d.%d.%d",octet[0],octet[1],octet[2],octet[3]);
    printf("\n\n");
    return 0;
}