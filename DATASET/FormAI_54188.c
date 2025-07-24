//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void simulate_gps(int x, int y){
    // Base case
    if(x == 0 && y == 0){
        printf("You have arrived at your destination.\n");
        return;
    }
    
    // Recursive cases
    if(x > 0){
        printf("Walk East %d meters.\n", x);
        simulate_gps(x-1, y);
    }
    if(y > 0){
        printf("Walk North %d meters.\n", y);
        simulate_gps(x, y-1);
    }
}

int main(){
    int x, y;
    
    printf("Enter the X and Y coordinates of your destination:\n");
    scanf("%d %d", &x, &y);
    
    printf("Starting GPS simulation...\n");
    simulate_gps(x, y);
    
    return 0;
}