//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>

#define MAX_TEMP 50 // Maximum temperature limit

int main() {
    float temperature;
   
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &temperature);
    
    if(temperature > MAX_TEMP) { // Check the temperature 
        printf("Temperature is too high!\n");
        exit(0);
    }
    else {
        printf("Temperature is under the limit.\n");
    }
    
    return 0;
}