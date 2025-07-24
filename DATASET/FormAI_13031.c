//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Claude Shannon
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

//function declaration
double getAverage(double arr[], int size); 
double getSD(double data[], int size); 

int main(){
    //initialize variables
    double temperature[24];
    double mean, standardDeviation;
    int i;

    //generate random temperature readings for 24 hours
    srand(time(0)); 
    for (i = 0; i < 24; i++){
        temperature[i] = (rand() % (50 - 0 + 1)) + 0; //generate temperatures between 0 and 50 celsius
    }

    //print the temperature reading for each hour
    printf("Temperature readings for the last 24 hours:\n");
    for (i = 0; i < 24; i++){
        printf("Hour %d: %.1lf Celsius\n", i+1, temperature[i]);
    }

    mean = getAverage(temperature, 24); //calculate the mean temperature reading
    standardDeviation = getSD(temperature, 24); //calculate the standard deviation of the temperature readings

    //print the mean and standard deviation
    printf("\n");
    printf("The average temperature reading for the last 24 hours is: %.1lf Celsius\n", mean);
    printf("The standard deviation of the temperature readings for the last 24 hours is: %.2lf Celsius\n", standardDeviation);

    //determine if high temperature warning is necessary
    if(temperature[23] > (mean + 2*standardDeviation)){
        printf("\n");
        printf("WARNING: The temperature has exceeded the normal range and is too high!\n");
    }

    //determine if low temperature warning is necessary
    if(temperature[23] < (mean - 2*standardDeviation)){
        printf("\n");
        printf("WARNING: The temperature has fallen below the normal range and is too low!\n");
    }

    return 0;
}

double getAverage(double arr[], int size) {
   int i;
   double sum = 0;
   double avg;
 
   for (i = 0; i < size; i++) {
      sum += arr[i];
   }
 
   avg = sum / size;
   return avg;
}

double getSD(double data[], int size){
    double standardDeviation = 0.0;
    int i;
 
    for(i = 0; i < size; ++i){
        standardDeviation += pow(data[i] - getAverage(data, size), 2);
    }
 
    standardDeviation = sqrt(standardDeviation / size);
    return standardDeviation;
}