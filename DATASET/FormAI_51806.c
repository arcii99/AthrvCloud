//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // Welcome message
    printf("Hello, I am the Wi-Fi Signal Strength Analyzer! Let's get started.\n\n");
    
    // Gathering network information
    printf("Please enter the name of the Wi-Fi network you want to analyze: ");
    char network[50];
    fgets(network,50,stdin);
    network[strcspn(network,"\n")]='\0'; // Removing the new line character
    printf("\n");
    
    // Scanning for the network and displaying signal strength
    printf("Scanning for Wi-Fi networks...\n");
    srand(time(NULL));
    int signal_strength = rand()%101; // Generating a random signal strength between 0-100
    printf("Signal strength for %s: %d%%\n\n", network, signal_strength);
    
    // Analyzing signal strength and making recommendations
    if(signal_strength >= 80){
        printf("Excellent signal strength! You can work smoothly on this network.\n\n");
    }
    else if(signal_strength >= 60){
        printf("Good signal strength! You might face some occasional disruptions but overall should work fine.\n\n");
    }
    else if(signal_strength >= 40){
        printf("Average signal strength! You may face connectivity issues and slow speeds.\n\n");
    }
    else{
        printf("Poor signal strength! You will experience frequent connectivity issues and slow speeds. Please try moving closer to the router or connecting to a different network.\n\n");
    }
    
    // Thank you message
    printf("Thank you for using the Wi-Fi Signal Strength Analyzer.\n");
    
    return 0; // End of program
}