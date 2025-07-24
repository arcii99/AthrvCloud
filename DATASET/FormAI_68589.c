//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50

void print_traffic_map(int traffic[], int size) {
    printf("Traffic Map:\n");
    for (int i = 0; i < size; i++) {
        if (traffic[i] == 0) {
            printf("-");
        } else {
            printf("%d", traffic[i]);
        }
    }
    printf("\n\n");
}

int main() {
    srand(time(NULL));
    
    int traffic[MAX_CARS] = {0};
    int num_cars = rand() % MAX_CARS + 1;
    
    for (int i = 0; i < num_cars; i++) {
        int position = rand() % MAX_CARS;
        while (traffic[position] != 0) {
            position = rand() % MAX_CARS;
        }
        traffic[position] = i + 1;
    }
    
    print_traffic_map(traffic, MAX_CARS);
    
    for (int i = MAX_CARS - 1; i >= 0; i--) {
        if (traffic[i] != 0) {
            int curr_pos = i;
            int next_pos = i + 1;
            while (traffic[next_pos] == 0 && next_pos < MAX_CARS) {
                next_pos++;
            }
            if (next_pos == MAX_CARS) {
                traffic[curr_pos] = 0;
            } else {
                traffic[next_pos - 1] = traffic[curr_pos];
                traffic[curr_pos] = 0;  
            }
        }
    }
    
    print_traffic_map(traffic, MAX_CARS);
    
    return 0;
}