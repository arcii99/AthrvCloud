//FormAI DATASET v1.0 Category: Weather simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  //seed random number generator with current time
    
    int temperature = rand() % 51 - 20; 
    //generate a random temperature between -20 and 30 degrees Celsius
    
    printf("The temperature outside is %d degrees Celsius.\n", temperature);
    
    if (temperature > 30) {
        printf("It is scorching hot outside, stay cool!\n");
    } else if (temperature > 20) {
        printf("It is a warm day outside, enjoy the sunshine!\n");
    } else if (temperature > 10) {
        printf("It is a bit chilly outside, bring a light jacket!\n");
    } else if (temperature > -10) {
        printf("It is freezing outside, bundle up!\n");
    } else {
        printf("Stay indoors, it is dangerously cold outside!\n");
    }
    
    return 0;
}