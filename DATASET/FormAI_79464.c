//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int speed = 0;
    int input = 0;
    int min_speed = 1;
    int max_speed = 1000;
    
    printf("Welcome to the Internet Speed Test!\n\n");
    printf("Press 1 to start the test: ");
    scanf("%d", &input);
    
    if (input == 1) {
        printf("\nCalculating your internet speed...");
        // Simulating speed test calculation
        srand(time(NULL));
        speed = (rand() % (max_speed - min_speed + 1)) + min_speed;
        printf("\n\nYour internet speed is %d Mbps.\n", speed);
    }
    else {
        printf("\nInvalid input.\n");
        return 0;
    }
    
    if (speed <= 10) {
        printf("\nYour internet speed is very slow. Consider upgrading your plan.\n");
    }
    else if (speed <= 50) {
        printf("\nYour internet speed is average. It should handle most tasks.\n");
    }
    else {
        printf("\nYour internet speed is fast! You should not have any problems.\n");
    }
    
    return 0;
}