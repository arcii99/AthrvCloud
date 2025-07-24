//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to calculate Wi-Fi signal strength
int calculateSignalStrength(int signalStrength,int frequency){
    return 20*log10(frequency)-signalStrength;
}

int main(void){

    //Declaration of variables
    int signalStrength,frequency;
    char option;

    printf("Welcome to Wi-Fi Signal Strength Analyzer!\n");

    //Loop to keep the program running
    while(1){
        printf("\nEnter the Wi-Fi signal strength: ");
        scanf("%d",&signalStrength);

        printf("\nEnter the frequency: ");
        scanf("%d",&frequency);

        //Function call to calculate signal strength
        int calculatedStrength = calculateSignalStrength(signalStrength,frequency);

        //Print the calculated signal strength
        printf("\nCalculated Wi-Fi signal strength is: %d dBm\n",calculatedStrength);

        printf("\nDo you want to check another Wi-Fi signal strength? (y/n): ");
        scanf(" %c",&option);

        //Condition to break from the loop
        if(option == 'n' || option == 'N'){
            break;
        }
    }

    printf("\nThank you for using Wi-Fi Signal Strength Analyzer! Have a nice day!\n");

    return 0;
}