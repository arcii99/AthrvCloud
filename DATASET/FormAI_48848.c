//FormAI DATASET v1.0 Category: Temperature monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define THRESHOLD 25 // temperature threshold value

int main() {
    srand(time(0)); // seed the random generator
    
    // initialization
    int temp, max_temp = -273, min_temp = 1000000, sum_temp = 0;
    int count = 0, above_thresh = 0, below_thresh = 0;
    float avg_temp;
    
    // prompt user for number of temperature readings
    printf("Enter the number of temperature readings: ");
    scanf("%d", &count);
    
    // generate and display temperatures
    printf("\nTemperature Readings:\n");
    for(int i = 0; i < count; i++) {
        temp = -50 + rand() % 100; // random temperature between -50 and 50
        
        // update statistics
        if(temp > max_temp) max_temp = temp;
        if(temp < min_temp) min_temp = temp;
        sum_temp += temp;
        if(temp > THRESHOLD) above_thresh++;
        else below_thresh++;
        
        printf("%d ", temp);
    }
    
    // calculate and display statistics
    avg_temp = (float)sum_temp / count;
    printf("\n\nTemperature Statistics:\n");
    printf("Maximum: %d\nMinimum: %d\nAverage: %.2f\n", max_temp, min_temp, avg_temp);
    printf("Readings above threshold: %d\nReadings below threshold: %d\n", above_thresh, below_thresh);
    
    return 0;
}