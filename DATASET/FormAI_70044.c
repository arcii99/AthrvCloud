//FormAI DATASET v1.0 Category: Temperature monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 40
#define MIN_TEMP 10

int main() {
    float temperature = 0;
    srand(time(NULL));
    int i;

    for (i=0; i<10; i++) {
        temperature = (float)(rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP);
        printf("Temperature %d: %.2f Celsius\n", i+1, temperature);
    }

    return 0;
}