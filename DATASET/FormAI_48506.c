//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define road_len 20   // Road length
#define max_speed 5   // Maximum speed limit
#define min_speed 1   // Minimum speed limit
#define car_density 0.4 // Car density on road

int car_count = 0;  // Number of cars currently on the road 

typedef struct car{
    int speed;
    int position;
} Car;

void initialize_road(Car* road) {
    int filled = 0;

    while (filled <= (int)(car_density * road_len)) {
      int position = rand() % road_len;

      if (road[position].speed == 0) {
        road[position].speed = min_speed + rand() % (max_speed - min_speed + 1);
        ++filled;
        ++car_count;
      }
  }
}

void update_positions(Car* road) {
    int i;
    for (i = 0; i < road_len; ++i) {
        if (road[i].speed != 0) {

            // Calculate distance to next car
            int next_car_distance = 1;
            int j;
            for (j = 1 ; j <= max_speed ; ++j) {
                if (road[(i+j) % road_len].speed != 0) {
                    next_car_distance = j;
                    break;
                }
            }

            // Check if car needs to slow down
            if (road[i].speed > next_car_distance) {
                --road[i].speed;
            } 

            // Check if car can speed up
            if (road[i].speed < max_speed) {
                int k;
                for (k = 1 ; k <= road[i].speed ; ++k) {
                    if (road[(i+k) % road_len].speed != 0) {
                        if (k-1 < road[i].speed) {
                            ++road[i].speed;
                        }
                        break;
                    }
                }
            }

            // Calculate new position
            road[i].position = (i + road[i].speed) % road_len;
        }
    }
}

void draw_road(Car* road) {
    int i,j;
    for (i = road_len - 1; i >= 0; --i) {
        if (road[i].speed > 0) {
            printf("C");
        }
        else {
            printf("-");
        } 
    } 
    printf("\n");
}

int main() {
    srand(time(NULL));  // Seed random number generator

    Car road[road_len];
    int i;

    // Initialize road with cars
    for (i = 0; i < road_len; ++i) {
        road[i].speed = 0;
        road[i].position = i;
    }

    initialize_road(road);

    // Simulation loop
    for (i = 0; i < 10; ++i) {
        draw_road(road);
        update_positions(road);
    }

    printf("Number of cars on road: %d\n", car_count);
    return 0;
}