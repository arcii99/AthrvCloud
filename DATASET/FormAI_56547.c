//FormAI DATASET v1.0 Category: Temperature monitor ; Style: medieval
#include <stdio.h>

int main()
{
    int temperature = 0;
    char weather_condition[50];
    printf("What be the outside temperature, good sir/madam? ");
    scanf("%d", &temperature);
    printf("And what be the weather condition?");
    scanf("%s", weather_condition);

    printf("\n\nHark! The temperature outside is %d degrees and the weather condition is %s.\n", temperature, weather_condition);

    if (temperature <= 0)
    {
        printf("Methinks it be freezing outside!\n");
    }
    else if (temperature > 0 && temperature <= 15)
    {
        printf("It's quite chilly outside!\n");
    }
    else if (temperature > 15 && temperature <= 25)
    {
        if (strcmp(weather_condition, "Rain") == 0 || strcmp(weather_condition, "rain") == 0)
        {
            printf("Looks like it be raining outside, be sure to grab thy umbrella!\n");
        }
        printf("Aye, it's a pleasant day!\n");
    }
    else if (temperature > 25 && temperature <= 35)
    {
        printf("It's quite warm outside, perhaps a glass of mead?\n");
    }
    else if (temperature > 35)
    {
        printf("By the gods, it's scorching outside!\n");
    }

    return 0;
}