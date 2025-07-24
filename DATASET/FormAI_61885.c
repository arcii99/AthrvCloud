//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: grateful
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX_CAR_NUM 50
#define MAX_PERIOD 10

void display_lanes(int lane[], int size);
void move_cars(int time_stamp, int lane[], int size, int speed_max);
int check_collision(int lane[], int size);
int count_cars(int lane[], int size);

int main(){
    srand(time(NULL));
    int northbound[MAX_CAR_NUM] = {0};
    int southbound[MAX_CAR_NUM] = {0};
    int num_cars_north = 0;
    int num_cars_south = 0;
    int max_time = 300;
    int time = 0;
    int speed_max = 5;

    for (int i=0; i<MAX_PERIOD; i++){
        int cars_generated = rand() % 10;

        for (int j=0; j<cars_generated; j++){
            int direction = rand() % 2;
            int lane_num = rand() % MAX_CAR_NUM;

            if (direction == 0 && num_cars_north < MAX_CAR_NUM){
                northbound[lane_num] = 1;
                num_cars_north++;
            }
            else if (direction == 1 && num_cars_south < MAX_CAR_NUM){
                southbound[lane_num] = 1;
                num_cars_south++;
            }
        }

        printf("Traffic generated at northbound and southbound...\n");
        display_lanes(northbound, MAX_CAR_NUM);
        display_lanes(southbound, MAX_CAR_NUM);

        while(time <= max_time){
            printf("Time: %d\n", time);
            move_cars(time, northbound, MAX_CAR_NUM, speed_max);
            move_cars(time, southbound, MAX_CAR_NUM, speed_max);

            if (check_collision(northbound, MAX_CAR_NUM) || check_collision(southbound, MAX_CAR_NUM)){
                printf("Crash detected!\n");
                break;
            }

            display_lanes(northbound, MAX_CAR_NUM);
            display_lanes(southbound, MAX_CAR_NUM);

            time++;
        }

        printf("Period %d end\n", i);
        int total_cars_north = count_cars(northbound, MAX_CAR_NUM);
        int total_cars_south = count_cars(southbound, MAX_CAR_NUM);
        printf("Total cars arrived during this period at northbound: %d\n", total_cars_north);
        printf("Total cars arrived during this period at southbound: %d\n", total_cars_south);
        num_cars_north -= total_cars_north;
        num_cars_south -= total_cars_south;
        printf("Current traffic:\n");
        display_lanes(northbound, MAX_CAR_NUM);
        display_lanes(southbound, MAX_CAR_NUM);
    }

    return 0;
}

void display_lanes(int lane[], int size){
    for (int i=0; i<size; i++){
        if (lane[i] == 1){
            printf("X");
        }
        else{
            printf("-");
        }
    }
    printf("\n");
}

void move_cars(int time_stamp, int lane[], int size, int speed_max){
    for (int i=0; i<size; i++){
        if (lane[i] == 1){
            int speed = rand() % speed_max + 1;
            if (time_stamp % speed == 0){
                lane[i] = 0;
                if (i == size - 1){
                    lane[0] = 1;
                }
                else{
                    lane[i+1] = 1;
                }
            }
        }
    }
}

int check_collision(int lane[], int size){
    for (int i=0; i<size; i++){
        if (lane[i] == 1 && lane[(i+1)%size] == 1){
            return 1;
        }
    }
    return 0;
}

int count_cars(int lane[], int size){
    int count = 0;
    for (int i=0; i<size; i++){
        if (lane[i] == 0){
            count++;
        }
    }
    return count;
}