//FormAI DATASET v1.0 Category: Weather simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 50
#define MIN_TEMP -20

int main() {
    srand(time(NULL)); // initialize random seed
    
    // Declare variables
    int romeo_temp, juliet_temp, current_temp = 0, difference;
    bool romeo_cold = false, juliet_cold = false;
    
    // Generate random temperatures for Romeo and Juliet
    romeo_temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
    juliet_temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
    
    // Check if Romeo is cold and print corresponding message
    if (romeo_temp < 0) {
        printf("Romeo: My love, I feel so cold. The temperature is only %d degrees Celsius.\n", romeo_temp);
        romeo_cold = true;
    } else {
        printf("Romeo: My love, it's a beautiful day today. The temperature is %d degrees Celsius.\n", romeo_temp);
    }
    
    // Check if Juliet is cold and print corresponding message
    if (juliet_temp < 0) {
        printf("Juliet: Oh Romeo, I feel so cold. The temperature is only %d degrees Celsius.\n", juliet_temp);
        juliet_cold = true;
    } else {
        printf("Juliet: My love, it's a lovely day today. The temperature is %d degrees Celsius.\n", juliet_temp);
    }
    
    // Determine the current temperature based on the average of Romeo and Juliet's temperatures
    current_temp = (romeo_temp + juliet_temp) / 2;
    
    // Determine the difference between the current temperature and the minimum temperature
    difference = MIN_TEMP - current_temp;
    
    // Check if Romeo or Juliet are too cold or too hot and print corresponding message
    if (romeo_cold && juliet_cold) {
        printf("Romeo: My love, we should find shelter. The temperature is %d degrees too low.\n", difference);
        printf("Juliet: Yes Romeo, let's find somewhere warm to stay.\n");
    } else if (romeo_cold) {
        printf("Romeo: My love, you are so warm compared to me. The temperature is %d degrees too low.\n", difference);
        printf("Juliet: My poor Romeo, let's find a way to keep you warm.\n");
    } else if (juliet_cold) {
        printf("Juliet: My love, I feel like I'm freezing. The temperature is %d degrees too low.\n", difference);
        printf("Romeo: Fear not, my dear. Let me keep you warm.\n");
    } else if (current_temp < MIN_TEMP) {
        printf("Romeo: My love, the temperature is %d degrees too low. We need to find shelter.\n", difference);
        printf("Juliet: Yes, Romeo. Let's find a warm place to stay.\n");
    } else if (current_temp > MAX_TEMP) {
        printf("Romeo: My love, it's so warm today. The temperature is %d degrees too high.\n", difference);
        printf("Juliet: I know, Romeo. Is there a place we can cool down?\n");
    } else {
        printf("Romeo: My love, the temperature is perfect today.\n");
        printf("Juliet: Yes, Romeo. It's a beautiful day for us.\n");
    }
    
    return 0; // end program
}