//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_CARS 50
#define MAX_TIME 300
#define DELAY_SEC 1

struct Car {
    int speed;
    int position;
};

struct Road {
    int total_cars;
    int end_pos;
    struct Car cars[MAX_CARS];
};

void initialize_roads(struct Road *r, int total_roads) {
    for(int i=0; i<total_roads; i++) {
        r[i].total_cars = 0;
        r[i].end_pos = rand() % 50 + 50;
        for(int j=0; j<MAX_CARS; j++) {
            r[i].cars[j].position = -1;
        }
    }
}

void update_cars(struct Road *r) {
    for(int i=0; i<r->total_cars; i++) {
        if(r->cars[i].position < r->end_pos) {
            r->cars[i].position += r->cars[i].speed;
        }
    }
}

void move_cars(struct Road *r) {
    for(int i=0; i<r->total_cars; i++) {
        int new_pos = r->cars[i].position + r->cars[i].speed;
        if(new_pos > r->end_pos) {
            r->total_cars--;
            for(int j=i; j<r->total_cars; j++) {
                r->cars[j] = r->cars[j+1];
            }
        }
        else if(new_pos < r->cars[i+1].position) {
            r->cars[i].position = new_pos;
        }
        else {
            r->cars[i].speed = r->cars[i+1].speed;
            r->cars[i].position = r->cars[i+1].position - 1;
        }
    }
}

void display_roads(struct Road *r, int total_roads) {
    printf("\nCurrent Status of the roads\n");
    printf("============================\n");
    for(int i=0; i<total_roads; i++) {
        printf("Road %d: ", i+1);
        for(int j=0; j<=r[i].end_pos; j++) {
            if(j == r[i].end_pos) {
                printf("|");
            }
            else if(j == r[i].cars[0].position) {
                printf("%d", r[i].cars[0].speed);
            }
            else if(j == r[i].cars[1].position) {
                printf("%d", r[i].cars[1].speed);
            }
            else {
                printf("-");
            }
        }
        printf("\n");
    }
}

int main() {

    srand(time(NULL));
    struct Road roads[3];
    int total_roads = 3;
    int current_time = 0;

    initialize_roads(roads, total_roads);

    while(current_time < MAX_TIME) {
        printf("Time = %d\n", current_time);
        for(int i=0; i<total_roads; i++) {
            if(rand() % 2 == 0) {
                int car_pos = -1;
                int car_speed = rand() % 3 + 1;
                if(roads[i].total_cars > 0) {
                    car_pos = roads[i].cars[roads[i].total_cars-1].position - 1;
                }
                if(car_pos < 0) {
                    car_pos = rand() % 5;
                }
                if(roads[i].total_cars < MAX_CARS) {
                    roads[i].cars[roads[i].total_cars].speed = car_speed;
                    roads[i].cars[roads[i].total_cars].position = car_pos;
                    roads[i].total_cars++;
                }
            }
            update_cars(&roads[i]);
            move_cars(&roads[i]);
        }
        display_roads(roads, total_roads);
        sleep(DELAY_SEC);
        current_time++;
    }

    printf("\nSimulation Completed!\n");

    return 0;
}