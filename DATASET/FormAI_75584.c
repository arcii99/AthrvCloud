//FormAI DATASET v1.0 Category: Temperature monitor ; Style: dynamic
#include<stdio.h>

int main()
{
    double temp[5];         //Creating an array to store 5 temperature values.
    double sum = 0;         //Initializing a variable to store the sum of temperature values.
    double avg;             //Initializing a variable to store the average of temperature values.

    //Taking input temperature values from the user.
    for(int i=0; i<5; i++)
    {
        printf("Enter temperature value %d: ", i+1);
        scanf("%lf", &temp[i]);
        sum += temp[i];                 //Adding the input temperature value to the sum variable.
    }

    avg = sum / 5;                      //Calculating the average temperature value.

    //Printing the temperature values and their deviation from the average value.
    printf("\nTemperature values and deviation from the average value:\n");
    for(int i=0; i<5; i++)
    {
        printf("%lf\t%lf\n", temp[i], temp[i]-avg);  //Printing each temperature value and its deviation from the average value.
    }

    return 0;
}