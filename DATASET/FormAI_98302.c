//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    printf("Welcome to Wi-Fi Signal Strength Analyzer!\n\n");

    //gather input from user
    printf("Enter the signal strength (in decibels): ");
    int signal_strength;
    scanf("%d", &signal_strength);

    //check if signal strength is within acceptable range
    if(signal_strength < -100 || signal_strength > 0){
        printf("Invalid signal strength input. Please enter a value between -100 and 0.\n");
        return 1;
    }

    //calculate the percentage of signal strength
    int signal_percentage = abs(signal_strength / 100);

    printf("The signal strength is %d%%.\n", signal_percentage);

    //determine signal quality based on signal percentage
    if(signal_percentage >= 75){
        printf("The signal strength is excellent!\n");
    }else if(signal_percentage < 75 && signal_percentage >= 50){
        printf("The signal strength is good.\n");
    }else if(signal_percentage < 50 && signal_percentage >= 25){
        printf("The signal strength is fair.\n");
    }else{
        printf("The signal strength is poor. Consider relocating your router or reconnecting to a closer network.\n");
    }

    return 0;
}