//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANES 3
#define MAX_CARS 10
#define CAR_LENGTH 3
#define CAR_SPACING 2
#define SIM_DURATION 60

typedef struct {
    int lane;
    int position;
} Car;

int main() {
    Car cars[MAX_CARS];
    int num_cars = 0;

    srand(time(NULL));

    for (int t = 0; t < SIM_DURATION; t++) {
        // add new car to first lane with probability 0.25
        if (num_cars < MAX_CARS && rand() / (double)RAND_MAX < 0.25) {
            cars[num_cars].lane = 0;
            cars[num_cars].position = CAR_LENGTH + CAR_SPACING;
            num_cars++;
        }

        // move cars forward
        for (int i = 0; i < num_cars; i++) {
            Car *car = &cars[i];
            if (car->position + CAR_SPACING < 100) {
                car->position += 1;
            }
        }

        // change lanes with probability 0.1
        for (int i = 0; i < num_cars; i++) {
            Car *car = &cars[i];
            int next_lane = (car->lane + rand() % 3 - 1 + NUM_LANES) % NUM_LANES;
            int next_pos = car->position;
            for (int j = 0; j < num_cars; j++) {
                if (i != j && cars[j].lane == next_lane &&
                        cars[j].position > next_pos-CAR_LENGTH-CAR_SPACING &&
                        cars[j].position < next_pos+CAR_LENGTH+CAR_SPACING) {
                    next_pos = cars[j].position + CAR_LENGTH + CAR_SPACING;
                }
            }
            car->lane = next_lane;
            car->position = next_pos;
        }

        // print current state
        printf("t=%d\n", t);
        for (int lane = 0; lane < NUM_LANES; lane++) {
            for (int pos = 0; pos < 100; pos++) {
                char c = '-';
                for (int i = 0; i < num_cars; i++) {
                    Car *car = &cars[i];
                    if (car->lane == lane && car->position == pos) {
                        c = 'X';
                        break;
                    } else if (car->lane == lane &&
                            car->position > pos - CAR_LENGTH &&
                            car->position < pos + CAR_SPACING) {
                        c = '=';
                        break;
                    }
                }
                putchar(c);
            }
            putchar('\n');
        }
    }

    return 0;
}