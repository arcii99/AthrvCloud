//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int signal_strength;
    printf("Enter Wi-Fi signal strength (0-100) : ");
    scanf("%d",&signal_strength);
    if(signal_strength < 0 || signal_strength > 100)
    {
        printf("Invalid signal strength entered\n");
        return 0;
    }
    float radius = pow(10,(27-(signal_strength/5.0)));
    printf("Signal radius : %.2f m\n",radius);

    if(radius < 1)
        printf("Strong signal\n");
    else if(radius < 10)
        printf("Average signal\n");
    else if(radius < 50)
        printf("Weak signal\n");
    else
        printf("No signal\n");

    return 0;
}