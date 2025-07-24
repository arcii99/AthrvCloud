//FormAI DATASET v1.0 Category: Weather simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed the random generator using current time
    
    int temperature = rand() % 61 - 30; // generate a random temperature between -30 and 30 degrees Celsius
    int precipitation = rand() % 101; // generate a random precipitation percentage between 0 and 100
    
    printf("Current temperature: %d C\n", temperature);
    printf("Current precipitation: %d %%\n", precipitation);

    if (temperature < 0 && precipitation > 50) { // if temperature is below freezing and there is more than 50% precipitation
        printf("WARNING: Ice storm detected. Stay inside and avoid driving!\n");
    }
    else if (temperature < 0 && precipitation <= 50) { // if temperature is below freezing but there is less than or equal to 50% precipitation
        printf("WARNING: Black ice possible. Use caution when driving!\n");
    }
    else if (temperature >= 0 && temperature <= 15 && precipitation > 50) { // if temperature is between 0 and 15 degrees Celsius and there is more than 50% precipitation
        printf("WARNING: Heavy rain expected. Flooding possible. Stay alert!\n");
    }
    else if (temperature >= 0 && temperature <= 15 && precipitation <= 50) { // if temperature is between 0 and 15 degrees Celsius but there is less than or equal to 50% precipitation
        printf("WARNING: Light rain possible. Use caution when driving!\n");
    }
    else if (temperature > 15 && precipitation > 50) { // if temperature is above 15 degrees Celsius and there is more than 50% precipitation
        printf("WARNING: Thunderstorm expected. Stay indoors and away from windows!\n");
    }
    else { // if temperature is above 15 degrees Celsius and there is less than or equal to 50% precipitation
        printf("It's a pleasant day. Enjoy the weather!\n");
    }

    return 0;
}