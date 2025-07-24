//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n\n");
    int signal_strength = 0;
    char* feedback;

    printf("Please enter the signal strength (0 to 100): ");
    scanf("%d", &signal_strength);

    if(signal_strength < 0 || signal_strength > 100)
    {
        printf("Invalid signal strength. Please enter a number between 0 and 100.\n");
        return 1;
    }

    if(signal_strength >= 90)
    {
        feedback = "Great! Your Wi-Fi signal is excellent!";
    }
    else if(signal_strength >= 70)
    {
        feedback = "Not bad! Your Wi-Fi signal is good.";
    }
    else if(signal_strength >= 50)
    {
        feedback = "Your Wi-Fi signal could be better. Consider moving closer to the router.";
    }
    else
    {
        feedback = "Poor signal strength. Your internet connection may be slow or unstable.";
    }

    printf("\nYour Wi-Fi signal strength is %d.\n%s\n", signal_strength, feedback);

    return 0;
}