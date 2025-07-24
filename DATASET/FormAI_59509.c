//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

// Parameters
#define L 100   // Road length
#define V_MAX 5 // Maximum car speed
#define P 0.3   // Probability of a car being present
#define T 100   // Number of simulation time steps

// Global variables
int x[L];       // Road cells
int v[L];       // Car speeds
int t = 0;      // Simulation time
int total_cars = 0; // Total number of cars in the simulation

// Initializes the road with cars and empty spaces
void init_road() {
    srand(time(NULL));
    for(int i=0; i<L; i++) {
        if((double)rand()/(double)RAND_MAX < P) {
            x[i] = 1;
            total_cars++;
            v[i] = rand() % V_MAX + 1;
        } else {
            x[i] = 0;
            v[i] = 0;
        }
    }
}

// Prints the current state of the road
void print_road() {
    for(int i=0; i<L; i++) {
        if(x[i] == 0) {
            putchar('.');
        } else {
            putchar('*');
        }
    }
    putchar('\n');
}

// Advances the simulation by one time step
void advance() {
    // Acceleration
    #pragma omp parallel for
    for(int i=0; i<L; i++) {
        if(x[i] == 1 && v[i] < V_MAX) {
            v[i]++;
        }
    }

    // Deceleration
    #pragma omp parallel for
    for(int i=0; i<L; i++) {
        int d = 1;
        while(d <= v[i]) {
            if(x[(i + d) % L] != 0) {
                if(d - 1 < v[i]) {
                    v[i] = d - 1;
                }
                break;
            }
            d++;
        }
    }

    // Randomization
    #pragma omp parallel for
    for(int i=0; i<L; i++) {
        if(x[i] == 1 && v[i] > 0 && (double)rand()/(double)RAND_MAX < 0.5) {
            v[i]--;
        }
    }

    // Movement
    #pragma omp parallel for
    for(int i=0; i<L; i++) {
        if(x[i] == 1) {
            x[i] = 0;
            x[(i + v[i]) % L] = 1;
        }
    }

    t++; // Increase simulation time
}

int main() {
    init_road(); // Initialize road

    // Run simulation
    while(t < T) {
        printf("Time: %d\n", t);
        print_road();
        advance();
    }

    printf("Simulation complete\n");
    printf("Total number of cars: %d\n", total_cars);

    return 0;
}