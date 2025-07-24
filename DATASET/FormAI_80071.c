//FormAI DATASET v1.0 Category: Temperature monitor ; Style: energetic
#include<stdio.h>

int main()
{
    float temp;
    printf("Enter the current temperature in Celsius: ");
    scanf("%f",&temp); //user inputs temperature

    if(temp<=0) //if temperature is less than or equal to 0 degree Celsius
    {
        printf("\nIt's freezing outside, stay indoors!\n");
    }

    else if(temp>0 && temp<=10) //if temperature is greater than 0 and less than or equal to 10 degree Celsius
    {
        printf("\nIt's cold outside, wear a jacket!\n");
    }

    else if(temp>10 && temp<=22) //if temperature is greater than 10 and less than or equal to 22 degree Celsius
    {
        printf("\nIt's a nice day outside, enjoy it!\n");
    }

    else if(temp>22 && temp<=30) //if temperature is greater than 22 and less than or equal to 30 degree Celsius
    {
        printf("\nIt's warm and sunny outside, go out and have fun!\n");
    }

    else //if temperature is greater than 30 degree Celsius
    {
        printf("\nIt's too hot outside, stay indoors or cool off with some ice cream!\n");
    }

    return 0; //end of the program
}