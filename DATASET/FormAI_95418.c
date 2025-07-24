//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: curious
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int redDuration, greenDuration, yellowDuration;
    printf("Enter the duration for Red Light in seconds: ");
    scanf("%d", &redDuration); //Input duration for Red Light
    printf("Enter the duration for Green Light in seconds: ");
    scanf("%d", &greenDuration); //Input duration for Green Light
    printf("Enter the duration for Yellow Light in seconds: ");
    scanf("%d", &yellowDuration); //Input duration for Yellow Light

    while(1)
    {
        //Red Light
        printf("\nRed Light ON for %d seconds\n", redDuration);
        sleep(redDuration); //Delay for the Red Light duration

        //Yellow Light
        printf("\nYellow Light ON for %d seconds\n", yellowDuration);
        sleep(yellowDuration); //Delay for the Yellow Light duration

        //Green Light
        printf("\nGreen Light ON for %d seconds\n", greenDuration);
        sleep(greenDuration); //Delay for the Green Light duration

        //Yellow Light
        printf("\nYellow Light ON for %d seconds\n", yellowDuration);
        sleep(yellowDuration); //Delay for the Yellow Light duration
    }
    return 0;
}