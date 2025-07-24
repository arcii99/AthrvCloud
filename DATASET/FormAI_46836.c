//FormAI DATASET v1.0 Category: Temperature monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int temperature = 0, max_temperature = 0, min_temperature = 100, average_temperature = 0;
    int count = 0;
    srand(time(NULL));
    printf("Welcome to the Medieval Temperature Monitor!\n");
    printf("You will be asked to input the temperature of your town:\n");
    while(temperature != -1){
        printf("Enter the temperature (enter -1 to exit): ");
        scanf("%d", &temperature);
        if(temperature == -1){
            break;
        }
        max_temperature = (temperature > max_temperature) ? temperature : max_temperature;
        min_temperature = (temperature < min_temperature) ? temperature : min_temperature;
        average_temperature += temperature;
        count++;
    }
    if(count == 0){
        printf("No temperature readings recorded. Fare thee well!\n");
        return 0;
    }

    average_temperature /= count;
    printf("The maximum temperature recorded was %d degrees Castleheit.\n", max_temperature);
    printf("The minimum temperature recorded was %d degrees Castleheit.\n", min_temperature);
    printf("The average temperature recorded was %d degrees Castleheit.\n", average_temperature);
    printf("Thank you for using our Medieval Temperature Monitor. Until next time!\n");
    return 0;
}