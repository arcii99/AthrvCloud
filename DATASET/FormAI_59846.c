//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int traffic[10][10], car_count, i, j;

    // Initialize traffic with 0
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            traffic[i][j] = 0;
        }
    }

    // Generate random car count
    srand(time(NULL));
    car_count = rand()%10 + 1;

    // Add cars to traffic
    for(i=0; i<car_count; i++) {
        int x, y;
        x = rand()%10;
        y = rand()%10;
        if(traffic[x][y] == 0) {
            traffic[x][y] = 1;
        }
    }

    // Display traffic
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            if(traffic[i][j] == 1) {
                printf("C ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    return 0;
}