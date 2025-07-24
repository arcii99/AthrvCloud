//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() 
{
    //Getting the current time and date
    time_t currentTime;
    time(&currentTime);
    
    //Displaying current time and date
    printf("Current time and date: %s", ctime(&currentTime));
    
    //Generating a random signal strength value from 0 to 100
    srand(time(0));
    int signalStrength = rand() % 101;
    
    //Displaying the generated signal strength value
    printf("Signal strength: %d\n", signalStrength);
    
    //Checking the signal strength range and displaying appropriate message
    if(signalStrength >= 0 && signalStrength <= 20)
        printf("Signal strength is very poor. Please move closer to the Wi-Fi router.\n");
    else if(signalStrength > 20 && signalStrength <= 40)
        printf("Signal strength is poor. Try moving closer to the Wi-Fi router.\n");
    else if(signalStrength > 40 && signalStrength <= 60)
        printf("Signal strength is fair. You may face some issues while streaming or downloading.\n");
    else if(signalStrength > 60 && signalStrength <= 80)
        printf("Signal strength is good. You should not face any issues while using the internet.\n");
    else
        printf("Signal strength is excellent. You can stream and download without any issues.\n");
    
    return 0;
}