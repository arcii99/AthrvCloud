//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Ada Lovelace
// Ada Lovelace-style Temperature monitor program in C

#include <stdio.h>

int main() {
    float temp_c, temp_f;
    int hours, minutes, seconds;
    
    printf("Welcome to the Temperature Monitor Program\n");
    printf("-----------------------------------------\n");
    
    // Get temperature in Celcius
    printf("Please enter the current temperature in Celcius: ");
    scanf("%f", &temp_c);
    
    // Convert to Fahrenheit
    temp_f = (9.0 / 5.0) * temp_c + 32;
    
    printf("The current temperature is %.2f degrees Fahrenheit.\n", temp_f);
    
    // Get time input
    printf("Please enter the time in the format (HH:MM:SS): ");
    scanf("%d:%d:%d", &hours, &minutes, &seconds);
    
    printf("The time is %02d:%02d:%02d\n", hours, minutes, seconds);
    
    // Determine time of day
    char* time_of_day;
    if (hours < 12) {
        time_of_day = "morning";
    } else if (hours >= 12 && hours < 18) {
        time_of_day = "afternoon";
    } else {
        time_of_day = "evening";
    }
    
    printf("Good %s!\n", time_of_day);
    
    // Check temperature range
    if (temp_f < 60) {
        printf("It's too cold! Bundle up!\n");
    } else if (temp_f >= 60 && temp_f < 80) {
        printf("It's a comfortable temperature.\n");
    } else {
        printf("It's hot outside! Stay cool!\n");
    }
    
    return 0;
}