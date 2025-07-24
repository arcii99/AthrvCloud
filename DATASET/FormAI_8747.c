//FormAI DATASET v1.0 Category: Temperature monitor ; Style: intelligent
#include<stdio.h>

int main()
{
    float temp;
    
    printf("Please enter the current temperature in Celsius: ");
    scanf("%f", &temp);
    
    if(temp < -273.15)
    {
        printf("Error! Temperature cannot be less than -273.15 degrees Celsius.");
    }
    else if(temp == -273.15)
    {
        printf("Absolute zero, no molecular movement.");
    }
    else if(temp <= 0)
    {
        printf("It is very cold today! Better wear a jacket.");
    }
    else if(temp > 0 && temp <= 25)
    {
        printf("The temperature is moderate today.");
    }
    else if(temp > 25 && temp <= 35)
    {
        printf("It is quite warm today! Better stay hydrated.");
    }
    else
    {
        printf("It is very hot today! Better stay indoors or near a pool!");
    }
    
    return 0;
}