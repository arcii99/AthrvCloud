//FormAI DATASET v1.0 Category: Weather simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature[24]; //24 hour temperature array
    int i;
    srand((unsigned int)time(NULL));

    //generating random temperature values for 24 hours
    for(i = 0; i < 24; i++) {
        temperature[i] = (rand() % 60) - 20; //-20 to 40 degree Celsius range
    }

    //displaying temperature table
    printf("Hour\tTemperature\n");
    for(i = 0; i < 24; i++) {
        printf("%d:00\t%dC\n",i,temperature[i]);
    }

    //finding maximum and minimum temperature
    int max_temp = temperature[0], min_temp = temperature[0], hour_max, hour_min;
    for(i = 1; i < 24; i++) {
        if(temperature[i] > max_temp) {
            max_temp = temperature[i];
            hour_max = i;
        }
        if(temperature[i] < min_temp) {
            min_temp = temperature[i];
            hour_min = i;
        }
    }

    //displaying maximum and minimum temperature with corresponding hour
    printf("\nMaximum temperature of %dC was recorded at %d:00\n",max_temp,hour_max);
    printf("Minimum temperature of %dC was recorded at %d:00\n",min_temp,hour_min);

    return 0;
}