//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: scalable
#include <stdio.h>

int main()
{   
    //Variables Initialization
    float principleAmount, rateOfInterest, tenure;
    float totalAmountPayable, EMI;
    int months;
    
    //User Input
    printf("Enter the Principal amount: ");
    scanf("%f", &principleAmount);
    
    printf("Enter the Rate of Interest: ");
    scanf("%f", &rateOfInterest);
    
    printf("Enter the Tenure (in years): ");
    scanf("%f", &tenure);
    
    //Calculations
    totalAmountPayable = principleAmount * pow(1+(rateOfInterest/100),tenure);
    
    months = tenure * 12;
    EMI = totalAmountPayable / months;
    
    //Output
    printf("\nTotal Amount Payable: %.2f", totalAmountPayable);
    printf("\nEMI (per month): %.2f", EMI);

    return 0;
}