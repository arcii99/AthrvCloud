//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: random
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, m;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of m: ");
    scanf("%d", &m);

    int subnet = n ^ m; //calculating the subnet
    printf("The subnet mask is: %d", subnet);
    printf("\n");

    int bits = 0;
    for(int i=31; i>=0; i--)
    {
        if(subnet & (1 << i)) //checking the set bit
        {
            bits++;
        }
    }

    printf("The number of subnets is: %d", 1 << bits); //calculating the number of subnets
    printf("\n");

    int hosts = 32 - bits - 2; //calculating the number of hosts
    printf("The number of hosts per subnet is: %d", (1 << hosts));
    printf("\n");

    return 0;
}