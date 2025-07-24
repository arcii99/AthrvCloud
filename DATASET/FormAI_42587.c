//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include<stdio.h>
#include<math.h>

/* A program to compute network subnetting based on user input */

int main() {
    int netMask, mask, subnetBits;
    long int network;
    char netClass;
  
    printf("Welcome to the medieval subnet calculator!\n\n");
    printf("Please enter the network mask here (in decimal form): ");
    scanf("%d", &netMask);

    if (netMask >= 8 && netMask <= 30) {
        mask = pow(2, 32 - netMask);
        subnetBits = log2(mask);
        if (netMask <= 23) {
            netClass = 'C';
            printf("This is Class %c network\n", netClass);
            printf("The subnet bits: %d\n", subnetBits);
            printf("\nEnter the network (in decimal form): ");
            scanf("%ld", &network);
            printf("You entered network: %ld\n\n", network);
            printf("Subnetting results:\n");
            long int i;
            for (i = 0; i < pow(2, subnetBits); i++) {
                printf("%ld - %ld\n", network+(i*mask), network+((i+1)*mask-1));
            }          
        } else if (netMask <= 15) {
            netClass = 'B';
            printf("This is Class %c network\n", netClass);
            printf("The subnet bits: %d\n", subnetBits);
            printf("\nEnter the network (in decimal form): ");
            scanf("%ld", &network);
            printf("You entered network: %ld\n\n", network);
            printf("Subnetting results:\n");
            long int i;
            for (i = 0; i < pow(2, subnetBits); i++) {
                printf("%ld - %ld\n", network+(i*mask), network+((i+1)*mask-1));
            }    
        } else {
            netClass = 'A';
            printf("This is Class %c network\n", netClass);
            printf("The subnet bits: %d\n", subnetBits);
            printf("\nEnter the network (in decimal form): ");
            scanf("%ld", &network);
            printf("You entered network: %ld\n\n", network);
            printf("Subnetting results:\n");
            long int i;
            for (i = 0; i < pow(2, subnetBits); i++) {
                printf("%ld - %ld\n", network+(i*mask), network+((i+1)*mask-1));
            }    
        }         
    } else {
        printf("\nInvalid network mask! Please enter masks between 8 and 30.\n");
    }
      
    printf("\nThank you for using our medieval subnet calculator program.\n");
    return 0;
}