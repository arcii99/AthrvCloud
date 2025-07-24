//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int traffic[10][10];
    int i, j, c, r;
    
    srand(time(0));
    
    // Initializing traffic flow
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            traffic[i][j] = rand() % 5;
        }
    }
    
    printf("Welcome to the Traffic Flow Simulation!\n\n");
    
    printf("Current Traffic Flow:\n");
    // Displaying traffic flow
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", traffic[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");

    // Simulation loop
    for (c = 0; c < 5; c++) {
        printf("Iteration %d:\n", c+1);
        for (r = 0; r < 10; r++) {
            for (i = 0; i < 10; i++) {
                // Cars move to the left
                if (traffic[r][i] && i > 0 && traffic[r][i-1] == 0) {
                    traffic[r][i-1] = traffic[r][i];
                    traffic[r][i] = 0;
                }
            }
        }
        // Displaying updated traffic flow
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                printf("%d ", traffic[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    printf("Simulation complete. Thank you for using our program!\n");
    
    return 0;
}