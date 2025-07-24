//FormAI DATASET v1.0 Category: Weather simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int temperature = rand() % 61 - 20; // random temperature between -20 and 40 degrees Celsius
    int humidity = rand() % 101; // random humidity percentage between 0 and 100
    int pressure = rand() % 11 + 990; // random pressure between 990 and 1000 hPa
    
    printf("Today's weather conditions:\n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Pressure: %d hPa\n", pressure);
    
    if (temperature < 0) {
        printf("It's very cold outside!\n");
    } else if (temperature >= 0 && temperature <= 10) {
        printf("It's quite chilly outside.\n");
    } else if (temperature > 10 && temperature <= 20) {
        printf("It's a bit cool outside.\n");
    } else if (temperature > 20 && temperature <= 30) {
        printf("It's comfortably warm outside.\n");
    } else {
        printf("It's quite hot outside!\n");
    }
    
    if (humidity < 30) {
        printf("It's a bit dry outside.\n");
    } else if (humidity >= 30 && humidity <= 70) {
        printf("Humidity is at a comfortable level.\n");
    } else {
        printf("It's quite humid outside.\n");
    }
    
    if (pressure < 1000) {
        printf("The pressure seems to be low.\n");
    } else if (pressure >= 1000 && pressure <= 1010) {
        printf("The pressure seems to be normal.\n");
    } else {
        printf("The pressure seems to be high.\n");
    }
    
    return 0;
}