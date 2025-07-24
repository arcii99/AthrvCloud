//FormAI DATASET v1.0 Category: Random ; Style: excited
//I am so excited to share with you my unique C Random example program!
//This program generates and outputs ten random numbers between 0 and 99
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Get ready to witness the power of randomization!\n");

    //seed the generator with the current time 
    srand(time(0));

    //generate and output 10 random numbers
    for(int i=0; i<10; i++) {
        printf("Random number %d: %d\n", i+1, rand() % 100);
    }

    printf("Hope you enjoyed watching these random numbers. Come back soon for more!\n");

    return 0;
}