//FormAI DATASET v1.0 Category: Random ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator
    int num = rand() % 100; // generate a random number between 0 and 99
    
    printf("I cannot believe it! I just generated a random number: %d\n", num);
    
    if (num % 2 == 0) {
        printf("And it's even! Wow, what are the chances?!\n");
    } else if (num % 3 == 0) {
        printf("And it's divisible by 3! Holy cow, this is amazing!\n");
    } else {
        printf("And it's just a regular number... but still pretty cool I guess.\n");
    }
    
    printf("Wait, let me generate another one!\n");
    num = rand() % 100;
    printf("Okay, got another random number: %d\n", num);
    
    int i;
    for (i = 0; i < num; i++) {
        printf("I am so surprised, I can't stop printing this message!\n");
    }
    
    printf("Okay, okay, enough with the surprises. That's all for now!\n");
    
    return 0;
}