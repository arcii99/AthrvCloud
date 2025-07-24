//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROADS 4
#define MAX_CARS_PER_ROAD 10

void print_traffic(char traffic_data[NUM_ROADS][MAX_CARS_PER_ROAD]) {
    int i, j;

    printf("\n");

    for (i = 0; i < NUM_ROADS; i++) {
        for (j = 0; j < MAX_CARS_PER_ROAD; j++) {
            if (traffic_data[i][j] == '0')
                printf("_ ");
            else
                printf("%c ", traffic_data[i][j]);
        }

        printf("\n");
    }
}

void simulation(char traffic_data[NUM_ROADS][MAX_CARS_PER_ROAD]) {
    int i, j, k;
    char temp;

    for (i = 0; i < NUM_ROADS; i++) {
        for (j = 0; j < MAX_CARS_PER_ROAD; j++) {
            if (traffic_data[i][j] == '0')
                continue;

            temp = traffic_data[i][j];

            if (i == 0) {
                if (j == MAX_CARS_PER_ROAD - 1)
                    traffic_data[i][j] = '0';
                else
                    traffic_data[i][j + 1] = temp;
            } else if (i == NUM_ROADS - 1) {
                if (j == 0) 
                    traffic_data[i][j] = '0';
                else
                    traffic_data[i][j - 1] = temp;
            } else {
                if (rand() % 2 == 0 && j > 0)
                    traffic_data[i][j - 1] = temp;
                else if (j < MAX_CARS_PER_ROAD - 1)
                    traffic_data[i][j + 1] = temp;
            }

            k = rand() % (MAX_CARS_PER_ROAD * 4);

            if (k < MAX_CARS_PER_ROAD && traffic_data[i][k] == '0') {
                traffic_data[i][k] = temp;
                traffic_data[i][j] = '0';

                break;
            }
        }
    }

    print_traffic(traffic_data);
}

int main() {
    char traffic_data[NUM_ROADS][MAX_CARS_PER_ROAD] = {'0'};
    int i, j, k;

    srand(time(NULL));

    for (i = 0; i < NUM_ROADS; i++) {
        k = rand() % MAX_CARS_PER_ROAD;

        for (j = 0; j <= k; j++) 
            traffic_data[i][j] = 'A' + (rand() % 26);
    }

    printf("Traffic Flow Simulation\n\n");

    while (1) {
        simulation(traffic_data);

        printf("\nPress any key to continue\n");
        getchar();
    }

    return 0;
}