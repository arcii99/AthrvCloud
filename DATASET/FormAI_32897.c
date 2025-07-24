//FormAI DATASET v1.0 Category: Temperature monitor ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

//User Defined Constants for the Program
#define MAX_TEMP_LIMIT 100.0
#define MIN_TEMP_LIMIT 0.0
#define TEMP_SENSOR_ACCURACY 0.5

//Function Prototypes
double getTemperature();
void display(double temp);

int main(){
    int i;
    double temperature[10];
    double avgTemp = 0, variance = 0, sd = 0;
    
    srand(time(0));         //Seed for Random Number Generator
    
    printf("**********Temperature Monitor***********\n\n");
    
    //Loop to read the temperature values
    for(i=0; i<10; i++){
        temperature[i] = getTemperature();
        display(temperature[i]);
        avgTemp += temperature[i];
    }
    avgTemp /= 10.0;            //Calculating Average Temperature
    
    //Loop to calculate Variance
    for(i=0; i<10; i++){
        variance += pow((temperature[i] - avgTemp), 2);
    }
    variance /= 10.0;           //Calculating Variance
    
    sd = sqrt(variance);        //Calculating Standard Deviation
    
    printf("\nAverage Temperature: %.2lf degree Celsius\n", avgTemp);
    printf("Variance: %.2lf\n", variance);
    printf("Standard Deviation: %.2lf\n", sd);
    
    return 0;
}

//Function to generate random temperature value based on defined limits and accuracy
double getTemperature(){
    double temp;
    temp = (rand() / (double)RAND_MAX) * MAX_TEMP_LIMIT;
    temp = floor(temp * (1/TEMP_SENSOR_ACCURACY) ) / (1/TEMP_SENSOR_ACCURACY);
    if(temp < MIN_TEMP_LIMIT){
        temp = MIN_TEMP_LIMIT;
    }
    return temp;
}

//Function to display the temperature value
void display(double temp){
    printf("Temperature: %.2lf degree Celsius\n", temp);
}