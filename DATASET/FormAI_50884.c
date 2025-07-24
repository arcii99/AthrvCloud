//FormAI DATASET v1.0 Category: Temperature monitor ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    float temp=0;
    srand(time(0)); //Initialize random number generator
    int i=0;
    while(i<20) //Display temperature 20 times
    {
        float random_num = (rand()%101)/10.0; //Generate a random number between 0-100 and divide by 10 to get a float number with one decimal place
        temp = temp + random_num; //Add the random number to the current temperature
        printf("Current temperature is: %.1f°C\n", temp/(i+1)); //Print average temperature till now
        i++;
        sleep(1); //Delay of 1 second before displaying temperature again
    }
    printf("Final temperature is: %.1f°C\n", temp/20); //Print final average temperature after 20 iterations
    return 0;
}