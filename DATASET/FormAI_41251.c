//FormAI DATASET v1.0 Category: Temperature monitor ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL)); //initialize random seed

    int temp = rand() % 41 - 10; //generate random temperature between -10 and 30
    printf("The current temperature is %d degrees Celsius.\n", temp);

    if(temp < 0)
    {
        printf("It's freezing outside! Wear warm clothes.\n");
    }
    else if(temp < 10)
    {
        printf("It's cold outside. Wear a jacket.\n");
    }
    else if(temp < 20)
    {
        printf("It's cool outside. Enjoy the weather.\n");
    }
    else if(temp < 30)
    {
        printf("It's warm outside. Wear something light.\n");
    }
    else
    {
        printf("It's hot outside! Stay hydrated.\n");
    }

    return 0;
}