//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initializing random seed
    
    int signal_strength = rand() % 101; // generating random signal strength
    
    printf("Ye olde Wi-Fi Signal Strength Analyzer\n");
    printf("--------------------------------------\n");
    
    if(signal_strength >= 90)
        printf("Hark! The signal strength be excellent! A great day for streaming ye favorite shows!\n");
    else if(signal_strength >= 70)
        printf("The Wi-Fi signal strength be good enough for browsing! Keep calm and carry on!\n");
    else if(signal_strength >= 50)
        printf("The signal strength be fair, but it may be slow. Take a few paces nearer to the router, methinks!\n");
    else
        printf("Alack! The signal be weak! Thou must move nearer to the router or suffer buffering and lag!\n");
    
    printf("--------------------------------------\n");
    printf("Ye signal strength be: %d\n", signal_strength);
    
    return 0;
}