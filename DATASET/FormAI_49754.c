//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int traffic[10][10], i, j, cars;
    srand(time(NULL));

    //initialize traffic grid with random number of cars
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            traffic[i][j] = rand() % 50;
        }
    }

    //print initial traffic grid
    printf("Initial Traffic Flow:\n");
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            printf("%d ", traffic[i][j]);
        }
        printf("\n");
    }

    //simulate traffic flow for 10 iterations
    for(int iteration = 1; iteration <= 10; iteration++){
        printf("\n\nIteration %d:\n", iteration);
        for(i = 0; i < 10; i++){
            for(j = 0; j < 10; j++){
                //check if car moves to right lane
                if(j < 9 && traffic[i][j] >= traffic[i][j+1]){
                    cars = traffic[i][j+1];
                    traffic[i][j+1] = traffic[i][j];
                    traffic[i][j] = cars;
                }
                //check if car moves to left lane
                else if(j > 0 && traffic[i][j] >= traffic[i][j-1]){
                    cars = traffic[i][j-1];
                    traffic[i][j-1] = traffic[i][j];
                    traffic[i][j] = cars;
                }
                //check if car moves forward
                else if(i > 0 && traffic[i][j] > traffic[i-1][j]){
                    cars = traffic[i-1][j];
                    traffic[i-1][j] = traffic[i][j];
                    traffic[i][j] = cars;
                }
            }
        }

        //print new traffic grid after iteration
        for(i = 0; i < 10; i++){
            for(j = 0; j < 10; j++){
                printf("%d ", traffic[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}