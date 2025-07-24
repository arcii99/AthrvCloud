//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int signalStrength[10];
    int i, totalStrength = 0;
    float averageStrength;
    srand(time(0));

    printf("Welcome to the Wi-Fi signal strength analyzer!\n");

    for(i=0; i<10; i++)
    {
        signalStrength[i] = rand()%101;
        totalStrength += signalStrength[i];
    }

    averageStrength = (float)totalStrength/10;

    printf("Signal Strengths: ");
    for(i=0; i<10; i++)
    {
        printf("%d ", signalStrength[i]);
    }

    printf("\nAverage Signal Strength: %.2f\n", averageStrength);

    if(averageStrength >= 70)
    {
        printf("Wow! You have an Excellent Wi-Fi signal, Keep it Up!\n");
    }
    else if(averageStrength >= 40 && averageStrength < 70)
    {
        printf("Good Signal Strength! You can browse without any problem.\n");
    }
    else
    {
        printf("Poor Signal Strength! Please move your device close to the router or get a signal booster.\n");
    }

    return 0;
}