//FormAI DATASET v1.0 Category: Temperature monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>

float temp[7]; //declare an array to store 7 temperature readings
int counter=0; //initialize the counter variable to 0

int main()
{
    printf("---Temperature Monitor---\n");
    while(1) //start an infinite loop to continuously take temperature readings
    {
        float reading;
        printf("Enter temperature reading: ");
        scanf("%f",&reading); //take temperature input

        if(reading<-273) //check if temperature input is below absolute zero
        {
            printf("Temperature below absolute zero!\n");
            continue; //skip this reading and ask for another reading
        }

        temp[counter]=reading; //add reading to the array
        counter++; //increment the counter variable

        if(counter==7) //once 7 readings are taken, display the statistics
        {
            float sum=0, avg, min=temp[0], max=temp[0];
            int i;
            for(i=0;i<7;i++)
            {
                sum+=temp[i];
                if(temp[i]<min) min=temp[i];
                if(temp[i]>max) max=temp[i];
            }
            avg=sum/7;
            printf("Statistics:\n");
            printf("Average temperature: %.2f\n",avg);
            printf("Minimum temperature: %.2f\n",min);
            printf("Maximum temperature: %.2f\n",max);

            counter=0; //reset the counter variable
        }
    }

    return 0;
}