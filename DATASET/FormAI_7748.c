//FormAI DATASET v1.0 Category: Temperature monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    float temp;
    bool alarm = false;

    printf("Enter the current temperature in Celsius: ");
    scanf("%f", &temp);
    
    if(temp > 100 || temp < 0){
        alarm = true;
    }

    if(alarm){
        printf("ALERT! Temperature out of range.\n");
    } else {
        printf("Temperature within acceptable range.\n");
    }

    return 0;
}