//FormAI DATASET v1.0 Category: Temperature monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int temperature;
    printf("Enter the current temperature: ");
    scanf("%d", &temperature);
    if (temperature < 0)
    {
        printf("It's freezing outside.\n");
    }
    else if (temperature <= 10)
    {
        printf("It's very cold outside.\n");
    }
    else if (temperature <= 20)
    {
        printf("It's cool outside.\n");
    }
    else if (temperature <= 30)
    {
        printf("It's warm outside.\n");
    }
    else if (temperature <= 40)
    {
        printf("It's hot outside.\n");
    }
    else
    {
        printf("It's scorching outside.\n");
    }

    return 0;
}