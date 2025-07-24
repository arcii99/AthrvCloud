//FormAI DATASET v1.0 Category: Funny ; Style: energetic
#include <stdio.h>

int main() {
    int energy_level = 100; // initial energy level
    int laughter_count = 0; // holder for the number of times laughter is printed
    int i; // for loop counter
    
    printf("Get ready for a fun ride!\n");

    for(i = 0; i < energy_level; i++) {
        if(i % 10 == 0) {
            printf("Hahaha\n");
            laughter_count++; 
        } else if(i % 5 == 0) {
            printf("LOLOLOL\n");
            laughter_count++;
        } else if(i % 2 == 0) {
            printf("Hehehe\n");
            laughter_count++;
        } else {
            printf("HAHAHA\n");
            laughter_count++;
        }
    }

    printf("Congratulations! You made it through the ride!\n");
    printf("You laughed %d times and your energy level is now at %d.\n", laughter_count, energy_level);

    return 0;
}