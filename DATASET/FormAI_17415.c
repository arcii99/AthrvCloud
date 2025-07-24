//FormAI DATASET v1.0 Category: Funny ; Style: peaceful
#include <stdio.h>

int main() {
    printf("Let's take a peaceful walk in the park.\n");
    
    int ducks = 10;
    while (ducks > 0) {
        printf("There are %d ducks swimming in the pond.\n", ducks);
        
        if (ducks % 2 == 0) {
            printf("Looks like every other duck has a twin!\n");
        } else {
            printf("Looks like these ducks are all unique!\n");
        }
        
        ducks--;
    }
    
    printf("We've fed all the ducks and they're happily swimming away.\n");
    
    int benchCapacity = 3;
    int peopleOnBench = 0;
    while (peopleOnBench < benchCapacity) {
        printf("Let's take a rest on this peaceful bench.\n");
        printf("There are %d people on the bench.\n", peopleOnBench);

        if (peopleOnBench == 0) {
            printf("Looks like we're the first ones here.\n");
        } else if (peopleOnBench == 1) {
            printf("Someone else just joined us.\n");
        } else {
            printf("This bench is starting to get cozy with %d people.\n", peopleOnBench);
        }

        peopleOnBench++;
    }

    printf("The bench is now full, time to move on.\n");
    
    printf("As we walk away from the park, let's take a moment to appreciate the beauty of nature around us.\n");

    return 0;
}