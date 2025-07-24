//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: high level of detail
#include<stdio.h>

int main() {
    int n, m, i, j, count = 0;
    printf("Enter the number of cars: ");
    scanf("%d", &n);
    printf("Enter the time to clear each car: ");
    scanf("%d", &m);
    
    printf("Traffic Flow Simulation\n");

    // Loop to simulate traffic flow
    for(i = 1; i <= n; i++) {

        // Check if there is a car waiting
        if(i == 1) {
            printf("Car %d is entering traffic\n", i);
        } else {
            // Check if the previous car has cleared
            if((i-1)*m <= count) {
                printf("Car %d is entering traffic\n", i);
            } else {
                // Wait for the previous car to clear
                printf("Car %d is waiting for car %d to clear\n", i, i-1);
                count += ((i-1)*m) - count;
                printf("Car %d starts moving after waiting for %d seconds\n", i, count);
                count += m;
            }
        }
    }

    return 0;
}