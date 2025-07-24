//FormAI DATASET v1.0 Category: Temperature monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* function prototypes */
float get_random_temperature();
void display_temperature(float);

int main()
{
    float current_temperature;
    srand(time(0)); // seed the random number generator with current time

    /* run the program indefinitely until cancelled */
    while (1)
    {
        current_temperature = get_random_temperature();
        display_temperature(current_temperature);
        sleep(1); // wait 1 second before displaying next temperature
    }

    return 0;
}

/* function definitions */

/* generates a random temperature between 0 to 100 degree Celsius */
float get_random_temperature()
{
    float temperature;

    temperature = (float)(rand() % 101); // generate random number between 0 to 100
    temperature += ((float)(rand() % 11)) / 10; // add a decimal point with random fraction value
    return temperature;
}

/* displays the current temperature with appropriate messages */
void display_temperature(float temperature)
{
    printf("\nCurrent Temperature: %.1f degree Celsius\n", temperature);

    if (temperature <= 0)
    {
        printf("Brrr!! Extremely cold outside.\n");
    }
    else if (temperature > 0 && temperature <= 10)
    {
        printf("It's chilly outside.\n");
    }
    else if (temperature > 10 && temperature <= 20)
    {
        printf("It's moderately cool outside.\n");
    }
    else if (temperature > 20 && temperature <= 30)
    {
        printf("It's warm outside.\n");
    }
    else if (temperature > 30 && temperature <= 40)
    {
        printf("It's hot outside.\n");
    }
    else
    {
        printf("Phew!! Extremely hot outside.\n");
    }
}