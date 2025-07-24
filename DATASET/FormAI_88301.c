//FormAI DATASET v1.0 Category: Weather simulation ; Style: intelligent
#include <stdio.h> 

int main() 
{ 
    //DECLARE VARIABLES
    int temperature, wind_speed;
    double wind_chill_index;
    
    //ASK USER FOR INPUT
    printf("Enter temperature in Fahrenheit: ");
    scanf("%d", &temperature);
    printf("Enter wind speed in miles per hour: ");
    scanf("%d", &wind_speed);
    
    //CALCULATE WIND CHILL INDEX
    wind_chill_index = 35.74 + (0.6215 * temperature) - (35.75 * (pow(wind_speed, 0.16))) + (0.4275 * temperature * (pow(wind_speed, 0.16)));
    
    //PRINT RESULT
    printf("The wind chill index is %.2lf\n", wind_chill_index);
    
    return 0; 
}