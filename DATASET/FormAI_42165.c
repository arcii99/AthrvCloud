//FormAI DATASET v1.0 Category: Temperature monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float current_temp = 25.0;
    float temp_threshold = 30.0;
    srand(time(0));
    printf("Welcome to the Future Temperature Monitor\n");
    printf("Current Temperature: %.1fC\n", current_temp);

    while (1) {
        int rand_num = rand() % 20;
        float rand_temp = (((float)rand_num) / 10.0);
        if (rand() % 2 == 0) {
            current_temp += rand_temp;
        } else {
            current_temp -= rand_temp;
        }

        if (current_temp >= temp_threshold) {
            printf("WARNING: Temperature threshold reached!\n");
        }
        printf("Current Temperature: %.1fC\n", current_temp);
        sleep(1);
    }
    return 0;
}