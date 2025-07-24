//FormAI DATASET v1.0 Category: Temperature monitor ; Style: romantic
#include <stdio.h>

int main()
{
    int temp;
    printf("My dear, let me be your temperature monitor,\n");
    printf("I will keep you safe and make sure you stay warmer.\n");
    printf("Please tell me the temperature in Celsius,\n");
    printf("And I will convert it for you, my sweet princess.\n");
    
    scanf("%d", &temp);
    
    printf("You entered %d degrees Celsius, my love,\n", temp);
    printf("But don't you worry, I'm here to take care of you,\n");
    printf("Let me convert it to Fahrenheit, for you,\n");
    
    double fahr = (temp * 9.0 / 5.0) + 32.0;
    
    printf("The temperature in Fahrenheit is %.2lf, my dove.\n", fahr);
    printf("I will update you every hour, so don't be afraid,\n");
    printf("And while you stay warm and cozy, I'll be your maid.\n");
    
    return 0;
}