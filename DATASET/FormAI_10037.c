//FormAI DATASET v1.0 Category: Color Code Converter ; Style: curious
#include<stdio.h>
#include<stdlib.h>

void main(){

    // Declare variables 
    int r,g,b;

    // Welcome user with a friendly message
    printf("Hello there! Let's convert some color codes today!");

    // Prompt user for input
    printf("\nEnter the red, green, and blue values separated by spaces: ");
    scanf("%d %d %d",&r,&g,&b);

    // Check if the input values are within the range
    if(r>=0 && r<=255 && g>=0 && g<=255 && b>=0 && b<=255){
        // Convert to hex
        int hexValue = (r << 16) + (g << 8) + b; // bitwise operations
        printf("\nThat's an awesome color! Here's the hex value: #%06X\n", hexValue);
    }
    else{
        // Notify user of invalid input
        printf("\nInvalid color code! Please enter values between 0 and 255.\n");
    }
    // Say goodbye to the user
    printf("\nThank you for using our color code converter. Have a great day!\n");
}