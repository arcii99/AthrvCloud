//FormAI DATASET v1.0 Category: Weather simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // random number generator seed
    srand(time(0));

    // set the range of temperatures and conditions
    int minTemp = 50;
    int maxTemp = 85;
    char *conditions[] = {"clear", "partly cloudy", "cloudy", "rainy"};

    // generate random temperature and condition
    int temperature = rand() % (maxTemp - minTemp + 1) + minTemp;
    int conditionIndex = rand() % 4;
    char *condition = conditions[conditionIndex];

    // print temperature and condition
    printf("Temperature: %d degrees Fahrenheit\n", temperature);
    printf("Conditions: %s\n", condition);

    // print recommendations based on conditions
    printf("\nRecommendations:\n");
    if (temperature >= 80) {
        printf("- Stay hydrated\n");
        printf("- Avoid exerting yourself outdoors\n");
    } else if (temperature >= 70) {
        printf("- Wear sunscreen\n");
        printf("- Stay cool and take breaks if needed\n");
    } else if (temperature >= 60) {
        printf("- Bring a light jacket\n");
        printf("- Enjoy the nice weather!\n");
    } else {
        printf("- Wear a jacket or coat\n");
        printf("- Stay dry and avoid prolonged outdoor exposure\n");
    }

    // print road condition based on precipitation
    if (conditionIndex == 3) {
        printf("\nRoad Conditions: slippery\n");
    } else {
        printf("\nRoad Conditions: clear\n");
    }

    return 0;
}