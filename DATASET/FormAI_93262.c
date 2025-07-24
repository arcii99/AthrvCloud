//FormAI DATASET v1.0 Category: Temperature monitor ; Style: happy
#include <stdio.h>

int main() {
    printf("\n**************************************************************");
    printf("\n* Welcome to the Happy Temperature Monitor Program!            *");
    printf("\n**************************************************************\n");
    
    float temp = 0;
    int count = 0;
    float avgTemp = 0;
    float sum = 0;
    while(count < 10) {
        printf("Please enter temperature reading #%d: ", count+1);
        scanf("%f",&temp);
        
        if(temp < -50 || temp > 150) {
            printf("Invalid temperature reading entered. Please enter a temperature between -50 and 150\n");
            continue;
        }
        
        sum += temp;
        count++;
    }
    
    avgTemp = sum/count;
    printf("\nThe average temperature is: %.2f\n", avgTemp);
    
    printf("\n**************************************************************");
    printf("\n*              Thank you for using our program!               *");
    printf("\n**************************************************************\n");
    
    return 0;
}