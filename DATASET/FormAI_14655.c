//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate random conspiracy theories
    for(int i = 1; i <= 10; i++) {
        int num = rand() % 5 + 1;
        switch(num) {
            case 1:
                printf("The government is hiding the fact that cows can fly.\n");
                break;
            case 2:
                printf("All celebrities are secretly part of a cult.\n");
                break;
            case 3:
                printf("The moon landing was faked.\n");
                break;
            case 4:
                printf("Aliens are among us and the government knows about it.\n");
                break;
            case 5:
                printf("The Illuminati controls all major world events.\n");
                break;
            default:
                printf("Error: Invalid number generated.\n");
                break;
        }
    }

    return 0;
}