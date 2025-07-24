//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Returns a random conspiracy theory
char* generate_conspiracy() {
    switch(rand() % 5) {
        case 0:
            return "Bigfoot is a government-created super soldier";
        case 1:
            return "The moon landing was faked by Hollywood";
        case 2:
            return "Chemtrails are a government mind control experiment";
        case 3:
            return "The earth is flat and the government is hiding it from us";
        default:
            return "Aliens are real and the government is hiding it from us";
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate and print 10 random conspiracy theories
    for(int i = 0; i < 10; i++) {
        char* conspiracy = generate_conspiracy();
        printf("%d. %s\n", i+1, conspiracy);
        free(conspiracy);
    }
    
    return 0;
}