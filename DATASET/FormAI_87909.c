//FormAI DATASET v1.0 Category: Temperature monitor ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL));
    float temp = 0, avg = 0, max = -273.0, min = 1000.0;
    char* status;

    printf("**** Temperature Monitor ****\n\n");

    for(int i = 1; i <= 10; i++){
        temp = (float)(rand() % 100) - 50;
        avg += temp;
        if(temp > max){
            max = temp;
        }
        if(temp < min){
            min = temp;
        }

        if(temp <= -20){
            status = "Extremely Cold";
        }
        else if(temp > -20 && temp <= 0){
            status = "Cold";
        }
        else if(temp > 0 && temp <= 10){
            status = "Cool";
        }
        else if(temp > 10 && temp <= 20){
            status = "Mild";
        }
        else if(temp > 20 && temp <= 30){
            status = "Warm";
        }
        else if(temp > 30 && temp <= 40){
            status = "Hot";
        }
        else{
            status = "Extremely Hot";
        }

        printf("Temperature Reading %d: %.2f°C (%s)\n", i, temp, status);
    }

    avg /= 10.0;
    printf("\nAverage Temperature: %.2f°C\n", avg);
    printf("Maximum Temperature: %.2f°C\n", max);
    printf("Minimum Temperature: %.2f°C\n", min);

    return 0;
}