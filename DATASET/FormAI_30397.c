//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Sherlock Holmes
#include <stdio.h>

int main()
{
    int data, checksum = 0xFEEDBEEF; //mask to be applied
    
    printf("Welcome, detective. I see that you are in need of a checksum calculator. I'm not one for flattery, but I must say that you are quite clever for observing such a feature.\n");
    
    printf("Please enter the data for checksum calculation (in hexadecimal format): ");
    
    for(int i = 0; i < 10; i++)
    {
        scanf("%x", &data);
        checksum ^= data; //applying mask
    }
    
    printf("Detective, we shall now mask the data. This process is the most important step since it will reveal any fingerprints left on the evidence. This is where we can uncover the true nature of our prime suspect. We will add up all the bits in our data and apply the 'XOR' operator. The result will be the masked evidence that we will use to uncover the checksum.\n");
    
    printf("The checksum value for your data is: %X\n", checksum);
    printf("Elementary, my dear detective. We have successfully calculated the checksum value for your input data. I now proclaim that the mystery has been solved.\n");
    
    return 0;
}