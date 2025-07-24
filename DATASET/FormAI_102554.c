//FormAI DATASET v1.0 Category: Weather simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 100
#define MIN_TEMPERATURE 0

int main() {
    srand(time(NULL));
    float temperature = MIN_TEMPERATURE + (float) rand() / RAND_MAX * (MAX_TEMPERATURE - MIN_TEMPERATURE);
    
    printf("Current temperature: %.2f°C\n", temperature);
    
    if (temperature >= 80) {
        printf("It's very hot outside, stay hydrated!");
    } else if (temperature >= 60 && temperature < 80) {
        printf("It's a nice day, enjoy it!");
    } else if (temperature >= 40 && temperature < 60) {
        printf("It's getting chilly, bring a jacket.");
    } else {
        printf("It's cold outside, bundle up!");
    }
    
    return 0;
}