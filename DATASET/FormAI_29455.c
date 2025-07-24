//FormAI DATASET v1.0 Category: Weather simulation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int temp, humidity;
    char sky[10];

    printf("Enter temperature: ");
    scanf("%d", &temp);

    printf("Enter humidity: ");
    scanf("%d", &humidity);

    if(temp<0 || temp>60 || humidity<0 || humidity>100)
    {
        printf("Invalid input\n");
        exit(0);
    }

    if(temp>=0 && temp<=30)
    {
        if(humidity>=0 && humidity<=50)
            strcpy(sky, "Sunny");
        else if(humidity>50 && humidity<=100)
            strcpy(sky, "Partly cloudy");
    }
    else if(temp>30 && temp<=40)
    {
        if(humidity>=0 && humidity<=50)
            strcpy(sky, "Partly cloudy");
        else if(humidity>50 && humidity<=100)
            strcpy(sky, "Cloudy");
    }
    else if(temp>40 && temp<=60)
    {
        if(humidity>=0 && humidity<=50)
            strcpy(sky, "Cloudy");
        else if(humidity>50 && humidity<=100)
            strcpy(sky, "Rainy");
    }

    printf("\nTemperature is %d, Humidity is %d and the weather is %s\n", temp, humidity, sky);

    return 0;
}