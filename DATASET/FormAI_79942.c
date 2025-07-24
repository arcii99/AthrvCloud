//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: irregular
#include <stdio.h>

int main()
{
    // Initializing variables
    int signalStrength;
    char signalQuality;

    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n\n");

    // Prompting user to input signal strength value
    printf("Please enter the Wi-Fi signal strength value (in dBm): ");
    scanf("%d", &signalStrength);

    // Evaluating the signal strength value and assigning signal quality based on dBm value
    if(signalStrength >= -30)
        signalQuality = 'E';
    else if(signalStrength >= -67)
        signalQuality = 'G';
    else if(signalStrength >= -70)
        signalQuality = 'F';
    else if(signalStrength >= -80)
        signalQuality = 'D';
    else if(signalStrength >= -90)
        signalQuality = 'C';
    else if(signalStrength >= -100)
        signalQuality = 'B';
    else
        signalQuality = 'A';

    // Displaying signal quality to the user
    printf("\nSignal Quality: %c\n", signalQuality);

    // Adding some humor
    printf("Remember, if your Wi-Fi signal quality is 'A', it stands for 'Awesome'!\n");

    return 0;
}