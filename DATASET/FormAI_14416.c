//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    int i, j, light;

    // Loop infinitely
    while (1) {
        // Switch between the three traffic lights
        for (light = 0; light < 3; light++) {

            // Green Light
            if (light == 0) {
                printf("\nGreen Light\n");
                printf("Cars can go ahead\n");
                for (i = 10; i >= 1; i--) {
                    printf("Remaining time for green light: %d\n", i);
                    sleep(1);
                }
            }

            // Yellow Light
            if (light == 1) {
                printf("\nYellow Light\n");
                printf("Cars should be ready to stop\n");
                for (j = 3; j >= 1; j--){
                    printf("Remaining time for yellow light: %d\n", j);
                    sleep(1);
                }
            }

            // Red Light
            if (light == 2) {
                printf("\nRed Light\n");
                printf("Cars Should Stop\n");
                for (i = 15; i >= 1; i--) {
                    printf("Remaining time for red light: %d\n", i);
                    sleep(1);
                }
            }
        }
    }
    return 0;
}