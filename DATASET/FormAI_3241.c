//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SENSOR_COUNT 10 // number of sensors in the network
#define THRESHOLD 2.0 // threshold for intrusion detection

int main(){
    
    float values[SENSOR_COUNT]; // array to store sensor values
    float mean = 0.0, variance = 0.0, std_dev = 0.0; // values for statistical analysis
    
    // initialize random values for sensors
    for(int i=0; i<SENSOR_COUNT; i++){
        values[i] = rand() % 10 + 1;
        printf("Sensor %d value: %.2f\n", i+1, values[i]);
    }
    
    // calculate mean value of sensors
    for(int i=0; i<SENSOR_COUNT; i++){
        mean += values[i];
    }
    mean = mean/SENSOR_COUNT;
    
    // calculate variance of sensors
    for(int i=0; i<SENSOR_COUNT; i++){
        variance += pow(values[i]-mean, 2);
    }
    variance = variance/SENSOR_COUNT;
    
    // calculate standard deviation of sensors
    std_dev = sqrt(variance);
    
    // detect intrusion if standard deviation is greater than threshold
    if(std_dev > THRESHOLD){
        printf("\nIntrusion detected!\n");
    }else{
        printf("\nNo intrusion detected.\n");
    }
    
    return 0;
}